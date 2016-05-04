#ifndef __CARMANAGER_H__
#define __CARMANAGER_H__

#include<cocos2d.h>
#include<cocostudio\CocoStudio.h>
#include"enums.h"
#include"Car.h"

using namespace cocos2d;


class CarManager :public Node
{
private:
	static CarManager* manager;
	static Vector<Car*> cars[8];
	
	CREATE_FUNC(CarManager);
	virtual bool init();

public:
	static CarManager* getInstance();
	virtual void update(float delta);
	bool addCar(Car* aCar,CarPosition pos);
};

#endif