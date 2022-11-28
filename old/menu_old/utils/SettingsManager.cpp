#include "SettingsManager.h"

SettingsManager::SettingsManager(){
	this->loadSettings();
}

void SettingsManager::registerSetting(String key, int value){

}

int SettingsManager::getSetting(String key){
	auto a = this->settings.find(key);
	if(a!= this->settings.end()){
		return a->second;
	}else{
		return -1;
	}
}

void SettingsManager::setSettings(String key, int value){

}

void SettingsManager::loadSettings(){
	if(!sdCard->sdCardExists() || !sdCard->getInit()){
		this->loaded = false;
		toast->setToast("SD Problem");
		return;
	}

	String fileName = "/settings";
	if(!sdCard->doesFileExists(fileName)){
		this->loaded = false;
		toast->setToast("File Problem");
		return;
	}

	String settingsstring = sdCard->readFile(fileName);

	for(int idx = settingsstring.indexOf("\n"); idx != -1; idx = settingsstring.indexOf("\n")){
		String setting = settingsstring.substring(0, idx);
		int split = setting.indexOf("=");

		String key = setting.substring(0,split);
		int value = setting.substring(split+1,setting.length()-1).toInt();

		this->settings.insert(std::make_pair(key, value));

		settingsstring = settingsstring.substring(idx+1,settingsstring.length());
	}
}

void SettingsManager::storeSettings(){
	return;
}