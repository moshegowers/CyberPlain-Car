#include <list>
#include "Car.h"

using namespace CarNamespace;

#define MAX_CARS 100
class Garage
{
public:
	Garage():m_capacity(0)
	{
		m_carList = new std::list<Car*>;
	}

	void addCarToGarage(Car *car);

	void removeCarFromGarage(size_t licenseNum);

	Car *findCarInGarage(size_t licenseNum);

	void printAllCarsInGarage();

private:
	size_t m_capacity;
	std::list<Car*> *m_carList;
};

