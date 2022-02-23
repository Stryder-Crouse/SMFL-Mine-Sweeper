#pragma once
#include"cell.h"
class board {
public:
	bool continueGame = true;
	int wonOrLost=0;
	const int amountOfMines = 99;
	bool fristClick =true;
	std::vector<cell*> grid;
	std::vector<sf::RectangleShape*> lines;
	board(int generationMode);
	void didWin();
	void showAllMines();
	void generateMineRandom(int bannedIndex);
	void generateCells();
	void generateLines();
	void cheakMines();
	void showSurroundings(int cellIndex);
	void generateMineClustered();
	bool cheakIntersection(sf::Vector2i mouseCord, sf::Sprite box);
	void restart();
	void cheakClick(sf::Vector2i mouseCord, bool isRightClick);

	void drawBoard(sf::RenderWindow& win);

	

	


};
