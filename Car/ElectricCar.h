#include "Car.h"
using namespace CarNamespace;

#ifndef ELECTRIC_CAR_H
#define ELECTRIC_CAR_H

class ElectricCar : Car
{
public:
	ElectricCar(const ElectricCar &electricCar);
	// return engine volume of car
	size_t getBatteryCapacity() const;
	// assine engine volume of car
	void setBatteryCapacity(int batteryCapacity);

	void printCarDetailes();

private:
	size_t	m_batteryCapacity;
};

#endif