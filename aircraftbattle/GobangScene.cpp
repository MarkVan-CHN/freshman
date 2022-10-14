#include "GobangScene.h"

bool GobangScene::init()
{
	if(!Scene::init())
	return false;
	//��ȡ��Ļ���ĵ�**
	auto VisibleSize = Director::getInstance()->getVisibleSize();//��ȡ��Ļ
	auto framesize = Director::getInstance()->getOpenGLView();//��ȡ����
	Vec2 origin = Director::getInstance()->getVisibleOrigin();//��ȡԭ��
	Vec2 center(origin.x + VisibleSize.width / 2, origin.y + VisibleSize.height / 2);//��ȡ��Ļ����
	//��Ӱ�ɫ������**
	auto layer = LayerColor::create(Color4B::WHITE);
	layer->setPosition(origin);//���ñ�����λ��
	layer->setContentSize(VisibleSize);//���ñ������С
	this->addChild(layer,0);
	//���̾���**
	auto sprite_Board = Sprite::create("chessboard.jpg",Rect(origin.x,origin.y,550-7,550-7/*�������̴�Сȥ���߿�*/));
	sprite_Board->setPosition(center);
	auto scaleby_sprite = ScaleBy::create(0, 0.95f, 0.95f);//��С���̵����ʴ�С
	sprite_Board->runAction(scaleby_sprite);
	this->addChild(sprite_Board,1);
	//��Ļ�������
	Vec2 Center_left(origin.x + (VisibleSize.width - 0.95f * sprite_Board->getContentSize().width) / 4,
		origin.y + VisibleSize.height / 2);
	//���������Ʊ�ǩ
	//������ť
	
	//��ʼ��Ϸ��ť
	//���尴ť
	//���䰴ť
	//�˳���Ϸ��ť
	return true;
}
