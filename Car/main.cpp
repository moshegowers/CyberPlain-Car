#include <string>
#include <iostream>
#include "Car.h"
using namespace CarNamespace;

void getCarDetailes(Car *car);

void main(void)
{
	Car car1;
	do
	{
		getCarDetailes(&car1);
	} while (!car1.getIsValid());

	Car car2;
	do
	{
		getCarDetailes(&car2);
	} while (!car2.getIsValid());
	
	car1.printCarDetailes();
	car2.printCarDetailes();
}

void getCarDetailes(Car *car)
{
	if (car == NULL)
	{
		return;
	}
	std::string make = "", model = "", color = "";
	int year = 0, volume = 0;

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

	printf("Please insert engine volume of car\n");
	std::cin >> volume;
	car->setEngineVolume(volume);
	if (!car->getIsValid())
	{
		return;
	}

	printf("Please insert color of car\n");
	std::cin >> color;
	car->setColor(color.c_str());
}