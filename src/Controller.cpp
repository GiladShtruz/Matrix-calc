#include "Controller.h"
#include "Controller.h"
#include "Controller.h"
#include "Controller.h"
#include "Controller.h"
#include "Controller.h"
#include "Controller.h"
#include "Controller.h"
#include <fstream> 
#include <string>

using std::cin;
using std::cout;
using std::endl;



Controller::Controller()
{
	commandList.push_back("id");
	commandList.push_back("tran");
}

void Controller::run()
{
	while (true) {
		std::cout << "List of available matrix operations:\n";
		for (int i = 0; i < commandList.size(); i++)
		{
			std::cout << i << ". " << commandList[i] << std::endl;
		}
		std::cout << "Enter command('help' for the list of available commands): ";

		std::string command;		
		std::cin >> command;

		if (command.compare("eval") == 0) {
			eval();
		}
		else if (command.compare("add") == 0) {
			add();
		}
		else if (command.compare("comp") == 0) {
			comp();
		}
		else if (command.compare("sub") == 0) {
			sub();
		}

		// one parameter:
		else if (command.compare("scal") == 0) {
			scal();
		}
		else if (command.compare("del") == 0) {
			del();
		}
		// no parameter: 
		else if (command.compare("help") == 0) {
			help();
		}
		else if (command.compare("exit") == 0) {
			cout << "Goodbye!" << endl;
			exit(EXIT_SUCCESS);
		}
	}
}

void Controller::eval()
{
	int num1;
	int num2;
	cin >> num1 >> num2;

}

void Controller::add()
{
	int num1;
	int num2;
	cin >> num1 >> num2;
	if (num1 < commandList.size() && num2 < commandList.size()) {
		std::string newCommand = commandList[num1] + " + " + commandList[num2];
		commandList.push_back(newCommand);
	}
	else {
		cout << "Out of range commands\n";
	}
}

void Controller::comp()
{
	int num1;
	int num2;
	cin >> num1 >> num2;
	if (num1 < commandList.size() && num2 < commandList.size()) {

	std::string newCommand = commandList[num1]+ " -> "+ commandList[num2];
	commandList.push_back(newCommand);
	}
	else {
		cout << "Out of range commands\n";
	}
}

void Controller::sub()
{
	int num1;
	int num2;
	cin >> num1 >> num2;
	if (num1 < commandList.size() && num2 < commandList.size()) {
	std::string newCommand = commandList[num1]+ " - "+ commandList[num2];
	commandList.push_back(newCommand);
	}
	else {
		cout << "Out of range commands\n";
	}
}

void Controller::scal()
{
	int num1;
	cin >> num1;
	std::string newCommand = "scal " + num1;
	commandList.push_back(newCommand);
}

void Controller::del()
{
	int intToRemove;
	cin >> intToRemove;
	if (intToRemove < commandList.size()) {
		commandList.erase(commandList.begin() + intToRemove);
	}
	else {
		cout << "Out of range commands\n";
	}

}

void Controller::help()
{
	cout << "see?";
	std::ifstream file("help.txt");
	std::string line;
	while (std::getline(file, line))
	{
		cout << line << endl;
	}

}



