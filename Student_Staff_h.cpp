#pragma once
#include <string>
#include "Student.h"
#include "Staff.h"

class Student_Staff
{
public:
	Student_Staff();
	~Student_Staff();

	/**
	 * Function : Highest_GPA
	 * Description This function checks the array of students and its size
	 *              then prints out the information about the one who
	 *              has the highest GPA
	**/
	void Highest_GPA();

	/**
	 * Function: N_of_UnderGrad
	 * Description : This function checks the array of students, and size
	 *               and returns the total number of undergraduate students
	**/
	int N_of_UnderGrad();

	/**
	 * Function : Same_Hire_Year
	 * Description : This function searches the array of staff within its size
	 *               and compare to hiring year argument and prints out the name
	 *               of all staff who have been hired in that year.
	**/
	void Same_Hire_Year(int hire_year);

private:
	Student* std_ptr_;
	int std_array_size_;
	Staff* staff_ptr_;
	int staff_array_size_;
};
