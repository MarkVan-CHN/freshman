#pragma once
#include "cocos2d.h"
#include "ConfigController.h"
#include "ui/CocosGUI.h"
#include "aircraft battle.h"
#include "AudioEngine.h"
#include "menulayer.h"

using namespace cocos2d::ui;
USING_NS_CC;
//mainscene�ṩ������Ϸ��ʼ���棬�����ʼ��Ϸ���л�����
class StartGameScene : public Scene
{
public:
	//����creat����
	CREATE_FUNC(StartGameScene);
	//��ʼ���Զ������Ϸ��ʼ����
	virtual bool init();
	//���徲̬��Աcenter�����г���ʹ��
	static Size center;
	//�ṩһ���˵����������г�������
	static menulayer* getmenu();
};