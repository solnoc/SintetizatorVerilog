#include "gate.h"

void gate::Draw(sf::RenderWindow* window)
{
	window->draw(*shape);
}
gate::~gate()
{
	delete shape;
}