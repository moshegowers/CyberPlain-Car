#ifndef CAR_H
#define CAR_H

#define MAX_YEAR 2017
#define MAX_VOLUME 3500

class Car {
public:
	Car();

	//copy cunstructor
	Car(const Car &car);

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

	// return engine volume of car
	size_t getEngineVolume() const;
	// assine engine volume of car
	void setEngineVolume(int engineVolume);

	// return color of car
	char *getColor();
	// assine color of car
	void setColor(const char *color);

	// return if car detailes is valid
	bool getIsValid() const;

	void printCarDetailes();

	//return the greater car, compare it by year of car
	static const Car& compareTowCarsByYear(const Car &lhs, const Car &rhs);

	//return the greater car, compare it by engine volume of car
	static const Car& compareTowCarsByVolume(const Car &lhs, const Car &rhs);

private:
	char	m_make[10];
	char	m_model[10];
	size_t	m_year;
	size_t	m_engineVolume;
	char	m_color[10];
	bool	m_isValid;
};

#endif