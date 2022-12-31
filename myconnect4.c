#include <stdio.h>

void clearboard(char board[6][7]);
void printboard(char board[6][7]);
void readplayernames(char player1, char player2);
void playgame(char board[6][7], char player1, char player2, int movesplayed);
void showmenu();
int makemove(char board[6][7], int movesplayed, char player1, char player2);
int checkforwinner(char board[6][7]);

int main() {

  int endofprogram = 0;

  while (endofprogram == 0) {
    char board[6][7];
    char player1 = 'X';
    char player2 = 'O';
    int movesplayed = 0;

    showmenu();

    int choice;
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      clearboard(board);
      readplayernames(player1, player2);
      playgame(board, player1, player2, movesplayed);
      break;
    case 2:
      printf("goodbye!\n");
      endofprogram = 1;
      break;
    default:
      printf("Wrong choice, try again!\n");
    }
  }

  return 0;
}

void clearboard(char board[6][7]) {
  int i;
  int j;

  for (i = 0; i < 6; i++) {
    for (j = 0; j < 7; j++) {
      board[i][j] = ' ';
    }
  }
}

void printboard(char board[6][7]) {
  int i;
  int j;

  char line1[] = "  1   2   3   4   5   6   7  ";
  char lines[] = "|---|---|---|---|---|---|---|";
  system("clear");
  printf("%s\n", line1);
  printf("%s\n", lines);

  for (i = 0; i < 6; i++) {
    for (j = 0; j < 7; j++) {
      printf("| %c ", board[i][j]);
    }
    printf("|\n");
    printf("%s\n", lines);
  }
}

void readplayernames(char player1, char player2) {
  player1 = 'X';
  player2 = 'O';
}

void playgame(char board[6][7], char player1, char player2, int movesplayed) {
  while (1) {
    printboard(board);

    if (makemove(board, movesplayed, player1, player2) == 1) {
      break;
    }

    movesplayed++;

    int result = checkforwinner(board);
    if (result != 0) {
      printboard(board);

      if (result == 1) {
        printf("\nX wins\n\n");
      }

      else if (result == 2) {
        printf("\nO wins\n\n");
      }

      break;
    }

    if (movesplayed == 42) {
      printboard(board);
      printf("\nTie!\n\n");
      break;
    }
  }
}

void showmenu() {
  printf("\n\n1.New Game\n");
  printf("2.Exit\n");
  printf("choose: ");
}

int makemove(char board[6][7], int movesplayed, char player1, char player2) {
  char sign = 'X';

  if (movesplayed % 2 == 1) {
    sign = 'O';
  }

  int column, i, j;

  while (1) {
    printf("\nplayer %c's turn: ", sign);

    scanf("%d", &column);

    if (column >= 0) {
      break;
    }
    printf("\nMove not allowed!\n");
  }

  if (column != 0) {
    for (i = 6; i >= 0; i--) {
      if (board[i][column - 1] == ' ') {
        board[i][column - 1] = sign;
        printf("\n\n");
        break;
      }
    }
  }

  else {
    return 1;
  }

  return 0;
}

int checkforwinner(char board[6][7]) {
  // check rows
  int i;
  int j;

  for (i = 0; i < 6; i++) {
    if ((board[i][0] == board[i][1]) && (board[i][0] == board[i][2]) &&
        (board[i][0] == board[i][3])) {
      if (board[i][0] == 'X') {
        return 1;
      } else if (board[i][0] == 'O') {
        return 2;
      }
    }
    if ((board[i][1] == board[i][2]) && (board[i][1] == board[i][3]) &&
        (board[i][1] == board[i][4])) {
      if (board[i][1] == 'X') {
        return 1;
      } else if (board[i][1] == 'O') {
        return 2;
      }
    }
    if ((board[i][2] == board[i][3]) && (board[i][2] == board[i][4]) &&
        (board[i][2] == board[i][5])) {
      if (board[i][2] == 'X') {
        return 1;
      } else if (board[i][2] == 'O') {
        return 2;
      }
    }
    if ((board[i][3] == board[i][4]) && (board[i][3] == board[i][5]) &&
        (board[i][3] == board[i][6])) {
      if (board[i][3] == 'X') {
        return 1;
      } else if (board[i][3] == 'O') {
        return 2;
      }
    }
  }

  // check columns

  for (j = 0; j < 7; j++) {
    if ((board[0][j] == board[1][j]) && (board[0][j] == board[2][j]) &&
        (board[0][j] == board[3][j])) {
      if (board[0][j] == 'X') {
        return 1;
      } else if (board[0][j] == 'O') {
        return 2;
      }
    }
    if ((board[1][j] == board[2][j]) && (board[1][j] == board[3][j]) &&
        (board[1][j] == board[4][j])) {
      if (board[1][j] == 'X') {
        return 1;
      } else if (board[1][j] == 'O') {
        return 2;
      }
    }
    if ((board[2][j] == board[3][j]) && (board[2][j] == board[4][j]) &&
        (board[2][j] == board[5][j])) {
      if (board[2][j] == 'X') {
        return 1;
      } else if (board[2][j] == 'O') {
        return 2;
      }
    }
  }

  // check diagonals
  if ((board[0][0] == board[1][1]) && (board[0][0] == board[2][2]) &&
      (board[0][0] == board[3][3])) {
    if (board[0][0] == 'X') {
      return 1;
    } else if (board[0][0] == 'O') {
      return 2;
    }
  }

  if ((board[0][1] == board[1][2]) && (board[0][1] == board[2][3]) &&
      (board[0][1] == board[3][4])) {
    if (board[0][1] == 'X') {
      return 1;
    } else if (board[0][1] == 'O') {
      return 2;
    }
  }

  if ((board[0][2] == board[1][3]) && (board[0][2] == board[2][4]) &&
      (board[0][2] == board[3][5])) {
    if (board[0][2] == 'X') {
      return 1;
    } else if (board[0][2] == 'O') {
      return 2;
    }
  }

  if ((board[0][3] == board[1][4]) && (board[0][3] == board[2][5]) &&
      (board[0][3] == board[3][6])) {
    if (board[0][3] == 'X') {
      return 1;
    } else if (board[0][3] == 'O') {
      return 2;
    }
  }

  if ((board[0][6] == board[1][5]) && (board[0][6] == board[2][4]) &&
      (board[0][6] == board[3][5])) {
    if (board[0][6] == 'X') {
      return 1;
    } else if (board[0][6] == 'O') {
      return 2;
    }
  }

  if ((board[0][5] == board[1][4]) && (board[0][5] == board[2][3]) &&
      (board[0][5] == board[3][2])) {
    if (board[0][5] == 'X') {
      return 1;
    } else if (board[0][5] == 'O') {
      return 2;
    }
  }

  if ((board[0][4] == board[1][3]) && (board[0][4] == board[2][2]) &&
      (board[0][4] == board[3][1])) {
    if (board[0][4] == 'X') {
      return 1;
    } else if (board[0][4] == 'O') {
      return 2;
    }
  }

  if ((board[0][3] == board[1][2]) && (board[0][3] == board[2][1]) &&
      (board[0][3] == board[3][0])) {
    if (board[0][3] == 'X') {
      return 1;
    } else if (board[0][3] == 'O') {
      return 2;
    }
  }

  if ((board[1][0] == board[2][1]) && (board[1][0] == board[3][2]) &&
      (board[1][0] == board[4][3])) {
    if (board[1][0] == 'X') {
      return 1;
    } else if (board[1][0] == 'O') {
      return 2;
    }
  }

  if ((board[1][1] == board[2][2]) && (board[1][1] == board[3][3]) &&
      (board[1][1] == board[4][4])) {
    if (board[1][1] == 'X') {
      return 1;
    } else if (board[1][1] == 'O') {
      return 2;
    }
  }

  if ((board[1][2] == board[2][3]) && (board[1][2] == board[3][4]) &&
      (board[1][2] == board[4][5])) {
    if (board[1][2] == 'X') {
      return 1;
    } else if (board[1][2] == 'O') {
      return 2;
    }
  }

  if ((board[1][3] == board[2][4]) && (board[1][3] == board[3][5]) &&
      (board[1][3] == board[4][6])) {
    if (board[0][0] == 'X') {
      return 1;
    } else if (board[0][0] == 'O') {
      return 2;
    }
  }

  if ((board[1][6] == board[2][5]) && (board[1][6] == board[3][4]) &&
      (board[1][6] == board[4][3])) {
    if (board[1][6] == 'X') {
      return 1;
    } else if (board[1][6] == 'O') {
      return 2;
    }
  }

  if ((board[1][5] == board[2][4]) && (board[1][5] == board[3][3]) &&
      (board[1][5] == board[4][2])) {
    if (board[1][5] == 'X') {
      return 1;
    } else if (board[1][5] == 'O') {
      return 2;
    }
  }

  if ((board[1][4] == board[2][3]) && (board[1][4] == board[3][2]) &&
      (board[1][4] == board[4][1])) {
    if (board[1][4] == 'X') {
      return 1;
    } else if (board[1][4] == 'O') {
      return 2;
    }
  }

  if ((board[1][3] == board[2][2]) && (board[1][3] == board[3][1]) &&
      (board[1][3] == board[4][0])) {
    if (board[1][3] == 'X') {
      return 1;
    } else if (board[1][3] == 'O') {
      return 2;
    }
  }

  if ((board[2][0] == board[3][1]) && (board[2][0] == board[4][2]) &&
      (board[2][0] == board[5][3])) {
    if (board[2][0] == 'X') {
      return 1;
    } else if (board[2][0] == 'O') {
      return 2;
    }
  }

  if ((board[2][1] == board[3][2]) && (board[2][1] == board[4][3]) &&
      (board[2][1] == board[5][4])) {
    if (board[2][1] == 'X') {
      return 1;
    } else if (board[2][1] == 'O') {
      return 2;
    }
  }

  if ((board[2][2] == board[3][3]) && (board[2][2] == board[4][4]) &&
      (board[2][2] == board[5][5])) {
    if (board[2][2] == 'X') {
      return 1;
    } else if (board[2][2] == 'O') {
      return 2;
    }
  }

  if ((board[2][3] == board[3][4]) && (board[2][3] == board[4][5]) &&
      (board[2][3] == board[5][6])) {
    if (board[2][3] == 'X') {
      return 1;
    } else if (board[2][3] == 'O') {
      return 2;
    }
  }

  if ((board[2][6] == board[3][5]) && (board[2][6] == board[4][4]) &&
      (board[2][6] == board[5][3])) {
    if (board[2][6] == 'X') {
      return 1;
    } else if (board[2][6] == 'O') {
      return 2;
    }
  }

  if ((board[2][5] == board[3][4]) && (board[2][5] == board[4][3]) &&
      (board[2][5] == board[5][2])) {
    if (board[2][5] == 'X') {
      return 1;
    } else if (board[2][5] == 'O') {
      return 2;
    }
  }

  if ((board[2][4] == board[3][3]) && (board[2][4] == board[4][2]) &&
      (board[2][4] == board[5][1])) {
    if (board[2][4] == 'X') {
      return 1;
    } else if (board[2][4] == 'O') {
      return 2;
    }
  }

  if ((board[2][3] == board[3][2]) && (board[2][3] == board[4][1]) &&
      (board[2][3] == board[5][0])) {
    if (board[2][3] == 'X') {
      return 1;
    } else if (board[2][3] == 'O') {
      return 2;
    }
  }

  if ((board[5][0] == board[4][1]) && (board[5][0] == board[3][2]) &&
      (board[5][0] == board[2][3])) {
    if (board[5][0] == 'X') {
      return 1;
    } else if (board[5][0] == 'O') {
      return 2;
    }
  }

  if ((board[5][1] == board[4][2]) && (board[5][1] == board[3][3]) &&
      (board[5][1] == board[2][4])) {
    if (board[5][1] == 'X') {
      return 1;
    } else if (board[5][1] == 'O') {
      return 2;
    }
  }

  if ((board[5][2] == board[4][3]) && (board[5][2] == board[3][4]) &&
      (board[5][2] == board[2][5])) {
    if (board[5][2] == 'X') {
      return 1;
    } else if (board[5][2] == 'O') {
      return 2;
    }
  }

  if ((board[5][3] == board[4][4]) && (board[5][3] == board[3][5]) &&
      (board[5][3] == board[2][6])) {
    if (board[5][3] == 'X') {
      return 1;
    } else if (board[5][3] == 'O') {
      return 2;
    }
  }

  if ((board[5][4] == board[4][3]) && (board[5][4] == board[3][2]) &&
      (board[5][4] == board[2][1])) {
    if (board[5][4] == 'X') {
      return 1;
    } else if (board[5][4] == 'O') {
      return 2;
    }
  }

  if ((board[5][5] == board[4][4]) && (board[5][5] == board[3][3]) &&
      (board[5][5] == board[2][2])) {
    if (board[5][5] == 'X') {
      return 1;
    } else if (board[5][5] == 'O') {
      return 2;
    }
  }

  if ((board[5][6] == board[4][5]) && (board[5][6] == board[3][4]) &&
      (board[5][6] == board[2][3])) {
    if (board[5][6] == 'X') {
      return 1;
    } else if (board[5][6] == 'O') {
      return 2;
    }
  }

  return 0;
}
