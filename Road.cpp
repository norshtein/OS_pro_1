#include"Road.h"
#include"cocos2d.h"

USING_NS_CC;

void test()
{
	Sprite* s = Sprite::create();
	s->setPosition(s->getPosition() + Vec2(s->getContentSize().width, s->getContentSize().height));
	
}