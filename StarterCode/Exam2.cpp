#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Employee.h"


int main() {
	/*Employee Employee1(101, "Alex");
	cout << Employee1.getPayRate() << endl;
	cout << Employee1.getBalance() << endl;
	cout << Employee1.getName() << endl;
	cout << Employee1.getEmployeeID() << endl;
	Employee1.giveRaise(5);
	Employee1.pay();
	cout << Employee1.getBalance() << endl;*/
	ifstream inFile("input.txt");
	vector<string> lines, words;
	vector<Employee> Employees;
	string line,word, name;
	int id;
	while (getline(inFile, line)) {
		lines.push_back(line);
	}
	for (int i = 0; i < lines.size(); i++) {
		words.clear();
		istringstream inST(lines[i]);
		while (inST >> word) {
			words.push_back(word);
		}
		if (words[0] == "NEW") {
			name = words[2] + " " + words[3];
			id = stoi(words[1]);
			Employee newEmployee(id,name);
			Employees.push_back(newEmployee);
		}
		else if (words[0] == "RAISE") {
			id = stoi(words[1]);
			for (int j = 0; j < Employees.size(); j++) {
				if (Employees[j].getEmployeeID() == id) {
					Employees[j].giveRaise(stoi(words[2]));
				}
			}
		}
		else if (words[0] == "PAY") {
			for (int j = 0; j < Employees.size(); j++) {
				Employees[j].pay();
				
			}
		}
		else if (words[0] == "FIRE") {
			id = stoi(words[1]);
			for (int j = 0; j < Employees.size(); j++) {
				if (Employees[j].getEmployeeID() == id) {
					Employees[j].fire();
				}
			}
		}
		
	}

	inFile.close();
	ofstream outFile("output.txt");


	for (int i = 0; i < Employees.size(); i++) {
		outFile << Employees[i].getName() << ", ID Number " << Employees[i].getEmployeeID() << ":" << endl;
		if (Employees[i].isEmployed()) {
			outFile << "Current pay rate: $" << Employees[i].getPayRate() << endl;
		}
		else {
			outFile << "Not employed with the company" << endl;
		}
		outFile << "Pay earned to date: $" << Employees[i].getBalance() << endl << endl;
	}
	outFile.close();
}