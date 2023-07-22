#include "SUDOKU_Cfg.h"
#include "SUDOKU_Private.h"
#include "SUDOKU.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

char Editable_Fields_Array[(GAME_SIZE * GAME_SIZE) + 1] = {0};

void Sudoku_Init(void)
{
    char i, j;
    game_moves = 0;
    for (i = 0; i < GAME_SIZE; i++)
    {
        for (j = 0; j < GAME_SIZE; j++)
        {
            if (Game_Data[i][j] == 0)
            {
                Editable_Fields_Array[(i * GAME_SIZE) + j] = 1;
                game_moves++;
            }
        }
    }
}

error_t Sudoku_Check(void)
{
    char i, k;
    char j = (char)sqrt(GAME_SIZE); // number of mini matrices in each row or col in the game
    char mini_i, mini_j;

    error_t status = OK;

    if ((Editable_Fields_Array[(row * GAME_SIZE) + col] == 1) && (input != 0))
    {
        for (i = 0; i < GAME_SIZE; i++)
        {
            if (input == Game_Data[i][col])
            {
                status = COL_Error;
                break;
            }
        }
        for (i = 0; i < GAME_SIZE; i++)
        {
            if (input == Game_Data[row][i])
            {
                if (status == COL_Error)
                {
                    status = ROW_COL_Error;
                }
                else
                {
                    status = ROW_Error;
                }
                break;
            }
        }
        if (status == OK)
        {
            mini_i = row / j;
            mini_j = col / j;
            mini_i *= j;
            mini_j *= j;
            for (i = mini_i; i < mini_i + j; i++)
            {
                for (k = mini_j; k < mini_j + j; k++)
                {
                    if (input == Game_Data[i][k])
                    {
                        status = CELL_Error;
                        break;
                    }
                }
            }
        }
    }
    else if ((Editable_Fields_Array[(row * GAME_SIZE) + col] == 1) && (input == 0))
    {
        status = OK;
    }
    else
    {
        status = NO_EDIT_Error;
    }
    return status;
}

void Sudoku_GUI(error_t status)
{
    system("cls");
    char i, j;
    char mini_i = sqrt(GAME_SIZE);

    for (i = 0; i < GAME_SIZE; i++)
    {
        if ((i % mini_i) == 0)
        {
            for (char k = 0; k < GAME_SIZE + mini_i; k++)
            {
                printf(ANSI_GREEN " --- ");
                printf(ANSI_RESET);
            }
            printf(ANSI_GREEN "  |");
            printf(ANSI_RESET);
            printf("\n");
        }
        for (j = 0; j < GAME_SIZE; j++)
        {
            if ((j % mini_i) == 0)
            {
                printf(ANSI_GREEN "  |  ");
                printf(ANSI_RESET);
            }
            if (Game_Data[i][j] == 0)
            {
                printf(ANSI_BLUE " <_> ");
                printf(ANSI_RESET);
            }
            else
            {
                if ((Editable_Fields_Array[(i * GAME_SIZE) + j] == 1))
                {
                    printf(ANSI_YELLOW "  %d  ", Game_Data[i][j]);
                    printf(ANSI_RESET);
                }
                else
                {
                    printf("  %d  ", Game_Data[i][j]);
                }
            }
        }
        printf(ANSI_GREEN "  |");
        printf(ANSI_RESET);
        printf("\n");
    }
    for (char k = 0; k < GAME_SIZE + mini_i; k++)
    {
        printf(ANSI_GREEN " --- ");
        printf(ANSI_RESET);
    }
    printf(ANSI_GREEN "  |");
    printf(ANSI_RESET);
    printf("\n");
    switch (status)
    {
    case ROW_Error:
        MessageBox(0, "WRONG NUMBER!!!\n Number is Available more than once in the ROW!!!", "WARNING", 0);
        fflush(stdout);
        break;
    case COL_Error:
        MessageBox(0, "WRONG NUMBER!!!\n Number is Available more than once in the COL!!!", "WARNING", 0);
        break;
    case ROW_COL_Error:
        MessageBox(0, "WRONG NUMBER!!!\n Number is Available more than once in the ROW and COL!!!", "WARNING", 0);
        break;
    case CELL_Error:
        MessageBox(0, "WRONG NUMBER!!!\n Number is Available more than once in the CELL(mini matrix)!!!", "WARNING", 0);
        break;
    case NO_EDIT_Error:
        MessageBox(0, "WRONG POSITION!!!\n YOU Can't EDIT Constant POSITIONS!!!", "WARNING", 0);
        break;
    case INVALID_INPUT_Error:
        MessageBox(0, "WRONG INPUT!!!\n Entered Position OR Number is WRONG!!!", "WARNING", 0);
        break;
    case GAME_DONE:
        MessageBox(0, "CONGRATULATIONS!!!\n YOU WON :)!!!", "FINISHED", 0);
        break;
    }
}
void Sudoku_EditGame(void)
{
    if ((Game_Data[row][col] == 0) && (input != 0))
    {
        game_moves--;
    }
    else if ((Game_Data[row][col] != 0) && (input == 0))
    {
        game_moves++;
    }
    Game_Data[row][col] = input;
}

error_t Sudoku_GetInput(void)
{
    error_t status = OK;
    int temp_input;
    int temp_row;
    int temp_col;
    printf("enter number : \n");
    scanf("%d", &temp_input);
    printf("enter input row : \n");
    scanf("%d", &temp_row);
    printf("enter input col : \n");
    scanf("%d", &temp_col);

    if ((temp_input < 0) || (temp_input > GAME_SIZE) || (temp_row < 0) || (temp_row > GAME_SIZE) || (temp_col < 0) || (temp_col > GAME_SIZE))
    {
        status = INVALID_INPUT_Error;
    }
    else
    {
        input = temp_input;
        row = temp_row;
        col = temp_col;
    }
    return status;
}

void Sudoku_Game(void)
{
    error_t status = OK;
    Sudoku_Init();
    Sudoku_GUI(status);
    while (game_moves)
    {
        fflush(stdin);
        status = Sudoku_GetInput();
        if (status == INVALID_INPUT_Error)
        {
            Sudoku_GUI(status);
        }
        else
        {
            status = Sudoku_Check();
            if (status == OK)
            {
                Sudoku_EditGame();
                Sudoku_GUI(status);
            }
            else
            {
                Sudoku_GUI(status);
            }
        }
    }
    Sudoku_GUI(GAME_DONE);
}
