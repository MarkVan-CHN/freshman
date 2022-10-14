#include "menulayer.h"
bool menulayer::i_bgm_1 = false;
bool menulayer::i_1 = true;
bool menulayer::ii = true;
bool menulayer::init()
{
	if (!Layer::create())
		return false;
	auto center = Director::getInstance()->getVisibleSize() / 2;
	//创建菜单项层在点击菜单按钮后出现
	auto menuitemlayer = LayerColor::create(Color4B::BLACK);
	this->addChild(menuitemlayer, 3);
	menuitemlayer->setOpacity(150);
	menuitemlayer->setVisible(false);
	playbutton = Button::create("playbutton.png", "", "playbutton.png");
	playbutton->setScale(0.5f);
	playbutton->setPosition(Vec2(center.width, center.height / 3));
	this->addChild(playbutton, 1);
	//按钮事件监听器用于切换场景开始游戏
	playbutton->addTouchEventListener([=](Ref* sender, Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
			{
				auto audio_1 = AudioEngine::play2d("button_1.mp3", false);
				EventCustom event("replacescene");
				AudioEngine::stopAll();
				bg_2 = AudioEngine::play2d("MTM_055.mid.mp3",true);
				_eventDispatcher->dispatchEvent(&event);
			}
		});
	auto menubutton = Button::create("menubutton.png", "", "menubutton.png");
	menubutton->setPosition(Vec2(center.width * 1.878, center.height * 1.8));
	menubutton->setScale(0.35f);
	//菜单按钮监听器用于调出菜单项并暂停游戏
	menubutton->addTouchEventListener([=](Ref* sender, Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
			{
				auto audio_1 = AudioEngine::play2d("button_1.mp3", false);
				menuitemlayer->setVisible(true);
				menubutton->setEnabled(false);
				if (i)
					playbutton->setEnabled(false);
				i_1 = !i_1;
				Director::getInstance()->pause();
			}
		});
	this->addChild(menubutton);
	auto closeitem = MenuItemImage::create("exitbutton.png", "", [](Ref* sender)
		{
			auto audio_1 = AudioEngine::play2d("button_1.mp3", false);
			Director::getInstance()->end();
		});
	closeitem->setScale(0.5f);
	auto resumeitem = MenuItemImage::create("continuebutton.png", "", [=](Ref* sender)
		{
			auto audio_1 = AudioEngine::play2d("button_1.mp3", false);
			menuitemlayer->setVisible(false);
			menubutton->setEnabled(true);
			Director::getInstance()->resume();
			i_1 = !i_1;
			if (i)
				playbutton->setEnabled(true);
				
		});
	resumeitem->setScale(0.5f);
	resumeitem->setPosition(200,36);
	auto musicitem = MenuItemImage::create("musicbutton.png","",[this](Ref * sender)
	{
		auto audio_1 = AudioEngine::play2d("button_1.mp3", false);
		this->i_bgm_1 = !this->i_bgm_1;
		if (i_bgm_1)
			AudioEngine::pauseAll();
		else
			AudioEngine::resumeAll();
	});
	musicitem->setScale(0.5f);
	musicitem->setPosition(-200, 5);
	auto menu = Menu::create(closeitem,resumeitem,musicitem,NULL);
	menuitemlayer->addChild(menu);
	return true;
}
