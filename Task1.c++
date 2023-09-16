#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
using namespace std;
int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int guess=0;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" <<endl;
    cout << "I have selected a random number between 1 and 100. Try to guess it!" <<endl;
    while (guess != secretNumber){
        cout << "Enter your guess: ";
        cin >> guess;

        attempts++;

        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number (" << secretNumber << ") in " << attempts << " attempts!" << endl;
        }
    }
    return 0;
}
