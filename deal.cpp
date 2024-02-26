#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

void shuffle(int arr[], int size)
{
    for (int i = size - 1; i > 0; --i)
    {
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }
}

int getOffer(int cases[], int numCases, int round)
{
    int totalValue = 0;
    for (int i = 0; i < 25; i++)
    {
        totalValue += cases[i];
    }

    int averageValue = totalValue / numCases;
    int offer = (round * averageValue) / 10;

    return offer;
}

int main()
{
    srand(time(0));

    int amounts[25] = {1, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500, 750, 1000, 5000, 10000, 25000, 50000, 75000, 100000, 200000, 300000, 400000, 500000, 750000, 1000000};

    cout << "Welcome to Deal or No Deal!\n\n";
    cout << "Here are the values in each of the 25 cases:\n\n";
    for (int i = 0; i < 25; i++)
    {
        cout << i + 1 << ": $" << amounts[i] << endl;
    }
    cout << endl;

    int cases[25];
    for (int i = 0; i < 25; i++)
    {
        cases[i] = amounts[i];
    }

    shuffle(cases, 25);
    cout << endl;
    cout << "The cases were shuffled!\n";
    cout << endl;

    int round = 1;
    int casesLeft = 25;
    int playerCase;

    cout << "Choose your case (1-25): ";
    cin >> playerCase;

    while (playerCase > 25 || playerCase < 1 || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\033[1;31mInvalid input\033[0m\n\n";
        cout << "Choose your case (1-25): ";
        cin >> playerCase;
    }

    int playerValue = cases[playerCase - 1];
    casesLeft--;

    cout << "You chose case " << playerCase << " that will be revealed at the end of the game.\n";
    cout << endl;

    while (true)
    {
        cout << "Round " << round << endl;
        cout << endl;

        cout << "Remaining cases: ";
        for (int i = 0; i < 25; i++)
        {
            if (cases[i] != 0 && cases[i] != playerValue)
                cout << i + 1 << " ";
        }
        cout << endl;

        cout << "Remaining amounts: ";
        int sortedCases[25];
        for (int i = 0; i < 25; i++)
        {
            sortedCases[i] = cases[i];
        }
        sort(sortedCases, sortedCases + 25);
        for (int i = 0; i < 25; i++)
        {
            if (sortedCases[i] != 0)
                cout << "$" << sortedCases[i] << " ";
        }
        cout << endl;

        int chosenCase;
        cout << endl;
        cout << "Choose a case to open from the remaining : ";
        cin >> chosenCase;

        while (cases[chosenCase - 1] == 0 || cases[chosenCase - 1] == playerValue || chosenCase > 25 || chosenCase < 1 || cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\033[1;31mInvalid input\033[0m\n\n";
            cout << "Choose a case to open from the remaining : ";
            cin >> chosenCase;
        }

        int caseValue = cases[chosenCase - 1];
        cout << endl;
        cout << "You opened case " << chosenCase << " containing \033[1;31m$" << caseValue << "\033[0m\n";
        cout << endl;

        cases[chosenCase - 1] = 0;
        casesLeft--;

        if (casesLeft % 5 == 0)
        {
            int offer = getOffer(cases, casesLeft, round);
            cout << "The banker offers you \033[32m$" << offer << "\033[0m for your case. Deal or no deal? (D/n): ";

            char response;
            cin >> response;
            cout << endl;

            if (response == 'D' || response == 'd' || response == 'Y' || response == 'y')
            {
                cout << "Your case contains \033[32m$" << playerValue << "\033[0m\n";
                cout << "Congratulations! You won \033[32m$" << offer << "\033[0m!\n";
                cout << endl;
                return 0;
            }
        }

        if (casesLeft == 1)
        {
            int remaining;
            for (int i = 0; i < 25; i++)
            {
                if (cases[i] != 0)
                    remaining = i + 1;
            }
            cout << "Do you want to swap case " << remaining << " with case " << playerCase << " (Y/n): ";

            char response;
            cin >> response;

            int value;
            if (response == 'Y' || response == 'y')
            {
                for (int i = 0; i < 25; i++)
                {
                    if (cases[i] != 0)
                        value = cases[i];
                }
            }
            else
                value = playerValue;

            cout << endl;
            cout << "Your case contains \033[32m$" << playerValue << "\033[0m" << endl;
            cout << "The other case constains \033[32m$" << cases[remaining - 1] << "\033[0m" << endl;
            cout << endl;
            cout << "Congratulations! You won \033[32m$" << value << "\033[0m!" << endl;
            cout << endl;
            return 0;
        }
        round++;
    }
}