#include "Engine.h"

#ifndef CAR_H
#define CAR_H

#define MAX_YEAR 2017
#define MIN_YEAR 1950
namespace CarNamespace
{
	class Car {
	public:
		Car();

		//copy cunstructor
		Car(const Car &car);

		int getLicenseNum();

		// return company make name of car
		char *getMake();
		// assine company make name of car
		void setMake(const char *make);

		// return model of car
		char *getModel();
		// assine model of car
		void setModel(const char *model);

		// return product year of car
		size_t getYear() const;
		// assine product year of car
		void setYear(int year);

		// return color of car
		char *getColor();
		// assine color of car
		void setColor(const char *color);

		// return if car detailes is valid
		bool getIsValid() const;
		// assine is valid car detailes
		void setIsValid(bool isValid);

		Engine* getEngine() const;

		void setEngine(Engine *engine);

		EngineType getCarDetailes();
		virtual void printCarDetailes();

		//return the greater car, compare it by year of car
		static const Car& compareTowCarsByYear(const Car &lhs, const Car &rhs);

	protected:
		bool	m_isValid;

	private:
		int		m_licenseNum;
		char	m_make[10];
		char	m_model[10];
		size_t	m_year;
		char	m_color[10];
		Engine  *m_engine;

		static int	s_licenseNum;
	};
}

#endif