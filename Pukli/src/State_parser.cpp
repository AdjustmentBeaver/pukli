#include "rapidjson\document.h"
#include "Game_object.h"
#include <string>
#include <vector>

using namespace rapidjson;

bool parse_state(const char* file_name, std::string state_id, std::vector<Game_object*> *p_objects) {

}

void parse_objects(Value& p_state_root, std::vector<Game_object*> *p_objects){

}

void parse_textures(Value& p_state_root, std::vector<std::string> *p_texture_ids){

}