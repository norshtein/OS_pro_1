#ifndef __CAR_H__
#define __CAR_H__
#include<cocos2d.h>
#include<cocostudio\CocoStudio.h>
#include"enums.h"

using namespace cocos2d;

class Car : public Node
{
private:
	Sprite* shape;
	CarDirection direction;
	CarStatus status;
	CarType type;

public:
	void run();
	void stop();
	Sprite* getShape();
	void bindShape(Sprite* bp);
	CarDirection getDirection();
	bool setDirection(CarDirection aDirection);
	CarStatus getStatus();
	bool setStatus(CarStatus aStatus);
	CarType getType();
	bool setType(CarType aType);
	CREATE_FUNC(Car);
	virtual bool init();
	bool collideWith(Car* anotherCar);
};







#endif