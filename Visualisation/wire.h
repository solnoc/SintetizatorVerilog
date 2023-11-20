#pragma once
#include "assets.h"

class wire {
public:
	wire(bool value = false);
	wire(std::vector<sf::Vertex> corners, bool value = false);
	bool GetValue();
	void SetValue(bool value);
	void AddCorner(float x, float y);
	void AddCorner(sf::Vector2f corner);
	void AddCorner(sf::Vertex corner);
	void AddDisjoining(sf::Vector2f disjoint);
	void AddCrossing(sf::Vector2f cross);
	void DrawWire(sf::RenderWindow* window);
	~wire();

protected:
	int GiveWireWithCrossing(sf::Vector2f cross);

private:
	std::vector<sf::Vertex> corners; // corners represents the points of the wire starting with the outside corners[0]->cornes[1]->corners[2]
	std::vector<std::pair<sf::Vector2f, bool>> crossings; // wire passing over another wire
	std::vector<sf::Vector2f> disjoints; // wire splliting into 2 or more dirrections
	bool value;

	sf::CircleShape* disjoint;
	sf::RectangleShape* cross;
};