#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    int totoNumbers[6];
    for (int i = 0; i < 6; i++)
    {
        int num = rand() % 49 + 1;
        while (true)
        {
            bool unique = true;
            for (int j = 0; j < i; j++)
            {
                if (totoNumbers[j] == num)
                {
                    unique = false;
                    break;
                }
            }
            if (unique)
            {
                break;
            }
            else
            {
                num = rand() % 49 + 1;
            }
        }
        totoNumbers[i] = num;
    }

    int userNumbers[6];
    cout << "Please enter your 6 numbers (between 1 and 49): ";
    for (int i = 0; i < 6; i++)
    {
        cin >> userNumbers[i];
    }

    int correctGuesses = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (userNumbers[i] == totoNumbers[j])
            {
                correctGuesses++;
                break;
            }
        }
    }

    cout << "You guessed " << correctGuesses << " numbers correctly." << endl;
    if (correctGuesses == 6)
    {
        cout << "Congratulations! You have won $7,000,000." << endl;
    }
    else if (correctGuesses == 5)
    {
        cout << "You have won $7,000." << endl;
    }
    else if (correctGuesses == 4)
    {
        cout << "You have won $70." << endl;
    }
    else if (correctGuesses == 3)
    {
        cout << "You have won $7." << endl;
    }
    else
    {
        cout << "Sorry, you did not win a prize." << endl;
    }

    cout << "The Toto numbers are: ";
    for (int i = 0; i < 6; i++)
    {
        cout << totoNumbers[i] << " ";
    }
    cout << endl;
    cout << endl;
    return 0;
}