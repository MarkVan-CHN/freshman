#pragma once
#include <map>
#include "cocos2d.h"
USING_NS_CC;
class ConfigController
{
public:
	static ConfigController* getInstance();
	static void destroyInstance();
	~ConfigController();
	std::string getCNByID(int id);
private:
	//��¼�����ּ��� key:��� string:������
	static ConfigController* instance;
	std::map<int, Value> prt_cnWords;

}; 
