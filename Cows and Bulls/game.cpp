#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

bool hasDuplicates(string str)
{
    int count[10] = {0};
    for (int i = 0; i < str.length(); i++)
    {
        int digit = str[i] - '0';
        if (++count[digit] > 1)
        {
            return true;
        }
    }
    return false;
}

void cb(string number, string input, int &cows, int &bulls)
{
    bulls = 0;
    cows = 0;
    for (int i = 0; i < number.length(); i++)
    {
        if (number[i] == input[i])
            bulls++;
        else if (number.find(input[i]) != string::npos)
            cows++;
    }
}

string getNumberEnding(int number)
{
    int lastDigit = number % 10;
    int lastTwoDigits = number % 100;
    switch (lastDigit)
    {
    case 1:
        if (lastTwoDigits != 11)
            return "st";
        break;
    case 2:
        if (lastTwoDigits != 12)

            return "nd";
        break;
    case 3:
        if (lastTwoDigits != 13)
            return "rd";
        break;
    }
    return "th";
}

int main()
{
    srand(time(0));

    int guesses = 0;
    string number = "";
    string input;

    int firstDigit = rand() % 9 + 1;
    number += to_string(firstDigit);

    for (int i = 0; i < 3; i++)
    {
        int digit = rand() % 10;
        while (number.find(to_string(digit)) != string::npos || (i == 0 && digit == 0))
        {
            digit = rand() % 10;
        }
        number += to_string(digit);
    }

    while (true)
    {
        cout << "Enter a 4-digit number with no repeating digits: ";
        cin >> input;

        if (input.length() != 4 || input[0] == '0' || !isdigit(input[0]) || hasDuplicates(input))
        {
            cout << "Invalid input, try again.\n";
            cout << endl;
            continue;
        }

        guesses++;

        int cows = 0;
        int bulls = 0;
        cb(number, input, cows, bulls);
        cout << endl;
        cout << "Cows: " << cows << endl;
        cout << "Bulls: " << bulls << endl;
        cout << endl;

        if (bulls == 4)
        {
            cout << "Well done, you guessed the number from the " << guesses << getNumberEnding(guesses) << " time\n";
            return 0;
        }
    }
}
