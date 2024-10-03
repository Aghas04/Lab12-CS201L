#pragma once
// Your name
// Today's date
// Exam 2

#include <string>
#include <iostream>
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee
{
private:
	int employeeID;
	string name;
	double balance = 0.0;
	double payRate = 10.0;
	bool employed = true;
public:
	// Constructor
	Employee(int id, string myName);

	// Getter to return the employee ID
	int getEmployeeID() {
		return employeeID;
	}

	// Getter to return the current pay rate
	double getPayRate() {
		return payRate;
	}

	// Getter to return the current amount of pay earned
	double getBalance() {
		return balance;
	}

	// Getter to get Employee's name
	string getName() {
		return name;
	}

	// Function to give the raise. It takes in a percent in whole numbers 
	// (ex: 5 for 5%)
	void giveRaise(int rate);

	// Pays the employee
	void pay() {
		balance += payRate;
	}

	// Fires the Employee
	void fire() {
		employed = false;
		payRate = 0.0;
	}

	// Returns if the Employee is currently employed
	bool isEmployed() {
		return employed;
	}

};

#endif