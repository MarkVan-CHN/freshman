#pragma once
#include "cocos2d.h"
#include "ConfigController.h"
USING_NS_CC;
class layer1 :public Layer
{
public:
	static layer1* create(Sprite* l);
	CREATE_FUNC(layer1);
	virtual bool init();//重定义初始化方法
private:
	Vec2 position;
	Sprite* sprite;
};
