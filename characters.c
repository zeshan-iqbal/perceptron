#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "characters.h"


void makeCharacters (int characters[NB_CHAR][CHAR_HEIGHT][CHAR_WIDTH]) {
  int zero [7][4] = {
    {1,1,1,1},
    {1,0,0,1},
    {1,0,0,1},
    {1,0,0,1},
    {1,0,0,1},
    {1,0,0,1},
    {1,1,1,1},
  };
  int one [7][4] = {
    {0,0,1,0},
    {0,1,1,0},
    {1,0,1,0},
    {0,0,1,0},
    {0,0,1,0},
    {0,0,1,0},
    {0,0,1,0},
  };
  int two [7][4] = {
    {1,1,1,1},
    {0,0,0,1},
    {0,0,0,1},
    {1,1,1,1},
    {1,0,0,0},
    {1,0,0,0},
    {1,1,1,1},
  };
  int three [7][4] = {
    {1,1,1,1},
    {0,0,0,1},
    {0,0,0,1},
    {0,1,1,1},
    {0,0,0,1},
    {0,0,0,1},
    {1,1,1,1},
  };
  int four [7][4] = {
    {1,0,0,1},
    {1,0,0,1},
    {1,0,0,1},
    {1,1,1,1},
    {0,0,0,1},
    {0,0,0,1},
    {0,0,0,1},
  };
  int five [7][4] = {
    {1,1,1,1},
    {1,0,0,0},
    {1,0,0,0},
    {1,1,1,1},
    {0,0,0,1},
    {0,0,0,1},
    {1,1,1,1},
  };
  int six [7][4] = {
    {1,1,1,1},
    {1,0,0,0},
    {1,0,0,0},
    {1,1,1,1},
    {1,0,0,1},
    {1,0,0,1},
    {1,1,1,1},
  };
  int seven [7][4] = {
    {1,1,1,1},
    {0,0,0,1},
    {0,0,0,1},
    {0,1,1,1},
    {0,0,0,1},
    {0,0,0,1},
    {0,0,0,1},
  };
  int eight [7][4] = {
    {1,1,1,1},
    {1,0,0,1},
    {1,0,0,1},
    {1,1,1,1},
    {1,0,0,1},
    {1,0,0,1},
    {1,1,1,1},
  };
  int nine [7][4] = {
    {1,1,1,1},
    {1,0,0,1},
    {1,0,0,1},
    {1,1,1,1},
    {0,0,0,1},
    {0,0,0,1},
    {0,0,0,1},
  };

  int i = 0,
      j = 0;

  for (i = 0; i < 7; i++) {
    for (j = 0; j < 4; j++) {
      characters[0][i][j] = zero[i][j];
    }
  }
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 4; j++) {
      characters[1][i][j] = one[i][j];
    }
  }
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 4; j++) {
      characters[2][i][j] = two[i][j];
    }
  }
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 4; j++) {
      characters[3][i][j] = three[i][j];
    }
  }
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 4; j++) {
      characters[4][i][j] = four[i][j];
    }
  }
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 4; j++) {
      characters[5][i][j] = five[i][j];
    }
  }
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 4; j++) {
      characters[6][i][j] = six[i][j];
    }
  }
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 4; j++) {
      characters[7][i][j] = seven[i][j];
    }
  }
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 4; j++) {
      characters[8][i][j] = eight[i][j];
    }
  }
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 4; j++) {
      characters[9][i][j] = nine[i][j];
    }
  }
}
/*
void makeCharacters (int characters[NB_CHAR][CHAR_HEIGHT][CHAR_WIDTH]){

  int a [7][4] = {
    {0,0,0,0},
    {0,0,0,0},
    {1,1,1,1},
    {0,0,0,1},
    {1,1,1,1},
    {1,0,0,1},
    {1,1,1,1},
  };
  int b [7][4] = {
    {1,0,0,0},
    {1,0,0,0},
    {1,0,0,0},
    {1,1,1,1},
    {1,0,0,1},
    {1,0,0,1},
    {1,1,1,1},
  };
  int c [7][4] = {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {1,1,1,1},
    {1,0,0,0},
    {1,0,0,0},
    {1,1,1,1},
  };
  int d [7][4] = {
    {0,0,0,1},
    {0,0,0,1},
    {0,0,0,1},
    {1,1,1,1},
    {1,0,0,1},
    {1,0,0,1},
    {1,1,1,1},
  };
  int e [7][4] = {
    {0,0,0,0},
    {0,0,0,0},
    {1,1,1,0},
    {1,0,1,0},
    {1,1,1,0},
    {1,0,0,0},
    {1,1,1,1},
  };
  int f [7][4] = {
    {0,0,0,0},
    {1,1,1,0},
    {1,0,0,0},
    {1,1,1,0},
    {1,0,0,0},
    {1,0,0,0},
    {1,0,0,0},
  };
  int g [7][4] = {
    {0,0,0,0},
    {0,1,1,1},
    {0,1,0,1},
    {0,1,1,1},
    {0,0,0,1},
    {0,0,0,1},
    {0,1,1,1},
  };

  int i = 0,
      j = 0;

  for (i = 0; i < 7; i++) {
    for (j = 0; j < 4; j++) {
      characters[0][i][j] = a[i][j];
    }
  }
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 4; j++) {
      characters[1][i][j] = b[i][j];
    }
  }
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 4; j++) {
      characters[2][i][j] = c[i][j];
    }
  }
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 4; j++) {
      characters[3][i][j] = d[i][j];
    }
  }
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 4; j++) {
      characters[4][i][j] = e[i][j];
    }
  }
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 4; j++) {
      characters[5][i][j] = f[i][j];
    }
  }
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 4; j++) {
      characters[6][i][j] = g[i][j];
    }
  }
}
*/

void makeFalsesCharacters (int falsesCharacters[NB_CHAR][CHAR_HEIGHT][CHAR_WIDTH], int characters[NB_CHAR][CHAR_HEIGHT][CHAR_WIDTH], int probability) {
  int i = 0,
      j = 0,
      k = 0;

  srand(time(NULL));

  for (i = 0; i < NB_CHAR; i++) {
    for (j = 0; j < CHAR_HEIGHT; j++) {
      for (k = 0; k < CHAR_WIDTH; k++) {
        falsesCharacters[i][j][k] = characters[i][j][k];
        if ((rand() % 100) < probability) {
          falsesCharacters[i][j][k] ^= 1;
        }
      }
    }
  }
}

void printChars(int char1[CHAR_HEIGHT][CHAR_WIDTH], int char2[CHAR_HEIGHT][CHAR_WIDTH]) {
  int i = 0,
      j = 0;

  for (i = 0; i < CHAR_HEIGHT; i++) {
    for (j = 0; j < CHAR_WIDTH; j++) {
      if (char1[i][j] == 1) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\t");
    for (j = 0; j < CHAR_WIDTH; j++) {
      if (char2[i][j] == 1) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}
