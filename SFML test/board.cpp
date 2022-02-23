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



void board::generateMineClustered(int bannedIndex)
{
	std::random_device seed;
	std::random_device seed2;
	std::random_device seed3;
	std::random_device seed4;
	std::mt19937_64 generator(seed());
	std::mt19937_64 generator2(seed2());
	std::mt19937_64 generator3(seed3());
	std::mt19937_64 generator4(seed4());
	std::uniform_int_distribution<int> distribution(0, 479);
	std::uniform_int_distribution<int> distribution2(2, 7);
	std::uniform_int_distribution<int> distribution3(1, 4);
	std::uniform_int_distribution<int> distribution4(1, 2);
	int numberOfMines = 0;
	int randomIndex = 0;
	int randomPattern;
	int patternType;
	while (numberOfMines < amountOfMines) {
		do {
			randomIndex = distribution(generator);
			randomPattern = distribution2(generator2);
		} while (randomIndex == bannedIndex || grid.at(randomIndex)->mine == true);
		//pattern one (one mine)
		if (amountOfMines-numberOfMines<=3) {
			grid.at(randomIndex)->mine = true;
			numberOfMines++;
		}
		else {
			switch (randomPattern)
			{
				//pattern 2
			case 2:
				if (((randomIndex) % 16 != 15 || randomIndex == 0) && randomIndex + 17 < grid.size()) {
					if (grid.at(randomIndex)->mine == false && grid.at(randomIndex + 1)->mine == false && grid.at(randomIndex + 16)->mine == false && grid.at(randomIndex + 17)->mine == false) {
						grid.at(randomIndex)->mine = true;
						grid.at(randomIndex + 1)->mine = true;
						grid.at(randomIndex + 16)->mine = true;
						grid.at(randomIndex + 17)->mine = true;
						numberOfMines += 4;
					}
				}

				break;
			case 3:
				patternType = distribution3(generator3);
				//pattern 3
				if (patternType == 1) {
					if (randomIndex-1!=bannedIndex && randomIndex + 1 != bannedIndex&& randomIndex - 15 != bannedIndex) {
						if ((randomIndex) % 16 != 15 && randomIndex + 1 < grid.size() && randomIndex - 15 >= 0 && (randomIndex) % 16 != 0) {
							if (grid.at(randomIndex)->mine == false && grid.at(randomIndex - 1)->mine == false && grid.at(randomIndex + 1)->mine == false && grid.at(randomIndex - 15)->mine == false) {
								grid.at(randomIndex)->mine = true;
								grid.at(randomIndex - 1)->mine = true;
								grid.at(randomIndex + 1)->mine = true;
								grid.at(randomIndex - 15)->mine = true;
								numberOfMines += 4;

							}
						}
					}
				}
				//pattern 4
				else if (patternType == 2) {
					if (randomIndex -17 != bannedIndex&& randomIndex +16 != bannedIndex&& randomIndex - 16 != bannedIndex) {
						if ((randomIndex) % 16 != 0 && randomIndex - 17 >= 0 && randomIndex + 16 < grid.size()) {
							if (grid.at(randomIndex)->mine == false && grid.at(randomIndex + 16)->mine == false && grid.at(randomIndex - 16)->mine == false && grid.at(randomIndex - 17)->mine == false) {
								grid.at(randomIndex)->mine = true;
								grid.at(randomIndex + 16)->mine = true;
								grid.at(randomIndex - 16)->mine = true;
								grid.at(randomIndex - 17)->mine = true;
								numberOfMines += 4;
							}
						}
					}
				}
				//pattern 5
				else if (patternType == 3) {
					if (randomIndex - 16 != bannedIndex&& randomIndex +16 != bannedIndex&& randomIndex +17 != bannedIndex) {
						if (randomIndex - 16 >= 0 && (randomIndex) % 16 != 15 && randomIndex + 17 < grid.size()) {
							if (grid.at(randomIndex)->mine == false && grid.at(randomIndex - 16)->mine == false && grid.at(randomIndex + 16)->mine == false && grid.at(randomIndex + 17)->mine == false) {
								grid.at(randomIndex)->mine = true;
								grid.at(randomIndex - 16)->mine = true;
								grid.at(randomIndex + 16)->mine = true;
								grid.at(randomIndex + 17)->mine = true;
								numberOfMines += 4;
							}
						}
					}
				}
				//pattern 6
				else {
					if (randomIndex - 1 != bannedIndex&& randomIndex +1 != bannedIndex&& randomIndex + 15 != bannedIndex) {
						if ((randomIndex) % 16 != 0 && randomIndex - 1 >= 0 && randomIndex + 15 < grid.size()) {
							if (grid.at(randomIndex)->mine == false && grid.at(randomIndex - 1)->mine == false && grid.at(randomIndex + 1)->mine == false && grid.at(randomIndex + 15)->mine == false) {
								grid.at(randomIndex)->mine = true;
								grid.at(randomIndex - 1)->mine = true;
								grid.at(randomIndex + 1)->mine = true;
								grid.at(randomIndex + 15)->mine = true;
								numberOfMines += 4;
							}
						}
					}
				}
				break;
			case 4:
				patternType = distribution3(generator3);
				//pattern 7
				if (patternType == 1) {
					if (randomIndex - 1 != bannedIndex&& randomIndex + 1 != bannedIndex&& randomIndex - 16 != bannedIndex) {
						if ((randomIndex) % 16 != 15 && randomIndex + 1 < grid.size() && randomIndex - 16 >= 0 && (randomIndex) % 16 != 0) {
							if (grid.at(randomIndex)->mine == false && grid.at(randomIndex - 1)->mine == false && grid.at(randomIndex + 1)->mine == false && grid.at(randomIndex - 16)->mine == false) {
								grid.at(randomIndex)->mine = true;
								grid.at(randomIndex - 1)->mine = true;
								grid.at(randomIndex + 1)->mine = true;
								grid.at(randomIndex - 16)->mine = true;
								numberOfMines += 4;
							}
						}
					}
				}
				//pattern 8
				else if (patternType == 2) {
					if (randomIndex - 1 != bannedIndex&& randomIndex + 16 != bannedIndex&& randomIndex - 16 != bannedIndex) {
						if (randomIndex - 16 >= 0 && randomIndex + 16 < grid.size() && (randomIndex) % 16 != 15) {
							if (grid.at(randomIndex)->mine == false && grid.at(randomIndex + 1)->mine == false && grid.at(randomIndex - 16)->mine == false && grid.at(randomIndex + 16)->mine == false) {
								grid.at(randomIndex)->mine = true;
								grid.at(randomIndex - 1)->mine = true;
								grid.at(randomIndex + 16)->mine = true;
								grid.at(randomIndex - 16)->mine = true;
								numberOfMines += 4;
							}
						}
					}
				}
				//pattern 9
				else if (patternType == 3) {
					if (randomIndex - 1 != bannedIndex&& randomIndex + 1 != bannedIndex&& randomIndex + 16 != bannedIndex) {
						if (randomIndex + 16 < grid.size() && randomIndex - 1 >= 0 && (randomIndex) % 16 != 15 && (randomIndex) % 16 != 0) {
							if (grid.at(randomIndex)->mine == false && grid.at(randomIndex - 1)->mine == false && grid.at(randomIndex + 1)->mine == false && grid.at(randomIndex + 16)->mine == false) {
								grid.at(randomIndex)->mine = true;
								grid.at(randomIndex - 1)->mine = true;
								grid.at(randomIndex + 1)->mine = true;
								grid.at(randomIndex + 16)->mine = true;
								numberOfMines += 4;
							}
						}
					}
				}
				//pattern 10
				else {
					if (randomIndex - 1 != bannedIndex&& randomIndex + 16 != bannedIndex&& randomIndex - 16 != bannedIndex) {
						if (randomIndex - 16 >= 0 && randomIndex + 16 < grid.size() && (randomIndex) % 16 != 0) {
							if (grid.at(randomIndex)->mine == false && grid.at(randomIndex - 1)->mine == false && grid.at(randomIndex - 16)->mine == false && grid.at(randomIndex + 16)->mine == false) {
								grid.at(randomIndex)->mine = true;
								grid.at(randomIndex - 1)->mine = true;
								grid.at(randomIndex - 16)->mine = true;
								grid.at(randomIndex + 16)->mine = true;
								numberOfMines += 4;
							}
						}
					}
				}

				break;
			case 5:
				patternType = distribution4(generator4);
				//pattern 11
				if (patternType == 1) {
					if (randomIndex + 1 != bannedIndex&& randomIndex - 16 != bannedIndex&& randomIndex - 17 != bannedIndex) {
						if ((randomIndex) % 16 != 15 && randomIndex + 1 < grid.size() && (randomIndex) % 16 != 0 && randomIndex - 17 >= 0) {
							if (grid.at(randomIndex)->mine == false && grid.at(randomIndex + 1)->mine == false && grid.at(randomIndex - 16)->mine == false && grid.at(randomIndex - 17)->mine == false) {
								grid.at(randomIndex)->mine = true;
								grid.at(randomIndex + 1)->mine = true;
								grid.at(randomIndex - 16)->mine = true;
								grid.at(randomIndex - 17)->mine = true;
								numberOfMines += 4;
							}
						}
					}
				}
				//pattern 12
				else {
					if (randomIndex + 1 != bannedIndex&& randomIndex + 16 != bannedIndex&& randomIndex - 15 != bannedIndex) {
						if ((randomIndex) % 16 != 15 && randomIndex - 15 >= 0 && randomIndex + 16 < grid.size()) {
							if (grid.at(randomIndex)->mine == false && grid.at(randomIndex + 1)->mine == false && grid.at(randomIndex + 16)->mine == false && grid.at(randomIndex - 15)->mine == false) {
								grid.at(randomIndex)->mine = true;
								grid.at(randomIndex + 1)->mine = true;
								grid.at(randomIndex + 16)->mine = true;
								grid.at(randomIndex - 15)->mine = true;
								numberOfMines += 4;
							}
						}
					}
				}
				break;
			case 6:
				patternType = distribution4(generator4);
				//pattern 13
				if (patternType==1) {
					if (randomIndex +1 != bannedIndex&& randomIndex +2 != bannedIndex&& randomIndex - 1 != bannedIndex) {
						if ((randomIndex + 1) % 16 != 15 && randomIndex + 2 < grid.size() && (randomIndex) % 16 != 15 && (randomIndex) % 16 != 0 && randomIndex - 1 >= 0) {
							if (grid.at(randomIndex)->mine == false && grid.at(randomIndex - 1)->mine == false && grid.at(randomIndex + 1)->mine == false && grid.at(randomIndex + 2)->mine == false) {
								grid.at(randomIndex)->mine = true;
								grid.at(randomIndex + 1)->mine = true;
								grid.at(randomIndex + 2)->mine = true;
								grid.at(randomIndex - 1)->mine = true;
								numberOfMines += 4;
							}
						}
					}
				}
				//pattern 14
				else {
					if (randomIndex +32 != bannedIndex&& randomIndex + 16 != bannedIndex&& randomIndex - 16 != bannedIndex) {
						if (randomIndex + 32 < grid.size() && randomIndex - 16 >= 0) {
							if (grid.at(randomIndex)->mine == false && grid.at(randomIndex - 16)->mine == false && grid.at(randomIndex + 16)->mine == false && grid.at(randomIndex + 32)->mine == false) {
								grid.at(randomIndex)->mine = true;
								grid.at(randomIndex + 16)->mine = true;
								grid.at(randomIndex + 32)->mine = true;
								grid.at(randomIndex - 16)->mine = true;
								numberOfMines += 4;
							}
						}
					}
				}
				break;
			case 7:
				patternType = distribution4(generator4);
				//pattern 15
				if (patternType==1) {
					if (randomIndex - 15 != bannedIndex&& randomIndex + 15 != bannedIndex&& randomIndex +30 != bannedIndex) {
						if ((randomIndex + 15) % 16 != 0 && randomIndex + 30 < grid.size() && (randomIndex) % 16 != 15 && (randomIndex) % 16 != 0 && randomIndex - 15 >= 0) {
							if (grid.at(randomIndex)->mine == false && grid.at(randomIndex + 15)->mine == false && grid.at(randomIndex + 30)->mine == false && grid.at(randomIndex - 15)->mine == false) {
								grid.at(randomIndex)->mine = true;
								grid.at(randomIndex + 15)->mine = true;
								grid.at(randomIndex + 30)->mine = true;
								grid.at(randomIndex - 15)->mine = true;
								numberOfMines += 4;
							}
						}
					}
				}
				//pattern 16
				else {
					if (randomIndex +34 != bannedIndex&& randomIndex + 17 != bannedIndex&& randomIndex - 17 != bannedIndex) {
						if ((randomIndex) % 16 != 0 && (randomIndex) % 16 != 15 && (randomIndex + 17) % 16 != 15 && randomIndex + 34 < grid.size() && randomIndex - 17 >= 0) {
							if (grid.at(randomIndex)->mine == false && grid.at(randomIndex + 17)->mine == false && grid.at(randomIndex + 34)->mine == false && grid.at(randomIndex - 17)->mine == false) {
								grid.at(randomIndex)->mine = true;
								grid.at(randomIndex + 17)->mine = true;
								grid.at(randomIndex + 34)->mine = true;
								grid.at(randomIndex - 17)->mine = true;
								numberOfMines += 4;
							}
						}
					}
				}
				
				break;
			default:
				break;
			}
		
		}

	}


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

void board::generateNumbers() {
	int currentX = 70;
	int currentY = 100;
	int frist = 1;
	int second = 0;

	for (int i = 1; i <= 30; i++) {
		cell* cellNumber = new cell(false, i, sf::Vector2i(currentX, currentY));
		if (i % 10 == 0 && i!=0) {
			frist = 0;
			second++;
		}
		if (frist==0) {
			cellNumber->box.setTexture(cellNumber->textures[13]);
		}
		else if (frist==9) {
			cellNumber->box.setTexture(cellNumber->textures[14]);
		}
		else {
			cellNumber->box.setTexture(cellNumber->textures[frist]);
		}
		numbers.push_back(cellNumber);

		if (second>0) {
			cell* cellNumber2 = new cell(false, i, sf::Vector2i(currentX-30, currentY));
			cellNumber2->box.setTexture(cellNumber2->textures[second]);
			numbers.push_back(cellNumber2);
		}

		currentY += 32;
		frist++;
	}
	currentY = 70;
	currentX = 100;
	frist = 1;
	second = 0;

	for (int j = 1; j <= 16; j++) {
		cell* cellNumber = new cell(false, j, sf::Vector2i(currentX, currentY));
		if (j % 10 == 0 && j != 0) {
			frist = 0;
			second++;
		}
		if (frist == 0) {
			cellNumber->box.setTexture(cellNumber->textures[13]);
		}
		else if (frist == 9) {
			cellNumber->box.setTexture(cellNumber->textures[14]);
		}
		else {
			cellNumber->box.setTexture(cellNumber->textures[frist]);
		}
		numbers.push_back(cellNumber);

		if (second > 0) {
			cell* cellNumber2 = new cell(false, j, sf::Vector2i(currentX, currentY-30));
			cellNumber2->box.setTexture(cellNumber2->textures[second]);
			numbers.push_back(cellNumber2);
		}

		currentX += 32;
		frist++;

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

int board::amountOfNonShownCells(int index)
{
	int amountOfNonShownCells = 0;

	if ((index % 16 != 15 || index == 0) && index + 1 < grid.size()) {
		if (!grid.at(index)->isShown(1, grid) && !grid.at(index)->hasAFlag(1, grid)) {
			std::cout << "1" << std::endl;
			amountOfNonShownCells++;
		}
	}
	if (index % 16 != 0 && index -1>=0) {
		if (!grid.at(index)->isShown(-1, grid) && !grid.at(index)->hasAFlag(-1, grid)) {
			std::cout << "2" << std::endl;
			amountOfNonShownCells++;
		}
	}
	if (index % 16 != 0 && index + 15 < grid.size()) {
		if (!grid.at(index)->isShown(15, grid) && !grid.at(index)->hasAFlag(15, grid)) {
			std::cout << "3" << std::endl;
			amountOfNonShownCells++;
		}
	}
	if (!grid.at(index)->isShown(16, grid) && !grid.at(index)->hasAFlag(16, grid) && index + 16 < grid.size()) {
		std::cout << "4" << std::endl;
		amountOfNonShownCells++;
	}
	if (((index) % 16 != 15 || index == 0) && index + 17 < grid.size()) {
		if (!grid.at(index)->isShown(17, grid) && !grid.at(index)->hasAFlag(17, grid)) {
			std::cout << "5" << std::endl;
			amountOfNonShownCells++;
		}
	}
	if ((index) % 16 != 15 && index - 15 >= 0) {
		if (!grid.at(index)->isShown(-15, grid) && !grid.at(index)->hasAFlag(-15, grid)) {
			std::cout << "6" << std::endl;
			amountOfNonShownCells++;
		}
	}
	if (!grid.at(index)->isShown(-16, grid) && !grid.at(index)->hasAFlag(-16, grid) && index - 16 >= 0) {
		std::cout << "7" << std::endl;
		amountOfNonShownCells++;
	}
	if ((index) % 16 != 0 && index - 17 >= 0) {
		if (!grid.at(index)->isShown(-17, grid) && !grid.at(index)->hasAFlag(-17, grid)) {
			std::cout << "8" << std::endl;
			amountOfNonShownCells++;
		}
	}

	return amountOfNonShownCells;
}

bool board::cheakIntersection(sf::Vector2i mouseCord,sf::Sprite box) {
	if (mouseCord.x > box.getPosition().x && mouseCord.x<(box.getPosition().x + box.getLocalBounds().width) && mouseCord.y>box.getPosition().y && mouseCord.y < (box.getPosition().y + box.getLocalBounds().height))
	{
		return true;
	}
	return false;

}

void board::debugClick(sf::Vector2i mouseCord) {
	sf::RectangleShape test;
	test.setSize(sf::Vector2f(1, 1));
	test.setPosition(mouseCord.x, mouseCord.y);
	for (int i = 0; i < 480; i++) {
		if (cheakIntersection(mouseCord, grid.at(i)->box)) {
			std::cout << "------------------------" << std::endl;
			std::cout << "index = " << grid.at(i)->cellPostion << "\nMines Left = " << grid.at(i)->minesToFind << std::endl;
			std::cout << "shown = " << grid.at(i)->shown<< "\nFlaged = " << grid.at(i)->flaged << std::endl;
			std::cout << "amount of non showed cells = " << amountOfNonShownCells(i) << std::endl;
		}
	}
}

void board::cheakClick(sf::Vector2i mouseCord,bool isRightClick,int generationType)
{
	sf::RectangleShape test;
	test.setSize(sf::Vector2f(1,1));
	test.setPosition(mouseCord.x, mouseCord.y);

	for (int i = 0; i < 480; i++) {
		if (cheakIntersection(mouseCord, grid.at(i)->box)) {
			if (fristClick == true) {
				if (generationType == 1) {
					generateMineRandom(i);
				}
				else if (generationType == 2) {
					generateMineClustered(i);
				}
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

void board::cheakClick(int index, bool isRightClick, int generationType)
{
			if (fristClick == true) {
				if (generationType == 1) {
					generateMineRandom(index);
				}
				else if (generationType == 2) {
					generateMineClustered(index);
				}
				cheakMines();
				fristClick = false;
			}

			int returnType = grid.at(index)->show(isRightClick);
			if (returnType == 11) {
				showSurroundings(index);
			}
			if (returnType == 9) {
				wonOrLost = -1;
				continueGame = false;
				showAllMines();
			}

		

	
}

void board::drawBoard(sf::RenderWindow& win) {

	for (int i = 0; i < lines.size(); i++) {
		win.draw(*lines.at(i));
	
	}
	for (int i = 0; i < grid.size(); i++) {
		win.draw(grid.at(i)->box);
	}
	for (int i = 0; i < numbers.size(); i++) {
		//win.draw(numbers.at(i)->box);
	}


}

board::board(int generationMode) {
	
	generateCells();
	generateLines();
	generateNumbers();

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

int board::countshowncells() {
	int showncells = 0;
	for (int i = 0; i < 480; i++) {
		if (grid.at(i)->shown == true&& grid.at(i)->mine== false) {
			showncells++;
		}
	}
	return showncells;
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

void board::cheatShowMines() {
	for (int i = 0; i < 480; i++) {
		if (grid.at(i)->mine == true && grid.at(i)->flaged == false) {
			grid.at(i)->box.setTexture(grid.at(0)->textures[9]);
		}
		
	}
}

void board::cheatHideMines() {
	for (int i = 0; i < 480; i++) {
		if (grid.at(i)->box.getTexture()==&grid.at(0)->textures[9]) {
			grid.at(i)->box.setTexture(grid.at(0)->textures[0]);
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
