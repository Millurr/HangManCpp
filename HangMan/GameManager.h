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

                        "\n  +---+\n  |   |\n  O   |\n /|\  |\n      |\n      |\n=========\n",

                        "\n  +---+\n  |   |\n  O   |\n /|\  |\n /    |\n      |\n=========\n",

                        "\n  +---+\n  |   |\n  O   |\n /|\  |\n / \  |\n      |\n=========\n" };

    string copyWord;

    string rightWord;

    string wrongLetters;

    string rightLetters;

public:
    void start();

    char validate(string input);

    bool finish();

    void run();
};
