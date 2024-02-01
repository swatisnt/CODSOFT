#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int lower, upper;

    do {
        // Get range from the user
        cout << "Enter the lower bound of the range: ";
        cin >> lower;
        cout << "Enter the upper bound of the range: ";
        cin >> upper;

        // Seed for random number generation
        srand(time(0));

        // Generate a random number within the specified range
        int randomNumber = rand() % (upper - lower + 1) + lower;

        int guess;
        int attempts = 0;

        cout << "Guess the number between " << lower << " and " << upper << ": ";

        do {
            cin >> guess;
            attempts++;

            if (guess == randomNumber) {
                cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
            } else if (guess < randomNumber) {
                cout << "Too low. Try again: ";
            } else {
                cout << "Too high. Try again: ";
            }

        } while (guess != randomNumber);

        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            break; // exit the loop if the user does not want to play again
        }

    } while (true);

    return 0;
}