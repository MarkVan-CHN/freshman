#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "AudioEngine.h"
//#include "aircraft battle.h"
USING_NS_CC;
using namespace cocos2d::ui;
class menulayer :public Layer
{
public:
	CREATE_FUNC(menulayer);
	virtual bool init();
	Button* playbutton;
	bool i = true;
	static bool i_bgm_1;
	static bool i_1;
	static bool ii;
	int bg_2;
};
	