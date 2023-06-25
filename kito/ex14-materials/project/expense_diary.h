#pragma once
#include <vector>
#include <algorithm>
#include "record.h"

class Diary {
	std::vector<record> diary;
	int* sum;
public:
	int sort_field, order;

	Diary() : diary(), sort_field(2), order(0) { sum = new int[4]{ 0, 0, 0, 0 }; }
	~Diary() { delete[] sum; }
	Date cast_date(const std::string& time);
	int cast_int(const std::string& s);
	
	bool compare_record(const record& rc1, const record& rc2, int field, int order);

	int add_record(const int&, const int&, const std::string&, const std::string&);
	
	void display_diary(int show_type, int field, int order);
};

inline int Diary::cast_int(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;

	if (!s.empty() && it == s.end())
		return std::stoi(s);
	return 0;
}

Date Diary::cast_date(const std::string& time)
{
	size_t off = 0, count = time.find('/');
	int day = cast_int(time.substr(off, count));
	off += count + 1;
	count = time.find('/', off) - off;
	int month = cast_int(time.substr(off, count));
	off += count + 1;
	int year = cast_int(time.substr(off, 4));

	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day < 1 || day > 31)
			day = 0;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day < 1 || day > 30)
			day = 0;
		break;
	case 2:
		if (year % 4 == 0) {
			if (day < 1 || day > 29)
				day = 0;
		}
		else {
			if (day < 1 || day > 28)
				day = 0;
		}
		break;
	default:
		month = 0;
		break;
	}
	return Date(day, month, year);
}

inline bool Diary::compare_record(const record& rc1, const record& rc2, int field, int order)
{
	switch (field)
	{
	case 1:
		return (order ? (rc1.type > rc2.type) : (rc1.type < rc2.type));
	case 2:
		return (order ? (rc1.time > rc2.time) : (rc1.time < rc2.time));
	case 3:
		return (order ? (rc1.cost > rc2.cost) : (rc1.cost < rc2.cost));
	default:
		return false;
	}

}

int Diary::add_record(
	const int& type,
	const int& cost,
	const std::string& time,
	const std::string& note
) {

	if (type < 1 || type > 4)
		return -1;

	if (cost < 1000 || cost > 10000000)
		return -1;

	record rc;

	rc.time = cast_date(time);
	
	if (!rc.time.is_valid())
		return -1;

	rc.cost = cost;
	rc.note = note;
	rc.type = type;


	diary.insert(
		std::upper_bound(
			diary.begin(), 
			diary.end(), 
			rc, 
			[&](const record& rc1, const record& rc2) 
			{
				return this->compare_record(rc1, rc2, this->sort_field, this->order);
			}),
		rc
	);

	sum[rc.type - 1] += rc.cost;

	return 1;
}

void Diary::display_diary(int show_type,int field, int order)
{

	if (field != this->sort_field || order != this->order) {
		
		std::sort(diary.begin(), diary.end(),
			[&](const record& rc1, const record& rc2) {
				return this->compare_record(rc1, rc2, field, order);
			});

		this->sort_field = field;
		this->order = order;
	}

	std::cout << "|| show type: " << show_type << " || sort field: " << sort_field << " || order: " << order << " ||\n\n";

	if (show_type < 1 || show_type > 4) {
		for (const record& rc : diary)
			std::cout << rc << std::endl;
	}
	else {
		for (const record& rc : diary)
			if(rc.type == show_type)
				std::cout << rc << std::endl;
	}
}