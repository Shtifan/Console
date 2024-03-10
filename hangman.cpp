#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void print(int part)
{
    switch (part)
    {
    case 1:
        cout << "|--------" << endl;
        cout << "|       |" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|_______" << endl;
        break;
    case 2:
        cout << "|--------" << endl;
        cout << "|       |" << endl;
        cout << "|       O" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|_______" << endl;
        break;
    case 3:
        cout << "|--------" << endl;
        cout << "|       |" << endl;
        cout << "|       O" << endl;
        cout << "|       |" << endl;
        cout << "|" << endl;
        cout << "|_______" << endl;
        break;
    case 4:
        cout << "|--------" << endl;
        cout << "|       |" << endl;
        cout << "|       O" << endl;
        cout << "|      /|" << endl;
        cout << "|" << endl;
        cout << "|_______" << endl;
        break;
    case 5:
        cout << "|--------" << endl;
        cout << "|       |" << endl;
        cout << "|       O" << endl;
        cout << "|      /|\\" << endl;
        cout << "|" << endl;
        cout << "|_______" << endl;
        break;
    case 6:
        cout << "|--------" << endl;
        cout << "|       |" << endl;
        cout << "|       O" << endl;
        cout << "|      /|\\" << endl;
        cout << "|      /" << endl;
        cout << "|_______" << endl;
        break;
    case 7:
        cout << "|--------" << endl;
        cout << "|       |" << endl;
        cout << "|       O" << endl;
        cout << "|      /|\\" << endl;
        cout << "|      / \\" << endl;
        cout << "|_______" << endl;
        cout << "Game Over! You have been hanged." << endl;
        break;
    }
}

string generateWord()
{
    string words[] = {"apple", "banana", "cherry", "dog", "elephant", "frog", "gorilla", "hippopotamus", "iguana", "jaguar", "kangaroo", "leopard", "monkey", "newt", "octopus", "penguin", "quokka", "rhinoceros", "squirrel", "tiger"};
    int index = rand() % 20;
    return words[index];
}

int reveal(string guess, string word, vector<bool> &revealed)
{
    if (guess.length() != 1)
    {
        if (guess == word)
        {
            for (int i = 0; i < word.length(); i++)
                revealed[i] = true;
            return 2;
        }
        return -1;
    }
    else
    {
        bool guessed = false;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == guess[0])
            {
                revealed[i] = true;
                guessed = true;
            }
        }
        if (guessed)
            return 1;
        return 0;
    }
}

void printGuesses(string word, const vector<bool> &revealed, const vector<string> &guesses)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (revealed[i])
            cout << word[i];
        else
            cout << "*";
    }
    cout << endl
         << "Guessed: ";
    for (const string &guess : guesses)
        cout << guess << " ";
    cout << endl;
}

bool allRevealed(const vector<bool> &revealed)
{
    for (bool r : revealed)
    {
        if (!r)
            return false;
    }
    return true;
}

int main()
{
    srand(time(0));
    string word = generateWord();
    int wordLength = word.length();
    vector<bool> revealed(wordLength, false);

    int attempts = 0;
    const int maxAttempts = 7;
    vector<string> guesses;

    cout << "Welcome to Hangman!" << endl;

    while (true)
    {
        printGuesses(word, revealed, guesses);
        if (attempts == maxAttempts)
        {
            print(7);
            cout << "You have run out of attempts. The word was: " << word << endl;
            break;
        }
        if (allRevealed(revealed))
        {
            cout << "Congratulations! You've guessed the word: " << word << endl;
            break;
        }
        string guess;
        cout << "Enter your guess: ";
        cin >> guess;

        bool alreadyGuessed = false;
        for (const string &g : guesses)
        {
            if (g == guess)
            {
                alreadyGuessed = true;
                cout << "You've already guessed that letter!" << endl;
                break;
            }
        }

        if (!alreadyGuessed)
        {
            guesses.push_back(guess);
            int result = reveal(guess, word, revealed);
            if (result == -1)
            {
                cout << "Try guessing the whole word!" << endl;
            }
            else if (result == 0)
            {
                cout << "Incorrect guess!" << endl;
                print(++attempts);
            }
            else if (result == 1)
            {
                cout << "Correct guess!" << endl;
            }
            else if (result == 2)
            {
                cout << "Congratulations! You've guessed the word: " << word << endl;
                break;
            }
        }
    }

    return 0;
}
