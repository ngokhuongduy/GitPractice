#include <iostream>
#include <conio.h>
const int size = 5 ;
using namespace std;

int menu(){
	int c;
	cout <<"Welcom To Tic-Tac-Toe game! Play with your way!"<< endl;
	cout <<"If you find any problem, please contact ngokhuongduy39@gmail.com"<< endl;
	cout <<"SELECT YOUR MODE  (1 - PLAY GAME, OTHER - EXIT GAME): ";
	cin >> c;
	return c;
}
void printBoard(char arr[][size]){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}
 
bool isWin(char arr[][size], int r, int c, char ch){
	if (arr[r][c]==ch){
        if ((arr[r][c] == arr[r+1][c]) && (arr[r+1][c] == arr[r+2][c])) 
		{
			return true;
		}
		else if ((arr[r][c] == arr[r][c+1]) && (arr[r][c+1] == arr[r][c+2])) 
		{
			return true;
		}
		else if ((arr[r][c] == arr[r+1][c+1]) && (arr[r+1][c+1] == arr[r+2][c+2])) 
		{
       		return true;
		}
		else if ((arr[r][c] == arr[r-1][c+1]) && (arr[r-1][c+1] == arr[r-2][c+2])) 
		{
			return true;
		}
		return false;
	}
}
bool isDraw(char arr[][size]){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (arr[i][j] == '-')
                return false;
        }
    }
        return true;
}
 
int main(){
	char board[size][size];
	char p1name[20],p2name[20];
	if(menu()==1){
		cout<<"Enter Player 1 name: ";
		cin >>p1name;
		cout<<"Enter Player 2 name: ";
		cin >>p2name;
    	for (int i = 0; i < size; i++){
        	for (int j = 0; j < size; j++){
            	board[i][j] = '-';
        	}
    	}
    	bool isGameEnd = false;
    	int row, col, playerTurn = 1;
    	char player;
    	while (!isGameEnd){
        	system("cls");
        	printBoard(board);
        	if (playerTurn == 1)
				{
            	    player = 'X';
            		cout << "Your turn " << p1name << " - "  << player <<":";
            		playerTurn = 2;
        		}
        		else if (playerTurn == 2)
				{
            		player = 'O';
            		cout << "Your turn " << p2name << " - "  << player <<":";
            		playerTurn = 1;
        		}
        		do{
        			cin >> row >> col;
        	}
			while (!(row >= 0 && row < size && col >= 0 && col < size && board[row][col] == '-'));
        	board[row][col] = player;
        	if (isWin(board,row,col,player)){
            	system("cls");
            	printBoard(board);
            	cout << "Player " << player << " Wins" << endl;
            	isGameEnd = true;
        	}
        	else if (isDraw(board)){
            	system("cls");
            	printBoard(board);
            	cout << "Game Draw" << endl;
            	isGameEnd = true;
        	}
    	}	
	}
    return (0);
}