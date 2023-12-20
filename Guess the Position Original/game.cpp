#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    string c;
    int a, b, num1[3], num2[3], sum = 1, br = 1;
    srand(time(0));
    cout << "Are you know how to play"
         << "\n";
    cin >> c;
    if (c == "no" || c == "NO" || c == "No")
    {
        cout << "You will see 3 numbers, from 0 to 20 inclusive"
             << "\n";
        cout << "They will stir"
             << "\n";
        cout << "The purpose is to know the location of one of the numbers"
             << "\n";
        cout << "The first number corresponds to the position"
             << "\n";
        cout << "The second - to the number behind that position"
             << "\n";
    }
    cout << "\n";
    cout << "\n";
    cout << "\n";
    while (br != 0)
    {
        for (int i = 0; i < 3; i++)
        {
            num1[i] = rand() % 21;
            num2[i] = num1[i];
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 2; j > i; j--)
            {
                if (num1[j - 1] > num1[j])
                {
                    num1[j - 1] = num1[j - 1] + num1[j];
                    num1[j] = num1[j - 1] - num1[j];
                    num1[j - 1] = num1[j - 1] - num1[j];
                }
            }
        }
        cout << br << "\n"
             << "\n"
             << "\n";
        for (int i = 0; i < 3; i++)
        {
            cout << num1[i] << " ";
        }
        cout << "\n";
        cout << "\n";
        cout << "1 2 3"
             << "\n";
        cout << "# # #\n";
        cout << "\n";
        cin >> a >> b;
        cout << "\n";
        if (a == 1)
        {
            if (b == num2[1])
            {
                sum *= 2;
                cout << "Well Done +" << sum / 2 << "$";
                cout << "\n";
                cout << "\n";
                cout << "\n";
                cout << "\n";
                br++;
            }
            else
            {
                cout << "1 --> " << num2[1];
                br = 0;
                cout << "\n"
                     << "You Lost";
                cout << "\n";
                cout << "\n";
                break;
            }
        }
        if (a == 2)
        {
            if (b == num2[2])
            {
                sum *= 2;
                cout << "Well Done +" << sum / 2 << "$";
                cout << "\n";
                cout << "\n";
                cout << "\n";
                cout << "\n";
                br++;
            }
            else
            {
                cout << "2 --> " << num2[2];
                br = 0;
                cout << "\n"
                     << "You Lost";
                cout << "\n";
                cout << "\n";
                break;
            }
        }
        if (a == 3)
        {
            if (b == num2[3])
            {
                sum *= 2;
                cout << "Well Done +" << sum / 2 << "$";
                cout << "\n";
                cout << "\n";
                cout << "\n";
                cout << "\n";
                br++;
            }
            else
            {
                cout << "3 --> " << num2[3];
                br = 0;
                cout << "\n"
                     << "You Lost";
                cout << "\n";
                cout << "\n";
                break;
            }
        }
    }
    cout << "You Won " << sum << "$"
         << "\n"
         << "\n"
         << "\n";
    return 0;
}
