#pragma once
#include <SFML/Graphics.hpp>

class assets_class 
{
public:
	static assets_class& get()
	{
		static assets_class ast;
		return ast;
	}

	assets_class();
	~assets_class();

	sf::Texture* getTexture(std::string name);
	void loadTexture(std::string name, std::string location);

private:
	std::map<std::string, sf::Texture*> assets;
};
