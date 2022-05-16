#pragma once
#include "binary_gate.h"

class or_gate : public binary_gate
{
public:
	or_gate(sf::Vector2f position = sf::Vector2f(0.0f, 0.0f), float angle = 0.0f, sf::Vector2f size = sf::Vector2f(10.0f, 10.0f));
	void Update();
	void Draw(sf::RenderWindow* window);

private:
	std::pair<sf::Vertex,sf::Vertex> connective_lines[2];
};

