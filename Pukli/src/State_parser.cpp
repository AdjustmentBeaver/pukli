#include "rapidjson\document.h"
#include "Game_object.h"
#include "Game.h"
#include <string>
#include <vector>
#include <fstream>
#include "State_parser.h"
#include "utils.h"
#include "Texture_manager.h"

using namespace rapidjson;

bool State_parser::parse_state(const char* file_name, std::string state_id, std::vector<Game_object*> *p_objects, std::vector<std::string> *p_texture_ids) {
	std::string file = get_file_contents(file_name);
	Document d;
	if (d.Parse(file.c_str()).HasParseError()) {
		LOG << "[ERROR] Parse:" << d.GetParseError() << "location:" << d.GetErrorOffset();
		return false;
	}
	const Value& state_root = d["states"][state_id.c_str()];
	const Value& texture_root = state_root["textures"];
	const Value& objects_root = state_root["objects"];

	parse_textures(texture_root, p_texture_ids);
	parse_objects(objects_root, p_objects);

	return true;
}

void State_parser::parse_objects(const Value& p_state_root, std::vector<Game_object*> *p_objects) {

}

void State_parser::parse_textures(const Value& p_state_root, std::vector<std::string> *p_texture_ids) {
	for (SizeType i = 0; i < p_state_root.Size(); i++) {
		std::string id = p_state_root[i]["id"].GetString();
		std::string file_name = p_state_root[i]["file_name"].GetString();
		p_texture_ids->push_back(id);
		The_Texture_manager->load(file_name, id, The_Game->get_renderer);
	}
}

std::string State_parser::get_file_contents(const char *filename) {
	std::ifstream ifs(filename);
	std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
	return content;
}
