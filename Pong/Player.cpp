#include "Player.h"
#include <assert.h>
#include <windows.h>


void Player::init()
{
	w = 10;
	h = 60;

	posX = 0;
	posY = 220;

	speed = 10;
}
/*
	Player Details - Player 1 and Player 2
*/
void Player::Move()
{
	assert(mySide != Side_Undefined);

	float delta = 0;

	if(mySide == Side_Left)
	{	// Player 1 - Up	
		if(GetAsyncKeyState('Q') != 0)
		{
			delta -= speed;
		}
		// Player 1 - Down
		if(GetAsyncKeyState('A') != 0)
		{
			delta += speed;
		}
	}

	if(mySide == Side_Right)
	{	// Player 2 - Up
		if(GetAsyncKeyState('P') != 0)
		{
			delta -= speed;
		}
		// Player 2 - Down
		if(GetAsyncKeyState('L') != 0)
		{
			delta += speed;
		}
	}

	if(( posY + delta > 100) && ((posY + delta) < (600 - h )))
	{
		posY += delta;
	}
}

void Player::SetSide(Side eSide)
{
	mySide = eSide;

	if(mySide == Side_Left)
	{
		posX = 30;
	}

	if(mySide == Side_Right)
	{
		posX = 760;
	}
}
