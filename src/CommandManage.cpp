#include "CommandManage.h"
#include "Matrix.h"
#include <sstream>


using std::cin;
using std::cout;
using std::endl;

CommandManage::CommandManage()
{
	commandList.push_back("id");
	commandList.push_back("tran");
}

void CommandManage::printList()
{
	std::cout << "List of available matrix operations:\n";
	for (int i = 0; i < commandList.size(); i++)
	{
		std::cout << i << ". " << commandList[i] << std::endl;
	}
}

void CommandManage::eval()
{
	int commandIndex;
	int matOrder;
	cin >> commandIndex >> matOrder;
	readCommand(commandIndex, matOrder);

}

void CommandManage::add()
{
	int num1;
	int num2;
	cin >> num1 >> num2;
	if (num1 < commandList.size() && num2 < commandList.size()) {

		std::string command1 = commandList[num1];
		std::string command2 = commandList[num2];
		addBracketsIfNeed(command1);
		addBracketsIfNeed(command2);

		std::string newCommand = command1 + " + " + command2;
		commandList.push_back(newCommand);
	}
	else {
		cout << "Out of range commands\n";
	}
}

void CommandManage::addBracketsIfNeed(std::string& command) {
	if (command.find("+") != -1 || command.find("->") != -1 ||command.find("-") != -1) {
		command = "(" + command + ")";
	}
}

void CommandManage::comp()
{
	int num1;
	int num2;
	cin >> num1 >> num2;
	if (num1 < commandList.size() && num2 < commandList.size()) {

		std::string command1 = commandList[num1];
		std::string command2 = commandList[num2];
		addBracketsIfNeed(command1);
		addBracketsIfNeed(command2);

		std::string newCommand = command1 + " -> " + command2;
		commandList.push_back(newCommand);
	}
	else {
		cout << "Out of range commands\n";
	}
}

void CommandManage::sub()
{
	int num1;
	int num2;
	cin >> num1 >> num2;
	if (num1 < commandList.size() && num2 < commandList.size()) {
		std::string command1 = commandList[num1];
		std::string command2 = commandList[num2];
		addBracketsIfNeed(command1);
		addBracketsIfNeed(command2);
		std::string newCommand = command1 +  " - " + command2;		
		commandList.push_back(newCommand);
	}
	else {
		cout << "Out of range commands\n";
	}
}

void CommandManage::scal()
{
	int num1;
	cin >> num1;
	std::string newCommand = "scal " + std::to_string(num1);
	commandList.push_back(newCommand);
}

void CommandManage::del()
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

void CommandManage::help()
{
	
	std::ifstream file("help.txt");
	std::string line;
	while (std::getline(file, line))
	{
		cout << line << endl;
	}
	cout << endl;
}



void CommandManage::readCommand(int commandIndex, int matOrder)
{
	// find how much matrix needed:
	int matCounter = 1;
	std::string commandStr = commandList[commandIndex];
	for (int i = 0; i < commandStr.size(); i++)
	{
		if (commandStr[i] == '+' || commandStr[i] == '-' && commandStr[i + 1] != '>') {
			matCounter++;
		}
	}

	// ask for the matrix:
	cout << "Please enter " + std::to_string(matCounter) + " matrices:\n\n";
	std::vector<Matrix> matrices;
	for (int i = 0; i < matCounter; i++)
	{
		Matrix mat(matOrder);
		mat.readUserMatrix(matOrder);
		matrices.push_back(mat);
	}

	// read the command:
	std::stringstream commandStream(commandStr);
	std::string word;
	int count = 0;

	int currentMat = 0;

	enum OperateState
	{
		ADD,
		SUB,		
		NOTHING
	};	
	enum OperateStart
	{
		START,
		NOT_START		
	};

	enum OperateState state = NOTHING;
	enum OperateStart startState = NOT_START;
	while (commandStream >> word) {
		if (word.compare("+") == 0 ){
			currentMat++;
			state = ADD;
			startState = NOT_START;
		}
		else if (word.compare("-") == 0) {
			currentMat++;
			state = SUB;
			startState = NOT_START;
		}
		else if (word.compare("->") == 0) {			
			startState = NOT_START;
		}
		
		else if (word.find("id") != std::string::npos) {
			// nothing	
			startState = START;
			// 		
		}
		else if (word.find("tran") != std::string::npos) {
			matrices[currentMat].transpose();
			startState = START;
		}
		else if (word.find("scal") != std::string::npos) {
			int scalNum;
			commandStream >> scalNum;
			matrices[currentMat] = matrices[currentMat] * scalNum;
			startState = START;
		}
		std::streampos pos = commandStream.tellg();
		commandStream >> word;
		commandStream.seekg(pos);

		
		if (state != NOTHING && word.compare("->") != 0 && startState == START) {
			if (state == ADD) {
				matrices[currentMat] = matrices[currentMat - 1] + matrices[currentMat];
			}
			
			else if (state == SUB) {
				matrices[currentMat] = matrices[currentMat - 1] - matrices[currentMat];
			}
			state = NOTHING;
		}
		
	}
	matrices[currentMat].printMatrix();
}
