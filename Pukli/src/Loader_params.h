#ifndef __LOADER_PARAMS_H__
#define __LOADER_PARAMS_H__

#include <string>

class Loader_params {
public:
	Loader_params(int x, int y, int width, int height, std::string texture_id, int callback_id = 0, int num_frames = 0, int anim_speed = 0) :
		m_x(x),
		m_y(y),
		m_width(width),
		m_height(height),
		m_texture_id(texture_id),
		m_num_frames(num_frames),
		m_callback_id(callback_id),
		m_anim_speed(anim_speed) {}

	const int get_x() const { return m_x; }
	const int get_y() const { return m_y; }
	const int get_width() const { return m_width; }
	const int get_height() const { return m_height; }
	const std::string get_texture_id() const { return m_texture_id; }
	const int get_callback_id() const { return m_callback_id };
	const int get_num_frames() const { return m_num_frames; }
	const int get_anim_speed() const { return m_anim_speed; }

	~Loader_params() {}
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	std::string m_texture_id;
	int m_callback_id;
	int m_num_frames;
	int m_anim_speed;
};

#endif