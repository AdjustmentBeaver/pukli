#ifndef __LEVEL_H__
#define __LEVEL_H__


#include <string>
#include <vector>
#include "Layer.h"

struct Tileset
{
	int first_grid_ID;
	int tile_width;
	int tile_height;
	int spacing;
	int margin;
	int width;
	int height;
	int num_columns;
	std::string name;
};

class Level {
public:
	Level();
	~Level() {}
	void update();
	void render();

	std::vector<Tileset>* get_Tilesets() {
		return &m_tilesets;
	}

	std::vector<Layer*>* get_Layers() {
		return &m_layers;
	}

private:
	std::vector<Tileset> m_tilesets;
	std::vector<Layer*> m_layers;
};

#endif // !__LEVEL_H__