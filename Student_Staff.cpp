#include "Student_Staff.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const string kStudentFile("student.txt");
const string kStaffFile("staff.txt");

//constructor
Student_Staff::Student_Staff() {
	//need to open two files student.txt
	// and staff.txt.
	// first line has the number of line in the file
	// aka the number of student/staff info
	std_ptr_ = nullptr;
	staff_ptr_ = nullptr;
	std_array_size_ = 0;
	staff_array_size_ = 0;
	int line_num = 0;
	ifstream std_infile;
	ifstream staff_infile(kStaffFile);
	string stringLine;
	istringstream sstring;

	std_infile.open(kStudentFile);
	if (std_infile) {
		while (getline(std_infile, stringLine)) {
			// cout << stringLine << endl;
			istringstream  sstring(stringLine);
			if (line_num == 0) {
				// found the line #
			   // get how many lines of student there is in the file
				sstring >> std_array_size_;
				if (sstring.fail())
					cout << kStudentFile << " line_number " << line_num << " has an error" << endl;
				else if (std_array_size_ > 0) {
					cout << "Allocating student array of size " << std_array_size_ << endl;
					std_ptr_ = new Student[std_array_size_];
				}
			}
			else {
				string first, last, id, dob;
				float gpa;
				int credit, year;
				char program;
				// fill in the student data
				sstring >> first >> last >> id >> dob
					>> gpa >> year >> credit >> program;
				// cout << first << " "<<  last << "  " <<  id << "  " << dob << "  "
				//	  <<  gpa << " " <<  year  << "   " <<  credit << "   " << program <<  endl;

				if (sstring.fail())
					cout << kStudentFile << ": line number " << line_num << " has an error " << endl;
				if (std_ptr_) {
					std_ptr_[line_num - 1].setFirstName(first);
					std_ptr_[line_num - 1].setLastName(last);
					std_ptr_[line_num - 1].setID(id);
					std_ptr_[line_num - 1].setDateOfBirth(dob);
					std_ptr_[line_num - 1].setGPA(gpa);
					std_ptr_[line_num - 1].setStartYear(year);
					std_ptr_[line_num - 1].setCompletedCredit(credit);
					std_ptr_[line_num
						- 1].setProgram(program);
				}
			}
			line_num++;
		}
		std_infile.close();
	}
	else {
		cout << "could not open the file " << kStudentFile << endl;
	}

	line_num = 0;
	if (staff_infile.is_open()) {
		while (getline(staff_infile, stringLine)) {
			istringstream sstring(stringLine);
			if (line_num == 0) {
				// found the line #
				// get how many lines of staff there is in the file
				sstring >> staff_array_size_;
				if (sstring.fail())
					cout << kStaffFile << " line_number " << line_num << " has an error" << endl;
				else if (staff_array_size_ > 0) {
					cout << "Allocating staff array of size " << staff_array_size_ << endl;
					staff_ptr_ = new Staff[staff_array_size_];
				}
			}
			else {
				string first, last, id, ph_no, doh;
				float salary;
				char bonus;
				// fill in the student data
				sstring >> first >> last >> id >> ph_no >> doh
					>> bonus >> salary;
				if (sstring.fail())
					cout << kStaffFile << " line number " << line_num << " has an error " << endl;
				if (staff_ptr_) {
					staff_ptr_[line_num - 1].setFirstName(first);
					staff_ptr_[line_num - 1].setLastName(last);
					staff_ptr_[line_num - 1].setID(id);
					staff_ptr_[line_num - 1].setDateOfHiring(doh);
					staff_ptr_[line_num - 1].setBonusCode(bonus);
					staff_ptr_[line_num - 1].setCurrentSalary(salary);
					staff_ptr_[line_num - 1].setPhoneNumber(ph_no);
				}
			}
			line_num++;
		}
		staff_infile.close();
	}
	else {
		cout << "could not open the file " << kStaffFile << endl;
	}

	cout << "number of student read is " << std_array_size_ << endl;
	for (int i = 0; i < std_array_size_; i++) {
		std_ptr_[i].Print_Std_Info();
	}
	cout << "number of staff read is " << staff_array_size_ << endl;
	for (int i = 0; i < staff_array_size_; i++) {
		staff_ptr_[i].Print_Staff_Info();
	}

};

// destructor
Student_Staff::~Student_Staff() {
	if (std_ptr_)
		delete[] std_ptr_;
	if (staff_ptr_)
		delete[] staff_ptr_;
}

void Student_Staff::Highest_GPA() {
	// check who has highest gpa among all student
	float highest_gpa = 1.0;
	for (int i = 0; i < std_array_size_; i++) {
		if (std_ptr_[i].getGPA() > highest_gpa)
			highest_gpa = std_ptr_[i].getGPA();
	}
	cout << "The highest gpa is " << highest_gpa << std::endl;
};

int Student_Staff::N_of_UnderGrad() {
	int no_of_undergrad = 0;
	for (int i = 0; i < std_array_size_; i++) {
		if (std_ptr_[i].getProgram() == 'B')
			no_of_undergrad++;
	}
	return no_of_undergrad;
};

void Student_Staff::Same_Hire_Year(int year) {
	bool found = false;
	cout << "the following employees were hired in year " << year
		<< std::endl;
	for (int i = 0; i < staff_array_size_; i++) {
		string hire_year = staff_ptr_[i].getDateOfHiring().substr(6, 4);
		if (hire_year.compare(to_string(year)) == 0) {
			cout << staff_ptr_[i].getFirstName() << " "
				<< staff_ptr_[i].getLastName() << std::endl;
			found = true;
		}
	}
	if (found == false)
		cout << "<No-One>" << endl;
	cout << endl;
};