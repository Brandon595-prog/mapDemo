#pragma once
#ifndef BRANDON_DANIELSON
#define BRANDON_DANIELSON 

#include <string> 
#include <map> 

struct Employee {
	std::string name; 
	std::string email; 
	std::string department;

}; 

int get_number(const std::string& prompt); 
int get_menu_choice(); 

void display_all(const std::map<int, Employee>& employees); 
void search_employees(const std::map<int, Employee>& employees); 

void add_employee(std::map<int, Employee>& employees);  
void update_employees(std::map<int, Employee>& employees);  
void remove_employees(std::map<int, Employee>& employees); 



#endif

