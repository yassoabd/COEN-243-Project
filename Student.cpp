#include "Student.h"
// CompleteProgram function
bool Student::CompleteProgram()
{
	bool complete = false;
	if ((program_ == 'B' && completed_credit_ >= 140) ||
		(program_ == 'M' && completed_credit_ >= 16) ||
		(program_ == 'P' && completed_credit_ >= 12))
		complete = true;

	return complete;
}

//StudentStatus function
string Student::StudentStatus()
{
	string status = "";
	if (gpa_ >= 3.5)
		status = "A+";
	else if (gpa_ >= 3 && gpa_ > 3.5)
		status = "A";
	else if (gpa_ >= 2.5 && gpa_ < 3)
		status = "B";
	else if (gpa_ >= 2 && gpa_ < 2.5)
		status = "C";
	else
		status = "D";
	return status;
}

// Print_Std_Info function
void Student::Print_Std_Info()
{
	cout << "First name       : " << first_name_ << endl;
	cout << "Last name        : " << last_name_ << endl;
	cout << "Student ID       : " << id_ << endl;
	cout << "Date of Birth    : " << date_of_birth_ << endl;
	cout << "GPA              : " << gpa_ << endl;
	cout << "Start year       : " << start_year_ << endl;
	cout << "Completed credit : " << completed_credit_ << endl;
	cout << "Program          : ";
	if (program_ == 'B')
		cout << "Bachelor" << endl;
	else if (program_ == 'M')
		cout << "Master" << endl;
	else
		cout << "Ph.D" << endl;
	cout << endl;
}

// Compare_GPA function
string Student::Compare_GPA(Student& s)
{
	if (gpa_ >= s.getGPA())
		return id_;
	else
		return s.getID();
}
