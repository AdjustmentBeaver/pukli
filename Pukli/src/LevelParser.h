#ifndef __LEVELPARSER_H__
#define __LEVELPARSER_H__

#include "Level.h"
#include "rapidjson\document.h"

using namespace rapidjson;

class LevelParser
{
public:
	Level* parse_level(const char* levelFile);
private:
	void parse_tilesets(const Value& tileset_root, std::vector<Tileset>* tilesets);
	void parse_tile_layer(const Value& tile_element, std::vector<Layer*> layers, const std::vector<Tileset>* tilesets);
	int m_tile_size;
	int m_width;
	int m_height;
};

#endif // !__LEVELPARSER_H__
