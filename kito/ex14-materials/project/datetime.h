#pragma once

#include <iostream>
#include <string>

class Date {
public:
	std::string day, month, year;

	bool operator==(const Date& other) const
	{
		return day == other.day && month == other.month && year == other.year;
	}

	std::string cast_string(int number);

	bool is_valid() {
		if (year.length() != 4)
			return 0;

		if (day == "00" || month == "00")
			return 0;

		return 1;
	}

	friend std::ostream& operator<<(std::ostream& os, const Date& dt);

	bool operator<(const Date& dt) const;
	bool operator>(const Date& dt) const;

	Date(int day, int month, int year);

	Date() = default;

	Date(const std::string& day, const std::string& month, const std::string& year)
		: day(day), month(month), year(year)
	{
	}
};

inline std::string Date::cast_string(int number)
{
	std::string temp = std::to_string(number);

	if (temp.length() == 1)
		return '0' + temp;
	
	return temp;
}

inline Date::Date(int day, int month, int year)
{
	this->day = cast_string(day);
	this->month = cast_string(month);
	this->year = std::to_string(year);
}

inline std::ostream& operator<<(std::ostream& os, const Date& dt)
{
	os << dt.day << '/' << dt.month << '/' << dt.year;
	return os;
}
//20240229 > 20230202
inline bool Date::operator<(const Date& dt) const
{
	return (this->year + this->month + this->day > dt.year + dt.month + dt.day);
}

inline bool Date::operator>(const Date& dt) const
{
	return (this->year + this->month + this->day < dt.year + dt.month + dt.day);
}