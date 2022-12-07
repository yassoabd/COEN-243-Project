#pragma once
#include <string>
#include <iostream>
using namespace std;

class Student
{
private:
	string first_name_;
	string last_name_;
	string id_;
	string date_of_birth_;
	float gpa_;
	int start_year_;
	int completed_credit_;
	char program_;

public:
	Student() {
		first_name_ = "NotAssigned";
		last_name_ = "NotAssigned";
		id_ = "000000";
		date_of_birth_ = "01/01/1900";
		gpa_ = 0.0;
		start_year_ = 1918;
		completed_credit_ = 0;
		program_ = 'B';
	};

	Student(string first, string last, string id,
		string dob, float gpa, int s_year,
		int credit, char prgm) :
		first_name_(first),
		last_name_(last),
		id_(id),
		date_of_birth_(dob),
		gpa_(gpa),
		start_year_(s_year),
		completed_credit_(credit),
		program_(prgm) {
	};

	inline void setFirstName(string fn) {
		first_name_ = fn;
	};

	inline string getFirstName() {
		return(first_name_);
	};

	inline void setLastName(string ln) {
		last_name_ = ln;
	};

	inline string getLastName() {
		return last_name_;
	};

	inline void setID(string id) {
		id_ = id;
	};

	inline string getID() {
		return id_;
	};

	inline void setDateOfBirth(string dob) {
		date_of_birth_ = dob;
	};

	inline string getDateOfBirth() {
		return date_of_birth_;
	};

	inline void setGPA(float gpa) {
		gpa_ = gpa;
	};

	inline float getGPA() {
		return gpa_;
	};

	inline void setStartYear(int sy) {
		start_year_ = sy;
	};

	inline int getStartYear() {
		return start_year_;
	};

	inline void setCompletedCredit(int cc) {
		completed_credit_ = cc;
	};

	inline int getCompletedCredit() {
		return completed_credit_;
	};

	inline void setProgram(char p) {
		program_ = p;
	};

	inline char getProgram() {
		return program_;
	};

	bool CompleteProgram();
	void Print_Std_Info();
	string StudentStatus();
	string Compare_GPA(Student& s);
};

