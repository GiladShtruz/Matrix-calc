#include "Controller.h"
#include <fstream> 
#include <string>

using std::cin;
using std::cout;
using std::endl;



Controller::Controller()
{
	
}

void Controller::run()
{
	
	while (true) {
		commandManager.printList();		
		std::cout << "Enter command('help' for the list of available commands): ";

		std::string command;		
		std::cin >> command;

		if (command.compare("eval") == 0) {
			commandManager.eval();
		}
		else if (command.compare("add") == 0) {
			commandManager.add();
		}
		else if (command.compare("comp") == 0) {
			commandManager.comp();
		}
		else if (command.compare("sub") == 0) {
			commandManager.sub();
		}

		// one parameter:
		else if (command.compare("scal") == 0) {
			commandManager.scal();
		}
		else if (command.compare("del") == 0) {
			commandManager.del();
		}
		// no parameter: 
		else if (command.compare("help") == 0) {
			commandManager.help();
		}
		else if (command.compare("exit") == 0) {
			cout << "Goodbye!" << endl;
			exit(EXIT_SUCCESS);
		}
	}
}



