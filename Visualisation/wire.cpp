#include "wire.h"

wire::wire(bool value)
{
	disjoint = new sf::CircleShape(1.5f);
	disjoint->setOrigin(disjoint->getGlobalBounds().width / 2.0f, disjoint->getGlobalBounds().height / 2.0f);

	cross = new sf::RectangleShape(sf::Vector2f(6.0f, 3.0f));
	cross->setTexture(assets_class::get().getTexture("semi_cerc"));
	cross->setOrigin(cross->getGlobalBounds().width / 2.0f, cross->getGlobalBounds().height);

	this->value = value;
}
wire::wire(std::vector<sf::Vertex> corners, bool value) : wire(value)
{
	this->corners = corners;
}
bool wire::GetValue()
{
	return value;
}
void wire::SetValue(bool value)
{
	this->value = value;
}
void wire::AddCorner(float x, float y)
{
	corners.push_back(sf::Vertex(sf::Vector2f(x, y)));
}
void wire::AddCorner(sf::Vector2f corner)
{
	corners.push_back(sf::Vertex(corner));
}
void wire::AddCorner(sf::Vertex corner)
{
	corners.push_back(corner);
}
void wire::AddDisjoining(sf::Vector2f disjoint)
{
	disjoints.push_back(disjoint);
}
void wire::AddCrossing(sf::Vector2f cross)
{
	bool horizontal = false;
	int i = GiveWireWithCrossing(cross);
	if (corners[i].position.y == corners[i + 1].position.y)
	{
		horizontal = true;

		float xRight = std::max(corners[i].position.x, corners[i + 1].position.x);
		float xLeft = std::min(corners[i].position.x, corners[i + 1].position.x);
		sf::Vertex leftMost = sf::Vertex(sf::Vector2f(xLeft, cross.y));
		sf::Vertex leftAtCrossing = sf::Vertex(sf::Vector2f(cross.x - 3.0f, cross.y));
		sf::Vertex righAtCrossing = sf::Vertex(sf::Vector2f(cross.x + 3.0f, cross.y));
		sf::Vertex rightMost = sf::Vertex(sf::Vector2f(xRight, cross.y));

		bool going_right = corners[i].position.x < corners[i + 1].position.x;
		corners[i] = (going_right ? leftMost : rightMost);
		corners[i + 1] = (going_right ? leftAtCrossing : righAtCrossing);
		corners.insert(corners.begin() + i + 2, sf::Vertex(sf::Vector2f(-1.0f,-1.0f)));
		corners.insert(corners.begin() + i + 3, (going_right ? righAtCrossing : leftAtCrossing));
		corners.insert(corners.begin() + i + 4, (going_right ? rightMost : leftMost));
	}
	else if (corners[i].position.x == corners[i + 1].position.x)
	{
		float yDown = std::max(corners[i].position.y, corners[i + 1].position.y);
		float yUp = std::min(corners[i].position.y, corners[i + 1].position.y);
		sf::Vertex upMost = sf::Vertex(sf::Vector2f(cross.x, yUp));
		sf::Vertex upAtCrossing = sf::Vertex(sf::Vector2f(cross.x, cross.y - 3.0f));
		sf::Vertex downAtCrossing = sf::Vertex(sf::Vector2f(cross.x, cross.y + 3.0f));
		sf::Vertex downMost = sf::Vertex(sf::Vector2f(cross.x, yDown));

		bool going_down = corners[i].position.y < corners[i + 1].position.y;
		corners[i] = (going_down ? upMost : downMost);
		corners[i + 1] = (going_down ? upAtCrossing : downAtCrossing);
		corners.insert(corners.begin() + i + 2, sf::Vertex(sf::Vector2f(-1.0f, -1.0f)));
		corners.insert(corners.begin() + i + 3, (going_down ? downAtCrossing : upAtCrossing));
		corners.insert(corners.begin() + i + 4, (going_down ? downMost : upMost));
	}
	crossings.push_back(std::make_pair(cross, horizontal));
}
int wire::GiveWireWithCrossing(sf::Vector2f cross)
{
	for (int i = 0; i < corners.size()-1; i++)
	{
		if (corners[i].position.y == corners[i + 1].position.y && corners[i].position.y == cross.y)
		{
			float xRight = std::max(corners[i].position.x, corners[i + 1].position.x);
			float xLeft = std::min(corners[i].position.x, corners[i + 1].position.x);
			if (cross.x > xLeft && cross.x < xRight)
			{
				return i;
			}
		}
		else if (corners[i].position.x == corners[i + 1].position.x && corners[i].position.x == cross.x)
		{
			float yDown = std::max(corners[i].position.y, corners[i + 1].position.y);
			float yUp = std::min(corners[i].position.y, corners[i + 1].position.y);
			if (cross.y > yUp && cross.y < yDown)
			{
				return i;
			}
		}
	}
	return -1;
}
void wire::DrawWire(sf::RenderWindow* window)
{
	sf::Color color = (value ? sf::Color::Blue : sf::Color::White);
	
	sf::Vertex line[2] = { corners[0],corners[1] };
	line[0].color = color;
	line[1].color = color;
	window->draw(line, 2, sf::Lines);
	for (int i = 1; i < corners.size(); i++)
	{
		line[0] = line[1];
		if (corners[i].position.x == -1)
		{
			i++;
			line[0] = corners[i];
			line[0].color = color;
			i++;
		}
		line[1] = corners[i];
		line[1].color = color;
		window->draw(line, 2, sf::Lines);
	}
	disjoint->setFillColor(color);
	for (auto& it : disjoints)
	{
		disjoint->setPosition(it);
		window->draw(*disjoint);
	}
	cross->setFillColor(color);
	for (auto& it : crossings)
	{
		cross->setPosition(it.first);
		cross->setRotation(it.second ? 0.0f : 90.0f);
		window->draw(*cross);
	}
}
wire::~wire()
{
	delete disjoint;
	delete cross;
}

//