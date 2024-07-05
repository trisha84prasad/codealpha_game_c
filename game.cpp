#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

void playGame(int lowerLimit, int upperLimit) {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    // Generate a random number between lowerLimit and upperLimit
    int randomNumber = rand() % (upperLimit - lowerLimit + 1) + lowerLimit;
    int guess;
    int numberOfGuesses = 0;

    cout << "I have selected a number between " << lowerLimit << " and " << upperLimit << ". Try to guess it!" << endl;

    // Loop until the player guesses the correct number
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        numberOfGuesses++;

        if (guess > randomNumber) {
            cout << "Too high!" << endl;
        } else if (guess < randomNumber) {
            cout << "Too low!" << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << numberOfGuesses << " attempts." << endl;
        }
    } while (guess != randomNumber);
}

int main() {
    int lowerLimit = 1;
    int upperLimit = 100;
    char playAgain;

    do {
        playGame(lowerLimit, upperLimit);

        cout << "Would you like to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;
    return 0;
}
