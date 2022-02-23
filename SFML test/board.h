#pragma once
#include"cell.h"

class board {
public:
	int numberOfMinesLeft = 99;
	bool continueGame = true;
	int wonOrLost=0;
	const int amountOfMines = 99;
	bool fristClick =true;
	std::vector<cell*> grid;
	std::vector<sf::RectangleShape*> lines;
	std::vector<cell*> numbers;
	board(int generationMode);
	void didWin();
	int countshowncells();
	void showAllMines();
	void cheatShowMines();
	void cheatHideMines();
	void generateMineRandom(int bannedIndex);
	
	void generateCells();
	void generateNumbers();
	void generateLines();
	void cheakMines();
	void showSurroundings(int cellIndex);
	int amountOfNonShownCells(int index);
	void generateMineClustered(int bannedIndex);
	bool cheakIntersection(sf::Vector2i mouseCord, sf::Sprite box);
	void debugClick(sf::Vector2i mouseCord);
	void restart();
	void cheakClick(sf::Vector2i mouseCord, bool isRightClick, int generationType);

	void cheakClick(int index, bool isRightClick, int generationType);

	void drawBoard(sf::RenderWindow& win);

	

	


};
