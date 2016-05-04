#ifndef __LIGHT_H__
#define __LIGHT_H__

#include<cocos2d.h>
#include<cocostudio\CocoStudio.h>
#include"enums.h"

using namespace cocos2d;

class Light : public Node{
private:
	Sprite* red;
	Sprite* green;
	LightStatus status;
	static Light* light;
	Light();
public:
	LightStatus getStatus();
	void reverseStatus(float delta);
	static Light* getInstance();
};

#endif