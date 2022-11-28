#ifndef MENUEFRAMEWORK_H
#define MENUEFRAMEWORK_H

#include "menu/periferals/display.h"
#include "menu/MenuController.h"
#include "menu/base/ToastManager.h"
#include "menu/base/SettingsManager.h"

ToastManager* toastManager = new ToastManager();
ToneManager* toneManager = new ToneManager();

#endif