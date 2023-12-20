#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
    srand(time(0));
    int a, b, levels, lost = 0;
    string c;
    cout << " ___                ____ \n";
    cout << "|   | |     |    | |     \n";
    cout << "|   | |     |    | |____ \n";
    cout << "|   | |     |    | |     \n";
    cout << "|___| |____ |____| |____ \n";
    cout << "     THE        GAME     \n";
    cout << "Do you know how to play?" << endl;
    cin >> c;
    if (c == "no" || c == "NO" || c == "No")
    {
        cout << "You need to go to the end by sliding in holes with Olue" << endl;
        cout << "If you go in another hole, you lose" << endl;
        cout << "The Olue is small circles" << endl;
        cout << "Enter the number of the hole you want to enter (from 1 to 3)" << endl;
        cout << "Choose how many levels you want (one level has 10 stages)" << endl;
    }
    else
    {
        cout << "Choose how many levels you want" << endl;
    }
    cin >> levels;
    for (int i = 1; i <= levels; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cout << "Level " << i << ", Stage " << j << endl
                 << endl;
            for (int k = 1; k <= 10; k++)
            {
                a = 1 + rand() % 3;
            }
            if (a == 1)
            {
                cout << "  1     2     3" << endl;
                cout << " ___   ___   ___" << endl;
                cout << "|000| |   | |   |" << endl;
                cout << "|000| |   | |   |" << endl;
                cout << "|___| |___| |___|" << endl;
            }
            if (a == 2)
            {
                cout << "  1     2     3" << endl;
                cout << " ___   ___   ___" << endl;
                cout << "|   | |000| |   |" << endl;
                cout << "|   | |000| |   |" << endl;
                cout << "|___| |___| |___|" << endl;
            }
            if (a == 3)
            {
                cout << "  1     2     3" << endl;
                cout << " ___   ___   ___" << endl;
                cout << "|   | |   | |000|" << endl;
                cout << "|   | |   | |000|" << endl;
                cout << "|___| |___| |___|" << endl;
            }
            cin >> b;
            cout << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl;
            if (b != a)
            {
                lost++;
                cout << "You Lost" << endl;
                break;
            }
        }
        if (lost != 0)
        {
            break;
        }
        if (lost == 0)
        {
            cout << "YOU WON!!!" << endl;
        }
    }
    cout << endl;
    cout << endl;
    return 0;
}
