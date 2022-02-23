#pragma once
#include "include.h"
class cell {
public:
	//solver varables
	bool possableMine = false;
	int minesToFind;
	//end


	bool mine;
	int numberOfmines;
	int cellPostion;
	bool clicked;
	bool flaged=false;
	bool shown=false;
	sf::Sprite box;
	sf::Texture textures[15];
	cell(bool mine, int cellPostion, sf::Vector2i postionsCords);
	bool getMine();
	bool getflaged();
	void findSurrounding(std::vector<cell*> &board);
	void findMinesToFind(std::vector<cell*> &grid);
	bool hasAmine(int ofset, std::vector<cell*> board);
	bool hasAFlag(int ofset, std::vector<cell*> grid);
	bool isShown(int ofset, std::vector<cell*> grid);
	int show(bool rightClick);

};
