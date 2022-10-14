#include "ConfigController.h"
ConfigController* ConfigController::instance = nullptr;
ConfigController* ConfigController::getInstance()
{
	if (instance==nullptr)
	{
		instance = new ConfigController();
	}
	return instance;
}

void ConfigController::destroyInstance()
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

ConfigController::~ConfigController()
{
	prt_cnWords.clear();
}

std::string ConfigController::getCNByID(int id)
{
	if (prt_cnWords.empty())
	{
		auto data = FileUtils::getInstance()->getValueMapFromFile("res/tips.plist");
		for (auto maPair : data)
		{
			int key = Value(maPair.first).asInt();
			Value val = maPair.second;
			prt_cnWords.insert(std::pair<int, Value>(key, val));
		}
	}
	if (prt_cnWords.empty())
	{
		return "";
	}
	return prt_cnWords.at(id).asString();
}
