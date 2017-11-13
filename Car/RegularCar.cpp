#include "RegularCar.h"
#include <iostream>

RegularCar::RegularCar()
{
}

RegularCar::RegularCar(const RegularCar & regularCar) : Car(regularCar)
{
	m_engineVolume = regularCar.m_engineVolume;
}

size_t RegularCar::getEngineVolume() const
{
	return m_engineVolume;
}
void RegularCar::setEngineVolume(int engineVolume)
{
	if (engineVolume <= 0 || engineVolume >= MAX_VOLUME)
	{
		printf("The engine volume of car is not valid\n");
		m_isValid = false;
	}
	else
	{
		m_engineVolume = engineVolume;
	}
}

const RegularCar& RegularCar::compareTowCarsByVolume(const RegularCar &lhs, const RegularCar &rhs)
{
	if (lhs.getEngineVolume() == rhs.getEngineVolume())
	{
		return lhs;
	}
	else
	{
		return lhs.getEngineVolume() > rhs.getEngineVolume() ? lhs : rhs;
	}
}

void RegularCar::printCarDetailes()
{
	std::cout << "\n\nDetailes of car is\n-----------------------------" << std::endl;
	std::cout << "License number: " << this->getLicenseNum() << std::endl;
	std::cout << "Company make name: " << this->getMake() << std::endl;
	std::cout << "Model: " << this->getModel() << std::endl;
	std::cout << "Year: " << this->getYear() << std::endl;
	std::cout << "Engine volume: " << this->getEngineVolume() << std::endl;
	std::cout << "Color: " << this->getColor() << std::endl;
	std::cout << "-----------------------------" << std::endl;
}
