#include "startgame.h"
//init方法提供游戏初始界面，开始游戏按钮，菜单栏
Size StartGameScene::center = Size(0,0);
bool StartGameScene::init()
{
	if(!Scene::init())
	return false;
	auto bgm_1 = AudioEngine::play2d("bg_1.mp3",true);
	AudioEngine::setVolume(bgm_1, 0.3f);
	auto visiblesize=Director::getInstance()->getVisibleSize();
	center = visiblesize / 2;
	auto bg = Sprite::create("interface.png");
	bg->setPosition(center);
	this->addChild(bg);
	//获取标签中文字
	std::string name = ConfigController::getInstance()->getCNByID(2);
	auto label_1 = Label::createWithTTF(name,"ziti1.ttf",100);
	label_1->setTextColor(Color4B::GRAY);
	label_1->enableGlow(Color4B::BLUE);
	label_1->setPosition(center);
	this->addChild(label_1);
	//添加菜单栏到本层
	auto menu = getmenu();
	this->addChild(menu);
	//自定义事件监听器：当收到menulayer信号是触发切换场景
	auto replacescene = EventListenerCustom::create("replacescene",[](EventCustom* event) 
		{
				auto GameScene = mainscene::create();
				GameScene->initWithPhysics();
				Director::getInstance()->replaceScene(GameScene);
		});
	_eventDispatcher->addEventListenerWithSceneGraphPriority(replacescene, this);
	return  true;
}
menulayer* StartGameScene::getmenu()
{
	auto menu = menulayer::create();
	return menu;
}

