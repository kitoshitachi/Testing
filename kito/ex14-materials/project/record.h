#pragma once

#include "datetime.h"

class record
{
public:
	int type;
	int cost;
	Date time; // dd/mm/yyyy
	std::string note;

	record() : type(0), cost(0), time(Date()) {}

	record(int type, int cost, const Date& time, const std::string& note)
		: type(type), cost(cost), time(time), note(note) {}

	friend std::ostream& operator<<(std::ostream& os, const record& rc);

	bool operator==(const record& other) const
	{
		return type == other.type && cost == other.cost && time == other.time && note == other.note;
	}
};

inline std::ostream& operator<<(std::ostream& os, const record& rc)
{
	os << rc.type << ' ' << rc.cost << ' ' << rc.time << ' ' << rc.note;
	return os;
}
