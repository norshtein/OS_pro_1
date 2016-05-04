#include"CarManager.h"
#include"MainScene.h"
#include"Light.h"
#include<cmath>

CarManager* CarManager::manager = nullptr;
Vector<Car*> CarManager::cars[8];

static bool justTouchPoint(Rect& rec, Vec2 p)
{
	return fabs(p.x - rec.getMaxX()) < 2 || fabs(p.x - rec.getMinX()) < 2 ||
		fabs(p.y - rec.getMaxY()) < 2 || fabs(p.y - rec.getMinY()) < 2;
}
void CarManager::update(float delta)
{
	TMXObjectGroup* obg = Main::getMap()->getObjectGroup("object");
	ValueMap pos;
	 
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < cars[i].size();j++)
		{
			auto car = cars[i].at(j);
			if (car->getType() == NORMAL)
			{
				switch (car->getDirection())
				{
				case STON:
					pos = obg->getObject("STONSTOP");
					break;
				case NTOS:
					pos = obg->getObject("NTOSSTOP");
					break;
				case ETOW:
					pos = obg->getObject("ETOWSTOP");
					break;
				case WTOE:
					pos = obg->getObject("WTOESTOP");
					break;
				default:
					break;
				}
				auto p = Vec2(pos.at("x").asFloat(), pos.at("y").asFloat());
				if (justTouchPoint(car->getBoundingBox(),p) &&
					(((Light::getInstance()->getStatus() == RED && (car->getDirection() == STON || car->getDirection() == NTOS))) ||
					(Light::getInstance()->getStatus() == GREEN && (car->getDirection() == ETOW || car->getDirection() == WTOE))))
					continue;
			}
			
			
			if (j != 0 && car->getBoundingBox().intersectsRect(cars[i].at(j - 1)->getBoundingBox()))
				continue;

			bool flag = false;
			for (int k = 0; k < 8 && !flag;k++)
			for (auto anotherCar : cars[k])
			{
				if (car == anotherCar)
					continue;
				if (car->collideWith(anotherCar))
				{
					flag = true;
					break;
				}
			}
			if (flag)
				continue;

			car->run();
			if (car->getPosition().x <= -30 || car->getPosition().x >= 990 || car->getPosition().y <= -30 || car->getPosition().y >= 990)
			{
				cars[i].erase(j);
				j--;
			}
		}
	}
}
bool CarManager::addCar(Car* aCar, CarPosition position)
{
	TMXObjectGroup* obg = Main::getMap()->getObjectGroup("object");
	ValueMap pos;
	int index;
	switch (position)
	{
	case NTOSN:
		pos = obg->getObject("NTOSN");
		index = INTOSN;
		break;
	case NTOSS:
		pos = obg->getObject("NTOSS");
		index = INTOSS;
		break;
	case STONN:
		pos = obg->getObject("STONN");
		index = ISTONN;
		break;
	case STONS:
		pos = obg->getObject("STONS");
		index = ISTONS;
		break;
	case ETOWN:
		pos = obg->getObject("ETOWN");
		index = IETOWN;
		break;
	case ETOWS:
		pos = obg->getObject("ETOWS");
		index = IETOWS;
		break;
	case WTOEN:
		pos = obg->getObject("WTOEN");
		index = IWTOEN;
		break;
	case WTOES:
		pos = obg->getObject("WTOES");
		index = IWTOES;
		break;
	}
	aCar->setPosition(Vec2(pos.at("x").asFloat(), pos.at("y").asFloat()));
	bool flag = true;
	for (auto car : cars[index])
	{
		if (aCar->getBoundingBox().intersectsRect(car->getBoundingBox()))
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		Main::getMap()->addChild(aCar);
		cars[index].pushBack(aCar);
	}
	return true;
}

CarManager* CarManager::getInstance()
{
	if (manager == nullptr)
		manager = CarManager::create();
	return manager;
}

bool CarManager::init()
{
	if (!Node::init())
		return false;
	this->scheduleUpdate();
	return true;
}