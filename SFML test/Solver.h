#pragma once
#include "include.h"
#include "board.h"
#include "input.h"
class Solver{
public:
	bool canGuessAgain= true;

	int amountOfNonShownCells(int index, std::vector<cell*> grid);

	int ordentNonShownCells(std::string type, int index, std::vector<cell*> grid);

	std::vector<int> returnNonShownCells( int index, std::vector<cell*> grid);

	void updateGoodIndexs(std::vector<int> &goodIndexs, std::vector<int> &badIndexs);

	void createGoodIndexs(std::vector<int>& goodIndexs, int startingIndex);

	void updateMinesToFind(std::vector<cell*> &grid);

	Input startingGuesses(std::vector<cell*> grid);

	Input searchPattern1(std::vector<cell*> grid);

	Input searchPattern2(std::vector<cell*> grid);

	Input searchPattern3(std::vector<cell*> grid);

	Input clickCellsBasedOnIndexs(std::vector<int> goodIndexs, std::vector<cell*> grid, int index);

	void cheak1Oridenation(std::vector<int> banedIndexs, int i, bool& goUp, bool& goDown, bool& goLeft, bool& goRight);

	

	

	bool hasIndexs(std::vector<int> indexsToFind, std::vector<int> indexsToSearch);

	Input searchPattern4(std::vector<cell*> grid);

	Input guessPattern1(bool canGuess, std::vector<cell*> grid);

};