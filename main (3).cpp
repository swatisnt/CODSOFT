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
        cout << "\nEnter the upper bound of the range: ";
        cin >> upper;

        // Seed for random number generation
        srand(time(0));

        // Generate a random number within the specified range
        int randomNumber = rand() % (upper - lower + 1) + lower;

        int guess;
        int attempts = 0;
        int maxAttempts = 4; // Set maximum attempts
        int score = 100; // Initial score

        cout << "\nGuess the number between " << lower << " and " << upper << " (You have " << maxAttempts << " attempts): ";

        while (attempts < maxAttempts) {
            cin >> guess;
            attempts++;

            // Check if the guess is within the range
            if (guess < lower || guess > upper) {
                cout << "\nError: Your guess is outside the specified range. Try again within the range: ";
                continue;  // Skip the rest of the loop and prompt for a new guess
            }

            if (guess == randomNumber) {
                cout << "\nCongratulations! You guessed the correct number in " << attempts << " attempts." << endl;
                cout << "\nYour score: " << score << endl;
                break;
            } else if (guess < randomNumber) {
                cout << "\nToo low. ";
            } else {
                cout << "\nToo high. ";
            }

            int attemptsLeft = maxAttempts - attempts;
            cout << "\nAttempts left: " << attemptsLeft << ". Try again: ";
            score -= 10; // Deduct points for a wrong guess
        }

        if (attempts == maxAttempts) {
            cout << "\nSorry, you didn't guess the correct number. The correct number was: " << randomNumber << endl;
            cout << "\nYour score: " << score << endl;
        }

        char playAgain;
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            break; // exit the loop if the user does not want to play again
        }

    } while (true);

    return 0;
}