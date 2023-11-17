#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void PlayerMove();
void ComputerMove();
char Winner();
int  FreePlaces();
void PrintBoard();
void ResetBoard();





int main (void){
    char winner = ' ';
    ResetBoard();

    printf("Bienvenue au jeu celebere tic tac toe !\n");
    printf("imagine que le jeu est une matrice et selectione les case :\n");

    
    

while (FreePlaces() != 0 && winner == ' ')
{
    PrintBoard();
    if (Winner() != ' ') 
    {
            winner = Winner();
            printf("le gagnant est : %c",winner);
            break;
    }
    PlayerMove();
    ComputerMove();
    
}


    

  
}

void ResetBoard(){
    
    for (int i = 0 ; i < 3 ; i++)
    {
        for (int j = 0 ; j < 3 ; j++)
        {
            board[i][j] = ' ';
        }
    }
}


void PrintBoard(){
      
        printf(" %c | %c | %c ",board[0][0],board[0][1],board[0][2]);
        printf("\n---|---|---\n");
        printf(" %c | %c | %c ",board[1][0],board[1][1],board[1][2]);
        printf("\n---|---|---\n");
        printf(" %c | %c | %c ",board[2][0],board[2][1],board[2][2]);
        printf("\n");
}

int FreePlaces(){
    int FP = 9;
    

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                FP--;
            }
            
        }
        
    }   
    return FP;
}


void PlayerMove(){
    int x , y ;

    printf("saisir la ligne : ");
    scanf("%d",&x);
    x--;

    printf("saisir la colonne : ");
    scanf("%d",&y);
    y--; 
    if (board[x][y] != ' ')
    {
      do{
        printf("la case que vous avez choisie est occupee , veuillez resesir une nouvelle case ! \n");
        printf("saisir la ligne : ");
        scanf("%d",&x);
        x--;

        printf("saisir la colonne : ");
        scanf("%d",&y);
        y--; 
    
        }while (board[x][y] != ' ');
    }
    board[x][y] = 'X' ;
  
}

void ComputerMove(){
    int x , y ;
    
    srand(time(0));
do{
    x = rand() % 3 ;
    y = rand() % 3 ;
    
  }while(board[x][y] != ' ');

  board[x][y] = 'O' ;
}

char Winner(){
int i ;
for ( i = 0; i < 3; i++)
{
    
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
         {
            return board[i][0];
         }else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ' )
         {
            return board[0][i];
         }else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
         {
            return board[0][0];
         }else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
         {
            return board[0][2];
         }

    }  
}