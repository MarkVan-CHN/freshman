#include "layer.h"

layer1* layer1::create(Sprite* l)
{
	auto l1 = layer1::create();
	l1->sprite = l;
	return l1;
}

bool layer1::init()
{
	//if (!Layer::init())//�жϸ���init�����Ƿ�ɹ�������ɹ���ʼ�ض���init()
	//	return false;
	//auto listener1 = EventListenerTouchOneByOne::create();//���������¼�������

	//listener1->onTouchMoved = [this](Touch* touch, Event* event)//lambda��[�����б�](�����б�) mustable throw()->return {������}
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

