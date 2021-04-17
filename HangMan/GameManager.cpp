#include "GameManager.h"

void GameManager::start()
{
    cout << board[0];

    bool checking = true;
    while (checking) {
        cout << "Enter a word to start: " << endl;
        getline(cin, word);
        cout << "Are you sure this is the word to play with?(y/n)" << endl;
        string yesOrNo;
        cin >> yesOrNo;
        if (yesOrNo == "y") {
            checking = false;
        }
        else {
            word.clear();
            checking = true;
        }
    }

    rightLetters = word;

    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] != ' ') {
            rightLetters[i] = '-';
        }
        else {
            rightLetters[i] = ' ';
        }
    }

    cout << "Let's play Hang Man!" << endl;
    cout << rightLetters << endl;
}

char GameManager::validate(string input)
{
    bool foundLetter = false;
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == input[0]) {
            rightLetters[i] = input[0];
            cout << rightLetters << endl;
            foundLetter = true;
        }
    }

    // If wrong guess and it is not a letter that was guessed before, execute.
    if (!foundLetter && (wrongLetters.find(input[0]) > wrongLetters.size())) {
        wrongLetters += input[0];
        cout << "Wrong guesses: " << wrongLetters << endl;
        cout << board[wrongLetters.size()] << endl;
    }

    return 0;
}

bool GameManager::finish()
{
    if (wrongLetters.size() == 7) {
        cout << "You lost!" << endl;
        return true;
    }
    else if (rightWord == word) {
        cout << "You guessed it!" << endl;
        return true;
    }
    return false;
}

void GameManager::run()
{
    start();

    bool isRunning = true;

    while (isRunning) {
        string inp;
        cin >> inp;
        validate(inp);
        isRunning = !finish();
    }

}