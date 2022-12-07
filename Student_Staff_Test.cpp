#include <string>
#include <iostream>
#include <filesystem>


#include "Staff.h"
#include "Student.h"
#include "Student_Staff.h"

int main() {

	// Testing Employee Class
	Staff e1;
	Staff e2;
	e1.setDateOfHiring("03/10/1997");
	e1.setFirstName("Pierre");
	e1.setLastName("Boulos");
	e2.setDateOfHiring("04/10/1997");
	e2.setFirstName("Tony");
	e2.setLastName("Stock");

	e1.Print_Staff_Info();
	e2.Print_Staff_Info();

	string name = e1.Compare_EXP(e2);
	cout << name << std::endl;

	// Testing Student Class
	Student s1;
	Student s2("Mahdi",
		"Abdallah",
		"345876",
		"20/02/2001",
		(float)3.6,
		2018,
		42,
		'B');
	s1.Print_Std_Info();
	s2.Print_Std_Info();

	// Testing Student_Staff class 
	Student_Staff ss;

	ss.Highest_GPA();
	ss.Same_Hire_Year(2012);
	ss.Same_Hire_Year(2013);
	ss.Same_Hire_Year(2015);
	ss.Same_Hire_Year(2016);
	cout << "The number of undergrad student is " << ss.N_of_UnderGrad() << std::endl;
}