#include "Car.h"
#include<cocos2d.h>

USING_NS_CC;


static Rect getIntersect(Rect& rect1, Rect& rect2)
{
	float xa1 = rect1.getMinX();
	float ya1 = rect1.getMinY();


	float xa2 = rect1.getMaxX();
	float ya2 = rect1.getMaxY();


	float xb1 = rect2.getMinX();
	float yb1 = rect2.getMinY();


	float xb2 = rect2.getMaxX();
	float yb2 = rect2.getMaxY();


	float xc1, yc1;
	float xc2, yc2;


	xc1 = std::max(xa1, xb1);
	yc1 = std::max(ya1, yb1);


	xc2 = std::min(xa2, xb2);
	yc2 = std::min(ya2, yb2);
	return Rect(xc1, yc1, xc2 - xc1, yc2 - yc1);
}

void Car::run()
{
	if (getDirection() == STON)
		this->setPosition(this->getPosition() + Vec2(0, 1));
	else if (getDirection() == NTOS)
		this->setPosition(this->getPosition() + Vec2(0, -1));
	else if (getDirection() == ETOW)
		this->setPosition(this->getPosition() + Vec2(-1, 0));
	else if (getDirection() == WTOE)
		this->setPosition(this->getPosition() + Vec2(1, 0));
}
void Car::stop()
{

}
Sprite* Car::getShape()
{
	return this->shape;
}
CarDirection Car::getDirection()
{
	return this->direction;
}
bool Car::setDirection(CarDirection aDirection)
{
	this->direction = aDirection;
	return true;
}
CarStatus Car::getStatus()
{
	return this->status;
}
bool Car::setStatus(CarStatus aStatus)
{
	this->status = aStatus;
	return true;
}
CarType Car::getType()
{
	return this->type;
}
bool Car::setType(CarType aType)
{
	this->type = aType;
	return true;
}
bool Car::init()
{
	if (!Node::init())
		return false;
	this->shape = Sprite::create("normalcar.png");
	this->addChild(shape);
	this->setContentSize(Size(20,32));
	this->setAnchorPoint(Vec2(0.5, 0.5));
	shape->setPosition(this->getContentSize().width / 2, this->getContentSize().height / 2);
	this->setPosition(this->getPosition() - this->getContentSize() / 2);
	return true;
}
void Car::bindShape(Sprite* sp)
{
	this->removeChild(shape);
	shape = sp;
	this->addChild(shape);
	shape->setPosition(this->getContentSize().width / 2, this->getContentSize().height / 2);
}
bool Car::collideWith(Car* anotherCar)
{
	if (!this->getBoundingBox().intersectsRect(anotherCar->getBoundingBox()))
		return false;

	Rect prevRect = this->getBoundingBox();
	double deltaX, deltaY;
	switch (this->getDirection())
	{
	case STON:
		deltaY = 10;
		deltaX = 0;
		break;
	case NTOS:
		deltaY = -10;
		deltaX = 0;
		break;
	case ETOW:
		deltaY = 0;
		deltaX = -10;
		break;
	case WTOE:
		deltaY = 0;
		deltaX = 10;
		break;
	default:
		break;
	}
	Rect pingyi = Rect(prevRect.origin.x + deltaX, prevRect.origin.y + deltaY, prevRect.size.width, prevRect.size.height);
	Rect jiaoji = getIntersect(pingyi, anotherCar->getBoundingBox());

	if (jiaoji.size.width * jiaoji.size.height > 30)
		return true;
	return false;
}


