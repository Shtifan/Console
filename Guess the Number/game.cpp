#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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

    int a = rand() % 1001, b, br = 1;

    cout << "Enter a number: ";
    cin >> b;

    while (a != b)
    {
        if (b < a)
        {
            cout << "Enter a larger number: ";
            cin >> b;
        }
        else
        {
            cout << "Enter a smaller number: ";
            cin >> b;
        }
        br++;
    }
    cout << "Well done, you guessed the number from the " << br << getNumberEnding(br) << " time" << endl;
    cout << endl;
    return 0;
}