#pragma once
//#include "aircraftbattle/startgame.h"
#include "cocos2d.h"
#include "aircraftbattle/menulayer.h"
#include "ConfigController.h"
USING_NS_CC;
class mainscene :public Scene
{
public:
	CREATE_FUNC(mainscene);
	virtual bool init();
	void schedulee(float t);
	void enemyplane(float t);
	menulayer* menu;
	void nextlever();
private:
	Sprite* sprite;
	Vec2 position;
	int Score = 0;
	Label* scoreboard;
	int nowlever=1;
	Label* lever;
};



