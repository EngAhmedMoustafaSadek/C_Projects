#ifndef SUDOKU_PRIVATE_H_INCLUDED
#define SUDOKU_PRIVATE_H_INCLUDED

#define ANSI_RED "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_BLUE "\x1b[34m"
#define ANSI_MAGENTA "\x1b[54m"
#define ANSI_CYAN "\x1b[36m"
#define ANSI_RESET "\x1b[0m"

typedef enum
{
    OK = 0,
    ROW_Error,
    COL_Error,
    ROW_COL_Error,
    CELL_Error,
    NO_EDIT_Error,
    INVALID_INPUT_Error,
    GAME_DONE
} error_t;

extern char Game_Data[GAME_SIZE][GAME_SIZE];

static int row;
static int col;
static int input;
static char game_moves;

void Sudoku_Init(void);
error_t Sudoku_Check(void);
void Sudoku_GUI(error_t status);
void Sudoku_EditGame(void);
error_t Sudoku_GetInput(void);

#endif // SUDOKU_PRIVATE_H_INCLUDED
