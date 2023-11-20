#include "and_gate.h"

and_gate::and_gate(sf::Vector2f position, float angle, sf::Vector2f size) : binary_gate(position, angle, size)
{
	shape->setTexture(assets_class::get().getTexture("and_gate"));
}
void and_gate::Update()
{
	value = (input1Inverted ? !inputs[0]->GetValue() : inputs[0]->GetValue()) && 
		    (input2Inverted ? !inputs[1]->GetValue() : inputs[1]->GetValue());
	outputs[0]->SetValue(outputInverted ? !value : value);
	shape->setFillColor((value ? sf::Color::Blue : sf::Color::White));
}