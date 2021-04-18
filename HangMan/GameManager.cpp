#include "GameManager.h"

// Sets default values and starts the game
void GameManager::start()
{
    cout << board[0];

    string inp;

    cout << "Enter a word to start: " << endl;
    getline(cin, inp);

    setWord(inp);
    setRightWord(inp);

    cout << "Let's play Hang Man!" << endl;
    cout << getRightWord() << endl;
}

// This validates user input
void GameManager::validate(string input)
{
    bool foundLetter = false;
    input = tolower(input[0]);

    // Checks all letters in the string to compare to the input
    for (int i = 0; i < word.size(); i++)
    {
        // If a value equals, it'll update the right letters and set foundLetter to true so we know this was not a failed attempt
        if (tolower(word[i]) == input[0]) {
            foundLetter = true;
            updateGuesses(true, input[0], i);
        }
    }

    // If wrong guess and it is not a letter that was guessed before, execute.
    if (!foundLetter && (wrongLetters.find(input[0]) > wrongLetters.size())) {
        updateGuesses(false, input[0], 0);
    }
}

// Determines if the guess is right or wrong and will update accordingly
void GameManager::updateGuesses(bool isRight, char inp, int index)
{
    // Inputs the right value into the appropriate location in the string
    if (isRight) {
        rightLetters[index] = inp;
    }
    else {
        wrongLetters += inp;
    }
}

// Simply prints the current state of the board
void GameManager::printBoard()
{
    system("cls"); // clears the board to refresh the display
    cout << board[wrongLetters.size()] << endl;
    cout << "Wrong guesses: " << wrongLetters << endl;
    cout << "Right guesses: " << rightLetters << endl;
}

// This determines if the game finishes with a win or a loss
bool GameManager::finish()
{
    if (wrongLetters.size() >= 6) {
        cout << "You lost!" << endl;
        return true;
    }
    
    if (getRightWord() == getWord()) {
        cout << "You guessed it!" << endl;
        return true;
    }
    return false;
}

// Set's the word entered by the user and for comparison's sake, we set the values to all lowercase
void GameManager::setWord(string inp)
{
    for (int i = 0; i < inp.size(); i++)
    {
        inp[i] = tolower(inp[i]);
    }
    word = inp;
}

// Sets the word at the beginning to display the appropiate length of the right word with -'s
void GameManager::setRightWord(string inp)
{
    rightLetters = inp;
    for (int i = 0; i < inp.size(); i++)
    {
        if (inp[i] != ' ') {
            rightLetters[i] = '-';
        }
        else {
            rightLetters[i] = ' ';
        }
    }
}

string GameManager::getWord()
{
    return word;
}

string GameManager::getRightWord()
{
    return rightLetters;
}

// Run the main game loop
void GameManager::run()
{
    start();

    bool isRunning = true;

    while (isRunning) {
        string inp;
        cin >> inp;
        validate(inp);
        printBoard();
        isRunning = !finish();
    }

}