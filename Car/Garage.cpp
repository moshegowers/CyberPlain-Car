#include "Garage.h"
#include <iostream>

void Garage::addCarToGarage(Car *car)
{
	m_carList->insert(m_carList->begin(), car);
}

void Garage::removeCarFromGarage(size_t licenseNum)
{
	Car *car = findCarInGarage(licenseNum);
	if (NULL != car)
	{
		m_carList->remove(car);
		std::cout << "The car with license num \"" << licenseNum << "\" removed" << std::endl;
	}
	else
	{
		std::cout << "The car with license num \"" << licenseNum << "\" not found.\n";
	}
}

Car * Garage::findCarInGarage(size_t licenseNum)
{
	auto itearator = m_carList->begin();
	while (itearator != m_carList->end())
	{
		if (dynamic_cast<Car*>(*itearator)->getLicenseNum() == licenseNum)
		{
			return dynamic_cast<Car*>(*itearator);
		}
		else
		{
			++itearator;
		}
	}

	return NULL;
}

void Garage::printAllCarsInGarage()
{
	auto itearator = m_carList->begin();
	while (itearator != m_carList->end())
	{
		dynamic_cast<Car*>(*itearator)->printCarDetailes();
		++itearator;
	}
}
