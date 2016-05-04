#ifndef __ROAD_H__
#define __ROAD_H__

#include<cocos2d.h>
#include<cocostudio\CocoStudio.h>
#include"enums.h"
#include"Car.h"

using namespace cocos2d;

class Road :public Layer{
protected:
	Vector<Car*> carsOnRoad;
	RoadStatus status[4][4];
	Sprite* shape;
public:
	bool addCar(Car*);
	bool removeCar(Car*);
	virtual void update(float delta) override;
};

#endif