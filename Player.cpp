#include"Player.h"

Player::Player()
{
	isDead = false;
	player_dp = 0;
	player_ddp = 0;
	//heiPlayer:: ght = width = 0;
	player_pX = 0;
	player_pY = 0;
	entity.clear();
	player_half_X = 3;
	player_half_Y = 5;
}
float Player:: getHalfX()
{
	return player_half_X;
}
float Player:: getHalfY()
{
	return player_half_Y;
}
void Player:: up(float speed, float dt)
{
	player_pY += speed;
}
void Player::down(float speed, float dt) {
	player_pY -= speed;
}
void Player::left(float speed, float dt) {
	player_pX -= speed;
}
void Player::right(float speed, float dt) {
	player_pX += speed;
}
float Player:: getX()
{
	return player_pX;
}
float Player:: getY()
{
	return player_pY;
}
float Player:: getDP()
{
	return player_dp;
}
void Player:: setX(float src)
{
	player_pX = src;
}
void Player:: setY(float src)
{
	player_pY = src;
}
void Player:: setDP(float src)
{
	player_dp = src;
}
void Player:: setDDP(float src)
{
	player_ddp = src;
}
float Player:: getDDP()
{
	return player_ddp;
}
void Player:: setIsDead(bool type)
{
	Player:: isDead = type;
}
bool Player:: getIsDead()
{
	return isDead;
}
bool Player::isImpact(vector<Threat*>threat)
{
	for (auto x : threat)
	{
		for (auto y : x->getThreat())
		{
			if (player_pX + player_half_X > y->getX() - y->getHalfX()
				&& player_pY + player_half_Y > y->getY() - y->getHalfY()
				&& player_pX - player_half_X < y->getX() + y->getHalfX()
				&& player_pY - player_half_Y < y->getY() + y->getHalfY())
			{
				setIsDead(true);
				return true;
			}
		}
	}
	return false;
}
void Player::move(Input* input, float dt, float speed)
{
	{
		if (pressed(BUTTON_W))
		{
			up(speed, dt);
		}
		if (pressed(BUTTON_S))
		{
			down(speed, dt);
		}
		if (is_down(BUTTON_A))
		{
			left(speed, dt);
		}
		if (is_down(BUTTON_D))
		{
			right(speed, dt);
		}
		//checkWall()
		render_state = getRender();
		draw_titan(getX(), getY(), getHalfX(), getHalfY());
		return;
	}
}
void Player::checkWall(float x, float y, float half_x, float half_y)
{
	if (player_pX + player_half_X > half_x + x)
	{
		setX(half_x + x - player_half_X);
		setDP(0);
	}
	if (player_pY + player_half_Y > half_y + y)
	{
		setY(half_y + y - player_half_Y);
		setDP(0);
	}
	if (player_pX - player_half_X < -half_x - x)
	{
		setX(-half_x - x + player_half_X);
		setDP(0);
	}
	if (player_pY - player_half_Y < -half_y - y)
	{
		setY(-half_y - y + player_half_Y);
		setDP(0);
	}
}

//}
////void Player::Player:: setHeiPlayer:: ght(int heiPlayer:: ght)
////{
////	thiPlayer:: s->heiPlayer:: ght = heiPlayer:: ght;
////}
////void Player::Player:: setWidth(int width)
////{
////	thiPlayer:: s->width = width;
////}