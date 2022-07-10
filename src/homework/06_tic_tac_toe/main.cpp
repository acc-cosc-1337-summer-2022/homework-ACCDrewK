#include "tic_tac_toe.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    TicTacToe game;
    string first_player{""};
    char user_choice{'Y'};
    vector<int> past_positions{0};

    cout << "Welcome to TicTacToe!" << endl;
    cout << "\nThe first player should choose a symbol first, the other player will take the other symbol. The first "
            "player to get three in a row (either in a row, column, or diagonally) wins. Good luck!\n"
         << endl;
    do
    {
        // game setup phase
        first_player = "";      // reset player symbol for each game
        past_positions.clear(); // clear previous positions
        do
        {
            do
            {
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                cout << "Choose 'X' or 'O' for the first player: ";
                cin >> first_player;
                if (cin.fail())
                {
                    cout << "Error: the program could not read your input, please try again." << endl;
                }
            } while (cin.fail());
            if (!(first_player == "X" || first_player == "O"))
            {
                cout << "Invalid player symbol; please choose \"X\" or \"O\"" << endl;
            }
        } while (!(first_player == "X" || first_player == "O"));
        game.start_game(first_player);
        int position{0};

        // playing loop
        while (!game.game_over())
        {
            do
            {
                cout << "Enter a position: ";
                cin >> position;
                if (cin.fail())
                {
                    cout << "Error: you must enter a number for the position. Valid numbers are 1-9." << endl;
                    cin.clear();
                    cin.ignore(100, '\n');
                    continue;
                }
                else if (!(0 < position && position < 10))
                {
                    cout << "Invalid position: you must choose a cell number between 1 and 9" << endl;
                    continue;
                }
                else if (already_played(position, past_positions))
                {
                    cout << "Invalid position: you must choose a cell that has not already been filled." << endl;
                    continue;
                }
                break;
            } while (true);
            past_positions.push_back(position);
            game.mark_board(position);
            game.display_board();
        }

        // game end
        if (game.get_winner() != "C")
        {
            cout << "The winner is..." << game.get_winner() << "!!\n";
        }
        else
        {
            cout << "The game is a draw." << endl;
        }
        cout << "Game over!\nDo you want to play again? (y/n): ";
        cin >> user_choice;
    } while (user_choice == 'y' || user_choice == 'Y');

    return 0;
}