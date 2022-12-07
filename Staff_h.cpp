#pragma once

#include <iostream>
#include <string>

using namespace std;

class Staff {
private:
	// attributes
	string first_name;
	string last_name;
	string ID;
	string phone_number;    // format xxx-xxx-xxxx
	string date_of_hiring;  // format DD/MM/YYYY
	char bonus_code;
	float current_salary;

public:
	// Default constructor
	Staff() {
		first_name = "";
		last_name = "";
		ID = "12345";
		phone_number = "000-000-0000";
		date_of_hiring = "01/03/1970";
		bonus_code = 'E';
		current_salary = 0;
	};

	// constructor with init data
	Staff(string firstname, string lastname, string id, string phonenumber, string datehiring, char bonuscode, float currentsalary);

	// Destructor
	~Staff() {};

	void setFirstName(string firstname);
	void setLastName(string lastname);
	void setID(string id);
	void setPhoneNumber(string phonenumber);
	void setDateOfHiring(string datehiring);
	void setBonusCode(char bonuscode);
	void setCurrentSalary(float currentsalary);

	//GETTERS
	string getFirstName()const;
	string getLastName()const;
	string getID()const;
	string getPhoneNumber()const;
	string getDateOfHiring()const;
	char getBonusCode()const;
	float getCurrentSalary()const;

	void Print_Staff_Info() const;
	float Calculate_Salary() const;
	string Compare_EXP(const Staff& s);
};

