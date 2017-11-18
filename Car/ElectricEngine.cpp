#include <iostream>
#include "ElectricEngine.h"
#include "Car.h"
#include "RegularEngine.h"

size_t ElectricEngine::getBatteryCapacity() const
{
	return m_batteryCapacity;
}
void ElectricEngine::setBatteryCapacity(size_t batteryCapacity)
{
	if (batteryCapacity >= MIN_BATTERY_CAPACITY && batteryCapacity <= MAX_BATTERY_CAPACITY)
	{
		m_batteryCapacity = batteryCapacity;
	}
}

bool ElectricEngine::getEngineDetailes()
{
	size_t batteryCapacity = 0;
	printf("Please insert battery capacity of car\n");
	std::cin >> batteryCapacity;
	;
	if (batteryCapacity < MIN_BATTERY_CAPACITY || batteryCapacity > MAX_BATTERY_CAPACITY)
	{
		printf("The battery capacity is not valid. please insert value between %d and %d.\n", MIN_BATTERY_CAPACITY, MAX_BATTERY_CAPACITY);
		return false;
	}
	this->setBatteryCapacity(batteryCapacity);
	return true;
}

void ElectricEngine::printEngineDetailes()
{
	std::cout << "The engine type is Electric and this capcity baterry is: " << m_batteryCapacity << std::endl;
}
