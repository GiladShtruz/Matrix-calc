#pragma once
#include <iostream>
#include <fstream> 
#include <string>
#include <vector>


class CommandManage {
public:
	CommandManage();
	void printList();
	void eval();
	void add();
	void comp();
	void sub();
	void scal();
	void del();
	void help();


private:
	std::vector<std::string> commandList;

	void addBracketsIfNeed(std::string& command);
	void readCommand(int commandIndex, int matOrder);



};