#include "layer.h"

layer1* layer1::create(Sprite* l)
{
	auto l1 = layer1::create();
	l1->sprite = l;
	return l1;
}

bool layer1::init()
{
	//if (!Layer::init())//判断父类init方法是否成功，如果成功开始重定义init()
	//	return false;
	//auto listener1 = EventListenerTouchOneByOne::create();//创建单点事件监听器

	//listener1->onTouchMoved = [this](Touch* touch, Event* event)//lambda体[捕获列表](参数列表) mustable throw()->return {函数体}
	//{
	//	position = touch->getLocation();
	//	return true;
	//};
	//listener1->onTouchMoved = [this](Touch* touch, Event* event)
	//{
	//	Vec2 l = touch->getLocation() - position;
	//	/*auto node = event->getCurrentTarget();*/
	//	sprite->setPosition(l + sprite->getPosition());
	//	position = touch->getLocation();
	//};
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);
	return true;
}

