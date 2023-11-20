#pragma once
#include "gate.h"

class binary_gate : public gate
{
public:
	binary_gate(sf::Vector2f position = sf::Vector2f(0.0f, 0.0f), float angle = 0.0f, sf::Vector2f size = sf::Vector2f(10.0f, 10.0f));

	void SetInput(int i, wire* wire);
	void SetOutput(wire* var_wire);
	void SetAngle(float angle);
	void SetInvertor(int i, bool inverted);
	float GetAngle();
	sf::Vertex GetInputPosition(int i);
	sf::Vertex GetOutputPosition();

	void Draw(sf::RenderWindow* window);

	~binary_gate();
protected:
	float angle;
	bool input1Inverted;
	bool input2Inverted;
	bool outputInverted;
	sf::CircleShape* inverter[3];
};
