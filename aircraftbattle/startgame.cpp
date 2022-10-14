#include "startgame.h"
//init�����ṩ��Ϸ��ʼ���棬��ʼ��Ϸ��ť���˵���
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
	//��ȡ��ǩ������
	std::string name = ConfigController::getInstance()->getCNByID(2);
	auto label_1 = Label::createWithTTF(name,"ziti1.ttf",100);
	label_1->setTextColor(Color4B::GRAY);
	label_1->enableGlow(Color4B::BLUE);
	label_1->setPosition(center);
	this->addChild(label_1);
	//��Ӳ˵���������
	auto menu = getmenu();
	this->addChild(menu);
	//�Զ����¼������������յ�menulayer�ź��Ǵ����л�����
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

