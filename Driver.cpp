/****************************************************************
Program: Budget Buddy (Driver File)
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

int main(int argc, char* argv[]) //needs []
{
	char* user_file = argv[1];
	char* budget_file = argv[2];
	//login function

	//open_user_info(user_file, count, array);
	//open_budget_info(budget_file, count, array);
	int total_users = 0;
	create_users(total_users);
	//get_user_info(users, count, file);
	int total_budgets = 0;
	create_budgets(total_budgets);
	//get_budget_data(budgets, count, file);
	int total_transactions = 0;
	create_transactions(total_transactions);
	//get_transaction_data(transactions, count, file);
	//print_info(users, count, budgets);
	int num_budgets = 0;
	//delete_info(users, budgets, num_budgets);
	/*
	while (fails < 3){
	ask for login details;
	if successful, fails = 4;
	if fails == 3, print error, quit program;
	}

	while(true){
	display options for sorting
	call functions depending on the option selected
	}
	*/
	return 1;
}
