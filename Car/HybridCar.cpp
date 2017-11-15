#include "HybridCar.h"
#include <iostream>

using namespace CarNamespace;

CarType  HybridCar::getCarType()
{
	return m_carType;
}
void HybridCar::setCarType(size_t carType)
{
	if (carType != CarType::Electric && carType != CarType::Regular)
	{
		printf("The type of car is must be %d or %d only\n", CarType::Regular, CarType::Electric);
		m_isValid = false;
	}
	else
	{
		m_carType = static_cast<CarType>(carType);
	}
}

void HybridCar::printCarDetailes()
{
	std::cout << "\n\nDetailes of hybrid car is\n-----------------------------" << std::endl;
	std::cout << "License number: " << this->Car::getLicenseNum() << std::endl;
	std::cout << "Company make name: " << this->Car::getMake() << std::endl;
	std::cout << "Model: " << this->Car::getModel() << std::endl;
	std::cout << "Year: " << this->Car::getYear() << std::endl;
	std::cout << "Color: " << this->Car::getColor() << std::endl;
	std::cout << "Battery Capacity: " << this->getBatteryCapacity() << std::endl;
	std::cout << "Engine volume: " << this->getEngineVolume() << std::endl;
	std::cout << "Tech use now: " << (this->getCarType() == CarType::Regular ? "Regular" : "Electric") << std::endl;
	std::cout << "-----------------------------" << std::endl;
}
