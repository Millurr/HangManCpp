#pragma once
#include <iostream>
#include <string>

using namespace std;

class GameManager {

    string word;

    string board[7] = { "\n  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n",

                        "\n  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n",

                        "\n  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n",

                        "\n  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n",

                        "\n  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n",

                        "\n  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n",

                        "\n  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n" };

    string wrongLetters;

    string rightLetters;

    void setWord(string inp);

    void setRightWord(string inp);

    void updateGuesses(bool isRight, char inp, int index);

    void printBoard();

public:
    void start();

    void validate(string input);

    bool finish();

    string getWord();

    string getRightWord();

    void run();
};
