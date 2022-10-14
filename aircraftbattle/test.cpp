#include "test.h"
#include <stdio.h>
#include "AudioEngine.h"
//void particle(Layer* bg,Vec2 center,Vec2 screensize)
//{
//	auto particle_1 = Sprite::create("particle_3.png");
//	particle_1->setPosition(43, 55);
//	particle_1->setScale(0.2f);
//	particle_1->setOpacity(180);
//	particle_1->runAction(Repeat::create(Sequence::create(MoveTo::create(2, Vec2(400, 0)),
//		MoveTo::create(2.5, Vec2(0, 500)), MoveTo::create(2.5, Vec2(192, 0)), MoveTo::create(2.5, Vec2(1920 / 2, 300)),
//		MoveTo::create(2.5, Vec2(430, 1080 / 2)), nullptr), 100));
//	bg->addChild(particle_1,0);//子节点先渲染，同级Zorder值大的先渲染
//	auto particle_2 = Sprite::create("particle_3.png");
//	particle_2->setPosition(403, 321);
//	particle_2->setScale(0.22f);
//	particle_2->setRotation(45.5f);
//	particle_2->setOpacity(110);
//	particle_2->setColor(Color3B::RED);
//	particle_2->runAction(Repeat::create(Sequence::create(MoveTo::create(3, Vec2(screensize.x / 2, 0)),
//		MoveTo::create(4, Vec2(0, screensize.y / 2)), MoveTo::create(3, Vec2(screensize.x, screensize.y / 2)),
//		MoveTo::create(4, Vec2(screensize.x / 1.7f, screensize.y)), nullptr), 100));
//	bg->addChild(particle_2,0);
//	auto particle_3 = Sprite::create("particle_4.png");
//	particle_3->setPosition(143, 255);
//	particle_3->setScale(0.5f);
//	particle_3->setRotation(87.5f);
//	particle_3->setOpacity(180);
//	particle_3->runAction(Repeat::create(Sequence::create(MoveTo::create(4, Vec2(screensize.x/ 3.7f, screensize.y)),
//		MoveTo::create(4, Vec2(0, screensize.y/ 8)), MoveTo::create(3, Vec2(screensize.x, screensize.y / 5)),
//		MoveTo::create(5.5f, Vec2(screensize.x / 2, 0)), nullptr), 100));
//	bg->addChild(particle_3,0);
//	auto particle_4 = Sprite::create("particle_4.png");
//	particle_4->setPosition(center);
//	particle_4->setScale(0.45f);
//	particle_4->setRotation(187.5f);
//	particle_4->setColor(Color3B::GREEN);
//	particle_4->setOpacity(140);
//	particle_4->runAction(Repeat::create(Sequence::create(MoveTo::create(5, Vec2(screensize.x / 2, 0)),
//		MoveTo::create(3, Vec2(0, screensize.y / 3)), MoveTo::create(5, Vec2(screensize.x, screensize.y/ 2)),
//		MoveTo::create(7, Vec2(screensize.x / 6.7f, screensize.y)), nullptr), 100));
//	bg->addChild(particle_4, 0);
//	auto particle_5 = Sprite::create("particle_2.png");
//	particle_5->setPosition(center / 4);
//	particle_5->setScale(0.105f);
//	particle_5->setRotation(87.5f);
//	particle_5->setColor(Color3B::MAGENTA);
//	particle_5->setOpacity(140);
//	particle_5->runAction(Repeat::create(Sequence::create(MoveTo::create(3, Vec2(screensize.x / 2, 0)),
//		MoveTo::create(3.9f, Vec2(0, screensize.y / 3)), MoveTo::create(7, Vec2(screensize.x, screensize.y / 2)),
//		MoveTo::create(2.4f, Vec2(screensize.x / 5.7f, screensize.y)), nullptr), 100));
//	bg->addChild(particle_5,0);
//	auto particle_6 = Sprite::create("particle_4.png");
//	particle_6->setPosition(center * 1.7);
//	particle_6->setScale(0.41f);
//	particle_6->setRotation(187.5f);
//	particle_6->setColor(Color3B::BLUE);
//	particle_6->setOpacity(140);
//	particle_6->runAction(Repeat::create(Sequence::create(MoveTo::create(5, Vec2(screensize.x, screensize.y / 2)),
//		MoveTo::create(3, Vec2(0, screensize.y / 4.3f)), MoveTo::create(4.2f, Vec2(screensize.x/ 2, 0)),
//		MoveTo::create(7, Vec2(screensize.x / 6.7f, screensize.y)), nullptr), 100));
//	bg->addChild(particle_6,0);
//}
//void particle(Sprite* bg, Vec2 center, Vec2 screensize)
//{
//	auto particle_1 = Sprite::create("particle_3.png");
//	particle_1->setPosition(43, 55);
//	particle_1->setScale(0.2f);
//	particle_1->setOpacity(180);
//	particle_1->runAction(Repeat::create(Sequence::create(MoveTo::create(2, Vec2(400, 0)),
//		MoveTo::create(2.5, Vec2(0, 500)), MoveTo::create(2.5, Vec2(192, 0)), MoveTo::create(2.5, Vec2(1920 / 2, 300)),
//		MoveTo::create(2.5, Vec2(430, 1080 / 2)), nullptr), 100));
//	/*bg->addChild(particle_1, 0);*///子节点先渲染，同级Zorder值大的先渲染
//	auto particle_2 = Sprite::create("particle_3.png");
//	particle_2->setPosition(403, 321);
//	particle_2->setScale(0.22f);
//	particle_2->setRotation(45.5f);
//	particle_2->setOpacity(110);
//	particle_2->setColor(Color3B::RED);
//	particle_2->runAction(Repeat::create(Sequence::create(MoveTo::create(3, Vec2(screensize.x / 2, 0)),
//		MoveTo::create(4, Vec2(0, screensize.y / 2)), MoveTo::create(3, Vec2(screensize.x, screensize.y / 2)),
//		MoveTo::create(4, Vec2(screensize.x / 1.7f, screensize.y)), nullptr), 100));
//	bg->addChild(particle_2, 0);
//	auto particle_3 = Sprite::create("particle_4.png");
//	particle_3->setPosition(143, 255);
//	particle_3->setScale(0.5f);
//	particle_3->setRotation(87.5f);
//	particle_3->setOpacity(180);
//	particle_3->runAction(Repeat::create(Sequence::create(MoveTo::create(4, Vec2(screensize.x / 3.7f, screensize.y)),
//		MoveTo::create(4, Vec2(0, screensize.y / 8)), MoveTo::create(3, Vec2(screensize.x, screensize.y / 5)),
//		MoveTo::create(5.5f, Vec2(screensize.x / 2, 0)), nullptr), 100));
//	bg->addChild(particle_3, 0);
//	auto particle_4 = Sprite::create("particle_4.png");
//	particle_4->setPosition(center);
//	particle_4->setScale(0.45f);
//	particle_4->setRotation(187.5f);
//	particle_4->setColor(Color3B::GREEN);
//	particle_4->setOpacity(140);
//	particle_4->runAction(Repeat::create(Sequence::create(MoveTo::create(5, Vec2(screensize.x / 2, 0)),
//		MoveTo::create(3, Vec2(0, screensize.y / 3)), MoveTo::create(5, Vec2(screensize.x, screensize.y / 2)),
//		MoveTo::create(7, Vec2(screensize.x / 6.7f, screensize.y)), nullptr), 100));
//	bg->addChild(particle_4, 0);
//	auto particle_5 = Sprite::create("particle_2.png");
//	particle_5->setPosition(center / 4);
//	particle_5->setScale(0.105f);
//	particle_5->setRotation(87.5f);
//	particle_5->setColor(Color3B::MAGENTA);
//	particle_5->setOpacity(140);
//	particle_5->runAction(Repeat::create(Sequence::create(MoveTo::create(3, Vec2(screensize.x / 2, 0)),
//		MoveTo::create(3.9f, Vec2(0, screensize.y / 3)), MoveTo::create(7, Vec2(screensize.x, screensize.y / 2)),
//		MoveTo::create(2.4f, Vec2(screensize.x / 5.7f, screensize.y)), nullptr), 100));
//	bg->addChild(particle_5, 0);
//	auto particle_6 = Sprite::create("particle_4.png");
//	particle_6->setPosition(center * 1.7);
//	particle_6->setScale(0.41f);
//	particle_6->setRotation(187.5f);
//	particle_6->setColor(Color3B::BLUE);
//	particle_6->setOpacity(140);
//	particle_6->runAction(Repeat::create(Sequence::create(MoveTo::create(5, Vec2(screensize.x, screensize.y / 2)),
//		MoveTo::create(3, Vec2(0, screensize.y / 4.3f)), MoveTo::create(4.2f, Vec2(screensize.x / 2, 0)),
//		MoveTo::create(7, Vec2(screensize.x / 6.7f, screensize.y)), nullptr), 100));
//	bg->addChild(particle_6, 0);
//}
bool testscene21::init()
{
	
	//if (!Scene::init())//判断父类init方法是否成功，如果成功开始重定义init()
	//	return false;
	//srand(time(NULL));//产生随机整数
	//auto bmg_1 = AudioEngine::play2d("MTM_055.mid.mp3",true);//添加背景音乐
	//auto screensize = Director::getInstance()->getVisibleSize();//获取屏幕大小
	//auto origin = Director::getInstance()->getVisibleOrigin();
	//Vec2 center(origin.x + screensize.width / 2, origin.y + screensize.height / 2);
	//auto bg = Layer::create();//创建层
	////this->addChild(bg);
	////贴图层
	//auto texturelayer = Sprite::create("bg1.png");
	//texturelayer->setPosition(center);
	//texturelayer->setScale(0.6f);
 //   //this->addChild(texturelayer,-1);
	////内容层
 //   sprite = Sprite::create("plane.png");//创建精灵结点类对象
	//sprite->setPosition(center.x, center.y / 6);
	//sprite->setScale(0.25f);
	////this->addChild(sprite, 4);
	//auto listener_1 = EventListenerTouchOneByOne::create();
	//listener_1->onTouchBegan = [this,center](Touch* touch, Event* event)
	//{
	//	if ((touch->getLocation().x > center.x / 100) && (touch->getLocation().x > sprite->getPosition().x - 80) &&
	//		(touch->getLocation().x < center.x * 2) && (touch->getLocation().x < sprite->getPosition().x + 80) &&
	//		(touch->getLocation().y > center.y / 10) && (touch->getLocation().y > sprite->getPosition().y - 80) &&
	//		(touch->getLocation().y < center.y * 2) && (touch->getLocation().y < sprite->getPosition().y + 80))
	//	{
	//		position = touch->getLocation();
	//		this->schedule(CC_SCHEDULE_SELECTOR(testscene::schedulee), 0.3f);
	//		//auto effect_2 = AudioEngine::play2d("www.alltoall.net_woosh2.wa_8wjbr34OTU.mp3",false);
	//	}
	//	return true;
	//};
	//listener_1->onTouchMoved = [this, center](Touch* touch, Event* event)
	//{
	//	if ((touch->getLocation().x > center.x / 100) && (touch->getLocation().x > sprite->getPosition().x - 80) &&
	//		(touch->getLocation().x < center.x * 2) && (touch->getLocation().x < sprite->getPosition().x + 80) &&
	//		(touch->getLocation().y > center.y / 100) && (touch->getLocation().y > sprite->getPosition().y - 80) &&
	//		(touch->getLocation().y < center.y * 2) && (touch->getLocation().y < sprite->getPosition().y + 80))
	//	{
	//		Vec2 l = touch->getLocation() - position;
	//		sprite->setPosition(l + sprite->getPosition());
	//		position = touch->getLocation();
	//		//auto effect_1 = AudioEngine::play2d("www.alltoall.net_woosh3.wa_OUP0JNqHha.mp3", false,0.1);
	//		/*this->schedule(CC_SCHEDULE_SELECTOR(testscene::schedulee), 0.2f);*/
	//	}
	//};
	////_eventDispatcher->addEventListenerWithSceneGraphPriority(listener_1,this);
	////this->schedule(CC_SCHEDULE_SELECTOR(testscene::enemyplane), 0.5f);//定时产生敌机@难度系数
	////EventListenerPhysicsContact* hitlistener_1 = EventListenerPhysicsContact::create();
	///*hitlistener_1->onContactBegin = [=](PhysicsContact& contact)
	//{
	//	auto nodeA = contact.getShapeA()->getBody()->getNode();
	//	auto nodeB = contact.getShapeB()->getBody()->getNode();
	//	if (nodeA->getTag() == 1)
	//		nodeA->removeFromParentAndCleanup(true);
	//	if (nodeB->getTag() == 1)
	//		nodeB->removeFromParentAndCleanup(true);
	//	return  true;
	//};*/
	////_eventDispatcher->addEventListenerWithSceneGraphPriority(hitlistener_1, this);
	///*(schedulee(position,this)), 1.0f);*/
	////粒子效果
	////particle(bg,center,screensize);
	////particle(sprite, center, screensize/6);
	return false;//false表示碰撞后穿透
}


//void testscene::schedulee(float t)
//{
//	auto bullet_1 = Sprite::create("bullet.png");
//	//auto physics_1 = PhysicsBody::createBox(bullet_1->getContentSize());
//	//bullet_1->addComponent(physics_1);
//	//bullet_1->setPhysicsBody(physics_1);
//	//bullet_1->getPhysicsBody()->setContactTestBitmask(2);
//	//bullet_1->getPhysicsBody()->setCategoryBitmask(1);
//	//bullet_1->getPhysicsBody()->setCollisionBitmask(1);
//	//bullet_1->getPhysicsBody()->setGravityEnable(false);
//	bullet_1->setScale(0.15f);
//	bullet_1->setPosition(sprite->getPosition());
//	bullet_1->runAction(Repeat::create(MoveBy::create(1, Vec2(0, 300)), 100));
//	auto effect_1 = AudioEngine::play2d("www.alltoall.net_woosh3.wa_OUP0JNqHha.mp3", false,0.25);
//	this->addChild(bullet_1);
//}
//
//void testscene::enemyplane(float t)
//{
//	char filename[200];
//	sprintf_s(filename,sizeof(filename),"enemyplane_%d.png",rand()%3);
//	auto enemyplanes = Sprite::create(filename);
//	enemyplanes->setTag(1);
//	//auto physics_2 = PhysicsBody::createBox(enemyplanes->getContentSize());
//	//enemyplanes->setPhysicsBody(physics_2);
//	//enemyplanes->getPhysicsBody()->setContactTestBitmask(1);
//	//enemyplanes->getPhysicsBody()->setCategoryBitmask(0);
//	//enemyplanes->getPhysicsBody()->setCollisionBitmask(1);
//	//enemyplanes->getPhysicsBody()->setGravityEnable(false);
//	//std::uniform_int_distribution<int>u(1,2);//产生(1, 3)的随机浮点数
//	//std::default_random_engine e;
//	enemyplanes->setScale(0.2f* (double)(rand() % 3+1));//4种大小的敌机
//	enemyplanes->setPosition(0.04f * (double)(rand() % 24 + 1) * (Director::getInstance()->getVisibleSize().width),
//		Director::getInstance()->getVisibleSize().height);
//	enemyplanes->runAction(Repeat::create(MoveBy::create(1, Vec2(0, -30)), 200));
//	this->addChild(enemyplanes);
//}




