#include "aircraft battle.h"

bool mainscene::init()
{
	if(!Scene::init())
	return false;
	auto center = Director::getInstance()->getVisibleSize() / 2;
	auto menu = menulayer::create();
	this->addChild(menu,3);
	menu->playbutton->removeFromParentAndCleanup(true);
	menu->i = false;
	menu->ii = false;
	if (menu->i_1 == false)
		menu->i_1 = !menu->i_1;
	//menu->i_1 = true;
	//if(menu->i_bgm_1)
	/*auto w = AudioEngine::play2d("MTM_055.mid.mp3");*/
	//AudioEngine::pauseAll();
	//if (!menu->i_bgm_1)
	//{
	//	AudioEngine::stopAll();
	//	AudioEngine::play2d("MTM_055.mid.mp3");
	//}
	/*auto partcial_1 = ParticleMeteor::create();
	sprite->addChild(partcial_1);*/
	auto bg_video = Sprite::create("frame/1 (1).jpg");
	bg_video->setPosition(center);
	bg_video->setScale(0.53f);
	this->addChild(bg_video, -1);
	Animation* animation = Animation::create();
	char name[20];
	for (int i = 0; i < 25; i++)
	{
		sprintf_s(name, sizeof(name), "frame/1 (%d).jpg", i+1 );
		animation->addSpriteFrameWithFile(name);
	}
	animation->setDelayPerUnit(0.06f);
	auto animate = Animate::create(animation);
	bg_video->runAction(RepeatForever::create(animate));
	auto screensize = Director::getInstance()->getVisibleSize();//获取屏幕大小
	auto origin = Director::getInstance()->getVisibleOrigin();
	/*Vec2 center(origin.x + screensize.width / 2, origin.y + screensize.height / 2);*/
	//auto bg = Layer::create();//创建层
	//this->addChild(bg);
	////贴图层
	//auto texturelayer = Sprite::create("bg1.png");
	//texturelayer->setPosition(center);
	//texturelayer->setScale(0.6f);
 //   this->addChild(texturelayer,-1);
	//内容层
    sprite = Sprite::create("plane.png");//创建精灵结点类对象
	sprite->setPosition(center.width, center.height / 6);
	sprite->setScale(0.25f);
	auto physics = PhysicsBody::createBox(sprite->getContentSize());
	physics->setGravityEnable(false);
	physics->setContactTestBitmask(3);
	physics->setCategoryBitmask(4);
	physics->setCollisionBitmask(1);
	sprite->setPhysicsBody(physics);
	sprite->setTag(1);
	this->addChild(sprite, 2);
	auto partcial_1 = ParticleMeteor::create();
	partcial_1->setPosition(150, 0);
	sprite->addChild(partcial_1);
	auto listener_1 = EventListenerTouchOneByOne::create();
	listener_1->onTouchBegan = [=](Touch* touch, Event* event)
		{
			if ((touch->getLocation().x > center.width / 100) && (touch->getLocation().x > sprite->getPosition().x - 80) &&
				(touch->getLocation().x < center.width * 2) && (touch->getLocation().x < sprite->getPosition().x + 80) &&
				(touch->getLocation().y > center.height / 10) && (touch->getLocation().y > sprite->getPosition().y - 80) &&
				(touch->getLocation().y < center.height * 2) && (touch->getLocation().y < sprite->getPosition().y + 80)&&this->menu->i_1)
			{
				position = touch->getLocation();
				this->schedule(CC_SCHEDULE_SELECTOR(mainscene::schedulee), 0.2*(1.0+0.5*nowlever));
				auto effect_2 = AudioEngine::play2d("www.alltoall.net_woosh2.wa_8wjbr34OTU.mp3", false);
				//AudioEngine::pauseAll();
			}
			return true;
		};
	listener_1->onTouchMoved = [=](Touch* touch, Event* event)
	{
		if ((touch->getLocation().x > center.width / 100) && (touch->getLocation().x > sprite->getPosition().x - 200) &&
			(touch->getLocation().x < center.width * 2) && (touch->getLocation().x < sprite->getPosition().x + 200) &&
			(touch->getLocation().y > center.height / 100) && (touch->getLocation().y > sprite->getPosition().y - 200) &&
			(touch->getLocation().y < center.height * 2) && (touch->getLocation().y < sprite->getPosition().y + 200)&&this->menu->i_1)
		{
			Vec2 l = touch->getLocation() - position;
			sprite->setPosition(l + sprite->getPosition());
			position = touch->getLocation();
			auto effect_1 = AudioEngine::play2d("www.alltoall.net_woosh3.wa_OUP0JNqHha.mp3", false, 0.1);
		}
		if (this->getChildByName("enemyplanes")!=nullptr&&this->getChildByName("enemyplanes")->getPosition().y < -100)
			this->getChildByName("enemyplanes")->removeFromParentAndCleanup(true);
		if (this->getChildByTag(1111)!=nullptr&&this->getChildByTag(1111)->getPosition().y > 700)
			this->getChildByTag(1111)->removeFromParentAndCleanup(true);
		/*this->schedule(CC_SCHEDULE_SELECTOR(testscene::schedulee), 0.2f);*/
	
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener_1, this);
	this->schedule(CC_SCHEDULE_SELECTOR(mainscene::enemyplane), 0.3f/(nowlever*nowlever*nowlever*nowlever*nowlever));//定时产生敌机@难度系数
	EventListenerPhysicsContact* hitlistener_1 = EventListenerPhysicsContact::create();
	hitlistener_1->onContactBegin = [=](PhysicsContact& contact)
	{
		auto nodeA = contact.getShapeA()->getBody()->getNode();
		auto nodeB = contact.getShapeB()->getBody()->getNode();
		EventCustom event_1("switch_e");
		if (nodeA != nullptr && nodeB != nullptr)
		{
			if (nodeA->getTag() == 1 || nodeB->getTag() == 1|| nowlever == 7)
				_eventDispatcher->dispatchEvent(&event_1);
			if (nodeA->getName() == "enemyplanes")
			{
				if (nodeB->getTag() != 1)
				{
					Score = Score + nodeA->getTag();
					nodeA->removeFromParentAndCleanup(true);
					nodeB->setScale(0.05);
				}
			}
			if (nodeB->getName() == "enemyplanes")
			{
				if (nodeA->getTag() != 1)
				{
					Score = Score + nodeB->getTag();
					nodeA->setScale(0.05);
					nodeB->removeFromParentAndCleanup(true);
				}
			}
			nextlever();
			EventCustom event("updatescoreboard");
			_eventDispatcher->dispatchEvent(&event);
		}
		return  true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(hitlistener_1, this);
	auto updatescoreboard = EventListenerCustom::create("updatescoreboard", [this](EventCustom* event)
		{
			scoreboard->removeFromParentAndCleanup(true);
			char i[15];
			sprintf(i, "SCORE:%d", Score);
			scoreboard = Label::createWithTTF(i, "ziti.ttf", 100);
	        scoreboard->setPosition(130,700);
			scoreboard->setScale(0.35f);
			this->addChild(scoreboard,2);
		});
	_eventDispatcher->addEventListenerWithSceneGraphPriority(updatescoreboard, this);
	scoreboard = Label::createWithTTF("SCORE:0", "ziti.ttf", 100);
	scoreboard->setPosition(130, 700);
	scoreboard->setScale(0.35f);
	this->addChild(scoreboard, 2);
		//(schedulee(position,this)), 1.0f);
	std::string name_1 = ConfigController::getInstance()->getCNByID(8);
	auto lever_1 = Label::createWithTTF(name_1, "ziti.ttf", 30);
	lever_1->setPosition(130, 620);
	this->addChild(lever_1, 2);
	std::string name_2 = ConfigController::getInstance()->getCNByID(3);
	auto lever_2 = Label::createWithTTF(name_2, "ziti.ttf", 30);
	lever_2->setPosition(120, 660);
	this->addChild(lever_2, 2);
	lever = Label::createWithTTF("1", "ziti.ttf", 30);
	lever->setPosition(204.5, 660);
	//lever->setTag(3);
	this->addChild(lever, 2);
	auto switch_e = EventListenerCustom::create("switch_e", [this,center](EventCustom* event)
		{
			Director::getInstance()->pause();
			this->menu->i_1=!this->menu->i_1;
			auto switchlayer = LayerColor::create();
			switchlayer->setColor(Color3B::BLACK);
			switchlayer->setOpacity(100);
			switchlayer->setTag(4);
			this->addChild(switchlayer, 4);

			std::string name_1 = ConfigController::getInstance()->getCNByID(7);
			auto replay = Button::create("button_2.png");
			replay->setScale(0.5);
			replay->setPosition(Vec2(center.width-200,200));
			auto w1 = Label::createWithTTF(name_1, "ziti.ttf",30);
			w1->setPosition(440, 210);
			w1->setScale(0.8f);
			switchlayer->addChild(replay);
			switchlayer->addChild(w1,2);
			if (nowlever == 7)
			{
				std::string name = ConfigController::getInstance()->getCNByID(4);
				auto virtory = Label::createWithTTF(name, "ziti.ttf", 70);
				virtory->enableGlow(Color4B::YELLOW);
				virtory->setPosition(center);
				virtory->setColor(Color3B::ORANGE);
				w1->setPosition(center.width, 210);
				replay->setPosition(Vec2(center.width, 200));
				switchlayer->addChild(virtory);
			}
			else
			{
				std::string name = ConfigController::getInstance()->getCNByID(5);
				auto defeat = Label::createWithTTF(name, "ziti.ttf", 70);
				defeat->setPosition(center);
				defeat->setColor(Color3B::GRAY);
				switchlayer->addChild(defeat);
				std::string name_2 = ConfigController::getInstance()->getCNByID(6);
				auto replay_1 = Button::create("button_2.png");
				replay_1->setScale(0.5);
				replay_1->setPosition(Vec2(center.width + 200, 202));
				auto w2 = Label::createWithTTF(name_2, "ziti.ttf", 30);
				w2->setPosition(200, 200);
				w2->setScale(1.5f);
				switchlayer->addChild(replay_1);
				replay_1->addChild(w2);
				replay_1->addTouchEventListener([this](Ref* sender, Widget::TouchEventType type)
					{
						this->menu->i_1 = !this->menu->i_1;
						this->getChildByTag(4)->removeAllChildrenWithCleanup(true);
						this->getChildByTag(4)->removeFromParentAndCleanup(true);
						Director::getInstance()->resume();
					});
			}
			replay->addTouchEventListener([this](Ref* sender, Widget::TouchEventType type)
				{
					auto scene=mainscene::create();
					scene->initWithPhysics();
					Director::getInstance()->resume();
					//this->menu->i_1 = !this->menu->i_1;
					Director::getInstance()->replaceScene(scene);
				});
		});
	_eventDispatcher->addEventListenerWithSceneGraphPriority(switch_e, this);
	return true;
}

void mainscene::schedulee(float t)
{
	auto bullet_1 = Sprite::create("bullet.png");
	auto physics_1 = PhysicsBody::createBox(bullet_1->getContentSize());
	bullet_1->addComponent(physics_1);
	bullet_1->setPhysicsBody(physics_1);
	bullet_1->getPhysicsBody()->setContactTestBitmask(3);
	bullet_1->getPhysicsBody()->setCategoryBitmask(4);
	bullet_1->getPhysicsBody()->setCollisionBitmask(1);
	bullet_1->getPhysicsBody()->setGravityEnable(false);
	bullet_1->setScale(0.12f);
	bullet_1->setTag(1111);
	bullet_1->setPosition(sprite->getPosition());
	bullet_1->runAction(Repeat::create(MoveBy::create(1, Vec2(0, 300)), 100));
	auto effect_1 = AudioEngine::play2d("www.alltoall.net_woosh3.wa_OUP0JNqHha.mp3", false,0.25);
	this->addChild(bullet_1,1);
}

void mainscene::enemyplane(float t)
{
	char filename[200];
	sprintf_s(filename,sizeof(filename),"enemyplane_%d.png",rand()%3);
	auto enemyplanes = Sprite::create(filename);
	enemyplanes->setName("enemyplanes");
	auto physics_2 = PhysicsBody::createBox(enemyplanes->getContentSize()/3);
	enemyplanes->setPhysicsBody(physics_2);
	enemyplanes->getPhysicsBody()->setContactTestBitmask(4);//有一个为零则不产生消息
	enemyplanes->getPhysicsBody()->setCategoryBitmask(1);
	enemyplanes->getPhysicsBody()->setCollisionBitmask(2);//有一个按位与结果为零则不碰撞（接触不会弹开）
	enemyplanes->getPhysicsBody()->setGravityEnable(false);
	//std::uniform_int_distribution<int>u(1,2);//产生(1, 3)的随机浮点数
	//std::default_random_engine e;
	int scale = rand() % 5 + 1;
	enemyplanes->setTag(100/scale);
	enemyplanes->setScale(0.15f* (double)scale);//5种大小的敌机
	enemyplanes->setPosition(0.04f * (double)(rand() % 24 + 1) * (Director::getInstance()->getVisibleSize().width),
		Director::getInstance()->getVisibleSize().height);
	enemyplanes->runAction(Repeat::create(MoveBy::create(0.3/(nowlever), Vec2(0, -30)), 200));
	/*if (this->getChildByName("enemyplanes")->getPosition().y < 300)
		this->getChildByName("enemyplanes")->removeFromParentAndCleanup(true);
	if (this->getChildByTag(7)->getPosition().y > 500)
		this->getChildByTag(7)->removeFromParentAndCleanup(true);*/
	this->addChild(enemyplanes,1);
}

void mainscene::nextlever()
{
	char i[2];
	if (Score > 1000 && nowlever == 1)
	{
		nowlever++;
		sprintf(i, "%d", nowlever);
		lever->setString(i);
		/*lever_1->setPosition(204.5, 660);
		lever_1->setTag(3);
		this->addChild(lever_1, 2);*/
	}
	if (Score > 3000 && nowlever == 2)
	{
		nowlever++;
		sprintf(i, "%d", nowlever);
		lever->setString(i);
		auto partical_2 = ParticleMeteor::create();
		partical_2->setPosition(100, 0);
		sprite->addChild(partical_2);
		auto partical_3 = ParticleMeteor::create();
		partical_3->setPosition(200, 0);
		sprite->addChild(partical_3);
	}
	if (Score > 8000 && nowlever == 3)
	{
		nowlever++;
		sprintf(i, "%d", nowlever);
		lever->setString(i);
	}
	if (Score > 15000 && nowlever == 4)
	{
		nowlever++;
		sprintf(i, "%d", nowlever);
		lever->setString(i);
		auto partical_4 = ParticleFireworks::create();
		partical_4->setPosition(50, 150);
		partical_4->setScale(1.5f);
		sprite->addChild(partical_4);
		auto partical_5 = ParticleFireworks::create();
		partical_5->setScale(1.5f);
		partical_5->setPosition(250, 150);
		sprite->addChild(partical_5);
	}
	if (Score > 50000 && nowlever == 5)
	{
		nowlever++;
		sprintf(i, "%d", nowlever);
		lever->setString(i);
		auto partical_4 = ParticleFire::create();
		partical_4->setScale(1.5f);
		partical_4->setPosition(80, 200);
		sprite->addChild(partical_4);
		auto partical_5 = ParticleFire::create();
		partical_5->setScale(1.5f);
		partical_5->setPosition(220, 200);
		sprite->addChild(partical_5);
	}
	if (Score > 100000 && nowlever == 6)
	{
		nowlever++;
		sprintf(i, "%d", nowlever);
		lever->setString(i);
	}
}
