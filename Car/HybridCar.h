#include "RegularCar.h"
#include "ElectricCar.h"
using namespace CarNamespace;

#ifndef HYBRID_CAR_H
#define HYBRID_CAR_H

enum CarType
{
	Regular = 1,
	Electric = 2
};

class HybridCar : public RegularCar, public ElectricCar
{
public:
	HybridCar(){}

	CarType getCarType();
	void setCarType(size_t carType);

	void printCarDetailes();

private:
	CarType m_carType;
};

#endif