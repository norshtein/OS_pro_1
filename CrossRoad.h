#ifndef __CROSSROAD_H__
#define __CROSSROAD_H__

#include<cocos2d.h>
#include<cocostudio\CocoStudio.h>
#include"enums.h"
#include"Road.h"

using namespace cocos2d;

class CrossRoad :public Road
{
private:
	bool used[4][4];
};

#endif