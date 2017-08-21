#include "circle.h"

circle::circle()
{
	_radius = 1.0;
	_color = "red";
}

circle::circle(double r)
{
	_radius = r;
	_color = "red";
}

circle::circle(double r, std::string c)
{
	_radius = r;
	_color = c;
}

double circle::GetRadius()
{
	return _radius;
}

std::string circle::GetColor()
{
	return _color;
}

void circle::SetRadius(double r)
{
	_radius = r;
}

void circle::SetColor(std::string c)
{
	_color = c;
}

double circle::GetArea()
{
	return 3.14159 * _radius * _radius;
}