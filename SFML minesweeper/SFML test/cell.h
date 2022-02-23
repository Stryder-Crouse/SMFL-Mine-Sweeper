#pragma once
#include "include.h"
class cell {
public:
	bool mine;
	int numberOfmines;
	int cellPostion;
	bool clicked;
	bool flaged=false;
	bool shown=false;
	sf::Sprite box;
	sf::Texture textures[13];
	cell(bool mine, int cellPostion, sf::Vector2i postionsCords);
	bool getMine();
	bool getflaged();
	void findSurrounding(std::vector<cell*> board);
	bool hasAmine(int ofset, std::vector<cell*> board);
	int show(bool rightClick);

};
