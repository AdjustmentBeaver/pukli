#ifndef __CAMERA__
#define __CAMERA__

#include "Vec2D.h"

class Camera
{
public:
	void update(Vec2D velocity);
	void set_target(Vec2D* target) { m_target = target; }
	void set_position(const Vec2D& position) { m_position = position; }
	Vec2D get_position() const;

	//Singleton
	static Camera* instance()
	{
		if (s_camera == 0)
		{
			s_camera = new Camera();
		}
		return s_camera;
	}

private:
	Camera();
	~Camera();

	Vec2D* m_target;
	Vec2D m_position;

	static Camera* s_camera;
};

#define The_camera Camera::instance();

#endif