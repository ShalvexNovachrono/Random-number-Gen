#include <iostream>
#include <string>
#include <typeinfo>
#include <random>

using namespace std;

void print(string message) {
    cout << message << endl;
}

void printNoNewLine(string message) {
    cout << message;
}

string input(string message) {
    printNoNewLine(message);
    string thisInput;
    cin >> thisInput;
    return thisInput;
}

int GenRandomInt(int MIN, int MAX) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(MIN, MAX);
    return dis(gen);
}



bool IsNumberFound = false;
int main() {
    print("Guess a number from 1 - 10");
    int RandomNumber = GenRandomInt(1, 10);

    while (!IsNumberFound) {
        string InputS = input(">>> ");
        try {
            int InputI = stoi(InputS);
            if (InputI == RandomNumber) {
                print("You guessed it!");
                IsNumberFound = true;
                break;
            } else if (InputI > RandomNumber) {
                print("Guess lower!");
            } else {
                print("Guess higher!");
            }
        } catch (exception e) {
            print("Invalid input. Please enter a number. #Error");
        }
    }

}