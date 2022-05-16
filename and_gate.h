#pragma once
#include "binary_gate.h"

class and_gate : public binary_gate
{
public:
	and_gate(sf::Vector2f position = sf::Vector2f(0.0f, 0.0f), float angle = 0.0f, sf::Vector2f size = sf::Vector2f(10.0f, 10.0f));
	void Update();

};

