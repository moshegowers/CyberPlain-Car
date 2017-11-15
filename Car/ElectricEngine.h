#include "Engine.h"

#ifndef ELECTRIC_CAR_H
#define ELECTRIC_CAR_H

#define MAX_BATTERY_CAPACITY 3500
#define MIN_BATTERY_CAPACITY 1500
class ElectricEngine : public Engine
{
public:
	ElectricEngine(size_t batteryCapacity):m_batteryCapacity(batteryCapacity)
	{}


	// return engine volume of car
	size_t getBatteryCapacity() const;
	// assine engine volume of car
	void setBatteryCapacity(size_t batteryCapacity);

	bool getElctricEngineDetailes();
	void printEngineDetailes();

private:
	size_t	m_batteryCapacity;
};

#endif
