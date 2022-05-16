#pragma once
#include "wire.h"

class c_module
{
public:
	sf::Vector2f GetSize();
	sf::Vector2f GetPosition();
	virtual void Update() = 0;
	virtual void Draw(sf::RenderWindow* window) = 0;

protected:
	std::vector<wire*> inputs;
	std::vector<wire*> outputs;
	sf::Vector2f position;
	sf::Vector2f size;
 };