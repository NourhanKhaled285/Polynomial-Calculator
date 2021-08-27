#include<iostream>
using namespace std;
#include "Header.h"
#include <string>

int main() {
	poly_list y;
	string choice_operation;
	int choice = 0;

	cout << "Please Enter add if you want addition operation or sub for subtraction operation or mul for multiplication.\n";
	cin >> choice_operation;
	if (choice_operation == "add") {
		choice = 1;

	}
	else if (choice_operation == "sub") {
		choice = 2;
	


	}

	else if (choice_operation == "mul") {
		choice = 3;

	}
	else {
		cout << "invalid choice";
		return 0;
	}

	y.insert_polynominal_1();
	y.insert_polynominal_2();
	
	if (choice == 1) {
		y.add_poly();
	}

	else if (choice==2) {
		y.sub_poly();

	}
	else {
		y.multi_poly();
	}
	return 0;
	
}
