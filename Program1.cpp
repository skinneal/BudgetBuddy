/****************************************************************
Program: Budget Buddy (Implementation File)
Author: Allison Skinner
Date: 1/9/2020
Description: Allows users to log in to see their account, 
as well as import transactions and allow the users to filter them 
based on category, cost, or date
Input: .txt files, strings, ints, command line arguments
Output: .txt files, strings, ints
******************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

#include "./Program1.h"

//login function
//int username
//string password
/*
string login() {
	int login_attempt = 0;
	if (login_attempt == 3) {
		cout << "Login Failed 3 Times. Program will exit.";
		return 0;
	}
}
*/

/*
bool login(int user_total, user* array) {
	cout << "Welcome to Budget Buddy" << endl;
	cout << "Username: ";
	int username;
	cin >> username;
	for (int i = 0; i < user_total; i++) {
		if (array[i].id == username) {
			string password;
			cout << "Password: ";
			cin >> password;

			if (array[i].password == password) {
				cout << "Hello, " << array[i].name << endl;
				cout << "Username: " << array[i].id << endl;
				cout << "Current Balance: " << endl;
			}
		}
	}
	return true;
}
*/

/*
//successful login
void display_info_choice (char* filename) {
	int choice = 0; int print_choice = 0;
	cout << "Sort transactions by category (1), sort transactions by date (2), sort transactions by cost (3), or exit the program (4)? ";
	cin >> choice;
	if (choice == 1) { //category
		cout << "Print info to screen (1) or write to file (2)? ";
		cin >> print_choice;
		if (print_choice == 1) { //print to screen
		}
		if (print_choice == 2) { //print to file
			cout << "Enter file name that you want to print to (be sure to include file extension) ";
			cin >> *filename;
			//break;
		}
	}
	if (choice == 2) { //date
		cout << "Print info to screen (1) or write to file (2)? ";
		cin >> print_choice;
		if (print_choice == 1) { //print to screen
			//print
		}
		if (print_choice == 2) { //print to file
			cout << "Enter file name that you want to print to (be sure to include file extension) ";
			cin >> *filename;
			//break;
		}
	}
	if (choice == 3) { //cost
		cout << "Print info to screen (1) or write to file (2)? ";
		cin >> print_choice;
		if (print_choice == 1) { //print to screen
			//print
		}
		if (print_choice == 2) { //print to file
			cout << "Enter file name that you want to print to (be sure to include file extension) ";
			cin >> *filename;
			//break;
		}
	}
	if (choice == 4) { //exit program
		return 0;
	}
}
*/

/*********************************************************
Function: open_budget_info
Description: opens budget file
Parameters: char* budget_file, int* count, budget** array
Pre-Conditions: .txt file is found
Post-Conditions: .txt file is opened
*********************************************************/

void open_budget_info(char* budget_file, int* count, budget** array) {
	ifstream in_file;
	in_file.open(budget_file);
	in_file >> *count;

	*array = create_budgets(*count);
	get_budget_data(*array, *count, in_file);

	in_file.close();
}

/*********************************************************
Function: open_user_info
Description: opens user file
Parameters: char* user_file, int* count, user** array
Pre-Conditions: .txt file is found
Post-Conditions: .txt file is opened
*********************************************************/

void open_user_info(char* user_file, int* count, user** array) {
	ifstream in_file; 
	in_file.open(user_file);
	in_file >> *count;

	*array = create_users(*count);
	get_user_info(*array, *count, in_file);

	in_file.close();
}

/*********************************************************
Function: create_users
Description: allocate array for users of requested size
Parameters: int total_users
Pre-Conditions: get requested size
Post-Conditions: allocate enough space for array
*********************************************************/

user* create_users(int total_users) {
	user* array_of_users = new user[total_users];
	return array_of_users;
}

/*********************************************************
Function: get_user_info
Description: fill struct with user info from users.txt
Parameters: user* users, int count, ifstream& file
Pre-Conditions: .txt file exists, read .txt file
Post-Conditions: fill struct with user info
*********************************************************/

void get_user_info(user* users, int count, ifstream& file) {
	for (int i = 0; i < count; i++) {
		file >> users[i].name >> users[i].id >> users[i].password;
	}
}

/*********************************************************
Function: create_budgets
Description: allocate array for budgets of requested size
Parameters: int total_budgets
Pre-Conditions: get requested size
Post-Conditions: allocate enough space for array
*********************************************************/

budget* create_budgets(int total_budgets) {
	struct budget* array_of_budgets = new budget[total_budgets];
	return array_of_budgets;
}

/*********************************************************
Function: get_budget_data
Description: fill struct with budget info from budgets.txt
Parameters: budget* budgets, int count, ifstream& file
Pre-Conditions: .txt file exists, read .txt file
Post-Conditions: fill struct with budget info
*********************************************************/

void get_budget_data(budget* budgets, int count, ifstream& file) {
	string id;
	for (int i = 0; i < count; i++) {
		file >> budgets[i].id >> budgets[i].balance >> budgets[i].num_transactions;
			budgets[i].id = atoi(id.c_str());
	}
}

/*********************************************************
Function: create_transactions
Description: allocates array of transactions of requested size
Parameters: int total_transactions
Pre-Conditions: get requested size
Post-Conditions: allocate enough space for array
*********************************************************/

transaction* create_transactions(int total_transactions) {
	struct transaction* array_of_transactions = new transaction[total_transactions];
	return array_of_transactions;
}

/*********************************************************
Function: get_transaction_data
Description: fill struct with transaction info from budgets.txt
Parameters: transaction* transactions, int count, ifstream& file
Pre-Conditions: .txt file exists, read .txt file
Post-Conditions: fill struct with transaction info
*********************************************************/

void get_transaction_data(transaction* transactions, int count, ifstream& file) {
	for (int i = 0; i < count; i++) {
		file >> transactions[i].date >> transactions[i].amount >> transactions[i].description >> transactions[i].category;
	}
}

/*********************************************************
Function: print_info
Description: prints user and budget info
Parameters: user* users, int count, budget* budgets
Pre-Conditions: have user and budget info
Post-Conditions: prints user and budget info
*********************************************************/

void print_info(user* users, int count, budget* budgets) {
	cout << count << endl;
	for (int i = 0; i < count; i++) {
		cout << budgets[i].id << " ";
		cout << budgets[i].balance << " ";
		cout << budgets[i].num_transactions << endl;
		for (int j = 0; j < budgets[i].num_transactions; j++) {
			cout << budgets[i].t[j].date << " ";
			cout << budgets[i].t[j].amount << " ";
			cout << budgets[i].t[j].description << " ";
			cout << budgets[i].t[j].category << endl;
		}
	}
}

/*********************************************************
Function: delete_info
Description: deletes all dynamically allocated memory
Parameters: user** users, budget** budgets, int num_budgets
Pre-Conditions: dynamic memory used
Post-Conditions: deletes all dynamic memory used
*********************************************************/

void delete_info(user** users, budget** budgets, int num_budgets) {
	for (int i = 0; i < num_budgets; i++) {
		delete[] budgets[i]->t;
	}
	delete [] users;
	delete [] budgets;
	//delete [] transaction;
}



