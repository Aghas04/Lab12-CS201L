// Your name
// Today's date
// Exam 2

#include <string>
#include "Employee.h"
using namespace std;

Employee::Employee(int id, string myName) {
	employeeID = id;
	name = myName;
}
void Employee::giveRaise(int rate) {
	double ratepercent = rate / 100.0;
	double current = payRate;
	double adds = (ratepercent * current);
	double final = (adds + current);
	payRate = final;
}