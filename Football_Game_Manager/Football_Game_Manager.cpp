#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

// Function prototypes
void teamRegister();
void teamUnregister();
void teamUpdate();
int getIntegerInput(const string& prompt);
string getStringInput(const string& prompt);

int main() {
    int menuChoiceOne, menuChoiceTwo; 

    cout << "Welcome to Football Game Manager\n";

    do {
        cout << "Choose the thing you want to do\n1. Manage Teams\n2. Manage Games\n3. View Standings\n4. Exit\n";
        menuChoiceOne = getIntegerInput("Enter your choice: "); 

        switch (menuChoiceOne) {
            case 1: // Manage Teams
                do {
                    cout << "Choose the thing you want to do\n1. Register Teams\n2. Unregister Teams\n3. Update Teams\n4. Back to Main Menu\n";
                    menuChoiceTwo = getIntegerInput("Enter your choice: "); 

                    switch (menuChoiceTwo) {
                        case 1:// Team Register
                            teamRegister();
                            cout << "Returning to Team Management menu...\n";
                            break;
                        case 2:// Team Unregister
                            teamUnregister();
                            cout << "Returning to Team Management menu...\n";
                            break;
                        case 3:// Team Update 
                            teamUpdate();
                            cout << "Returning to Team Management menu...\n";
                            break;
                        case 4: // Return to Main Menu
                            cout << "Returning to Main Menu...\n";
                            break;
                        default:
                            cout << "Wrong choice!\nTry Again...\n";
                            break;
                    }
                } while (menuChoiceTwo != 4);
                break; // Exit the inner do-while and go back to the main menu
            case 2:
                cout << "Manage Games (Not yet implemented)\n";
                break;
            case 3:
                cout << "View Standings (Not yet implemented)\n";
                break;
            case 4:
                cout << "Exiting Football Game Manager...\n";
                break;
            default:
                cout << "Wrong choice!\nTry Again...\n";
                break;
        }
    } while (menuChoiceOne != 4);

    return 0;
}

void teamRegister() {
    char firstAnswer ,secondAnswer;

    cout << "Are you ready to register the football teams? [y/n]\n";
    cin >> firstAnswer;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (firstAnswer == 'y') {
        do {
            int num_ofTeams = getIntegerInput("How many teams are you trying to register? ");

            if (num_ofTeams % 2 == 0) {
                cout << "Proceed entering the name of teams...\n";
                vector<string> teamNames;
                for (int i = 0; i < num_ofTeams; i++) {
                    teamNames.push_back(getStringInput("Enter the name of team " + to_string(i + 1) + ": "));
                }

                json teamsJson = json::array();
                for (const string& teamName : teamNames) {
                    teamsJson.push_back({ {"name", teamName} });
                }

                ofstream file("teams.json");
                if (file.is_open()) {
                    file << teamsJson.dump(4);
                    cout << "Data saved to teams.json\n";
                } else {
                    cout << "Error saving data to file.\n";
                }

            } else {
                cout << "You entered an odd number of teams ...\n";
            }

            secondAnswer = getStringInput("Would you like to try again [y/n]? ")[0]; // Get the first character of the answer
        } while (secondAnswer == 'y');
    } else {
        cout << "Returning to Main Menu...\n";
    }
}

void teamUnregister() {
    string teamName = getStringInput("Enter the football team you want to unregister: ");
    cout << "You are trying to unregister " << teamName << "\n";
}

void teamUpdate() {
    string teamName = getStringInput("Enter the name of the team you want to update: ");
    cout << "you entered " << teamName << "\n";
}

int getIntegerInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        } else {
            cout << "Invalid input. Please enter an integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

string getStringInput(const string& prompt) {
    string line;
    while (true) {
        cout << prompt;
        if (getline(cin, line) && !line.empty()) {
            return line;
        } else {
            cout << "Invalid input. Input cannot be empty.\n";
            cin.clear();
        }
    }
}