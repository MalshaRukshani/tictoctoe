#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char player1 [10];
char player2 [20];
int choice;

/**********draw the table**********/


void drawBoard()
{
    
    printf("\n\n\tTic Tac Toe \t\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

}


/******* file handling *******/
void file (int x)
{
    FILE *file;
    file = fopen("moves1.txt", "w");
     fscanf(file,"%d",&x);
    fclose (file);
}

/********find the winner *********/

int winner()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
        
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
        
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
        
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
        
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
        
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
        
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
        
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
        
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] 
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}



/********** play with computer**********/
void withComputer(){
    printf("Enter Player1 name (O): ");
    scanf("%s",player1);

    strcpy(player2,"Computer");

    while(1){
        
        int loc, player;
        printf("%s plays as (x) & %s plays as (0)\n\n",player1,player2);
        drawBoard();

        if(square[0] == 'X'){
            printf("%s Enter a number : ",player1);
            player = 1;
            scanf("%d", &choice);
            file (choice);
        } else {

            while(1){
                int r = rand() % 9;
                if(r != 0 && square[r] != 'O' && square[r] != 'X'){
                   choice = r;
                   break;
                }
            }
            player = 2;
        }

        if(choice < 1 || choice > 9){
            printf("INVALID MOVE\n");
            
            continue;
        }

        if(square[choice] != 'O' && square[choice] != 'X'){

            if(player == 1){
                square[choice] = 'O';
                square[0] = 'O';
                for(int i = 0; i < 5; i++){
                    if(square[i] == 0){
                        square[i] = choice;
                        break;
                    }
                }
            } else {
                square[choice] = 'X';
                square[0] = 'X';
                for(int i = 0; i < 5; i++){
                    if(square[i] == 0){
                        square[i] = choice;
                        break;
                    }
                }
            }

        } else {
            printf("INVALID MOVE\n");
            
            continue;
        }

        if(winner() == 0){
            continue;
        } else if (winner() == 1){

            if(player == 1){
                printf("COMPUTER WINS THE MATCH\n");
            } else {
                printf("%s WINS THE MATCH\n",player2);
            }
            
            break;

        } else if(winner() == 2){
            printf("MATCH IS DRAW\n");
          
            break;
        }
    }

    

}
 

/******** main function ******/
int main()
{   int type;
    int player = 1, i;
    printf("\n\n\tTic Tac Toe \t\n\n");
    printf("\nCHOICE 1 = computer vs player\n"); 
    printf("\nCHOICE 2 = player vs player\n"); 
    printf("\n\nENTER YOUR CHOICE : ");
    scanf ("%d",&type);
    
    if (type==1)
    
   { 
       withComputer();
       
   }
    
    
    else
    {
    char mark;
    do
    {
        drawBoard();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);
        file (choice);
        printf("player %d selected %d \n",player ,choice);
        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;
            
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
            
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
            
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
            
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
            
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
            
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
            
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
            
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
            
        else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
        i = winner();

        player++;
    }while (i ==  - 1);
    
    drawBoard();
    
    if (i == 1)
        printf("\nPlayer %d is the winner ", --player);
    else
        printf("\nGame is draw");

    getch();
}
    return 0;
}



