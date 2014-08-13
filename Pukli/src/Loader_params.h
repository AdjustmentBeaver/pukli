#ifndef __LOADER_PARAMS_H__
#define __LOADER_PARAMS_H__

#include <string>

//m_callback_id, anim_speed hiányzik
//texture_id = 0  és num_frames = 0 !!!!! menu_button !!!

class Loader_params {
public:
	Loader_params(int x, int y, int width, int height, std::string texture_id, int num_frames = 0) : m_x(x), m_y(y), m_width(width), m_height(height), m_texture_id(texture_id), m_num_frames(num_frames){}

	int get_x() const { return m_x; }
	int get_y() const { return m_y; }
	int get_width() const { return m_width; }
	int get_height() const { return m_height; }
	int get_num_frames() const { return m_num_frames; }
	std::string get_texture_id() const { return m_texture_id; }
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	std::string m_texture_id;
	int m_num_frames;
};

#endif