#include<iostream>
#include<cstdlib>
#include <time.h>
#include <stdlib.h>
#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;



struct board
{
    bool square, circle, empty;
    int pos;
    board* next;
    board* prev;
};
board* getBoard(board* fullBoard);
bool wonx(board* fullBoard)
{
    board* temp1 = fullBoard;
    board* temp2 = fullBoard;
    board* temp3 = fullBoard;

    //----------9,8,7
    temp2 = temp2->next;
    temp3 = temp3->next->next;

    if (temp1->square == true && temp2->square == true && temp3->square == true)
    {
        cout << "player one won! " << endl;  return false;
    }
    //----------------------------------9,6,3
    temp2 = temp3->next;
    for (int i = 1; i <= 4; i++)
    {
        temp3 = temp3->next;
    }
    if (temp1->square == true && temp2->square == true && temp3->square == true)
    {
        cout << "player one won! " << endl;  return false;
    }
    //---------------------------------------9,5,1
    temp2 = temp2->next;
    temp3 = temp3->next->next;
    if (temp1->square == true && temp2->square == true && temp3->square == true)
    {
        cout << "player one won! " << endl;  return false;
    }
    //-----------------8,5,2
    temp1 = temp1->next;
    temp3 = temp3->prev;
    if (temp1->square == true && temp2->square == true && temp3->square == true)
    {
        cout << "player one won! " << endl;  return false;
    }
    //-----------------7,5,3
    temp1 = temp1->next;
    temp3 = temp3->prev;
    if (temp1->square == true && temp2->square == true && temp3->square == true)
    {
        cout << "player one won! " << endl;  return false;
    }
    //-----------6,5,4
    temp1 = temp1->next;
    temp3 = temp3->prev;
    if (temp1->square == true && temp2->square == true && temp3->square == true)
    {
        cout << "player one won! " << endl;  return false;
    }
    //-----------7,4,1
    temp1 = temp1->prev;
    temp2 = temp2->next;
    temp3 = temp3->next->next->next;
    if (temp1->square == true && temp2->square == true && temp3->square == true)
    {
        cout << "player one won! " << endl;  return false;
    }
    //------------3,2,1
    for (int i = 1; i <= 4; i++)
    {
        temp1 = temp1->next;
    }
    temp2 = temp2->next->next;
    if (temp1->square == true && temp2->square == true && temp3->square == true)
    {
        cout << "player one won! " << endl;  return false;
    }

    return true;


}

bool wono(board* fullBoard)
{
    board* temp1 = fullBoard;
    board* temp2 = fullBoard;
    board* temp3 = fullBoard;

    //----------9,8,7
    temp2 = temp2->next;
    temp3 = temp3->next->next;

    if (temp1->circle == true && temp2->circle == true && temp3->circle == true)
    {
        cout << "player two won !" << endl;  return false;
    }
    //----------------------------------9,6,3
    temp2 = temp3->next;
    for (int i = 1; i <= 4; i++)
    {
        temp3 = temp3->next;
    }
    if (temp1->circle == true && temp2->circle == true && temp3->circle == true)
    {
        cout << "player two won !" << endl;  return false;
    }
    //---------------------------------------9,5,1
    temp2 = temp2->next;
    temp3 = temp3->next->next;
    if (temp1->circle == true && temp2->circle == true && temp3->circle == true)
    {
        cout << "player two won !" << endl;  return false;
    }
    //-----------------8,5,2
    temp1 = temp1->next;
    temp3 = temp3->prev;
    if (temp1->circle == true && temp2->circle == true && temp3->circle == true)
    {
        cout << "player two won !" << endl;  return false;
    }
    //-----------------7,5,3
    temp1 = temp1->next;
    temp3 = temp3->prev;
    if (temp1->circle == true && temp2->circle == true && temp3->circle == true)
    {
        cout << "player two won !" << endl;  return false;
    }
    //-----------6,5,4
    temp1 = temp1->next;
    temp3 = temp3->prev;
    if (temp1->circle == true && temp2->circle == true && temp3->circle == true)
    {
        cout << "player two won !" << endl;  return false;
    }
    //-----------7,4,1
    temp1 = temp1->prev;
    temp2 = temp2->next;
    temp3 = temp3->next->next->next;
    if (temp1->circle == true && temp2->circle == true && temp3->circle == true)
    {
        cout << "player two won !" << endl;  return false;
    }
    //------------3,2,1
    for (int i = 1; i <= 4; i++)
    {
        temp1 = temp1->next;
    }
    temp2 = temp2->next->next;
    if (temp1->circle == true && temp2->circle == true && temp3->circle == true)
    {
        cout << "player two won !" << endl;  return false;
    }
    return true;


}

void startGame(int first, board* fullBoard)
{
    // putting the value at each linked list from 1 to 9
    int choice;
    char imp;
    bool isPlaying;


    for (int i = 1; i <= 9; i++)
        fullBoard = getBoard(fullBoard);

    //creating the frame

    bool isGameOn = true;
    int i = 1;
    while (isGameOn == true)
    {

        board* current = fullBoard;
        while (current != NULL)
        {

            if (current->empty == true)
                cout << "   " << current->pos;
            else if (current->circle == true)
                cout << "   " << "O";
            else
                cout << "   " << "X";
            if (current->pos == 4 || current->pos == 7)
            {
                cout << "\n";
                cout << "-----------------------\n";

            }
            else if (current->pos == 1)
                cout << "\n";
            else
                cout << "   |";
            current = current->next;

        }



        if (first == 1)
        {
            isPlaying = true;
            while (isPlaying == true)
            {
                cout << "Player 1, please put the number corresponding to the area you want to fill: ";
                cin >> imp;
                cin.clear();
                cin.ignore();
                choice = ((int)imp - 48);


                while (imp < '1' || imp > '9')
                {
                    cout << "Invalid choice. Please choose a valid option: ";
                    cin >> imp;
                    choice = ((int)imp - 48);
                    cin.clear();
                    cin.ignore();

                }
                current = fullBoard;
                while (current != NULL && current->pos != choice)
                    current = current->next;

                if (current->empty == true)
                {
                    current->empty = false;
                    current->square = true;
                    isPlaying = false;
                    first = 2;
                }
                else
                    cout << "The field that you chose is already used...\n";
            }

        }
        else
        {
            isPlaying = true;
            while (isPlaying == true)
            {
                cout << "Player 2, please put the number corresponding to the area you want to fill: ";
                cin >> imp;
                cin.clear();
                cin.ignore();
                choice = ((int)imp - 48);
                while (choice < 1 || choice > 9)
                {
                    cout << "Invalid choice. Please choose a valid option: ";
                    cin >> imp;
                    cin.clear();
                    cin.ignore();
                    choice = ((int)imp - 48);
                }
                current = fullBoard;
                while (current != NULL && current->pos != choice)
                    current = current->next;

                if (current->empty == true)
                {
                    current->empty = false;
                    current->circle = true;
                    isPlaying = false;
                    first = 1;
                }
                else
                    cout << "The field that you chose is already used...\n";
            }
        }


        system("cls");
        i++;
        if (wonx(fullBoard) == false)
            isGameOn = false;
        else if (wono(fullBoard) == false)
            isGameOn = false;

        else if (i > 9)
        {
            cout << "Oops ! It's a draw !" << endl;  isGameOn == false; break;
        }


    }
   // cout << "press any key to restart" << endl;
    system("pause > nul");

    system("cls");
    return;

}

board* getBoard(board* fullBoard)
{
    board* newBoard = new board;
    newBoard->empty = true;
    newBoard->circle = false;
    newBoard->square = false;
    newBoard->next = fullBoard;

    if (newBoard->next != NULL)
    {
        newBoard->pos = newBoard->next->pos + 1;
        fullBoard->prev = newBoard;
    }
    else
        newBoard->pos = 1;
    return newBoard;


}




typedef struct {
    int* row;
}WinList;



class Player {
private:
    string name;
    int score;
public:
    Player() :Player{ "" } {}
    Player(string n) :score{ 0 }, name{ n }{}

    void won() {

        score++;
    }
    int getScore() { return this->score; }

    string getName() { return this->name; }
};

class Game {
private:
    char board[9];
    int emptyIndex[9];
    int gameOn, againstComputer;
    int emptyCount;
    WinList winlist[8];

    void displayBoard() {
        cout << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
        cout << "   |   |   " << endl;
        cout << "-----------" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
        cout << "   |   |   " << endl;
        cout << "-----------" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
        cout << "   |   |   " << endl;
        cout << endl;
    }

    void computerInput() {
        int pos;
       pos = rand() % 10;

        if (emptyIndex[pos] == 1) {
            if (emptyCount < 0)
                return;
            computerInput();
        }
        else {
            cout << "Computer choose: " << pos + 1 << endl;
            emptyIndex[pos] = 1;
            emptyCount -= 1;
            board[pos] = 'O';
        }

    }

    void playerInput(Player& player) {
        int pos;
        cout << endl;
        cout << "\t" << player.getName() << " Turn: ";
        cout << "\t Enter the position " << endl;
        cin >> pos;
        pos -= 1;
        if (emptyIndex[pos] == 1) {
            cout << "The field that you chose is already used" << endl;
            playerInput(player);
        }
        else {
            emptyIndex[pos] = 1;
            emptyCount -= 1;
            player.getName().compare("Player I") == 0 ? board[pos] = 'X' : board[pos] = 'O';
        }

    }

    void checkWin(Player& p1, Player& p2) {
        int i, j, k;
        bool flag = false;
        char first_symbol;
        for (i = 0; i < 8; i++) {
            first_symbol = board[winlist[i].row[0]];

            if ((first_symbol != 'X') && (first_symbol != 'O')) {
                flag = false;
                continue;
            }
            flag = true;
            for (j = 0; j < 3; j++) {
                if (first_symbol != board[winlist[i].row[j]]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                gameOn = 0;
                if (first_symbol == 'X') {
                    cout << "-----------------------" << endl;
                    cout << "\t Player I WON" << endl;
                    cout << "-----------------------" << endl;
                    p1.won();
                }
                else {
                    p2.won();
                    if (againstComputer) {
                        cout << "-----------------------" << endl;
                        cout << "\t Computer WON" << endl;
                        cout << "-----------------------" << endl;
                    }
                    else {
                        cout << "-----------------------" << endl;
                        cout << "\t Player II WON" << endl;
                        cout << "-----------------------" << endl;

                    }
                }
                displayScore(p1, p2);
                break;
            }
        }
    }

    void play(Player& p1, Player& p2) {
        int hand = 0;
        gameOn = 1;
        displayBoard();
        while ((emptyCount > 0) && (gameOn != 0)) {

            if (againstComputer)
                hand == 1 ? computerInput() : playerInput(p2);
            else
                hand == 1 ? playerInput(p1) : playerInput(p2);
            hand = !hand;
            displayBoard();
            checkWin(p1, p2);
        }
        if (emptyCount <= 0) {
            cout << "      -----------------------" << endl;
            cout << "\t Oops it's a draw !" << endl;
            cout << "      -----------------------" << endl;
        }
        cout << endl;


    }
    void displayScore(Player& p1, Player& p2) {
        cout << endl;
        cout << "\t SCORE: \t";
        if (againstComputer)
            cout << " Player I: " << p1.getScore() << " \t Computer: " << p2.getScore() << endl;
        else
            cout << " Player I: " << p1.getScore() << " \t Player II: " << p2.getScore() << endl;
    }

public:
    Game() : emptyCount{ 0 }, gameOn{ 1 }, againstComputer{ 0 }{
        init();
        winlist[0].row = new int[3]{ 0,1,2 };
        winlist[1].row = new int[3]{ 3,4,5 };
        winlist[2].row = new int[3]{ 6,7,8 };
        winlist[3].row = new int[3]{ 0,3,6 };
        winlist[4].row = new int[3]{ 1,4,7 };
        winlist[5].row = new int[3]{ 2,5,8 };
        winlist[6].row = new int[3]{ 0,4,8 };
        winlist[7].row = new int[3]{ 2,4,6 };
    }

    void init() {
        gameOn = 1;

        emptyCount = 0;
        srand(time(0));
        for (size_t i = 0; i < 10; i++) {
            emptyIndex[i] = 0;
            board[i] = (i + 1) + '0';
            emptyCount++;
        }
        emptyCount--;
    }

    void onePlayerGame() {
        //Creating Player
        Player p("Player I");
        Player c("Computer");
        cout << "       -----------------------" << endl;
        cout << "\t Player I: X \t Computer: O" << endl;
        cout << "       -----------------------" << endl;
        cout << endl;
        againstComputer = 1;
        play(c, p);

    }
};

int main()
{ game:
   auto start = chrono::steady_clock::now();
    int good = 1;
    int dice, first;
    int decide;
    board* fullBoard = NULL;
    system("Color F4");
    cout << "Welcome to Tic-Tac-Toe ! " << endl << endl;

again:
    cout << "     1." << "Press 1 to play Vs the computer ! " << endl;
    cout << "     2."<<  "Press 2 to play Vs Your friend  ! " << endl;

    cin >> decide;
    if (decide == 2)
    {
        good = 0;
        cout << "Player 1 is 'X'" << endl << "Player 2 is 'O' " << endl ;
        cout << " Let me pick who is going first ! ";
        srand(time(NULL));
        dice = rand() % 6 + 1;

        cout << endl;
        if (dice <= 3)
        {
            first = 1;
            cout << "Player 1 Starts!\n";
        }
        else
        {
            first = 2;
            cout << "Player 2 Starts!\n\n";
        }
        system("pause");
        system("cls");
        //infinite loop for the game to restart
        //int j = 5;
        //while (j > 0)
            startGame(first, fullBoard);
            auto end = chrono::steady_clock::now();
            cout << "Elapsed time in seconds: "
        << chrono::duration_cast<chrono::seconds>(end - start).count()
        << " sec"<<endl;
        cout << "Press any key to play again ! ";
       char replay = '\0';
        cin >> replay;
       if (replay) {
           goto game;
       }

    }
    if (decide == 1)
    {
        good = 0;
        Game* game = new Game;
        game->init();
        game->onePlayerGame();
        auto end = chrono::steady_clock::now();
        cout << "Elapsed time in seconds: "
        << chrono::duration_cast<chrono::seconds>(end - start).count()
        << " sec"<<endl;
 cout << "Press any key to play again ! ";
       char replay = '\0';
        cin >> replay;
       if (replay) { goto game;

       }
    }
    if (decide != 1 && decide != 2)
    {
        system("cls");
        cout << " Wrong Input ! " << endl;
        goto again;
    }
    return 0;
}
