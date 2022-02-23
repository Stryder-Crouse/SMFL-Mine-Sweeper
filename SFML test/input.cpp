#include "input.h"

Input::Input()
{
}

Input::Input(int index, bool rightClick)
{
	Input::index = index;
	Input::rightClick = rightClick;
}
