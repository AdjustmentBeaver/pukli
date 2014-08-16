#include "rapidjson\document.h"
#include <iostream>
#include <vector>

class Game_object;

class State_parser
{
public:
	bool parse_state(const char* state_file, std::string state_id, std::vector<Game_object*> *p_objects);
private:
	void parse_objects(Document p_state_root, std::vector<Game_object*> *p_objects);
	
	void parse_textures(Document p_state_root, std::vector<std::string> *p_texture_ids);
};