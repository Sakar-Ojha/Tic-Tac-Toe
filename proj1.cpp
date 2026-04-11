/*
File: proj1.cpp
Project: CMSC 202 Project 1, Fall 2021
Author: Sakar Ojha
Date: 2/22/2025
Section:21
Email: o66@umbc.edu

This file contains the code for a tic-tac-toe game that is playyed between 2 players
Lets the user play again or quit and Displays output as the game goes on while also 
saving the output in a different .txt file.
*/

#include <iostream>
#include <fstream>

using namespace std;

const char SYMBOL1 = 'X'; //The symbol X
const char SYMBOL2 = 'O'; //The symbol O
char userSymbol; //THe symbol user picks
const int ARR_SIZE = 3; //Size of array 1st and 2nd dimensions 

void displayBoard(char array[][ARR_SIZE]);
void clearBoard(char array[][ARR_SIZE]);
void chooseSymbol();
bool checkRowCol(char array[][ARR_SIZE], int row, int column);
void makeMove(char array[][ARR_SIZE], int row, int column, char currentSymbol);
bool checkWin(char array[][ARR_SIZE], char symbol);
bool checkDraw(char array[][ARR_SIZE]);
bool mainMenu();
char whooseTurn(int turn, char player1, char player2);
char player2Symbol();
void playGame();

// -------------------------------------------
// -------------------------------------------
/*
Function: main
Pre-Condition: None.
Post-Condition: Calls playGame() to start the game.
*/
int main(){
    playGame();
    return 0;
}

// -------------------------------------------
// -------------------------------------------
/*
Function: displayBoard
Pre-Condition: A 3x3 tic-tac-toe board with valid characters ('X', 'O', '_').
Post-Condition: Prints the board to the console.
*/
void displayBoard(char array[][ARR_SIZE]){
    cout << "Current Board:" << endl;
    // double looping through the array
    for (int i = 0; i < ARR_SIZE; i++){
        for(int j = 0; j < ARR_SIZE; j++){
            //  adding a space for formatting 
            cout << array[i][j] << " ";           
            }
        cout << endl;
    }
    return;
}
// -------------------------------------------
// -------------------------------------------

/*
Function: clearBoard
Pre-Condition: A 3x3 tic-tac-toe board exists.
Post-Condition: Resets all board positions to '_'.
*/
void clearBoard(char array[][ARR_SIZE]){
    cout << "Clearing the Board..." << endl;
    for (int i = 0; i < ARR_SIZE; i++){
        // storing underscore character for every elemeent
        for (int j = 0; j < ARR_SIZE; j++){
            array[i][j] = '_'; 
        }
    }
}
// -------------------------------------------
// -------------------------------------------

/*
Function: chooseSymbol
------------------------
Pre-Condition: 
user input from the user of type character, preferably SYMBOL1 or SYMBOL2
------------------------
Post-Condition: 
If the user enters a valid symbol (SYMBOL1 or SYMBOL2), USER_SYMBOL is 
updated to store that value.If the user enters an invalid symbol, the 
function repeatedly prompts for valid input until a correct value is entered.
No RETURNS, just modifies the global variable userSymbol.
*/
void chooseSymbol(){
    char userInput;

    cout << "Choose a symbol: " << SYMBOL1 << " or " << SYMBOL2 << endl;
    cin >> userInput; 

    while((userInput != SYMBOL1) && (userInput != SYMBOL2)){
        cout << "Invalid input: Please select either" << SYMBOL1 << " or " << SYMBOL2 << endl;
        cin >> userInput;
    } 
    
    userSymbol = userInput; 
    cout << "Chosen " << userSymbol << endl;
}

// -------------------------------------------
// -------------------------------------------
/*
Function: checkRowCol
Pre-Condition: A valid tic-tac-toe board exists.
               User inputs row and column.
Post-Condition: Returns true if row and column are within bounds and unoccupied.
                Otherwise, prints an error message and returns false.
*/
bool checkRowCol(char array[][ARR_SIZE], int row, int column){
    //condition to check if input is in range
    //greater than of equal to 3 is out of bounds
    if ((row >= ARR_SIZE || row < 0) || (column >= ARR_SIZE || column < 0)){ 
        cout << "Please select from range (0-2) Inclusive" << endl;
        return false;
    }

    if (array[row][column] != '_'){    
        cout << "That place is already occupied." << endl;
        return false;
    }
    return true;
}

// -------------------------------------------
// -------------------------------------------
/*
Function: makeMove
Pre-Condition: A valid tic-tac-toe board exists.
               The row and column are valid and unoccupied.
Post-Condition: Places the current player's symbol at the given row and column.
*/
void makeMove(char array[][ARR_SIZE], int row, int column, char currentSymbol){
    array[row][column] = currentSymbol;
}

// -------------------------------------------
// -------------------------------------------
/*
Function: checkWin
Pre-Condition: A valid tic-tac-toe board exists.
Post-Condition: Returns true if the given symbol has a winning row, column, or diagonal.
                Otherwise, returns false.
*/
bool checkWin(char array[][ARR_SIZE], char symbol){
    for (int i = 0; i < ARR_SIZE; i++){
        if ((array[i][0] == symbol) && 
            (array[i][1] == symbol) && (array[i][2] == symbol)){
            return true;
            }
    }

    for (int i = 0; i < ARR_SIZE; i++){
        if ((array[0][i]) == symbol && 
            (array[1][i] == symbol) && (array[2][i] == symbol)){
            return true;
        }
    }

    if ((array[0][0]== symbol) && 
        (array[1][1]== symbol) && (array[2][2]== symbol)){
        return true;
    }

    if ((array[0][2]== symbol) && 
        (array[1][1]== symbol) && (array[2][0]== symbol)){
        return true;
    }

    return false;
}

// -------------------------------------------
// -------------------------------------------
/*
Function: checkDraw
Pre-Condition: A valid tic-tac-toe board exists.
Post-Condition: Returns true if there are no empty spaces and no winner.
                Otherwise, returns false.
*/
bool checkDraw(char array[][ARR_SIZE]){
    for (int i = 0; i < ARR_SIZE; i++){
        for (int j = 0; j < ARR_SIZE; j++){
            if(array[i][j] == '_'){
                return false;
            }
        }
    }
    //if there are no empty spaces to draw on, its a draw
    return true; 
}

// -------------------------------------------
// -------------------------------------------
/*
Function: mainMenu
Pre-Condition: None.
Post-Condition: Returns true if user chooses to play, false if they choose to exit.
*/
bool mainMenu(){
    //initializing variable for user's input
    int userChoice;

    cout << "Welcome to Tic-Tac_Toe" << endl;
    cout << "What would you like to do?\n"
         << "1. Play New Game\n"
         << "2. Exit" << endl;
    
    do{
        cin >> userChoice;
        if ((userChoice != 1) && (userChoice != 2)){
            cout << "Invalid choice, select (1 or 2): " << endl;
        }
    }
    // repeat until the input is 1 or 2
    while ((userChoice != 1) && (userChoice != 2));  
    
    if (userChoice == 1){
        // means they want to keep playing
        return true; 
    }
    else{
        //means they want to quit
        return false; 
    }
}

// -------------------------------------------
// -------------------------------------------
/*
Function: whooseTurn
Pre-Condition: Turn count is given.
Post-Condition: Returns the current player's symbol based on the turn count.
*/
char whooseTurn(int turn, char player1, char player2){
    // The current symbol/ player playing
    char currentSymbol;
    
    if ((turn % 2) == 0){
        currentSymbol = player1;
    }
    else{
        currentSymbol = player2;
    }
    return currentSymbol;
}
// -------------------------------------------
// -------------------------------------------
/*
Function: player2Symbol
Pre-Condition: The user has already chosen a symbol.
Post-Condition: Returns the opposite symbol for player 2.
*/
char player2Symbol(){
    char player1 = userSymbol;
    // Declaring player2 symbol
    char player2; 

    if (player1 == SYMBOL1){
        // player2 is the opposite symbol of what player 1 choses 
        player2 = SYMBOL2; 
    } 
    else{
        player2 = SYMBOL1;
    }
    return player2;
}

// -------------------------------------------
// -------------------------------------------
/*
Pre-condition:  A 2D character array (`array`) of size `ARR_SIZE x ARR_SIZE` is passed, 
                representing the current tic-tac-toe board.
                The program has permission to create/write to a file (`game_result.txt`).
                The file should not be open elsewhere in a way that prevents writing.
post-condition:A new text file named `"game_result.txt"` is created or overwritten.
               The final tic-tac-toe board state is written to the file.
*/
void saveGameResult(char array[][ARR_SIZE]){
    ofstream outFile("proj1_data.txt");

    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    outFile << "Final Board State:" << endl;
    for (int i = 0; i < ARR_SIZE; i++) {
        for (int j = 0; j < ARR_SIZE; j++) {
            outFile << array[i][j] << " ";
        }
        outFile << endl;
    }

    outFile.close();
}



// -------------------------------------------
// -------------------------------------------
/*
Function: playGame
Pre-Condition: None.
Post-Condition: Runs the game loop, allowing players to play until they quit.
*/
void playGame(){
    char array[ARR_SIZE][ARR_SIZE] = {{'_', '_','_'},
                                      {'_', '_','_'},
                                      {'_', '_','_'}};
    //determines when to end the game
    bool game_over; 

    //while they want to keep playing
    while(mainMenu()){
        game_over = false;
        chooseSymbol();
        char player1 = userSymbol;
        char player2 = player2Symbol();
        //initialized as 0 since player1 is first
        int turn = 0; 
        //Displays the empty board before letting user input
        displayBoard(array); 

        //until game isnt over
        while (!(game_over)){ 
            
            char currentSymbol = whooseTurn(turn, player1, player2);
            //increasing the value of turn by one for the next player
            turn ++; 
            //Declaring to use as users choice of position
            int row;
            int col; 
            
            cout << "Player" << currentSymbol <<", enter row and column(0-2): ";
            cin >> row >> col;
            //If the function checkRowCol evaluates to false with given input, it keeps asking/looping
            while (checkRowCol(array,row,col) == false){ 
                displayBoard(array);
                cout << "Player " << currentSymbol << ", enter row and column(0-2): ";
                cin >> row >> col;
            }
            //Puts the symbol in array after check
            makeMove(array, row, col, currentSymbol); 
            //shows the new input symbol
            displayBoard(array); 

            if (checkWin(array, currentSymbol)){
                cout << "Player " << currentSymbol << ", WINS!" << endl;
                //game_over is set to true to end the loop
                game_over = true; 
            }
            else{
                //If game is draw
                if(checkDraw(array)){ 
                    cout << "The game is a draw!" << endl;
                    cout << "Thank you for playing Tic-Tac-Toe" << endl;
                    game_over = true;
                }
            }
            saveGameResult(array);
        }
        
        clearBoard(array);
    } 
}