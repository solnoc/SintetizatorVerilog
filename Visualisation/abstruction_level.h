#pragma once
#include <SFML/Graphics.hpp>

class abstruction_level
{
public:
	virtual void Initialize()
	{
	}
	virtual void Update()
	{
	}
	virtual void Draw(sf::RenderWindow* window)
	{
	}
	virtual void Destroy()
	{
	}
};

class core_abstruction_level
{
public:
	core_abstruction_level()
	{
		currentLevel = nullptr;
		window = nullptr;
	}
	void ChangeAbstructionLevel(abstruction_level* level)
	{
		if (currentLevel != nullptr)
		{
			currentLevel->Destroy();
		}
		currentLevel = level;
		if (currentLevel != nullptr)
		{
			currentLevel->Initialize();
		}
	}
	void ChangeWindow(sf::RenderWindow* window)
	{
		this->window = window;
	}
	void Update()
	{
		if (currentLevel != nullptr)
		{
			currentLevel->Update();
		}
	}
	void Draw()
	{
		if (currentLevel != nullptr)
		{
			currentLevel->Draw(window);
		}
	}
	~core_abstruction_level()
	{
		if (currentLevel != nullptr)
		{
			currentLevel->Destroy();
		}
	}

private:
	abstruction_level* currentLevel;
	sf::RenderWindow* window;
};

extern core_abstruction_level coreLevel;
