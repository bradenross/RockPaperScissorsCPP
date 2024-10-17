// RockPaperScissorsCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int getBotChoice() {
    return rand() % 3 + 1;
}

string getChoiceAsString(int choice) {
    switch (choice) {
    case 1:
        return "Rock";
    case 2:
        return "Paper";
    case 3:
        return "Scissors";
    default:
        "ERROR";
    }
}

void getResults(int userChoice, int botChoice) {

    const std::string GREEN = "\033[32m";
    const std::string RED = "\033[31m";
    const std::string RESET = "\033[0m";

    if (userChoice == botChoice) {
        cout << "Tie!" << endl;
    }
    else if ((userChoice == 1 && botChoice == 3) ||
        (userChoice == 2 && botChoice == 1) ||
        (userChoice == 3 && botChoice == 2)) {
        cout << GREEN << "You win!" << RESET << endl;
    }
    else {
        cout << RED << "Bot wins!" << RESET << endl;
    }
}

int main()
{
    int choice = 0;

    while (true) {
        cout << "\nChoose an option:\n(1) Rock\n(2) Paper\n(3) Scissors\n(9) To quit\n";
        cin >> choice;

        if (choice == 9) {
            cout << "Quitting...\n";
            break;
        }

        if (choice < 1 || choice > 3) {
            cout << "Invalid option! Enter 1-3.\n";
            continue;
        }

        int botChoice = getBotChoice();
        cout << "\nBot: " << getChoiceAsString(botChoice) << "     You: " << getChoiceAsString(choice) << endl;
        getResults(choice, botChoice);
    }

}