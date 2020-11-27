/****************************************************************
Program: Budget Buddy (Interface File)
Author: Allison Skinner
Date: 1/9/2020
Description: Allows users to log in to see their account,
as well as import transactions and allow the users to filter them
based on category, cost, or date
Input: .txt files, strings, ints, command line arguments
Output: .txt files, strings, ints
******************************************************************/

//user struct for reading member info from the users.txt file
struct user {
	int count; //number of users in file
	string name; //username
	int id; //user id
	string password; //user password
};

//budget struct for holding info from the budgets.txt file
struct budget {
	//int count; //number of budgets in file
	int id; //budget id#
	float balance; //budget balance
	int num_transactions; //number of transactions
	struct transaction *t;
};

//transaction struct that budget struct points to
struct transaction {
	//int count; //number of transactions
	float amount; //transaction amount
	string date; //date of transaction
	string category; //transaction category
	string description; //transaction description
};

//login
void open_budget_info(char*, int*, struct budget**); //opens budget file
void open_user_info(char*, int*, struct user**); //opens user file
user* create_users(int); //dynamically allocate an array of users of the requested size
void get_user_info(user*, int, ifstream&); //fill a user struct with info that is read in from users.txt
budget* create_budgets(int); //dynamically allocate an array of budgets of the requested size
void get_budget_data(struct budget*, int, ifstream&); //fill a budget struct with info that is read in from budgets.txt
transaction* create_transactions(int); //dynamically allocate an array of transactions of the requested size
void get_transaction_data(transaction*, int, ifstream &); //fill a transaction struct with info that is read in from budgets.txt
void print_info(user*, int, budget*); //prints user and budget info
void delete_info(user**, budget**, int); //delete all the memory that was dynamically allocated

