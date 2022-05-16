#include "assets.h"

assets_class::assets_class()
{
	loadTexture("semi_cerc", "Semicerc.png");
	loadTexture("and_gate", "and_gate.png");
	loadTexture("or_gate", "or_gate.png");
	loadTexture("xor_gate", "xor_gate.png");
}
sf::Texture* assets_class::getTexture(std::string name)
{
	return assets[name];
}
void assets_class::loadTexture(std::string name, std::string location)
{
	sf::Texture* texture;
	texture = new sf::Texture();
	texture->loadFromFile("assets/" + location);
	assets.insert(std::make_pair(name, texture));
}
assets_class::~assets_class()
{
}