#include "xor_gate.h"

xor_gate::xor_gate(sf::Vector2f position, float angle, sf::Vector2f size) : binary_gate(position, angle, size)
{
	shape->setTexture(assets_class::get().getTexture("xor_gate"));

	if (angle == 0.0f)
	{
		connective_lines[0].first = sf::Vertex(sf::Vector2f(GetInputPosition(0).position.x + size.x / 10.0f, GetInputPosition(0).position.y));
		connective_lines[1].first = sf::Vertex(sf::Vector2f(GetInputPosition(1).position.x + size.x / 10.0f, GetInputPosition(1).position.y));
	}
	else if (angle == 90.0f)
	{
		connective_lines[0].first = sf::Vertex(sf::Vector2f(GetInputPosition(0).position.x, GetInputPosition(0).position.y + size.x / 6.0f));
		connective_lines[1].first = sf::Vertex(sf::Vector2f(GetInputPosition(1).position.x, GetInputPosition(1).position.y + size.x / 6.0f));
	}
	else if (angle == 180.0f)
	{
		connective_lines[0].first = sf::Vertex(sf::Vector2f(GetInputPosition(0).position.x - size.x / 6.0f, GetInputPosition(0).position.y));
		connective_lines[1].first = sf::Vertex(sf::Vector2f(GetInputPosition(1).position.x - size.x / 6.0f, GetInputPosition(1).position.y));
	}
	else if (angle == 270.0f)
	{
		connective_lines[0].first = sf::Vertex(sf::Vector2f(GetInputPosition(0).position.x, GetInputPosition(0).position.y + size.x / 6.0f));
		connective_lines[1].first = sf::Vertex(sf::Vector2f(GetInputPosition(1).position.x, GetInputPosition(1).position.y + size.x / 6.0f));
	}
	connective_lines[0].second = GetInputPosition(0);
	connective_lines[1].second = GetInputPosition(1);
}
void xor_gate::Update()
{
	value = ((input1Inverted ? !inputs[0]->GetValue() : inputs[0]->GetValue())   ||
		    (input2Inverted ? !inputs[1]->GetValue() : inputs[1]->GetValue()))   &&
		    (!((input1Inverted ? !inputs[0]->GetValue() : inputs[0]->GetValue()) &&
			(input2Inverted ? !inputs[1]->GetValue() : inputs[1]->GetValue())));
	outputs[0]->SetValue(outputInverted ? !value : value);
	shape->setFillColor((value ? sf::Color::Blue : sf::Color::White));
}

void xor_gate::Draw(sf::RenderWindow* window)
{
	sf::Vertex line[] = { connective_lines[0].first, connective_lines[0].second };
	bool value = (input1Inverted ? !inputs[0]->GetValue() : inputs[0]->GetValue());
	sf::Color color = (value ? sf::Color::Blue : sf::Color::White);
	line[0].color = color;
	line[1].color = color;
	window->draw(line, 2, sf::Lines);
	line[0] = connective_lines[1].first;
	line[1] = connective_lines[1].second;
	value = (input2Inverted ? !inputs[1]->GetValue() : inputs[1]->GetValue());
	color = (value ? sf::Color::Blue : sf::Color::White);
	line[0].color = color;
	line[1].color = color;
	window->draw(line, 2, sf::Lines);
	binary_gate::Draw(window);
}