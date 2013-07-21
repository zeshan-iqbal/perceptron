#include <stdio.h>
#include <stdlib.h>

#include "perc.h"
#include "rules.h"
#include "characters.c"


void xor (float a, float b) {
  prcpt * pAND = createPerc(2,1.);
  prcpt * pOR = createPerc(2,1.);
  prcpt * pNOT = createPerc(1,1.);

  aRuleSet * rulesAND = createRuleSetFromArgumentList(4,createRuleFromArgumentList(2, 0., 0., 0.), createRuleFromArgumentList(2, 0., 1., 0.), createRuleFromArgumentList(2, 1., 0., 0.), createRuleFromArgumentList(2, 1., 1., 1.));
  aRuleSet * rulesOR = createRuleSetFromArgumentList(4,createRuleFromArgumentList(2, 0., 0., 0.), createRuleFromArgumentList(2, 0., 1., 1.), createRuleFromArgumentList(2, 1., 0., 1.), createRuleFromArgumentList(2, 1., 1., 1.));
  aRuleSet * rulesNOT = createRuleSetFromArgumentList(2,createRuleFromArgumentList(1, 0., 1.), createRuleFromArgumentList(1, 1., 0.));

  learn(pAND, rulesAND);
  learn(pOR, rulesOR);
  learn(pNOT, rulesNOT);

  printf("%f\n", askFromArgumentList(pOR,askFromArgumentList(pAND, a, askFromArgumentList(pNOT, b)), askFromArgumentList(pAND, b, askFromArgumentList(pNOT, a))));

}

void carac() {
  int characters [NB_CHAR][CHAR_HEIGHT][CHAR_WIDTH];
  int falsesCharacters [NB_CHAR][CHAR_HEIGHT][CHAR_WIDTH];

  aRule ** rules = malloc (NB_CHAR * sizeof(aRule *));
  aRuleSet * ruleSet = NULL;
  
  prcpt ** perceptrons = malloc(NB_CHAR * sizeof(prcpt *));

  int resp = 0,
      foundMatch = 0,
      i = 0,
      j = 0;

  makeCharacters(characters);

  for (i = 0; i < NB_CHAR; i++) {
    rules[i] = createRuleFromMatrix(characters[i],0.);
  }
  
  ruleSet = createRuleSetFromArray(NB_CHAR, rules);
 
  for (i = 0; i < NB_CHAR; i++) {
    printf("PERCEPTRON %d\n", i);
    perceptrons[i] = createPerc(CHAR_HEIGHT * CHAR_WIDTH,0.1);
    for (j = 0; j < NB_CHAR; j++) {
      if (i == j) {
        rules[j]->desiredOutput = 1.;
      } else {
        rules[j]->desiredOutput = 0.;
      }
    }
    //printRuleSet(ruleSet);
    learn(perceptrons[i], ruleSet);
    printf("\n");
  }


  makeFalsesCharacters(falsesCharacters, characters, 5);


  for (i = 0; i < NB_CHAR; i++) {
    printChars(characters[i],falsesCharacters[i]);
    foundMatch = 0;
    for (j = 0; j < NB_CHAR; j++) {
      resp = (int)askFromMatrix(perceptrons[i],falsesCharacters[j]);
      if (resp) {
        if (foundMatch) {
          printf(" or a %d", j);
        } else {
          foundMatch = 1;
          printf("I think the char is a %d", j);
        }
      }
    }
    if (!foundMatch) {
      printf("I can't tell...\n");
    } else {
      printf("\n");
    }
    printf("\n");
  }
  
}


int main () {
  carac();
  return 0;
}
