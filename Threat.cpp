#include"Threat.h"
Threat::Threat(int posY) :y_coord(posY)
{
	trafficlight.setTime(random_int(100, 500));
	numEnemyInRow = 3;
	lv = 1;
	speed = 50;
	distance = 30;
	threat.resize(0);
	type = TYPE(-1);
	dir = -1;
}
enum DIRECTION { RIGHT, LEFT }; 
int Threat::getNumEnemyInRow()
{
	return numEnemyInRow;
}
unsigned int Threat:: getLv()
{
	return lv;
}
int Threat::getType()
{	
	return type;
}
float Threat::getSpeed()
{
	return speed;
}
int Threat::getDistance()
{
	return distance;
}
int Threat::getThreat(int type)
{
	return 0;
}
vector<Entity*>Threat::getThreat()
{
	return threat;
}
void Threat::setThreatInRow(int lv)
{
	if (numEnemyInRow < 6)
		if (lv % 5 == 0)
			numEnemyInRow++;
}

void Threat::setListEntity(TYPE type, int dir)
{
	//143->max, min=(43,-100)
	int randDistance_left = random_int(-100, -70),
		randDistance_right = random_int(15, 43);
	int randExDistance = random_int(30, 50);

	if (this->dir == -1)
		this->dir = dir;
	if (this->type == -1)
		this->type = type;

	switch (this->dir)
	{
	case LEFT:
	{
		switch (this->type)
		{
		case TYPE::CAR_LEFT:
		{
			if (threat.empty())
			{
				threat.push_back((new Car((float)randDistance_left + 15, (float)y_coord)));
			}
			else if (threat.size() < numEnemyInRow)
			{
				float prevCoordX = threat.back()->getX();
				float distance_temp = randExDistance + prevCoordX + 10;
				if (distance_temp < 50)
				{
					threat.push_back(new Car((float)distance_temp, (float)y_coord));
				}
			}
			break;
		}
		case TYPE::CAR2_LEFT:
		{
			if (threat.empty())
			{
				threat.push_back((new Car((float)randDistance_left + 15, (float)y_coord)));
			}
			else if (threat.size() < numEnemyInRow)
			{
				float prevCoordX = threat.back()->getX();
				float distance_temp = randExDistance + prevCoordX + 10;
				if (distance_temp < 50)
				{
					threat.push_back(new Car((float)distance_temp, (float)y_coord));
				}
			}
			break;
		}
		case TYPE::BUS_LEFT:
		{
			if (threat.empty())
			{
				threat.push_back((new Truck((float)randDistance_left + 15, (float)y_coord)));
			}
			else if (threat.size() < numEnemyInRow)
			{
				float prevCoordX = threat.back()->getX();
				float distance_temp = +randExDistance + prevCoordX + 10;
				if (distance_temp < 50)
				{
					threat.push_back(new Truck((float)distance_temp, (float)y_coord));
				}
			}
			break;
		}
		case TYPE::BALLOON_LEFT:
		{
			if (threat.empty())
			{
				threat.push_back((new Truck((float)randDistance_left + 15, (float)y_coord)));
			}
			else if (threat.size() < numEnemyInRow)
			{
				float prevCoordX = threat.back()->getX();
				float distance_temp = +randExDistance + prevCoordX + 10;
				if (distance_temp < 50)
				{
					threat.push_back(new Truck((float)distance_temp, (float)y_coord));
				}
			}
			break;
		}
		case TYPE::BIRD_LEFT:
		{
			if (threat.empty())
			{
				threat.push_back((new Bird((float)randDistance_left + 15, (float)y_coord)));
			}
			else if (threat.size() < numEnemyInRow)
			{
				float prevCoordX = threat.back()->getX();
				float distance_temp = +randExDistance + prevCoordX + 10;
				if (distance_temp < 50)
				{
					threat.push_back(new Bird((float)distance_temp, (float)y_coord));
				}
			}
			break;
		}
		case TYPE::BEE_LEFT:
		{
			if (threat.empty())
			{
				threat.push_back((new Bird((float)randDistance_left + 15, (float)y_coord)));
			}
			else if (threat.size() < numEnemyInRow)
			{
				float prevCoordX = threat.back()->getX();
				float distance_temp = +randExDistance + prevCoordX + 10;
				if (distance_temp < 50)
				{
					threat.push_back(new Bird((float)distance_temp, (float)y_coord));
				}
			}
			break;
		}
		case TYPE::CAT_LEFT:
		{
			if (threat.empty())
			{
				threat.push_back((new Dinosaur((float)randDistance_left + 15, (float)y_coord)));
			}
			else if (threat.size() < numEnemyInRow)
			{
				float prevCoordX = threat.back()->getX();
				float distance_temp = +randExDistance + prevCoordX + 10;
				if (distance_temp < 50)
				{
					threat.push_back(new Dinosaur((float)distance_temp, (float)y_coord));
				}
			}
			break;
		}
		case TYPE::PIG_LEFT:
		{
			if (threat.empty())
			{
				threat.push_back((new Dinosaur((float)randDistance_left + 15, (float)y_coord)));
			}
			else if (threat.size() < numEnemyInRow)
			{
				float prevCoordX = threat.back()->getX();
				float distance_temp = +randExDistance + prevCoordX + 10;
				if (distance_temp < 50)
				{
					threat.push_back(new Dinosaur((float)distance_temp, (float)y_coord));
				}
			}
			break;
		}
		case TYPE::TURTLE_LEFT:
		{
			if (threat.empty())
			{
				threat.push_back((new Dinosaur((float)randDistance_left + 15, (float)y_coord)));
			}
			else if (threat.size() < numEnemyInRow)
			{
				float prevCoordX = threat.back()->getX();
				float distance_temp = +randExDistance + prevCoordX + 10;
				if (distance_temp < 50)
				{
					threat.push_back(new Dinosaur((float)distance_temp, (float)y_coord));
				}
			}
			break;
		}
		}
		break;
	}

	case RIGHT:
	{
		switch (this->type)
		{
		case TYPE::CAR_RIGHT:
		{
			if (threat.empty())
			{
				threat.push_back(new Car((float)randDistance_right - 15, (float)y_coord));
			}
			else if (threat.size() < numEnemyInRow)
			{
				float prevCoordX = threat.back()->getX();
				float distance_temp = -randExDistance + prevCoordX - 10;
				if (distance_temp > -90)
				{
					threat.push_back(new Car((float)distance_temp, (float)y_coord));
				}
			}

			break;
		}
		case TYPE::CAR2_RIGHT:
		{
			if (threat.empty())
			{
				threat.push_back(new Car((float)randDistance_right - 15, (float)y_coord));
			}
			else if (threat.size() < numEnemyInRow)
			{
				float prevCoordX = threat.back()->getX();
				float distance_temp = -randExDistance + prevCoordX - 10;
				if (distance_temp > -90)
				{
					threat.push_back(new Car((float)distance_temp, (float)y_coord));
				}
			}
			break;
		}
		case TYPE::BUS_RIGHT:
		{
			if (threat.empty())
			{
				threat.push_back(new Truck((float)randDistance_right - 15, (float)y_coord));
			}
			else if (threat.size() < numEnemyInRow)
			{
				float prevCoordX = threat.back()->getX();
				float distance_temp = -randExDistance + prevCoordX - 10;
				if (distance_temp > -100)
				{
					threat.push_back(new Truck((float)distance_temp, (float)y_coord));
				}
			}

			break;
		}
		case TYPE::BALLOON_RIGHT:
		{
			if (threat.empty())
			{
				threat.push_back(new Truck((float)randDistance_right - 15, (float)y_coord));
			}
			else if (threat.size() < numEnemyInRow)
			{
				float prevCoordX = threat.back()->getX();
				float distance_temp = -randExDistance + prevCoordX - 10;
				if (distance_temp > -100)
				{
					threat.push_back(new Truck((float)distance_temp, (float)y_coord));
				}
			}
			break;
		}
		case TYPE::BIRD_RIGHT:
		{
			if (threat.empty())
			{
				threat.push_back(new Bird((float)randDistance_right - 15, (float)y_coord));
			}
			else if (threat.size() < numEnemyInRow)
			{
				float prevCoordX = threat.back()->getX();
				float distance_temp = -randExDistance + prevCoordX - 10;
				if (distance_temp > -100)
				{
					threat.push_back(new Bird((float)distance_temp, (float)y_coord));
				}
			}
			break;
		}
		case TYPE::BEE_RIGHT:
		{
			if (threat.empty())
			{
				threat.push_back(new Bird((float)randDistance_right - 15, (float)y_coord));
			}
			else if (threat.size() < numEnemyInRow)
			{
				float prevCoordX = threat.back()->getX();
				float distance_temp = -randExDistance + prevCoordX - 10;
				if (distance_temp > -100)
				{
					threat.push_back(new Bird((float)distance_temp, (float)y_coord));
				}
			}
		}
		break;
		}
		case TYPE::CAT_RIGHT:
		{

			if (threat.empty())
			{
				threat.push_back(new Dinosaur((float)randDistance_right - 15, (float)y_coord));
			}
			else if (threat.size() < numEnemyInRow)
			{
				float prevCoordX = threat.back()->getX();
				float distance_temp = -randExDistance + prevCoordX - 10;
				if (distance_temp > -100)
				{
					threat.push_back(new Dinosaur((float)distance_temp, (float)y_coord));
				}
			}
			break;
		}
		case TYPE::PIG_RIGHT:
		{
			if (threat.empty())
			{
				threat.push_back(new Dinosaur((float)randDistance_right - 15, (float)y_coord));
			}
			else if (threat.size() < numEnemyInRow)
			{
				float prevCoordX = threat.back()->getX();
				float distance_temp = -randExDistance + prevCoordX - 10;
				if (distance_temp > -100)
				{
					threat.push_back(new Dinosaur((float)distance_temp, (float)y_coord));
				}
			}
			break;
		}
		case TYPE::TURTLE_RIGHT:
		{

			if (threat.empty())
			{
				threat.push_back(new Dinosaur((float)randDistance_right - 15, (float)y_coord));
			}
			else if (threat.size() < numEnemyInRow)
			{
				float prevCoordX = threat.back()->getX();
				float distance_temp = -randExDistance + prevCoordX - 10;
				if (distance_temp > -100)
				{
					threat.push_back(new Dinosaur((float)distance_temp, (float)y_coord));
				}
			}
			break;
		}
		}
	}
}

int Threat::random_int(int min, int max)
{
	return min + rand() % (max + 1 - min);
}
bool Threat::checkWall_left(float x)
{
	if (x < -85)
		return false;
	return true;
}
bool Threat::checkWall_right(float x)
{
	if (x > 45)
		return false;
	return true;
}
void Threat::move(float speed, float dt)
{
	
		render_state = getRender();
		switch (dir)
		{
		case LEFT:
		{
			trafficlight.change(dt, random_int(100, 400));
			switch (type)
			{
			case BIRD_LEFT:
			{
				for (auto x : threat )
				{
					if(trafficlight.getState()== true){
						x->left(speed, dt, lv);
						Renderer::draw_greenlight(50, x->getY());
					}
					else
					{
						Renderer::draw_redlight(50, x->getY());
					}
					x->setHalf(4.5f, 3.25f);
					if (checkWall_left(x->getX()))
						Renderer::draw_birdL(x->getX(), x->getY(), x->getHalfX(), x->getHalfY());
					else
						threat.erase(threat.begin());
				}break;
			}
			case CAR_LEFT:
			{
				for (auto x : threat)
				{
					if (trafficlight.getState() == true) {
						x->left(speed, dt, lv);
						Renderer::draw_greenlight(50, x->getY());
					}
					else
					{
						Renderer::draw_redlight(50, x->getY());
					}
					x->setHalf(7.f, 2.25f);
					if (checkWall_left(x->getX()))
					{
						Renderer::draw_entities(CAR_LEFT, x->getX(), x->getY(), .5f, 0xFFFFF);
					}
					else
						threat.erase(threat.begin());
				}break;
			}
			case CAR2_LEFT:
			{
				for (auto x : threat)
				{
					if (trafficlight.getState() == true) {
						x->left(speed, dt, lv);
						Renderer::draw_greenlight(50, x->getY());
					}
					else
					{
						Renderer::draw_redlight(50, x->getY());
					}
					x->setHalf(5.5f, 2.25f);
					if (checkWall_left(x->getX()))
						Renderer::draw_entities(CAR2_LEFT, x->getX(), x->getY(), .5f, 0xFFFFF);
					else
						threat.erase(threat.begin());
				}break;
			}
			case BUS_LEFT:
			{
				for (auto x : threat)
				{
					if (trafficlight.getState() == true) {
						x->left(speed, dt, lv);
						Renderer::draw_greenlight(50, x->getY());
					}
					else
					{
						Renderer::draw_redlight(50, x->getY());
					}
					x->setHalf(5.5f, 3.5f);
					if (checkWall_left(x->getX()))
					{
						Renderer::draw_entities(BUS_LEFT, x->getX(), x->getY(), .5f, 0xFFFFF);
					}
					else
						threat.erase(threat.begin());
				}break;
			}
			case BALLOON_LEFT:
			{
				for (auto x : threat)
				{
					if (trafficlight.getState() == true) {
						x->left(speed, dt, lv);
						Renderer::draw_greenlight(50, x->getY());
					}
					else
					{
						Renderer::draw_redlight(50, x->getY());
					}
					x->setHalf(2.25f, 3.5f);
					if (checkWall_left(x->getX()))
					{
						Renderer::draw_entities(BALLOON_LEFT, x->getX(), x->getY(), .5f, 0xFFFFF);
					}
					else
						threat.erase(threat.begin());
				}break;
			}
			case TURTLE_LEFT:
			{
				for (auto x : threat)
				{
					if (trafficlight.getState() == true) {
						x->left(speed, dt, lv);
						Renderer::draw_greenlight(50, x->getY());
					}
					else
					{
						Renderer::draw_redlight(50, x->getY());
					}
					x->setHalf(4.f, 3.f);

					if (checkWall_left(x->getX()))
						Renderer::draw_turtleL(x->getX(), x->getY(), x->getHalfX(), x->getHalfY());
					else
						threat.erase(threat.begin());

				}break;
			}
			case BEE_LEFT:
			{
				for (auto x : threat)
				{
					if (trafficlight.getState() == true) {
						x->left(speed, dt, lv);
						Renderer::draw_greenlight(50, x->getY());
					}
					else
					{
						Renderer::draw_redlight(50, x->getY());
					}
					x->setHalf(4.f, 3.5f);
					if (checkWall_left(x->getX()))
						Renderer::draw_entities(BEE_LEFT, x->getX(), x->getY(), .5f, 0xFFFFF);
					else
						threat.erase(threat.begin());

				}break;
			}
			case PIG_LEFT:
			{
				for (auto x : threat)
				{
					if (trafficlight.getState() == true) {
						x->left(speed, dt, lv);
						Renderer::draw_greenlight(50, x->getY());
					}
					else
					{
						Renderer::draw_redlight(50, x->getY());
					}
					x->setHalf(5.f, 3.5f);
					if (checkWall_left(x->getX()))
						Renderer::draw_entities(PIG_LEFT, x->getX(), x->getY(), .5f, 0xFFFFF);
					else
						threat.erase(threat.begin());

				}break;
			}
			case CAT_LEFT:
			{
				for (auto x : threat)
				{
					if (trafficlight.getState() == true) {
						x->left(speed, dt, lv);
						Renderer::draw_greenlight(50, x->getY());
					}
					else
					{
						Renderer::draw_redlight(50, x->getY());
					}
					x->setHalf(4.f, 3.f);
					if (checkWall_left(x->getX()))
						Renderer::draw_entities(CAT_LEFT, x->getX(), x->getY(), .5f, 0xFFFFF);
					else
						threat.erase(threat.begin());

				}break;
			}
			}
			break;
		}
		case RIGHT:
		{
			trafficlight.change(dt, random_int(100, 400));
			switch (type)
			{
			case BIRD_RIGHT:
			{
				for (auto x : threat)
				{
					if (trafficlight.getState() == true) {
						x->right(speed, dt, lv);
						Renderer::draw_greenlight(50, x->getY());
					}
					else
					{
						Renderer::draw_redlight(50, x->getY());
					}
					x->setHalf(4.5f, 3.25f);
					if (checkWall_right(x->getX()))
						Renderer::draw_birdR(x->getX(), x->getY(), x->getHalfX(), x->getHalfY());
					else
						threat.erase(threat.begin());

				}break;
			}
			case CAR_RIGHT:
			{
				for (auto x : threat)
				{
					if (trafficlight.getState() == true) {
						x->right(speed, dt, lv);
						Renderer::draw_greenlight(50, x->getY());
					}
					else
					{
						Renderer::draw_redlight(50, x->getY());
					}
					x->setHalf(7.f, 2.25f);
					if (checkWall_right(x->getX()))
						Renderer::draw_entities(CAR_RIGHT, x->getX(), x->getY(), .5f, 0xFFFFF);

					else
						threat.erase(threat.begin());

				}break;
			}
			case CAR2_RIGHT:
			{
				for (auto x : threat)
				{
					if (trafficlight.getState() == true) {
						x->right(speed, dt, lv);
						Renderer::draw_greenlight(50, x->getY());
					}
					else
					{
						Renderer::draw_redlight(50, x->getY());
					}
					x->setHalf(5.5f, 2.25f);
					if (checkWall_right(x->getX()))
						Renderer::draw_entities(CAR2_RIGHT, x->getX(), x->getY(), .5f, 0xFFFFF);
					else
						threat.erase(threat.begin());

				}break;
			}
			case BUS_RIGHT:
			{
				for (auto x : threat)
				{
					if (trafficlight.getState() == true) {
						x->right(speed, dt, lv);
						Renderer::draw_greenlight(50, x->getY());
					}
					else
					{
						Renderer::draw_redlight(50, x->getY());
					}
					x->setHalf(5.5f, 3.5f);
					if (checkWall_right(x->getX()))
						Renderer::draw_entities(BUS_RIGHT, x->getX(), x->getY(), .5f, 0xFFFFF);
					else
						threat.erase(threat.begin());

				}break;
			}
			case BALLOON_RIGHT:
			{
				for (auto x : threat)
				{
					if (trafficlight.getState() == true) {
						x->right(speed, dt, lv);
						Renderer::draw_greenlight(50, x->getY());
					}
					else
					{
						Renderer::draw_redlight(50, x->getY());
					}
					x->setHalf(2.25f, 3.5f);
					if (checkWall_right(x->getX()))
						Renderer::draw_entities(BALLOON_RIGHT, x->getX(), x->getY(), .5f, 0xFFFFF);
					else
						threat.erase(threat.begin());

				}break;
			}
			case TURTLE_RIGHT:
			{
				for (auto x : threat)
				{
					if (trafficlight.getState() == true) {
						x->right(speed, dt, lv);
						Renderer::draw_greenlight(50, x->getY());
					}
					else
					{
						Renderer::draw_redlight(50, x->getY());
					}
					x->setHalf(4.f, 3.f);
					if (checkWall_right(x->getX()))
						Renderer::draw_turtleR(x->getX(), x->getY(), x->getHalfX(), x->getHalfY());
					else
						threat.erase(threat.begin());

				}break;
			}
			case BEE_RIGHT:
			{
				for (auto x : threat)
				{
					if (trafficlight.getState() == true) {
						x->right(speed, dt, lv);
						Renderer::draw_greenlight(50, x->getY());
					}
					else
					{
						Renderer::draw_redlight(50, x->getY());
					}
					x->setHalf(4.f, 3.5f);
					if (checkWall_right(x->getX()))
						Renderer::draw_entities(BEE_RIGHT, x->getX(), x->getY(), .5f, 0xFFFFF);
					else
						threat.erase(threat.begin());

				}break;
			}
			case PIG_RIGHT:
			{
				for (auto x : threat)
				{
					if (trafficlight.getState() == true) {
						x->right(speed, dt, lv);
						Renderer::draw_greenlight(50, x->getY());
					}
					else
					{
						Renderer::draw_redlight(50, x->getY());
					}
					x->setHalf(5.f, 3.5f);
					if (checkWall_right(x->getX()))
						Renderer::draw_entities(PIG_RIGHT, x->getX(), x->getY(), .5f, 0xFFFFF);
					else
						threat.erase(threat.begin());

				}break;
			}
			case CAT_RIGHT:
			{
				for (auto x : threat)
				{
					if (trafficlight.getState() == true) {
						x->right(speed, dt, lv);
						Renderer::draw_greenlight(50, x->getY());
					}
					else
					{
						Renderer::draw_redlight(50, x->getY());
					}
					x->setHalf(4.f, 3.f);
					if (checkWall_right(x->getX()))
						Renderer::draw_entities(CAT_RIGHT, x->getX(), x->getY(), .5f, 0xFFFFF);
					else
						threat.erase(threat.begin());

				}break;
			}
			}
			break;
		}
		}
}