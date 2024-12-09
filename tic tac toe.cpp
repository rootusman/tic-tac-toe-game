#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

string PlayerInput(char board[][3], string* player1, string* player2);
string CheckWinner(char board[][3], string player1, string player2);
void DisplayResult(string* winner, string player1, string player2);

int main() {
    char board[3][3]{
       {'-', '-', '-'},
       {'-', '-', '-'},
       {'-', '-', '-'}
    };
    string player1, player2;

    cout << "\t\t\t\t        ____________________\n";
    cout << "\t\t\t\t        | TIC - TAC - TOE  |\n";
    cout << "\t\t\t\t        Welcome to our Game\n";

    cout << "Enter player 1 name : ";
    getline(cin, player1);
    cout << "Enter player 2 name : ";
    getline(cin, player2);

    cout << "\nChoose the following format to enter input\n";
    cout << " 1 | 2 | 3 \n";
    cout << " 4 | 5 | 6 \n";
    cout << " 7 | 8 | 9 \n\n";

    string winner = PlayerInput(board, &player1, &player2);
    DisplayResult(&winner, player1, player2);

    return 0;
}

string PlayerInput(char board[][3], string* player1, string* player2) {
    string input;
    char usedPositions[9]{};
    int moveCount = 0;
    string currentWinner;

    for (int i = 0; i < 9; ++i) {
        string* currentPlayer = (i % 2 == 0) ? player1 : player2;
        char marker = (i % 2 == 0) ? 'X' : 'O';

        cout << *currentPlayer << "'s turn: ";
        while (true) {
            cin >> input;

            if (input.length() == 1 && input[0] >= '1' && input[0] <= '9' && !count(begin(usedPositions), end(usedPositions), input[0])) {
                usedPositions[moveCount++] = input[0];
                break;
            }
            cout << "Invalid input. Please enter an unoccupied position (1-9): ";
        }

        int position = input[0] - '1';
        board[position / 3][position % 3] = marker;

        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                cout << " " << board[row][col];
                if (col < 2) cout << " |";
            }
            cout << "\t\t" << (row * 3 + 1) << " | " << (row * 3 + 2) << " | " << (row * 3 + 3) << endl;
        }
        cout << endl;

        currentWinner = CheckWinner(board, *player1, *player2);
        if (!currentWinner.empty())
            return currentWinner;

        if (i == 8)
            return "Draw"; // All positions filled and no winner
    }
    return currentWinner;
}

string CheckWinner(char board[][3], string player1, string player2) {
    int winPatterns[8][3][2] = {
        {{0, 0}, {0, 1}, {0, 2}}, {{1, 0}, {1, 1}, {1, 2}}, {{2, 0}, {2, 1}, {2, 2}},
        {{0, 0}, {1, 0}, {2, 0}}, {{0, 1}, {1, 1}, {2, 1}}, {{0, 2}, {1, 2}, {2, 2}},
        {{0, 0}, {1, 1}, {2, 2}}, {{0, 2}, {1, 1}, {2, 0}}
    };

    for (auto& pattern : winPatterns) {
        char first = board[pattern[0][0]][pattern[0][1]];
        if (first != '-' && first == board[pattern[1][0]][pattern[1][1]] && first == board[pattern[2][0]][pattern[2][1]])
            return (first == 'X') ? player1 : player2;
    }
    return "";
}

void DisplayResult(string* winner, string player1, string player2) {
    if (*winner == "Draw") {
        cout << "\t\t\t\t\t\t\tGame is a Draw\n";
    }
    else {
        cout << "\n\n\t\t\t\t\t        Winner of the Game is : " << *winner << "\n\n";
    }
    cout << "\t\t\t\t\t  Thank You for playing TIC-TAC-TOE!\n";
    cout << "\t\t\t\t___________________________________________________________\n\n";
}
