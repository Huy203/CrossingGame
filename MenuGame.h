#pragma once
#include "ConsoleWindow.h"
#include"Sound.h"
#include <iostream>
#include <deque>
#include <string>
using namespace std;
static bool g_sound = true;
static bool g_music_button = false;
static bool g_music_menu = true;
static bool sound_temp = true;
static bool introduction_page = 0;
class MenuGame 
{
	BUTTON menuMode;
	BUTTON hotButton;
	bool running;
public:

	void loadSettings(Input* input) {
		render_state = getRender();
		Renderer::draw_Settings(0, 0, 0, 0, sound_temp);
		if (pressed(BUTTON_B)) {
			is_down(BUTTON_B) = false;
			menuMode = MAIN;
		}
		if ((pressed(BUTTON_LEFT)||pressed(BUTTON_A)) && sound_temp == true) sound_temp = false;
		if ((pressed(BUTTON_RIGHT) || pressed(BUTTON_D)) && !sound_temp == true) sound_temp = true;
		if (pressed(BUTTON_ENTER)) {
			g_music_menu = sound_temp;
			if (g_music_menu)
				Sound::audioMenu();
			else
				Sound::audioStop();
		}
	}
	void loadIntroduction(Input* input) {
		render_state = getRender();
		Renderer::draw_Introduction(0, 0, 0, 0, introduction_page);
		if (pressed(BUTTON_LEFT) || pressed(BUTTON_A)) introduction_page = 0;
		if (pressed(BUTTON_RIGHT) || pressed(BUTTON_D)) introduction_page = 1;
		if (pressed(BUTTON_B)) {
			introduction_page = 1;
			is_down(BUTTON_B) = false;
			menuMode = MAIN;
		}
	}
	MenuGame() {
		menuMode = MAIN;
		hotButton = NEW_GAME;
		Sound::audioMenu();
		running = true;
	}
	bool isRunning() {
		return running;
	}
	void setRunning(bool check) {
		running = check;
	}
	BUTTON getMenuMode() {
		return menuMode;
	}
	void setMenuMode(BUTTON newNode) {
		menuMode = newNode;
		running = true;
	}
	void loadMainMenu(Input* input) {
		render_state = getRender();
		if (pressed(BUTTON_S))
		{
			g_music_button = !g_music_button;
			if (g_music_button)
			{
				Sound::audioButton();
			}
			g_music_button = !g_music_button;
			hotButton = (BUTTON)(hotButton + 1);
			if (hotButton > 4)hotButton = EXIT;
		}
		if (pressed(BUTTON_W)) {
			g_music_button = !g_music_button;
			if (g_music_button)
			{
				Sound::audioButton();
			}
			g_music_button = !g_music_button;
			hotButton = (BUTTON)(hotButton - 1);
			if (hotButton < 0)hotButton = NEW_GAME;
		}
		if (pressed(BUTTON_ENTER))
		{
			is_down(BUTTON_ENTER) = false;
			menuMode = hotButton;
		}
		Renderer::draw_Menu(0, 0, 50, 50, hotButton);
	}
	void loadMenuGame(Input* input) {
		Renderer::clear_screen(0x01C4FF);
		render_state = getRender();
		switch (menuMode) {
		case MAIN:
			loadMainMenu(input);
			break;
		case NEW_GAME:
			running = false;
			break;
		case LOAD_GAME:
			return;
		case SETTINGS:
			loadSettings(input);
			break;
		case INTRODUCTION:
			loadIntroduction(input);
			break;
		case EXIT:
			menuMode = EXIT;
			break;
		}
	}
};

