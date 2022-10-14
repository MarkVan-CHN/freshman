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
	//记录中文字集合 key:编号 string:中文字
	static ConfigController* instance;
	std::map<int, Value> prt_cnWords;

}; 
