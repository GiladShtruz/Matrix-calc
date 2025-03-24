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
		int num1;
		int num2;
		std::cin >> command;

		if (command.compare("eval") == 0
			|| command.compare("add") == 0
			|| command.compare("comp") == 0
			|| command.compare("sub") == 0
			) {
			cin >> num1 >> num2;
		}
		else if (command.compare("scal") == 0
			|| command.compare("del") == 0
			) {
			cin >> num1;
		}
		else if (command.compare("help") == 0)
		{
			cout << "see?";
			std::ifstream file("help.txt");
			std::string line;
			while (std::getline(file, line))
			{
				cout << line << endl;
			}
		}
		else if (command.compare("exit") == 0)
		{
			cout << "Goodbye!" << endl;
			exit(EXIT_SUCCESS);
		}

	}
}
