#include "Solver.h"

int Solver::amountOfNonShownCells(int index, std::vector<cell*> grid)
{
	int amountOfNonShownCells = 0;

	if ((index % 16 != 15 || index == 0) && index + 1 < grid.size()) {
		if (!grid.at(index)->isShown(1, grid) && !grid.at(index)->hasAFlag(1, grid)) {
			amountOfNonShownCells++;
		}
	}
	if (index % 16 != 0 && index - 1 >= 0) {
		if (!grid.at(index)->isShown(-1, grid) && !grid.at(index)->hasAFlag(-1, grid)) {
			amountOfNonShownCells++;
		}
	}
	if (index % 16 != 0 && index + 15 < grid.size()) {
		if (!grid.at(index)->isShown(15, grid) && !grid.at(index)->hasAFlag(15, grid)) {
			amountOfNonShownCells++;
		}
	}
	if (!grid.at(index)->isShown(16, grid) && !grid.at(index)->hasAFlag(16, grid) && index + 16 < grid.size()) {
		amountOfNonShownCells++;
	}
	if (((index) % 16 != 15 || index == 0) && index + 17 < grid.size()) {
		if (!grid.at(index)->isShown(17, grid) && !grid.at(index)->hasAFlag(17, grid)) {
			amountOfNonShownCells++;
		}
	}
	if ((index) % 16 != 15 && index - 15 >= 0) {
		if (!grid.at(index)->isShown(-15, grid) && !grid.at(index)->hasAFlag(-15, grid)) {
			amountOfNonShownCells++;
		}
	}
	if (!grid.at(index)->isShown(-16, grid) && !grid.at(index)->hasAFlag(-16, grid) && index - 16 >= 0) {
		amountOfNonShownCells++;
	}
	if ((index) % 16 != 0 && index - 17 >= 0) {
		if (!grid.at(index)->isShown(-17, grid) && !grid.at(index)->hasAFlag(-17, grid)) {
			amountOfNonShownCells++;
		}
	}

	return amountOfNonShownCells;
}

int Solver::ordentNonShownCells(std::string type,int index, std::vector<cell*> grid)
{
	int above3 = 0;
	int below3 = 0;
	int right3 = 0;
	int left3  = 0;

	if (index % 16 != 15 || index == 0) {
		if (!grid.at(index)->isShown(1, grid) && !grid.at(index)->hasAFlag(1, grid)) {
			right3++;
		}
	}
	if (index % 16 != 0) {
		if (!grid.at(index)->isShown(-1, grid) && !grid.at(index)->hasAFlag(-1, grid)) {
			left3++;
		}
	}
	if (index % 16 != 0) {
		if (!grid.at(index)->isShown(15, grid) && !grid.at(index)->hasAFlag(15, grid)) {
			below3++;
			left3++;
		}
	}
	if (!grid.at(index)->isShown(16, grid) && !grid.at(index)->hasAFlag(16, grid)) {
		below3++;
	}
	if ((index) % 16 != 15 || index == 0) {
		if (!grid.at(index)->isShown(17, grid) && !grid.at(index)->hasAFlag(17, grid)) {
			below3++;
			right3++;
			
		}
	}
	if ((index) % 16 != 15) {
		if (!grid.at(index)->isShown(-15, grid) && !grid.at(index)->hasAFlag(-15, grid)) {
			above3++;
			right3++;
		}
	}
	if (!grid.at(index)->isShown(-16, grid) && !grid.at(index)->hasAFlag(-16, grid)) {
		above3++;
	}
	if ((index) % 16 != 0) {
		if (!grid.at(index)->isShown(-17, grid) && !grid.at(index)->hasAFlag(-17, grid)) {
			above3++;
			left3++;
		}
	}

	if (type == "3RA" || type == "3LA") {
		return above3;
	}
	else if (type == "3RB" || type == "3LB") {
		return below3;
	}
	else if (type == "3DR"|| type == "3UR") {
		return right3;
	}
	else if (type == "3DL"||type == "3UL") {
		return left3;
	}
	return -1;
}
std::vector<int> Solver::returnNonShownCells( int index, std::vector<cell*> grid)
{
	std::vector<int> indexs;
	if ((index % 16 != 15 || index == 0) && index +1<grid.size()) {
		if (!grid.at(index)->isShown(1, grid) && !grid.at(index)->hasAFlag(1, grid)) {
			indexs.push_back(index + 1);
		}
	}
	if (index % 16 != 0 && index - 1 >= 0) {
		if (!grid.at(index)->isShown(-1, grid) && !grid.at(index)->hasAFlag(-1, grid)) {
			indexs.push_back(index -1);
		}
	}
	if (index % 16 != 0 && index + 15 < grid.size()) {
		if (!grid.at(index)->isShown(15, grid) && !grid.at(index)->hasAFlag(15, grid)) {
			indexs.push_back(index + 15);
		}
	}
	if (index + 16 < grid.size()) {
		if (!grid.at(index)->isShown(16, grid) && !grid.at(index)->hasAFlag(16, grid)) {
			indexs.push_back(index + 16);
		}
	}
	if (((index) % 16 != 15 || index == 0) && index + 17 < grid.size()) {
		if (!grid.at(index)->isShown(17, grid) && !grid.at(index)->hasAFlag(17, grid)) {
			indexs.push_back(index + 17);
		}
	}
	if ((index) % 16 != 15 && index - 15 >= 0) {
		if (!grid.at(index)->isShown(-15, grid) && !grid.at(index)->hasAFlag(-15, grid)) {
			indexs.push_back(index - 15);
		}
	}
	if (index - 16 >= 0) {
		if (!grid.at(index)->isShown(-16, grid) && !grid.at(index)->hasAFlag(-16, grid)) {
			indexs.push_back(index - 16);
		}
	}
	
	if ((index) % 16 != 0 && index - 17 >= 0) {
		if (!grid.at(index)->isShown(-17, grid) && !grid.at(index)->hasAFlag(-17, grid)) {
			indexs.push_back(index - 17);
		}
	}
	return indexs;
}

void Solver::updateGoodIndexs(std::vector<int> &goodIndexs, std::vector<int> &badIndexs) {
	int amountDealted = 0;
	int count = 0;
	int count2 = 0;
	while (amountDealted < badIndexs.size()) {
		if (goodIndexs.at(count)==badIndexs.at(count2)) {
			goodIndexs.erase(goodIndexs.begin() + count);
			amountDealted++;
			count2++;
		}
		count++;
		if (count>=goodIndexs.size()) {
			count = 0;
		}
	}


}

void Solver::createGoodIndexs(std::vector<int>& goodIndexs, int startingIndex) {
	if (startingIndex+1<480 ) {
		goodIndexs.push_back(startingIndex+1);
	}
	if (startingIndex - 1 >=0) {
		goodIndexs.push_back(startingIndex - 1);
	}
	if (startingIndex+15<480 ) {
		goodIndexs.push_back(startingIndex+15);
	}
	if (startingIndex + 16 < 480) {
		goodIndexs.push_back(startingIndex + 16);
	}
	if (startingIndex+17<480 ) {
		goodIndexs.push_back(startingIndex+17);
	}
	if (startingIndex - 15 >= 0) {
		goodIndexs.push_back(startingIndex - 15);
	}
	if (startingIndex - 16 >= 0) {
		goodIndexs.push_back(startingIndex - 16);
	}
	if (startingIndex - 17 >= 0) {
		goodIndexs.push_back(startingIndex-17);
	}
}

void Solver::updateMinesToFind(std::vector<cell*> &grid)
{	
	for (int i = 0; i < 480; i++) {
		if (grid.at(i)->shown==true) {
			grid.at(i)->findMinesToFind(grid);
		}

		
	
	}
	
}

Input Solver::startingGuesses(std::vector<cell*> grid)
{
	if (grid.at(0)->shown == false && grid.at(0)->flaged == false) {
		
		return Input(0,false);
	}
	else if (grid.at(15)->shown == false && grid.at(15)->flaged == false) {
		
		return Input(15, false);
	}
	else if (grid.at(464)->shown == false && grid.at(464)->flaged == false) {
		
		return Input(464, false);
	}
	else if (grid.at(479)->shown == false && grid.at(479)->flaged == false) {
		
		return Input(479, false);
	}
	else { 
		
		return Input(-1, false);
	}

}
//flag easy
Input Solver::searchPattern1(std::vector<cell*> grid)
{
	
	for (int i = 0; i < 480;i++) {
		if (grid.at(i)->shown == true) {
			if (grid.at(i)->minesToFind==amountOfNonShownCells(i, grid)&& amountOfNonShownCells(i, grid)!=0) {
				
				if (((i) % 16 != 15 || i == 0) && i + 1 < grid.size() && grid.at(i + 1)->shown == false&& grid.at(i + 1)->flaged== false) {
					//std::cout << "mines to find " << grid.at(i)->minesToFind  << "-->" << amountOfNonShownCells(i, grid) << " -" << std::endl;
					//std::cout << " this1 right " << i << "-->" << i + 1 << "flaged" << std::endl;
					return Input(i+1,true);
				}
				if ((i) % 16 != 0 && i - 1 >= 0 && grid.at(i - 1)->shown == false && grid.at(i -1)->flaged == false) {
					//std::cout << "mines to find " << grid.at(i)->minesToFind  << "-->" << amountOfNonShownCells(i, grid) << " -" << std::endl;
					//std::cout << " this1 left " << i << "-->" << i - 1 << "flaged" << std::endl;
					return Input(i-1, true);
				}
				if ((i) % 16 != 0 && i + 15 < grid.size() && grid.at(i + 15)->shown == false && grid.at(i + 15)->flaged == false) {
					//std::cout << "mines to find " << grid.at(i)->minesToFind << "-->" << amountOfNonShownCells(i, grid) << "-" << std::endl;
					//std::cout << " this1 bottom left " << i << "-->" << i + 15 << "flaged" << std::endl;
					return Input(i + 15, true);
				}
				if ((i + 16) < grid.size() && grid.at(i + 16)->shown == false && grid.at(i + 16)->flaged == false) {
					//std::cout <<"mines to find "<< grid.at(i)->minesToFind  << "-->" << amountOfNonShownCells(i, grid) << "-" << std::endl;
					//std::cout << " this1 bottom " << i << "-->" << i + 16 << "flaged" << std::endl;
					return Input(i + 16, true);
				}
				if (((i) % 16 != 15 || i == 0) && i + 17 < grid.size() && grid.at(i + 17)->shown == false && grid.at(i + 17)->flaged == false) {
					//std::cout << "mines to find " << grid.at(i)->minesToFind << "-->" << amountOfNonShownCells(i, grid) << "-" << std::endl;
					//std::cout << " this1 bottom right " << i << "-->" << i + 17 << "flaged" << std::endl;
					return Input(i + 17, true);
				}
				if ((i) % 16 != 15 && i - 15 >= 0 && grid.at(i - 15)->shown == false && grid.at(i -15)->flaged == false) {
					//std::cout << "mines to find " << grid.at(i)->minesToFind  << "-->" << amountOfNonShownCells(i, grid) << "-" << std::endl;
					//std::cout << " this1 top right " << i << "-->" << i - 15 << "flaged" << std::endl;
					return Input(i -15, true);
				}
				if (i - 16 >= 0 && grid.at(i - 16)->shown == false && grid.at(i -16)->flaged == false) {
					//std::cout << "mines to find " << grid.at(i)->minesToFind  << "-->" << amountOfNonShownCells(i, grid) << "-" << std::endl;
					//std::cout << " this1 top " << i << "-->" << i - 16 << "flaged" << std::endl;
					return Input(i -16, true);
				}
				if ((i) % 16 != 0 && i - 17 >= 0 && grid.at(i - 17)->shown == false && grid.at(i -17)->flaged == false) {
					//std::cout << "mines to find " << grid.at(i)->minesToFind  << "-->" << amountOfNonShownCells(i, grid) << "-" << std::endl;
					//std::cout << " this1 top left " << i << "-->" << i - 17 << "flaged" << std::endl;
					return Input(i -17, true);
				}

			}
		}
	}



	return  Input(-1, false);
}

//click easy
Input Solver::searchPattern2(std::vector<cell*> grid)
{
	for (int i = 0; i < 480; i++) {
		if (grid.at(i)->shown == true) {
			if (grid.at(i)->minesToFind==0) {
				if (((i) % 16 != 15 || i == 0) && i + 1 < grid.size() && grid.at(i + 1)->shown == false && grid.at(i + 1)->flaged == false) {
					//std::cout << " this2 right " << i << "-->"<< i+1 << std::endl;
					return Input(i + 1, false);
				}
				if ((i) % 16 != 0 && i - 1 >= 0 && grid.at(i - 1)->shown == false && grid.at(i - 1)->flaged == false) {
					//std::cout << " this2 left " << i << "-->" << i - 1 << std::endl;
					return Input(i - 1, false);
				}
				if ((i) % 16 != 0 && i + 15 < grid.size() && grid.at(i + 15)->shown == false && grid.at(i + 15)->flaged == false) {
					//std::cout << " this2 bottom left " << i << "-->" << i + 15 << std::endl;
					return Input(i + 15, false);
				}
				if ((i + 16) < grid.size() && grid.at(i + 16)->shown == false && grid.at(i + 16)->flaged == false) {
					//std::cout << " this2 bottom " << i << "-->" << i + 16 << std::endl;
					return Input(i + 16, false);
				}
				if (((i) % 16 != 15 || i == 0) && i + 17 < grid.size() && grid.at(i + 17)->shown == false && grid.at(i + 17)->flaged == false) {
					//std::cout << " this2 bottom right " << i << "-->" << i + 17 << std::endl;
					return Input(i + 17, false);
				}
				if ((i) % 16 != 15 && i - 15 >= 0 && grid.at(i - 15)->shown == false && grid.at(i - 15)->flaged == false) {
					//std::cout << " this2 top right " << i << "-->" << i - 15 << std::endl;
					return Input(i - 15, false);
				}
				if (i - 16 >= 0 && grid.at(i - 16)->shown == false && grid.at(i - 16)->flaged == false) {
					//std::cout << " this2 top  " << i << "-->" << i - 16 << std::endl;
					return Input(i - 16, false);
				}
				if ((i) % 16 != 0 && i - 17 >= 0 && grid.at(i - 17)->shown == false && grid.at(i - 17)->flaged == false) {
					//std::cout << " this2 top left " << i << "-->" << i - 17 << std::endl;
					return Input(i - 17, false);
				}
			}
		}
	}
	return Input(-1,false);
}

Input Solver::searchPattern3(std::vector<cell*> grid)
{
	//need to cheak oridenation
	// also add cheaks
	for (int i = 0; i < 480; i++) {
		if (grid.at(i)->shown == true) {
			if (grid.at(i)->minesToFind==1) {
				//right
				if ((i+1 % 16 != 15 || i+1 == 0) && i + 1 < 480) {
					if (grid.at(i + 1)->minesToFind == 2 && grid.at(i + 1)->shown==true) {
						if (amountOfNonShownCells(i + 1, grid) == 3) {
							//above
							if (ordentNonShownCells("3RA", i + 1, grid) == 3) {
								//std::cout << "3RA  " << i << std::endl;
								if (i+1-15>=0) {
									return Input(i + 1 - 15, true);
								}
							}
							//below
							if (ordentNonShownCells("3RB", i + 1, grid) == 3) {
								//std::cout << "3RB  " << i << std::endl;
								if (i + 1 + 17 < grid.size()) {
									return Input(i + 1 + 17, true);
								}
							}
						}
					}
				}
				//left
				if (i-1 % 16 != 0 && i - 1 >= 0) {
					if (grid.at(i - 1)->minesToFind == 2 && grid.at(i - 1)->shown == true) {
						if (amountOfNonShownCells(i - 1, grid) == 3) {
							//above
							if (ordentNonShownCells("3LA", i - 1, grid) == 3) {
								//std::cout << "3LA  " << i << std::endl;
								if (i - 1 - 17 >= 0) {
									return Input(i - 1 - 17, true);
								}
							}
							//below
							if (ordentNonShownCells("3LB", i - 1, grid) == 3) {
								//std::cout << "3LB  " << i << std::endl;
								if (i - 1 + 15 < grid.size()) {
									return Input(i - 1 + 15, true);
								}
							}
						}
					}
				}
				//down
				if (i+16<480) {
					if (grid.at(i + 16)->minesToFind == 2 && grid.at(i + 16)->shown == true) {
						if (amountOfNonShownCells(i + 16, grid) == 3) {
							//Right
							if (ordentNonShownCells("3DR", i + 16, grid) == 3) {
								//std::cout << "3DR  " << i << std::endl;
								if (i + 16 + 17 < grid.size()) {
									return Input(i + 16 + 17, true);
								}
							}
							//Left
							if (ordentNonShownCells("3DL", i + 16, grid) == 3) {
								//std::cout << "3DL  " << i << std::endl;
								if (i + 16 + 15 < grid.size()) {
									return Input(i + 16 + 15, true);
								}
							}
						}
					}
				}
				//up
				if (i-16>=0) {
					if (grid.at(i - 16)->minesToFind == 2 && grid.at(i - 16)->shown == true) {
						if (amountOfNonShownCells(i - 16, grid) == 3) {
							//Right
							if (ordentNonShownCells("3UR", i - 16, grid) == 3) {
								//std::cout << "3UR  " << i << std::endl;
								if (i-16-15 >= 0) {
									return Input(i - 16 - 15, true);
								}
							}
							//Left
							if (ordentNonShownCells("3UL", i - 16, grid) == 3) {
								//std::cout << "3UL  " << i << std::endl;
								if (i - 16 - 17 >= 0) {
									return Input(i - 16 - 17, true);
								}
							}
						}
					}
				}
			
			}
		}
	}
	return Input(-1, false);
}

Input Solver::clickCellsBasedOnIndexs(std::vector<int> goodIndexs, std::vector<cell*> grid, int index) {
	for (int j = 0; j < goodIndexs.size();j++) {
		//std::cout << goodIndexs.at(j) << "," ;
	}
	//std::cout << " seed ->" << index << std::endl;
	for (int i = 0; i < goodIndexs.size(); i++) {
		if (index+1==goodIndexs.at(i)&&((index) % 16 != 15 || index == 0) && index + 1 < grid.size() && grid.at(index + 1)->shown == false && grid.at(index + 1)->flaged == false) {
			//std::cout << " this4 right " << index << "-->" << index + 1 << std::endl;
			return Input(index + 1, false);
		}
		if (index - 1 == goodIndexs.at(i) && (index) % 16 != 0 && index - 1 >= 0 && grid.at(index - 1)->shown == false && grid.at(index - 1)->flaged == false) {
			//std::cout << " this4 left " << index << "-->" << index - 1 << std::endl;
			return Input(index - 1, false);
		}
		if (index + 15 == goodIndexs.at(i) && (index) % 16 != 0 && index + 15 < grid.size() && grid.at(index + 15)->shown == false && grid.at(index + 15)->flaged == false) {
			//std::cout << " this4 bottom left " << index << "-->" << index + 15 << std::endl;
			return Input(index + 15, false);
		}
		if (index + 16 == goodIndexs.at(i) && (index + 16) < grid.size() && grid.at(index + 16)->shown == false && grid.at(index + 16)->flaged == false) {
			//std::cout << " this4 bottom " << index << "-->" << index + 16 << std::endl;
			return Input(index + 16, false);
		}
		if (index + 17 == goodIndexs.at(i) && ((index) % 16 != 15 || index == 0) && index + 17 < grid.size() && grid.at(index + 17)->shown == false && grid.at(index + 17)->flaged == false) {
			//std::cout << " this4 bottom right " << index << "-->" << index + 17 << std::endl;
			return Input(index + 17, false);
		}
		if (index -15 == goodIndexs.at(i) && (index) % 16 != 15 && index - 15 >= 0 && grid.at(index - 15)->shown == false && grid.at(index - 15)->flaged == false) {
			//std::cout << " this4 top right " << index << "-->" << index - 15 << std::endl;
			return Input(index - 15, false);
		}
		if (index -16 == goodIndexs.at(i) && index - 16 >= 0 && grid.at(index - 16)->shown == false && grid.at(index - 16)->flaged == false) {
			//std::cout << " this4 top  " << index << "-->" << index - 16 << std::endl;
			return Input(index - 16, false);
		}
		if (index -17 == goodIndexs.at(i) && (index) % 16 != 0 && index - 17 >= 0 && grid.at(index - 17)->shown == false && grid.at(index - 17)->flaged == false) {
			//std::cout << " this4 top left " << index << "-->" << index - 17 << std::endl;
			return Input(index - 17, false);
		}
	}
	return Input(-1, false);
}

void Solver::cheak1Oridenation(std::vector<int> banedIndexs, int i, bool &goUp, bool &goDown, bool &goLeft,bool &goRight) {
	if (banedIndexs.size()==2) {
		if ((banedIndexs.at(0) == i - 17 || banedIndexs.at(0) == i - 15) && (banedIndexs.at(1) == i - 15 || banedIndexs.at(1) == i - 17)) {
			goUp = true;
		}
		else if ((banedIndexs.at(0) == i + 17 || banedIndexs.at(0) == i + 15) && (banedIndexs.at(1) == i + 17 || banedIndexs.at(1) == i + 15)) {
			goDown = true;
		}
		else if ((banedIndexs.at(0) == i - 15 || banedIndexs.at(0) == i + 17) && (banedIndexs.at(1) == i - 15 || banedIndexs.at(1) == i + 17)) {
			goRight = true;
		}
		else if ((banedIndexs.at(0) == i - 17 || banedIndexs.at(0) == i + 15) && (banedIndexs.at(1) == i - 17 || banedIndexs.at(1) == i + 15)) {
			goLeft = true;
		}
	}
}




bool Solver::hasIndexs(std::vector<int> indexsToFind, std::vector<int> indexsToSearch) {
	int found = 0;
	for (int i = 0; i < indexsToFind.size();i++) {
		for (int j = 0; j < indexsToSearch.size(); j++)
		{
			if (indexsToSearch.at(j) == indexsToFind.at(i)) {
				found++;
			}
		}
	}
	//for (int i = 0; i < indexsToFind.size();i++) {
		////std::cout << "LOLO " << i << "    " << indexsToFind.at(i) << std::endl;
	//}
	//for (int i = 0; i < indexsToSearch.size(); i++) {
		////std::cout << "XXX " << i << "    " << indexsToSearch.at(i) << std::endl;
	//}
	//std::cout << found << " ---- " << indexsToFind.size()<<std::endl;
	if (found==indexsToFind.size()) {
		return true;
	}
	else {
		return false;
	}


}


Input Solver::searchPattern4(std::vector<cell*> grid) {
	std::vector<int> banedIndexs;
	std::vector<int> goodIndexs;
	
	
	for (int i = 0; i < 480; i++) {
		if (grid.at(i)->shown == true) {
			if (grid.at(i)->minesToFind == 1) {

				banedIndexs = returnNonShownCells(i, grid);
				
				////std::cout << "up " << goUp << "\ndown" << goDown << "\nleft" << goLeft << "\nRight" << goRight << std::endl;
				//right
				if (((i) % 16 != 15 || i == 0) && i + 1 < 480 ) {
					if (grid.at(i + 1)->shown == true && grid.at(i + 1)->flaged == false) {
						if (grid.at(i + 1)->minesToFind == 1) {
							createGoodIndexs(goodIndexs, i + 1);
							
							
							if (hasIndexs(banedIndexs, goodIndexs) == true) {
								updateGoodIndexs(goodIndexs, banedIndexs);
								if (clickCellsBasedOnIndexs(goodIndexs, grid, i + 1).index != -1) {
									//std::cout << i << "," << i + 1 << " allho1" << std::endl;
									for (int j = 0; j < banedIndexs.size(); j++) {
										//std::cout << j << " index:" << banedIndexs.at(j) << std::endl;
									}
									return clickCellsBasedOnIndexs(goodIndexs, grid, i + 1);
								}
							}
							goodIndexs.clear();
						}
					}
				}
				
				//left
				if ((i) % 16 != 0 && i - 1 >= 0 ) {
					if (grid.at(i - 1)->shown == true && grid.at(i - 1)->flaged == false) {
						if (grid.at(i - 1)->minesToFind == 1) {
							createGoodIndexs(goodIndexs, i - 1);
							

							if (hasIndexs(banedIndexs, goodIndexs) == true) {
								updateGoodIndexs(goodIndexs, banedIndexs);
								if (clickCellsBasedOnIndexs(goodIndexs, grid, i - 1).index != -1) {
									//std::cout << i << "," << i - 1 << " allho2" << std::endl;
									for (int j = 0; j < banedIndexs.size(); j++) {
										//std::cout << j << " index:" << banedIndexs.at(j) << std::endl;
									}
									return clickCellsBasedOnIndexs(goodIndexs, grid, i - 1);
								}
							}
							goodIndexs.clear();
						}
					}
				}
				//down
				if (i + 16 < 480) {
					if (grid.at(i + 16)->shown == true && grid.at(i + 16)->flaged == false) {
						if (grid.at(i + 16)->minesToFind == 1) {
							createGoodIndexs(goodIndexs, i + 16);
							

							if (hasIndexs(banedIndexs, goodIndexs) == true) {
								updateGoodIndexs(goodIndexs, banedIndexs);
								if (clickCellsBasedOnIndexs(goodIndexs, grid, i + 16).index != -1) {
									//std::cout << i << "," << i + 16 << " allho3" << std::endl;
									for (int j = 0; j < banedIndexs.size(); j++) {
										//std::cout << j << " index:" << banedIndexs.at(j) << std::endl;
									}
									return clickCellsBasedOnIndexs(goodIndexs, grid, i + 16);
								}
							}
							goodIndexs.clear();
						}
					}
				}
				//up
				if (i - 16 >= 0) {
					if (grid.at(i - 16)->shown == true && grid.at(i - 16)->flaged == false) {
						if (grid.at(i - 16)->minesToFind == 1) {
							createGoodIndexs(goodIndexs, i - 16);
							

							if (hasIndexs(banedIndexs, goodIndexs) == true) {
								//std::cout << "indexUP  " << i << std::endl;
								updateGoodIndexs(goodIndexs, banedIndexs);
								if (clickCellsBasedOnIndexs(goodIndexs, grid, i - 16).index != -1) {
									//std::cout << i << "," << i - 16 << " allho4" << std::endl;
									for (int j = 0; j < banedIndexs.size(); j++) {
										//std::cout << j << " index:" << banedIndexs.at(j) << std::endl;
									}
									return clickCellsBasedOnIndexs(goodIndexs, grid, i - 16);
								}
							}
							goodIndexs.clear();
						}
					}
				}

			}
		}
	}
	return Input(-1, false);
}

Input Solver::guessPattern1(bool canGuess, std::vector<cell*> grid ) {
	std::vector<int> possableGuesses;
	if (canGuess==true) {
		for (int i = 0; i < grid.size(); i++) {
			if (grid.at(i)->shown==false && grid.at(i)->flaged==false) {
				possableGuesses.push_back(i);
			}
		}
	}
	if (possableGuesses.size()==1) {
		return Input(possableGuesses.at(0), false);
	}
	else if (possableGuesses.size()==0) {
		return Input(-1, false);
	}
	std::random_device seed;
	std::mt19937_64 generator(seed());
	std::uniform_int_distribution<int> distribution(0, possableGuesses.size()-1);
	int randomIndex = distribution(generator);
	return Input(possableGuesses.at(randomIndex), false);
}
