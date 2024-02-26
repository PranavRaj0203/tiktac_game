#include <iostream>
#include <vector>
using namespace std;
void Diagram(vector<char> &cross)
{
    cout << "     |      |     " << endl
         << "    " << cross[0] << "|" << cross[1] << "     | " << cross[2] << endl
         << "__________________" << endl
         << "     |      |     " << endl
         << "    " << cross[3] << "| " << cross[4] << "    |" << cross[5] << "     " << endl
         << "     |      |     " << endl
         << "__________________" << endl
         << "    " << cross[6] << "|" << cross[7] << "     |" << cross[8] << "     " << endl
         << "     |      |     " << endl;
}
bool Validate_move(int move)
{
    if (move >= 0 && move <= 8)
    {
        return true;
    }
    else
    {
        cout << "Invalid move"
             << " tryagain \n";
        return false;
    }
}
bool check_win(vector<char> &cross, char symbol)
{
    for (int i = 0; i < 9; i += 3)
    {
        if (cross[i] == symbol && cross[i + 1] == symbol && cross[i + 2] == symbol)
            return true;
    }
    for (int i = 0; i < 3; ++i)
    {
        if (cross[i] == symbol && cross[i + 3] == symbol && cross[i + 6] == symbol)
            return true;
    }
    if (cross[0] == symbol && cross[4] == symbol && cross[8] == symbol)
        return true;

    if (cross[2] == symbol && cross[4] == symbol && cross[6] == symbol)
        return true;

    return false;
}
bool checkTie(const vector<char> &cross)
{
    for (int i = 0; i < 9; ++i)
    {
        if (cross[i] == ' ')
            return false;
    }
    return true;
}

int main()
{
    vector<char> cross(9, ' ');

    string n1, n2;
    cout << "Enter player 1 name: ";
    getline(cin, n1);
    cout << "Enter player 2 name: ";
    getline(cin, n2);

    int player = 1;

    while (true)
    {
        Diagram(cross);
        (player == 1) ? cout << n1 << " play your move" : cout << n2 << " play your move:";
        int move;
        cin >> move;
        move -= 1;
        if (Validate_move(move))
        {
            cross[move] = (player == 1) ? 'X' : 'O';
        }
        if (check_win(cross, cross[move]))
        {
            Diagram(cross);
            string n3 = (player == 1) ? n1 : n2;
            cout << "Player" << n3 << "wins";
            break;
        }
        if (checkTie(cross))
        {
            Diagram(cross);
            cout << "its a tie!";
            break;
        }
        player = (player == 1) ? 2 : 1;
    }
}