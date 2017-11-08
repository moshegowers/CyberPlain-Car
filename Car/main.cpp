#include <string>
#include <iostream>
#include "Car.h"

void getCarDetailes(Car *car);

void main(void)
{
	/*Car car1;
	do
	{
		getCarDetailes(&car1);
	} while (!car1.getIsValid());

	Car car2;
	do
	{
		getCarDetailes(&car2);
	} while (!car2.getIsValid());
	
	Car car3 = Car::compareTowCarsByYear(car1, car2);
	car3.printCarDetailes();*/

	Car *cars = new Car[10];
	Car car;
	getCarDetailes(&car);
	for (size_t i = 0; i < 10; i++)
	{
		cars[i] = car;
	}

	for (size_t i = 0; i < 10; i++)
	{
		cars[i].printCarDetailes();
	}
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