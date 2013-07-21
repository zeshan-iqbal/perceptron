#ifndef __PERC_H__
#define __PERC_H__

#include "rules.h"
#include "characters.h"

struct prcpt {
  int nbInputs; /* size of inx and w */
  float * inx; /* inputs */
  float * w; /* weight of inputs */
  float b; /* bias */
  float learningRate; /* ... */
  float out; /* the calculated output */
};
typedef struct prcpt prcpt;

/* creates a perceptron
 * param nbInputs : the number of inputs of the peceptron
 * param learningRate : the learning rate of the perceptron
 * returns a pointer to the created perceptron
 */
prcpt * createPerc(int nbInputs, float learningRate);


/* calculates, returns and stores in p->out the output of a perceptron
 * param p : the perceptron
 * returns the output
 */
float calculateOutput (prcpt * p);

/* prints the weights of a perceptron
 * param p : the perceptron
 */
void printWeights(prcpt * p);

/* makes a perceptron learn all the rules of a ruleSet 
 * param p : the perceptron
 * param ruleSet : the ruleSet containng the rules to learn
 */
void learn (prcpt * p, aRuleSet * ruleSet);

/* asks the user to type the inputs of the perceptron and prints the output calculated 
 * param p : the perceptron
 */
void answerUserQuestions(prcpt * p);

/* returns the output calculated by a perceptron
 * param p : the perceptron
 * next param : the inputs as arguments, array or matrix
 */
float askFromArgumentList (prcpt * p, ...);
float askFromArray (prcpt * p, float * inputs);
float askFromMatrix (prcpt * p, int character[CHAR_HEIGHT][CHAR_WIDTH]);

#endif
