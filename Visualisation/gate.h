#pragma once
#include "module.h"

class gate : public c_module
{
public:
	void Update() = 0;
	void Draw(sf::RenderWindow* window);
	~gate();

protected:
	sf::RectangleShape* shape;
	bool value;

};