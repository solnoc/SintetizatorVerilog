#include "binary_gate.h"

binary_gate::binary_gate(sf::Vector2f position, float angle, sf::Vector2f size)
{
	this->position = position;
	this->angle = angle;
	this->size = size;

	inputs = std::vector<wire*>(2);
	outputs = std::vector<wire*>(1);

	shape = new sf::RectangleShape(size);
	shape->setOrigin(shape->getGlobalBounds().width / 2.0f, shape->getGlobalBounds().height / 2.0f);
	shape->setRotation(angle);
	shape->setPosition(position);

	input1Inverted = false;
	input2Inverted = false;
	outputInverted = false;

	for (int i = 0; i < 3; i++)
	{
		inverter[i] = new sf::CircleShape(3.0f);
		inverter[i]->setOrigin(sf::Vector2f(inverter[i]->getGlobalBounds().width / 2.0f, inverter[i]->getGlobalBounds().height / 2.0f));
	}

	inverter[0]->setPosition(sf::Vector2f(GetInputPosition(0).position));
	inverter[1]->setPosition(sf::Vector2f(GetInputPosition(1).position));
	inverter[2]->setPosition(sf::Vector2f(GetOutputPosition().position));
}
void binary_gate::SetInput(int i, wire* wire)
{
	inputs[i] = wire;
}
void binary_gate::SetOutput(wire* var_wire)
{
	outputs[0] = var_wire;
}
void binary_gate::SetAngle(float angle)
{
	this->angle = angle;
	shape->setRotation(angle);
}
void binary_gate::SetInvertor(int i, bool inverted)
{
	switch (i)
	{
	case 0:
		input1Inverted = inverted;
		break;
	case 1:
		input2Inverted = inverted;
		break;
	case 2:
		outputInverted = inverted;
		break;
	default:
		break;
	}
}
sf::Vertex binary_gate::GetInputPosition(int i)
{
	if (angle == 0.0f)
		return sf::Vertex(sf::Vector2f(position.x - size.x / 2.0f, position.y + ((size.y / 6.0f) * (i ? 1 : -1))));
	else if (angle == 90.0f)
		return sf::Vertex(sf::Vector2f(position.x + ((size.x / 6.0f) * (i ? 1 : -1)), position.y - size.y / 2.0f));
	else if (angle == 180.0f)
		return sf::Vertex(sf::Vector2f(position.x + size.x / 2.0f, position.y + ((size.y / 6.0f) * (i ? -1 : 1))));
	else if (angle == 270.0f)
		return sf::Vertex(sf::Vector2f(position.x + ((size.x / 6.0f) * (i ? -1 : 1)), position.y - size.y / 2.0f));
}
sf::Vertex binary_gate::GetOutputPosition()
{
	if(angle == 0.0f)
		return sf::Vertex(sf::Vector2f(position.x + size.x / 2.0f, position.y));
	else if (angle == 90.0f)
		return sf::Vertex(sf::Vector2f(position.x, position.y + size.y / 2.0f));
	else if (angle == 180.0f)
		return sf::Vertex(sf::Vector2f(position.x - size.x / 2.0f, position.y));
	else if (angle == 270.0f)
		return sf::Vertex(sf::Vector2f(position.x, position.y - size.y / 2.0f));
}
float binary_gate::GetAngle()
{
	return angle;
}

void binary_gate::Draw(sf::RenderWindow* window)
{
	gate::Draw(window);
	if (input1Inverted)
	{
		inverter[0]->setFillColor(inputs[0]->GetValue() ? sf::Color::White : sf::Color::Blue);
		window->draw(*inverter[0]);
	}
	if (input2Inverted)
	{
		inverter[1]->setFillColor(inputs[1]->GetValue() ? sf::Color::White : sf::Color::Blue);
		window->draw(*inverter[1]);
	}
	if (outputInverted)
	{
		inverter[2]->setFillColor(outputs[0]->GetValue() ? sf::Color::White : sf::Color::Blue);
		window->draw(*inverter[2]);
	}
}

binary_gate::~binary_gate()
{
	delete inverter[0];
	delete inverter[1];
	delete inverter[2];
}