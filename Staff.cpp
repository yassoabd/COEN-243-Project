#include "Staff.h"
// Staff.cpp : This file contains the 'main' function of Saff.h . Program execution begins and ends there.
#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
const float kABonusRate = (float)0.08;
const float kBBonusRate = (float)0.06;
const float kCBonusRate = (float)0.03;
const float kDBonusRate = (float)0.01;
const float kEBonusRate = (float)0.00;

// setter functions
Staff::Staff(string firstname, string lastname, string id,
	string phonenumber, string datehiring, char bonuscode,
	float currentsalary) {
	first_name = firstname;
	last_name = lastname;
	ID = id;
	phone_number = phonenumber;
	date_of_hiring = datehiring;
	bonus_code = bonuscode;
	current_salary = currentsalary;
}

void Staff::setFirstName(string firstname)
{
	first_name = firstname;
}

void Staff::setLastName(string lastname)
{
	last_name = lastname;
}

void Staff::setID(string id)
{
	ID = id;
}

void Staff::setPhoneNumber(string phonenumber)
{
	phone_number = phonenumber;
}

void Staff::setDateOfHiring(string datehiring)
{
	date_of_hiring = datehiring;
}

void Staff::setBonusCode(char bonuscode)
{
	bonus_code = bonuscode;
}

void Staff::setCurrentSalary(float currentsalary)
{
	current_salary = currentsalary;
}

// getter functions
string Staff::getFirstName() const
{
	return first_name;
}

string Staff::getLastName() const
{
	return last_name;
}

string Staff::getID() const
{
	return ID;
}

string Staff::getPhoneNumber() const
{
	return phone_number;
}

string Staff::getDateOfHiring() const
{
	return date_of_hiring;
}

char Staff::getBonusCode() const
{
	return bonus_code;
}

float Staff::getCurrentSalary() const
{
	return current_salary;
}

// function that prints out all the information of that student (all the attributes).
void Staff::Print_Staff_Info() const
{
	cout << "First name     : " << first_name << endl;
	cout << "Last name      : " << last_name << endl;
	cout << "Employee ID    : " << ID << endl;
	cout << "Phone number   : " << phone_number << endl;
	cout << "Date of hiring : " << date_of_hiring << endl;
	cout << "BonusCode      : " << bonus_code << endl;
	cout << "Current salary : " << "$" << current_salary << endl;
	cout << endl;
}

// function that calculates new salary based on the bonus code

float Staff::Calculate_Salary() const
{
	float result = 0.0;
	switch (bonus_code) {
	case 'A':
		result = kABonusRate * current_salary;
		break;
	case 'B':
		result = kBBonusRate * current_salary;
		break;
	case 'C':
		result = kCBonusRate * current_salary;
		break;
	case 'D':
		result = kDBonusRate * current_salary;
		break;
	case 'E':
		result = kEBonusRate * current_salary;
		break;

	}
	return (current_salary + result);
}

// function that takes as inputs the Employee's objects and compares thheir experience. Who was hired first has more experience.
string Staff::Compare_EXP(const Staff& s)
{
	// date of hire format is DD/MM/YYYY
	stringstream date_e1(date_of_hiring);
	stringstream date_e2(s.getDateOfHiring());
	string name;
	int hire_year_e1, hire_month_e1, hire_day_e1;
	int hire_year_e2, hire_month_e2, hire_day_e2;
	char delimiter;
	date_e1 >> hire_day_e1 >> delimiter >> hire_month_e1 >> delimiter >> hire_year_e1;
	date_e2 >> hire_day_e2 >> delimiter >> hire_month_e2 >> delimiter >> hire_year_e2;

	if (hire_year_e1 < hire_year_e2)
		name = first_name;
	else if (hire_year_e1 > hire_year_e2)
		name = s.getFirstName();
	else { // SAME HIRE YEAR SO CHECK THE MONTH
		if (hire_month_e1 < hire_month_e2)
			name = first_name;
		else if (hire_month_e1 > hire_month_e2)
			name = s.getFirstName();
		else { // same hire month so check the day
			if (hire_day_e1 < hire_day_e2)
				name = first_name;
			else if (hire_day_e1 > hire_day_e2)
				name = s.getFirstName();
		}
	}

	return name;
}

