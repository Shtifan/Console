#include <iostream>
#include <string>
using namespace std;

int main()
{
    string win = "", temp = "";
    string arr[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = "_";
        }
    }
    for (int k = 0; k < 9; k++)
    {
        if (k % 2 == 0)
            win = "x";
        else
            win = "o";
        cout << "It's " << win << " turn" << endl;
        cout << endl;
        int row, column;
        cin >> row >> column;
        while (true)
        {
            if (arr[row - 1][column - 1] == "_")
            {
                arr[row - 1][column - 1] = win;
                break;
            }
            else
            {
                cout << endl;
                cout << "The position is occupied" << endl;
                cout << endl;
                cin >> row >> column;
            }
        }
        cout << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < 3; i++) // rows
        {
            for (int j = 0; j < 3; j++)
            {
                temp += arr[i][j];
            }
            if (temp == win + win + win)
            {
                cout << win << " wins" << endl;
                cout << endl;
                return 0;
            }
            temp = "";
        }
        for (int i = 0; i < 3; i++) // columns
        {
            for (int j = 0; j < 3; j++)
            {
                temp += arr[j][i];
            }
            if (temp == win + win + win)
            {
                cout << win << " wins" << endl;
                cout << endl;
                return 0;
            }
            temp = "";
        }
        for (int i = 0; i < 3; i++) // diagonal 1
        {
            temp += arr[i][i];
        }
        if (temp == win + win + win)
        {
            cout << win << " wins" << endl;
            cout << endl;
            return 0;
        }
        temp = "";
        for (int i = 0; i < 3; i++) // diagonal 2
        {
            temp += arr[2 - i][i];
        }
        if (temp == win + win + win)
        {
            cout << win << " wins" << endl;
            cout << endl;
            return 0;
        }
        temp = "";
        if (k == 8)
            cout << "Draw" << endl;
    }
    cout << endl;
}