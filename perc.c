#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "perc.h"
#include "rules.h"

prcpt * createPerc(int nbInputs, float learningRate) {
  int i = 0;

  prcpt * p = malloc(sizeof(prcpt));

  p->inx = malloc(nbInputs * sizeof(float));
  p->w = malloc(nbInputs * sizeof(float));

  /* init weights and b to 0 but could/should be random */
  for (i = 0; i < nbInputs; i++) {
    p->inx[i] = 0.;
    p->w[i] = 0.;
  }
  p->b = 0.;

  p->out = 0.;
  p->nbInputs = nbInputs;
  p->learningRate = learningRate;

  return p;
}

float calculateOutput (prcpt * p) {
  /* leanrning rule : output = 1 if (inx . w + b) > 0, else 0*/
  float product = 0;
  int i = 0;
  for (i = 0; i < p->nbInputs; i++) {
    product += p->inx[i] * p->w[i];
    //printf("product %f ", product);
  }

  product += p->b;
  //printf("product %f\n", product);

  p->out = (product > 0.);
  return p->out;
}

void printWeights(prcpt * p) {
  int i = 0;
  printf("WEIGHTS :\n");
  for (i = 0; i < p->nbInputs; i++) {
    printf("%3f ", p->w[i]);
  }
  printf("%3f\n",p->b);
}

/* Adjusts the weight and the bias of the perceptron regarding the calculated and the desired output
 * param p : the perceptron
 * param T : the correct output
 * param O : the calculated output
 */
void adjustWeights (prcpt * p, float T, float O) {
  int i = 0;
  for (i = 0; i < p->nbInputs; i++) {
    p->w[i] += p->learningRate * (T - O) * p->inx[i];
  }
  p->b += p->learningRate * (T - O);
  //printWeights(p);
}

void learn (prcpt * p, aRuleSet * ruleSet) {
  int done = 0,
      nbCycles = 0,
      i = 0,
      j = 0;

  float T = 0.,
        O = 0.;

  printf("Learning\n");

  /* we teach all rules of ruleSet as long as the perceptron makes some errors */
  while (!done) {
    nbCycles++;
    done = 1;
    for (i = 0; i < ruleSet->nbRules; i++) {
      //printf("---------------------------\nRULE %d\n",i);
      for (j = 0; j < p->nbInputs; j++) {
        //printf("%3f ", ruleSet->rules[i]->inx[j]) ; 
        p->inx[j] = ruleSet->rules[i]->inx[j]; 
      }
      T = ruleSet->rules[i]->desiredOutput;  /* correct desired output */
      O = calculateOutput(p); /* calculated output */
      //printf("-> %3f\n", T);
      //printf("O = %3f\n", O);
      if (O != T) {
        //printf("WROOOOOONG\n");
        done = 0;
        adjustWeights(p,T,O);
      }
    }
  }

  printf("Finished learning in %d cycles\n", nbCycles);
}

void answerUserQuestions(prcpt * p) {
  int i = 0,
      done = 0;

  printf("Now, ask me some questions\n");
  while (!done) {
    for (i = 0; i < p->nbInputs; i++) {
      printf("in[%d] : ", i);
      scanf("%f",&p->inx[i]);
      if (p->inx[i] != 1 && p->inx[i] != 0) {
        done = 1;
        break;
      }
    }
    if (!done) {
      printf("calculated : %f\n", calculateOutput(p));
    }
  }
}

float askFromArgumentList (prcpt * p, ...) {
  int i = 0;
  va_list ap;
  va_start(ap, p);

  for (i = 0; i < p->nbInputs; i++) {
    p->inx[i] = va_arg(ap,double);
  }

  return calculateOutput(p);
}

float askFromArray (prcpt * p, float * inputs) {
  int i = 0;

  for (i = 0; i < p->nbInputs; i++) {
    p->inx[i] = inputs[i];
  }

  return calculateOutput(p);
}

float askFromMatrix (prcpt * p, int character[CHAR_HEIGHT][CHAR_WIDTH]) {
  int nbL = 7,
      nbC = 4,
      i = 0,
      j = 0;
  float * tabInput = malloc((nbL * nbC + 1) * sizeof(float));
  float ret = -1.;

  for (i = 0; i < nbL; i++) {
    for (j = 0; j < nbC; j++) {
      tabInput[i * nbC + j] = character[i][j];
    }
  }
  ret = askFromArray(p,tabInput);

  free(tabInput);
  return ret;
}
