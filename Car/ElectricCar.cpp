#include <iostream>
#include "ElectricCar.h"
#include "Car.h"
using namespace CarNamespace;

ElectricCar::ElectricCar(const ElectricCar &electricCar) :Car(electricCar)
{
	m_batteryCapacity = electricCar.m_batteryCapacity;
}


size_t ElectricCar::getBatteryCapacity() const
{
	return m_batteryCapacity;
}
void ElectricCar::setBatteryCapacity(int batteryCapacity)
{
	if (batteryCapacity <= 0 || batteryCapacity >= MAX_BATTERY_CAPACITY)
	{
		printf("The battery Capacity of car is not valid\n");
		m_isValid = false;
	}
	else
	{
		m_batteryCapacity = batteryCapacity;
	}
}


void ElectricCar::printCarDetailes()
{
	std::cout << "\n\nDetailes of electric car is\n-----------------------------" << std::endl;
	std::cout << "License number: " << this->getLicenseNum() << std::endl;
	std::cout << "Company make name: " << this->getMake() << std::endl;
	std::cout << "Model: " << this->getModel() << std::endl;
	std::cout << "Year: " << this->getYear() << std::endl;
	std::cout << "Color: " << this->getColor() << std::endl;
	std::cout << "Engine volume: " << this->getBatteryCapacity() << std::endl;
	std::cout << "-----------------------------" << std::endl;
}