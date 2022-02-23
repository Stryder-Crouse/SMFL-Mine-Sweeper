#include "board.h"

void board::generateMineRandom(int bannedIndex)
{
	std::random_device seed;
	std::mt19937_64 generator(seed());
	std::uniform_int_distribution<int> distribution(0,479);
	int numberOfMines = 0;
	int randomIndex=0;
	while(numberOfMines<amountOfMines){
		do {
			randomIndex = distribution(generator);
		} while (randomIndex==bannedIndex || grid.at(randomIndex)->mine == true);
		grid.at(randomIndex)->mine = true;
		numberOfMines++;
		
	
	}
	
}

void board::generateMineClustered()
{

}

void board::generateCells() {
	int currentX = 100;
	int currentY = 100;
	for (int i = 0; i < 480; i++) {
		if (i % 16 == 0 && i != 0) {
			currentY = currentY + 32;
			currentX = 100;
		}
		cell* cellMine = new cell(false, i, sf::Vector2i(currentX, currentY));
		grid.push_back(cellMine);
		
		

		currentX = currentX + 32;


	}

}

void board::generateLines() {
	int currentX = 98;
	int currentY = 98;
	for (int i = 0; i < 17; i++) {
		sf::RectangleShape* newRect = new sf::RectangleShape();
		newRect->setSize(sf::Vector2f(2,962));
		newRect->setPosition(currentX, currentY);
		lines.push_back(newRect);
		
		currentX = currentX + 32;
	
	}
	currentX = 98;
	for (int i = 0; i < 31; i++) {
		sf::RectangleShape* newRect = new sf::RectangleShape();
		newRect->setSize(sf::Vector2f(514, 2));
		newRect->setPosition(currentX, currentY);
		lines.push_back(newRect);
		
		currentY = currentY + 32;
	}
}

void board::cheakMines() {
	for (int i = 0; i < 480; i++) {
		grid.at(i)->findSurrounding(grid);
	
	}
}

void board::showSurroundings(int cellIndex) {
	if (grid.at(cellIndex)->numberOfmines != 0) {
		grid.at(cellIndex)->show(false);
		return;
	}
	else {
		if (((cellIndex) % 16 != 15 || cellIndex==0) && cellIndex + 1 < grid.size()&& grid.at(cellIndex+1)->shown==false) {
			grid.at(cellIndex + 1)->show(false);
			showSurroundings(cellIndex + 1);
		}
		if ((cellIndex) % 16 != 0 && cellIndex - 1 >= 0 && grid.at(cellIndex - 1)->shown == false) {
			grid.at(cellIndex - 1)->show(false);
			showSurroundings(cellIndex - 1);
		}
		if ((cellIndex) % 16 != 0 && cellIndex + 15 < grid.size() && grid.at(cellIndex + 15)->shown == false) {
			grid.at(cellIndex + 15)->show(false);
			showSurroundings(cellIndex + 15);
		}
		if (cellIndex + 16 < grid.size() && grid.at(cellIndex + 16)->shown == false) {
			grid.at(cellIndex + 16)->show(false);
			showSurroundings(cellIndex + 16);
		}
		if (((cellIndex) % 16 != 15 || cellIndex == 0) && cellIndex + 17 < grid.size() && grid.at(cellIndex + 17)->shown == false) {
			grid.at(cellIndex + 17)->show(false);
			showSurroundings(cellIndex + 17);
		}
		if ((cellIndex) % 16 != 15 && cellIndex - 15 >= 0 && grid.at(cellIndex - 15)->shown == false) {
			grid.at(cellIndex - 15)->show(false);
			showSurroundings(cellIndex - 15);
		}
		if (cellIndex - 16 >= 0 && grid.at(cellIndex -16)->shown == false) {
			grid.at(cellIndex - 16)->show(false);
			showSurroundings(cellIndex - 16);
		}
		if ((cellIndex) % 16 != 0 && cellIndex - 17 >= 0 && grid.at(cellIndex -17)->shown == false) {
			grid.at(cellIndex - 17)->show(false);
			showSurroundings(cellIndex - 17);
		}
		
		/*if (((cellIndex) % 16 != 15 || cellIndex == 0) && cellIndex + 1 < grid.size()) {
			return showSurroundings(cellIndex + 1);
		}
		if ((cellIndex) % 16 != 0 && cellIndex - 1 >= 0) {
			
			return showSurroundings(cellIndex - 1);
		}
		if ((cellIndex) % 16 != 0 && cellIndex + 15 < grid.size()) {
			
			return showSurroundings(cellIndex + 15);
		}
		if (cellIndex + 16 < grid.size()) {
			return showSurroundings(cellIndex + 16);
		}
		if (((cellIndex) % 16 != 15 || cellIndex == 0) && cellIndex + 17 < grid.size()) {
			return showSurroundings(cellIndex + 17);
		}
		if ((cellIndex) % 16 != 15 && cellIndex -15 >=0) {
			return showSurroundings(cellIndex - 15);
		}
		if (cellIndex - 16 >= 0) {
			return showSurroundings(cellIndex - 16);
		}
		if ((cellIndex) % 16 != 0 && cellIndex - 17 >= 0) {
			return showSurroundings(cellIndex - 17);
		}
		*/
	}
}



bool board::cheakIntersection(sf::Vector2i mouseCord,sf::Sprite box) {
	if (mouseCord.x > box.getPosition().x && mouseCord.x<(box.getPosition().x + box.getLocalBounds().width) && mouseCord.y>box.getPosition().y && mouseCord.y < (box.getPosition().y + box.getLocalBounds().height))
	{
		return true;
	}
	return false;

}



void board::cheakClick(sf::Vector2i mouseCord,bool isRightClick)
{
	sf::RectangleShape test;
	test.setSize(sf::Vector2f(1,1));
	test.setPosition(mouseCord.x, mouseCord.y);

	for (int i = 0; i < 480; i++) {
		if (cheakIntersection(mouseCord, grid.at(i)->box)) {
			if (fristClick == true) {
				generateMineRandom(i);
				cheakMines();
				fristClick = false;
			}
			
			int returnType=grid.at(i)->show(isRightClick);
			if (returnType==11) {
				showSurroundings(i);
			}
			if (returnType==9) {
				wonOrLost = -1;
				continueGame = false;
				showAllMines();
			}
			
		}
	
	}
}
void board::drawBoard(sf::RenderWindow& win) {

	for (int i = 0; i < lines.size(); i++) {
		win.draw(*lines.at(i));
	
	}
	for (int i = 0; i < grid.size(); i++) {
		win.draw(grid.at(i)->box);
	}

}

board::board(int generationMode) {
	
	generateCells();
	generateLines();
	

}

void board::didWin() {
	int correct = 0;
	int amountOfFlags = 0;
	int notShownWithNoMines = 0;
	for (int i = 0; i < 480; i++) {
		if (grid.at(i)->flaged == true && grid.at(i)->mine == true) {
			correct++;
		}
		if (grid.at(i)->flaged == true) {
			amountOfFlags++;
		}
		if (grid.at(i)->shown == false&&grid.at(i)->mine==false) {
			notShownWithNoMines++;
		}
	
	}
	if (correct == amountOfFlags  && amountOfFlags == amountOfMines && notShownWithNoMines==0) {
		wonOrLost = 1;
		continueGame = false;
	}

}

void board::showAllMines() {
	for (int i = 0; i < 480; i++) {
		if (grid.at(i)->mine == true&& grid.at(i)->flaged==false) {
			grid.at(i)->show(false);
		}
		if (grid.at(i)->mine == false && grid.at(i)->flaged == true) {
			grid.at(i)->box.setTexture(grid.at(i)->textures[12]);
		
		}
	
	
	}

}

void board::restart()
{
	wonOrLost =0;
	continueGame = true;
	fristClick = true;
	for (int i = 0; i < grid.size();i++) {
		delete grid.at(i);
	}
	grid.erase(grid.begin(), grid.end());
	//std::cout << grid.size() << std::endl;
	for (int i = 0; i < lines.size(); i++) {
		delete lines.at(i);
	}
	lines.erase(lines.begin(), lines.end());
	
	generateCells();
	generateLines();

}
