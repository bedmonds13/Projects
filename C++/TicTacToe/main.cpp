#include <iostream>
#include <vector>
#include "Player.h"
#include <string>
using namespace std;

char board_squares[9] = {'1','2','3','4','5','6','7','8','9'};
void game_board(char *current_squares)
{
    cout << "     |          |" << '\n';
    cout << "  "<< current_squares[0] <<"  |     "<<current_squares[1]<<"    |   " << current_squares[2]<<'\n';
    cout << "_____|__________|______" <<'\n';
    cout << "     |          |  "   << '\n';
    cout << "  "<< current_squares[3] <<"  |     "<<current_squares[4]<<"    |   " << current_squares[5]<<'\n';
    cout << "_____|__________|______" <<'\n';
    cout << "     |          |" << '\n';
    cout << "  "<< current_squares[6] <<"  |     "<<current_squares[7]<<"    |   " << current_squares[8]<< '\n';
    cout << "     |          |" << '\n';
}

   //Check win conditions and create winner 
int win_check(Player player1, Player player2, Player &new_winner) 
{
    if(board_squares[0] == board_squares[1] && board_squares[1] == board_squares[2]){
        if(board_squares[0] == player1.get_mark() ){
                   new_winner = player1;
                }
                else{
                    new_winner = player2;
                }
                return 1;
            }
        if(board_squares[3] == board_squares[4] && board_squares[4] == board_squares[5]){
            if(board_squares[3] == player1.get_mark() ){
                new_winner = player1;
            }
            else{
                    new_winner = player2;
                }
            return 1;
        }
        if(board_squares[6] == board_squares[7] && board_squares[7] == board_squares[8]){
                if(board_squares[6] == player1.get_mark() ){
                new_winner = player1;
            }
            else{
                    new_winner = player2;
                }
            return 1;
        }
        if(board_squares[0] == board_squares[3] && board_squares[3] == board_squares[6]){
                if(board_squares[0] == player1.get_mark() ){
                new_winner = player1;
            }
            else{
                    new_winner = player2;
                }
            return 1;
        }
        if(board_squares[1] == board_squares[4] && board_squares[4] == board_squares[7]){
                if(board_squares[1] == player1.get_mark() ){
                new_winner = player1;
            }
            else{
                    new_winner = player2;
                }
            return 1;
        }
        if(board_squares[2] == board_squares[5] && board_squares[5] == board_squares[8]){
                if(board_squares[2] == player1.get_mark() ){
                new_winner = player1;
            }
            else{
                    new_winner = player2;
                }
            return 1;
        }
        if(board_squares[0] == board_squares[4] && board_squares[4] == board_squares[8]){
            if(board_squares[0] == player1.get_mark() ){
                new_winner = player1;
            }
            else{
                    new_winner = player2;
                }
            return 1;
        }
        if(board_squares[2] == board_squares[1] && board_squares[1] == board_squares[2]){
                if(board_squares[2] == player1.get_mark() ){
                new_winner = player1;
            }
            else{
                    new_winner = player2;
                }
            return 1;
        }
        if(board_squares[2] == board_squares[4] && board_squares[4] == board_squares[6]){
                if(board_squares[3] == player1.get_mark() ){
                new_winner = player1;
                }
                else{
                    new_winner = player2;
                }
            return 1;
    }
    else if(board_squares[0] != '1' && board_squares[1] != '2' && board_squares[2] != '3' 
            && board_squares[3] != '4' && board_squares[4] != '5' && board_squares[5] != '6' 
            && board_squares[6] != '7' && board_squares[7] != '8' && board_squares[8] != '9')
            return 0;
    return -1;
}

int main(){


    bool in_game = true; //Escape for game loop
    bool first_round_done = false;
    Player player1, player2, winner;
    char input;

     cout << "Start game session? Y/N?" << endl;
     cin >> input;
     int round =1 ;

    //Begin Game
     if(input == 'Y' || input == 'y' ){
            Player current_player;
            char input;
            int player_choice;
            string new_name;
            
            
                
            cout << "Player 1 choose your mark. 'x' or 'o'." << endl;
            cin >> input;
            cout << "Then type in your name." << endl;;
            
            cin >> new_name;
        
            if( input == 'x' || input == 'X')
            {
                player1.add_mark('X');
                player1.add_name(new_name);
                player2.add_mark('O');

            }
            else{
                player1.add_mark('0');
                player2.add_mark('X');

            }
            cout << "Player 2 choose a name for yourself." << endl;
            cin >> new_name;
            player2.add_name(new_name);
            
            do{
                
                
                if(round%2 == 1 ){
                    current_player = player1;
                }       
                else{
                    current_player = player2;
                }
                game_board(board_squares);//Display current gameboard
                cout << current_player.get_name() << " it is your turn. choose a square by inputting its number." << endl;
                cin >> player_choice;
                int chosen_square = player_choice -1;

                //Check selection and change mark for current player
                if (player_choice == 1 && board_squares[chosen_square] == '1')
                board_squares[chosen_square] = current_player.get_mark();
                else if (player_choice == 2 && board_squares[chosen_square] == '2')
                    board_squares[chosen_square] = current_player.get_mark();
                else if (player_choice == 3 && board_squares[chosen_square] == '3')
                    board_squares[chosen_square] = current_player.get_mark();
                else if (player_choice == 4 && board_squares[chosen_square] == '4')
                    board_squares[chosen_square] = current_player.get_mark();
                else if (player_choice == 5 && board_squares[chosen_square] == '5')

                    board_squares[chosen_square] = current_player.get_mark();
                else if (player_choice == 6 && board_squares[chosen_square] == '6')

                    board_squares[chosen_square] = current_player.get_mark();
                else if (player_choice == 7 && board_squares[chosen_square] == '7')

                    board_squares[chosen_square] = current_player.get_mark();
                else if (player_choice == 8 && board_squares[chosen_square] == '8')

                    board_squares[chosen_square] = current_player.get_mark();
                else if (player_choice == 9 && board_squares[chosen_square] == '9')

                board_squares[chosen_square] = current_player.get_mark();
                else
                {
                    cout << "Invalid input. Must choose a number 1-9 and hasnt been used before.";
                    first_round_done = true;
                    
                }
            
                //Break from loop and display winner
                if(win_check(player1, player2, winner) == 1){
                    game_board(board_squares);
                    cout << winner.get_name() << " wins the game" << endl;
                    in_game = false;
                }
                else if(win_check(player1, player2, winner) == 0){
                    game_board(board_squares);
                    cout << "Its a Tie!" << endl;
                    in_game = false;
                }
                round++;
                


                }while(in_game == true);
     }
     else if(input == 'N' || input == 'n')
        {
        cout << "Ok maybe next time" << endl;
    }
    else{
        cout << "Incorrect Response. Try again" << endl;
    }    
    cout << "GoodBye!"<< endl;


               
}

