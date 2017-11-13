#include <string>
#include <iostream>
#include "RegularCar.h"
#include "ElectricCar.h"
using namespace CarNamespace;

void getCarDetailes(Car *car);
void getRegularCarDetailes(RegularCar *regularCar);
void getElectricCarDetailes(ElectricCar *electricCar);

void main(void)
{
	RegularCar regularCar;
	do
	{
		regularCar.setIsValid(true);
		getRegularCarDetailes(&regularCar);
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (!regularCar.getIsValid());

	ElectricCar electricCar;
	do
	{
		electricCar.setIsValid(true);
		getElectricCarDetailes(&electricCar);
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (!electricCar.getIsValid());
	
	regularCar.printCarDetailes();
	electricCar.printCarDetailes();
}

void getCarDetailes(Car *car)
{
	if (car == NULL)
	{
		return;
	}
	std::string make = "", model = "", color = "";
	int year = 0;

	printf("\n\nPlease insert company make name of car\n");
	std::cin >> make;
	car->setMake(make.c_str());
	if (!car->getIsValid())
	{
		return;
	}

	printf("Please insert model of car\n");
	std::cin >> model;
	car->setModel(model.c_str());
	if (!car->getIsValid())
	{
		return;
	}

	printf("Please insert year of car\n");
	std::cin >> year;
	car->setYear(year);
	if (!car->getIsValid())
	{
		return;
	}

	printf("Please insert color of car\n");
	std::cin >> color;
	car->setColor(color.c_str());
}

void getRegularCarDetailes(RegularCar *regularCar)
{
	int volume = 0;

	getCarDetailes(regularCar);
	if (!regularCar->getIsValid())
	{
		return;
	}

	printf("Please insert engine volume of car\n");
	std::cin >> volume;
	regularCar->setEngineVolume(volume);
	if (!regularCar->getIsValid())
	{
		return;
	}
}

void getElectricCarDetailes(ElectricCar *electricCar)
{
	int batteryCapacity = 0;

	getCarDetailes(electricCar);
	if (!electricCar->getIsValid())
	{
		return;
	}

	printf("Please insert battery capacity of car\n");
	std::cin >> batteryCapacity;
	electricCar->setBatteryCapacity(batteryCapacity);
	if (!electricCar->getIsValid())
	{
		return;
	}
}