#pragma once
#include <iostream>
#include <vector>
#include "CommandManage.h"
#include "Matrix.h"

class Controller {
public:
	Controller();
	void run();

private:
	



	CommandManage commandManager;
	
	std::vector<Matrix> matList;
};