#include "Stack.h"
Vector2D::Vector2D()
{}
Vector2D::~Vector2D()
{}
Vector2D::Vector2D(double x, double y) : x{ x }, y{ y }
{}
Vector2D::Vector2D(const Vector2D& v)
{
	this->x = v.x;
	this->y = v.y;
}
void Vector2D::add(const Vector2D v)
{
	this->x += v.x;
	this->y += v.y;
}

