#pragma once
#include "cocos2d.h"
#include "ConfigController.h"
#include "ui/CocosGUI.h"
#include "aircraft battle.h"
#include "AudioEngine.h"
#include "menulayer.h"

using namespace cocos2d::ui;
USING_NS_CC;
//mainscene提供进入游戏开始界面，点击开始游戏后切换场景
class StartGameScene : public Scene
{
public:
	//重载creat方法
	CREATE_FUNC(StartGameScene);
	//初始化自定义的游戏开始场景
	virtual bool init();
	//定义静态成员center供所有场景使用
	static Size center;
	//提供一个菜单栏可在所有场景调用
	static menulayer* getmenu();
};