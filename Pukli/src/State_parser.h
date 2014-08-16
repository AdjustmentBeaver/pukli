#ifndef __STATE_PARSER__
#define __STATE_PARSER__

#include "rapidjson\document.h"
#include <iostream>
#include <vector>

using namespace rapidjson;

class Game_object;

class State_parser
{
public:
	bool parse_state(const char* file_name, std::string state_id, std::vector<Game_object*> *p_objects);
private:
	void parse_objects(Value& p_state_root, std::vector<Game_object*> *p_objects);
	
	void parse_textures(Value& p_state_root, std::vector<std::string> *p_texture_ids);
};

#endif