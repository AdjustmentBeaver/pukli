#ifndef __VEC_2D__
#define __VEC_2D__

#include <math.h>
#include "utils.h"

class Vec2D {
public:
	Vec2D() : m_x(0), m_y(0) {}
	Vec2D(double x, double y) : m_x(x), m_y(y) {}
	const double& get_x() const { return m_x; }
	const double& get_y() const { return m_y; }

	void set_x(double x) { m_x = x; }
	void set_y(double y) { m_y = y; }

	double length() const { return sqrt(m_x * m_x + m_y * m_y); }

	void normalize() { *this *= length() > 0 ? (1 / length()) : 1; }

	Vec2D& operator+=(const Vec2D& v2) {
		m_x += v2.m_x;
		m_y += v2.m_y;
		return *this;
	}
	Vec2D& operator-=(const Vec2D& v2) {
		m_x -= v2.m_x;
		m_y -= v2.m_y;
		return *this;
	}
	Vec2D& operator*=(const Vec2D& v2) {
		m_x *= v2.m_x;
		m_y *= v2.m_y;
		return *this;
	}
	Vec2D& operator*=(double scalar) {
		m_x *= scalar;
		m_y *= scalar;
		return *this;
	}
	Vec2D& operator/=(double scalar) {
		m_x /= scalar;
		m_y /= scalar;
		return *this;
	}

	~Vec2D() {}
private:
	double m_x;
	double m_y;
};
namespace {
	const Vec2D operator+(const Vec2D& v1, const Vec2D& v2) {
		return Vec2D(v1) += v2;
	}
	const Vec2D operator*(const Vec2D& v1, const Vec2D& v2) {
		return Vec2D(v1) *= v2;
	}
	const Vec2D operator*(const Vec2D& v1, double scalar) {
		return Vec2D(v1) *= scalar;
	}
	const Vec2D operator*(double scalar, const Vec2D& v1) {
		return v1*scalar;
	}
	const Vec2D operator-(const Vec2D& v1, const Vec2D& v2) {
		return Vec2D(v1) -= v2;
	}
	const Vec2D operator/(const Vec2D& v1, double scalar) {
		return Vec2D(v1) /= scalar;
	}
}
#endif