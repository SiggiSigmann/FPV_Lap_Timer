#include "SettingsManager.h"

void SettingsManager::setPersistance(IPersistance* persistance){
	this->persistance = persistance;

	if(persistance->isPrepared()){
		this->settings = new SimpleMap<String, String>([](String& a, String& b) -> int {
        	if (a == b) return 0;
        	if (a > b) return 1;
        	return -1;
    	});
		this->isRead = true;
	}else{
		toastManager->addToast(new Toast("Storage fail", 1000));
	}
}

void SettingsManager::persistSettings(){
	if(!isRead) return;
	String s;

    for (int i = 0; i < this->settings->size(); i++) {
        s +=  settings->getKey(i) + "->" + settings->getData(i) + "\n";
    }

	persistance->storeSettings(s);
}

void SettingsManager::loadSettings(){
	if(!isRead) return;
	String json = this->persistance->readSettings();
	this->settings->clear();

	unsigned int startidx = json.indexOf("\n");
	int oldStartIdx = 0;
	while( startidx != -1 && (json.length() > startidx +1)){
		String setting = json.substring(oldStartIdx,startidx+1);
		String key = setting.substring(0,setting.indexOf("->"));
		String val = setting.substring(setting.indexOf("->")+2,setting.length()-1);
		settings->put(key,val);
		oldStartIdx = startidx;
		startidx= json.indexOf("\n",startidx+1);
	}
}

String SettingsManager::get(String path){
	if(!isRead) return "";
	return this->settings->get(path);
}

void SettingsManager::set(String path, String val){
	if(!isRead) return;
	this->settings->put(path,val);
}

SettingsManager::~SettingsManager( ){
	if(this->settings != NULL) delete this->settings;
}