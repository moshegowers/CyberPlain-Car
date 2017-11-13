#include "Car.h"
using namespace CarNamespace;

#ifndef REGULAR_CAR_H
#define REGULAR_CAR_H

#define MAX_VOLUME 3500
class RegularCar : public Car
{
public:
	RegularCar() {};
	RegularCar(const RegularCar &regularCar);


	// return engine volume of car
	size_t getEngineVolume() const;
	// assine engine volume of car
	void setEngineVolume(int engineVolume);

	//return the greater car, compare it by engine volume of car
	static const RegularCar& compareTowCarsByVolume(const RegularCar &lhs, const RegularCar &rhs);

	void printCarDetailes();

private:
	size_t	m_engineVolume;
};

#endif
