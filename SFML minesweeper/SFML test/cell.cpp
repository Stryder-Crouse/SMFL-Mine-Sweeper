#include "cell.h"

cell::cell(bool mine, int cellPostion,sf::Vector2i postionsCords) {
	cell::mine = mine;
	cell::cellPostion = cellPostion;
	numberOfmines = 0;
	clicked = false;
	flaged = false;
	textures[0].loadFromFile("images/square.png");
	textures[9].loadFromFile("images/mine.png");
	textures[10].loadFromFile("images/flag.png");
	textures[11].loadFromFile("images/empty.png");
	textures[12].loadFromFile("images/X.png");
	textures[1].loadFromFile("images/one.png");
	textures[2].loadFromFile("images/two.png");
	textures[3].loadFromFile("images/three.png");
	textures[4].loadFromFile("images/four.png");
	textures[5].loadFromFile("images/five.png");
	textures[6].loadFromFile("images/six.png");
	textures[7].loadFromFile("images/seven.png");
	textures[8].loadFromFile("images/eight.png");
	box.setTexture(textures[0]);
	box.setPosition(postionsCords.x,postionsCords.y);
	

}

bool cell::getMine()
{
	return mine;
}

bool cell::getflaged()
{
	return flaged;
}

bool cell::hasAmine(int ofset, std::vector<cell*> grid) {
	if (cellPostion + ofset >= 0 && cellPostion + ofset < grid.size()) {
		if (grid.at(cellPostion + ofset)->getMine()) {
			return true;
		}
	}
	return false;
}

int cell::show(bool rightClick)
{
	
	if (rightClick == true&& shown==false ) {
		if (flaged == false) {
			flaged = true;
			box.setTexture(textures[10]);
			return 10;
		}
		else {
			flaged = false;
			box.setTexture(textures[0]);
			return 0;
		
		}
	}
	else if (rightClick == false && flaged == true) {
		return -1;
	}
	
	if (mine == true) {
		shown = true;
		box.setTexture(textures[9]);
		return 9;
	}
	switch (numberOfmines)
	{
	case 0:box.setTexture(textures[11]);
		shown = true;
		return 11;
	case 1:box.setTexture(textures[1]);
		shown = true;
		return 1;
	case 2:box.setTexture(textures[2]);
		shown = true;
		return 2;
	case 3:box.setTexture(textures[3]);
		shown = true;
		return 3;
	case 4:box.setTexture(textures[4]);
		shown = true;
		return 4;
	case 5:box.setTexture(textures[5]);
		shown = true;
		return 5;
	case 6:box.setTexture(textures[6]);
		shown = true;
		return 6;
	case 7:box.setTexture(textures[7]);
		shown = true;
		return 7;
	case 8:box.setTexture(textures[8]);
		shown = true;
		return 8;
	default:
		return -1;
	}
	

}



void cell::findSurrounding(std::vector<cell*> grid)
{
	if (mine == false) {
		if ((cellPostion) % 16 != 15 || cellPostion == 0) {
			if (hasAmine(1, grid)) {
				numberOfmines++;
			}
		}
		if (cellPostion % 16 != 0) {
			if (hasAmine(-1, grid)) {
				numberOfmines++;
			}
		}
		if (cellPostion % 16 != 0) {
			if (hasAmine(15, grid)) {
				numberOfmines++;
			}
		}
		if (hasAmine(16, grid)) {
			numberOfmines++;
		}
		if ((cellPostion) % 16 != 15 || cellPostion == 0) {
			if (hasAmine(17, grid)) {
				numberOfmines++;
			}
		}
		if ((cellPostion) % 16 != 15) {
			if (hasAmine(-15, grid)) {
				numberOfmines++;
			}
		}
		if (hasAmine(-16, grid)) {
				numberOfmines++;
		}
		if ((cellPostion) % 16 != 0) {
			if (hasAmine(-17, grid)) {
				numberOfmines++;
			}
		}
	}


}


