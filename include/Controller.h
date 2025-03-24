#pragma once
#include <iostream>
#include <vector>

class Controller {
public:
	Controller();
	void run();

private:
	std::vector<std::string> commandList;
};