#include "rapidjson\document.h"
#include "Game_object.h"
#include <string>
#include <vector>
#include <fstream>
#include "State_parser.h"

using namespace rapidjson;

bool State_parser::parse_state(const char* file_name, std::string state_id, std::vector<Game_object*> *p_objects) {
	std::string file = get_file_contents(file_name);
	Document d;
	d.Parse(file.c_str());
}

void State_parser::parse_objects(const Value& p_state_root, std::vector<Game_object*> *p_objects){

}

void State_parser::parse_textures(const Value& p_state_root, std::vector<std::string> *p_texture_ids){

}

std::string State_parser::get_file_contents(const char *filename) {
	std::ifstream ifs(filename);
	std::string content((std::istreambuf_iterator<char>(ifs)),( std::istreambuf_iterator<char>()));
	return content;
}
