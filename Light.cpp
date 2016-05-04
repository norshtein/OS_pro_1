#include"Light.h"
#include"cocos2d.h"

USING_NS_CC;

Light* Light::light = nullptr;

LightStatus Light::getStatus()
{
	return status;
}
void Light::reverseStatus(float dt)
{
	if (status == RED)
	{
		status = GREEN;
		red->setVisible(false);
		green->setVisible(true);
	}
	else if (status == GREEN)
	{
		status = RED;
		red->setVisible(true);
		green->setVisible(false);
	}
}
Light* Light::getInstance()
{
	if (light == nullptr)
		light = new Light();
	return light;
}

Light::Light() :Node()
{
	red = Sprite::create("red.png");
	green = Sprite::create("green.png");
	status = RED;

	red->setVisible(false);
	this->addChild(red);
	green->setVisible(true);
	this->addChild(green);

	schedule(schedule_selector(Light::reverseStatus), 8.0f, kRepeatForever, 0);

}