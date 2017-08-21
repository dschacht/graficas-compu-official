#pragma once

#include <string>

class circle
{
public:
	circle();
	circle(double r);
	circle(double r, std::string c);

	double GetArea();
	double GetRadius();
	std::string GetColor();

	void SetRadius(double r);
	void SetColor(std::string c);
private:
	double _radius;
	std::string _color;
};