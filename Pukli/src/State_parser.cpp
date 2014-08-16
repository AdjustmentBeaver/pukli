#include "rapidjson\document.h"
#include "Game_object.h"
#include <string>
#include <vector>
#include <fstream>
#include "State_parser.h"
#include "utils.h"

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

void State_parser::parse_objects(const Value& p_state_root, std::vector<Game_object*> *p_objects){
	int x, y, width, height, num_frames, callback_id, anim_speed;
	std::string texture_id, obj_type;

	for (SizeType i = 0; p_state_root.Size(); i++) {
		obj_type = p_state_root[i]["type"].GetString;
		x = p_state_root[i]["x"].GetInt;
		y = p_state_root[i]["y"].GetInt;
		width = p_state_root[i]["width"].GetInt;
		height = p_state_root[i]["height"].GetInt;
		num_frames = p_state_root[i]["num_frames"].GetInt;
		callback_id = p_state_root[i]["callback_id"].GetInt;
		anim_speed = p_state_root[i]["anim_speed"].GetInt;
		texture_id = p_state_root[i]["texture_id"].GetString;

		Game_object* p_game_object = The_game_object_factory->create(obj_type);
		p_game_object->load(new Loader_params(x, y, width, height, texture_id, num_frames, callback_id, anim_speed));
		p_objects->push_back(p_game_object);
	}
}

void State_parser::parse_textures(const Value& p_state_root, std::vector<std::string> *p_texture_ids) {

}

std::string State_parser::get_file_contents(const char *filename) {
	std::ifstream ifs(filename);
	std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
	return content;
}
