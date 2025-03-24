#pragma once
#include <iostream>
#include <vector>
#include "Matrix.h"

class Controller {
public:
	Controller();
	void run();

private:
	void eval();
	void add();
	void comp();
	void sub();
	void scal();
	void del();
	void help();




	std::vector<std::string> commandList;
	std::vector<Matrix> matList;
};