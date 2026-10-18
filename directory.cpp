#include "directory.h" 
#include <map> 
#include <iostream> 
#include <iomanip> 
#include <limits>

using namespace std; 

int get_number(const string& prompt)
{
	int number; 
	while (true) 
	{
		cout << prompt; 
		if (cin >> number && number > 0) 
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			return number;
		} 

		cout << "Please enter a valid positive number\n"; 

		if (cin.eof()) {
			throw runtime_error("input stream closed!");
		}

		cin.clear(); 
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	}

} 
int get_menu_choice() {

	cout << "\nEMPLOYEE DIRECTORY\n"
		<< "------------------------------\n" 
		<< "1. Display all employees\n" 
		<< "2. search by employee id\n" 
		<< "3. add employee\n" 
		<< "4. remove employee\n" 
		<< "5. Remove employee\n" 
		<< "6. Exit\n\n"; 
		
		int choice; 
		while (true) {
			choice = get_number("Choice: "); 

			if (choice >= 1 && choice <= 6) 
			{
				return choice;
			} 

			cout << "Please choose and option from 1 to 6!\n";
		
		} 
} 

string get_required_text(const string& prompt) {

	string text; 
	while (true) {
		cout << prompt; 
		if (!getline(cin, text)) {
			throw runtime_error("input stream closed!\n");
		} 

		if (text.find_first_not_of(" \t") != string::npos) 
		{
			return text;
		} 

		cout << "this field cannot be empty!\n";
	}
}

void display_all(const map<int, Employee>& employees) 
{
cout << "EMPLOYEE DIRECTORY\n" 
 	<< "----------------------------\n"; 

 	if (employees.empty()){
		cout << "No employees found!\n"; 
		return;
 	} 

 	int length = 25; 

 	cout << left << setw(5) << "ID" << setw(length) << "Name" << setw(length) << "Department" << setw(length) << "Email\n\n"; 

 	for (const auto& employee : employees) {
 		cout << left << setw(5) << employee.first << setw(length) << employee.second.name << setw(length) << employee.second.department 
 		<< setw(length) << employee.second.email << endl; 

	
 	}
}


void search_employees(const map<int, Employee>& employees) 
{

	int id = get_number("Enter an employee id: "); 
	auto iter = employees.find(id); // create an interator to point to and find id in map 

	if (iter == employees.end()){
		cout << "Employee not found!\n"; 
		return;
	} 

	cout << "Employee found: \n" 
		<< "ID: " << iter->first << endl 
		<< "Name: " << iter->second.name << endl 
		<< "Department: " << iter->second.department << endl 
		<< "Email: " << iter->second.email << endl;
} 


void update_employees( map<int, Employee>& employees){
	int id = get_number("Enter employee id to delete: \n"); 


	if (!employees.contains(id)) {
                 cout << "That employee id doesn't exists!\n"; 
                 return;
         } 
         
         cout << "\nCurrently employee: " << employees.at(id).name << endl;
         cout << "\nCurrent department: " << employees.at(id).department << endl;
         cout << "\nCurrent email: " << employees.at(id).email << endl;   

         employees.at(id).department = get_required_text("Enter new department: "); 
         employees.at(id).email = get_required_text("Enter new email: "); 
         
         cout << "Employee updated succesfully!\n"; 

}  
void add_employee( map<int, Employee>& employees) 
{

	int id = get_number("Enter new employee ID: "); 

	if (employees.contains(id)) {
		cout << "That employee id already exists!\n"; 
		return;
	} 

	Employee employee; 

	employee.name = get_required_text("Enter employee name: "); 
	employee.department = get_required_text("Enter their department: "); 
	employee.email = get_required_text("Enter employee email: "); 
	
	employees.insert({id, employee}); 
	
	cout << "Employee added successully\n";  

} 
void remove_employees( map<int, Employee>& employees) {
	int id = get_number("Enter employee id to remove: "); 
	int removed = employees.erase(id); 

	if (removed > 0) {
		cout << "Employee removed successfully!\n";
	} else {
		cout << "Employee was not found or erased!\n";
	}
} 


