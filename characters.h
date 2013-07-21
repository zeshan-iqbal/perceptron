#ifndef __CHARACTERS_H__
#define __CHARACTERS_H__

#define NB_CHAR 10
#define CHAR_HEIGHT 7
#define CHAR_WIDTH 4

/* stores in characters the bitmap of NB_CHAR characters
 * that will be learnt to the perceptrons
 */
void makeCharacters (int characters[NB_CHAR][CHAR_HEIGHT][CHAR_WIDTH]);

/* copy characters in falseCharacters, with a given probability (0 - 100) of reversing a pixel
 */
void makeFalsesCharacters (int falsesCharacters[NB_CHAR][CHAR_HEIGHT][CHAR_WIDTH], int characters[NB_CHAR][CHAR_HEIGHT][CHAR_WIDTH], int probability);

/* prints two characters side by side
 */
void printChars(int char1[CHAR_HEIGHT][CHAR_WIDTH], int char2[CHAR_HEIGHT][CHAR_WIDTH]);

#endif
