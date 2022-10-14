#include "GobangScene.h"

bool GobangScene::init()
{
	if(!Scene::init())
	return false;
	//获取屏幕中心点**
	auto VisibleSize = Director::getInstance()->getVisibleSize();//获取屏幕
	auto framesize = Director::getInstance()->getOpenGLView();//获取窗口
	Vec2 origin = Director::getInstance()->getVisibleOrigin();//获取原点
	Vec2 center(origin.x + VisibleSize.width / 2, origin.y + VisibleSize.height / 2);//获取屏幕中心
	//添加白色背景层**
	auto layer = LayerColor::create(Color4B::WHITE);
	layer->setPosition(origin);//设置背景层位置
	layer->setContentSize(VisibleSize);//设置背景层大小
	this->addChild(layer,0);
	//棋盘精灵**
	auto sprite_Board = Sprite::create("chessboard.jpg",Rect(origin.x,origin.y,550-7,550-7/*调整棋盘大小去除边框*/));
	sprite_Board->setPosition(center);
	auto scaleby_sprite = ScaleBy::create(0, 0.95f, 0.95f);//缩小棋盘到合适大小
	sprite_Board->runAction(scaleby_sprite);
	this->addChild(sprite_Board,1);
	//屏幕左侧中心
	Vec2 Center_left(origin.x + (VisibleSize.width - 0.95f * sprite_Board->getContentSize().width) / 4,
		origin.y + VisibleSize.height / 2);
	//五子棋名称标签
	//静音按钮
	
	//开始游戏按钮
	//悔棋按钮
	//认输按钮
	//退出游戏按钮
	return true;
}
