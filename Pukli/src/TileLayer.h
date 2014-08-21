#ifndef __TILELAYER_H__
#define __TILELAYER_H__

#include <vector>
#include "Vec2D.h"
#include "Layer.h"
#include "Level.h"

class Tile_layer : public Layer
{
public:
	Tile_layer(int tile_size, const std::vector<Tileset> &tilesets);
	virtual void update();
	virtual void render();

	void set_tile_IDs(const std::vector<std::vector<int>>& data)
	{
		m_tile_IDs = data;
	}
	void set_tile_size(int tileSize)
	{
		m_tile_size = tileSize;
	}
	Tileset get_tileset_by_ID(int tileID);
private:
	int m_num_columns;
	int m_num_rows;
	int m_tile_size;
	Vec2D m_position;
	Vec2D m_velocity;
	const std::vector<Tileset> &m_tilesets;
	std::vector<std::vector<int>> m_tile_IDs;
};

#endif // !__TILELAYER_H__
