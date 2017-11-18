#include <string>
#include <iostream>
#include "RegularCar.h"
#include "ElectricCar.h"
#include "Garage.h"
using namespace CarNamespace;

void getCarDetailes(Car *car);
void getRegularCarDetailes(RegularCar *regularCar);
void getElectricCarDetailes(ElectricCar *electricCar);
void addCarToGarage(Garage garage);
void removeCarFromGarage(Garage garage);
void searchCarInGarage(Garage garage);
void printAllCarsInGarage(Garage garage);
void clearScreen();

void main(void)
{
	Garage garage;
	std::string userInput;
	while (true)
	{
		std::cout << "\n*** Welcome to my garage ***\n" << std::endl;
		std::cout << "Please insert \"add\" for adding your car to garage" << std::endl;
		std::cout << "Please insert \"remove\" for removing your car from garage" << std::endl;
		std::cout << "Please insert \"search\" for search your car in garage" << std::endl;
		std::cout << "Please insert \"print\" for printing all cars in garage" << std::endl;
		std::cout << "Please insert \"quit\" for quit from program\n\n" << std::endl;

		userInput = "";
		std::cin >> userInput;

		switch (userInput[0])
		{
		case 'a':
			addCarToGarage(garage);
			break;
		case 'r':
			removeCarFromGarage(garage);
			break;
		case 's':
			searchCarInGarage(garage);
			break;
		case 'p':
			printAllCarsInGarage(garage);
			break;
		case 'q':
			return;
		default:
			break;
		}
	}
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

void addCarToGarage(Garage garage)
{
	size_t carType;
	Car *car;
	do
	{
		std::cout << "Please insert type of car. (use " << CarType::Regular << " for refular car or " << CarType::Electric << " for electric car.\n";
		std::cin >> carType;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (carType != CarType::Regular && carType != CarType::Electric);

	if (carType == CarType::Regular)
	{
		car = new RegularCar;
		do
		{
			car->setIsValid(true);
			getRegularCarDetailes(dynamic_cast<RegularCar*>(car));
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (!car->getIsValid());
	}
	else if (carType == CarType::Electric)
	{
		car = new ElectricCar;
		do
		{
			car->setIsValid(true);
			getElectricCarDetailes(dynamic_cast<ElectricCar*>(car));
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (!car->getIsValid());
	}

	if (NULL != car)
	{
		garage.addCarToGarage(car);
		car->printCarDetailes();
	}
	else
	{
		std::cout << "Adding your car failed" << std::endl;
	}
}

void removeCarFromGarage(Garage garage)
{
	size_t licenseNum = 0;
	std::cout << "Please insert license num of car.\n";
	std::cin >> licenseNum;
	garage.removeCarFromGarage(licenseNum);
}

void searchCarInGarage(Garage garage)
{
	size_t licenseNum = 0;
	std::cout << "Please insert license num of car.\n";
	std::cin >> licenseNum;
	Car *car = garage.findCarInGarage(licenseNum);
	if (NULL != car)
	{
		car->printCarDetailes();
	}
	else
	{
		std::cout << "The car with license num \"" << licenseNum << "\" not found.\n";
	}
}

void printAllCarsInGarage(Garage garage)
{
	garage.printAllCarsInGarage();
}

void clearScreen()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
