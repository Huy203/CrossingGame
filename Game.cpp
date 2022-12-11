#include "Game.h"
//dp: derivative of position: Van toc
//ddp:  derivative of derivative of positon: Gia toc
float arena_half_size_x = 85, arena_half_size_y = 45;

int Game::getLv()
{
	return lv;
}

//int Game::getScore()
//{
//	return score;
//}
//void Game::setScore()
//{
//
//	if (lv > 1)
//		score = (lv - 1) * 100;
//}
//void Game::scoreChange()
//{
//	setScore();
//	Renderer::draw_number(score, 78, 31, 1.3, 0xFF3131);
//}

vector<Threat*> Game::getThreat()
{
	return threat;
}
Player Game::getPlayer()
{
	return player;
}
void Game::startGame()
{
	player = Player();
	threat.clear();
	lv = 1;
	score.readHighScore();
	//menu.setMenuMode(NEW_GAME);
}

void Game::setHighScore()
{
	score.writeHighScore();
}
void Game::simulate_menu(Input* input)
{
	menu.loadMenuGame(input);
}
void Game::simulate_game(Input* input, float dt)
{
	render_state = getRender();

	//Renderer::	clear_screen(0xffffffff);

	float speed = 5.f;




	Renderer::draw_Background(0, 0, 73, 45);
	//Renderer::draw_turtleL(0, 0, 1, 1);
	player.move(input, dt, speed);
	player.checkWall(-28.5, 0, 71.5, 45);
	player.isImpact(threat);
	Renderer::draw_trees(0, 0);
	updatePosThreat();
	threatMove(dt);
	score.DisplayScore();
	score.DisplayHighScore();
	next_level();

}
//BUTTON Game::menu_game(Input* input) {
//	render_state = getRender();
//	if (released(BUTTON_UP))
//	{
//		g_music_menu = !g_music_menu;
//		if (g_music_menu)
//			Sound::audioMenu();
//		else
//			Sound::audioStop();
//	}
//	if (pressed(BUTTON_S))
//	{
//		g_music_button = !g_music_button;
//		if (g_music_button)
//		{
//			Sound::audioButton();
//		}
//		g_music_button = !g_music_button;
//		hot_button = (BUTTON)(hot_button + 1);
//		if (hot_button > 4)hot_button = EXIT;
//	}
//	if (pressed(BUTTON_W)) {
//		g_music_button = !g_music_button;
//		if (g_music_button)
//		{
//			Sound::audioButton();
//		}
//		g_music_button = !g_music_button;
//		hot_button = (BUTTON)(hot_button - 1);
//		if (hot_button < 0)hot_button = NEW_GAME;
//	}
//	/*Do something in menu*/;
//	Renderer::draw_Menu(0, 0, 50, 50, hot_button);
//	if (pressed(BUTTON_ENTER))
//	{
//
//		switch (hot_button)
//		{
//		case NEW_GAME:	//NEW GAME
//			return hot_button;
//
//		case LOAD_GAME:		//LOAD GAME
//			return hot_button;
//
//		case SETTINGS: //SETTINGS
//			return hot_button;
//
//		case INTRODUCTION:
//			Renderer::clear_screen(0xFFFFFF);
//
//			//Draw Introduction in here.
//
//			return hot_button;
//		case EXIT:
//			return hot_button;
//		}
//	}
//	return BUTTON(-1);
//}
void Game::reset_game()
{
	player.setY(-45);
	threat.clear();
}
void Game::restartGame()
{
	startGame();
}
bool Game::next_level()
{
	//Bien tren Y
	if (player.getY() == 40)
	{
		lv++;
		Sound::audioUpScore();
		score.setScore(lv);
		reset_game();
	}
	return false;
}
int Game::overGame(Input* input)
{
	Renderer::draw_rect(0, 0, 20, 10, 0xFFFA);
	if (pressed(BUTTON_Y))	//restart game
		return 1;
	if (pressed(BUTTON_ESC))
		return -1;
	return 0;
}
bool Game::quit(Input* input)
{
	if (is_down(BUTTON_ESC))
		return false;
	return true;
}

void Game::threatMove(float dt)
{
	for (auto x : threat)
	{

		x->move(0.5,dt);

	}
	return;
}
void Game::updatePosThreat()
{
	if (threat.empty())
	{
		threat.push_back(new Threat(-28));
		threat.push_back(new Threat(-13));
		threat.push_back(new Threat(13));
		threat.push_back(new Threat(28));
	}
	for (auto x : threat)
	{
		x->setThreatInRow(lv);
		int randomDir = 0 + rand() % 2;
		int randomType;
		if (lv == 1)
		{
			while (true)
			{
				randomType = 0 + rand() % 8;
				if (randomType % 2 == randomDir)
				{
					break;
				}
			}
		}
		if (lv == 2)
		{
			while (true)
			{
				randomType = 8 + rand() % 10;
				if (randomType % 2 == randomDir)
				{
					break;
				}
			}
		}
		if (lv > 2)
		{
			while (true)
			{
				randomType = 0 + rand() % 18;
				if (randomType % 2 == randomDir)
				{
					break;
				}
			}
		}
		x->setListEntity((TYPE)randomType, randomDir);
	}
	// draw traffic light 
}

bool Game::exitGame(thread& t1)
{
	t1.join();
	return true;
}

void Game::pauseGame(HANDLE hd)
{
	//g_pause = true;
	SuspendThread(hd);
}

void Game::resumeGame(HANDLE hd)
{
	//g_pause = false;
	ResumeThread(hd);
}