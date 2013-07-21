#ifndef __RULES_H__
#define __RULES_H__

#include "characters.h"

/* a rule structure */
struct aRule {
  float nbInputs; /* number of input of the rule (size of inx) */
  float * inx; /* inputs */
  float desiredOutput; /* the outPut the perceptron should take when submitted to the rule */
};
typedef struct aRule aRule;

/* a ruleSet structure
 * a ruleSet is a set of rules that a perceptron has to learn
 */
struct aRuleSet {
  int nbRules; /* number of rules of the set (size of rules) */
  struct aRule ** rules; /* array of pointers to rules (not a matrix) */
};
typedef struct aRuleSet aRuleSet;

/* creates a rule with nbInputs inputs
 * last param/element of the array is the desired output
 */
aRule * createRuleFromArgumentList (int nbInputs, ...);
aRule * createRuleFromArray (int nbInputs, float * inputs);
aRule * createRuleFromMatrix (int character[CHAR_HEIGHT][CHAR_WIDTH], float desiredOutput);

/*
 * frees the memory allocated for a rule
 * param rule : the rule to free
 */
void freeRule(aRule * rule);

/* creates a ruleSet (a collection of rules) that can be learnt 
 * createRuleFromXXX has to be called for EVERY rule of the ruleSet before calling createRuleSetFromXXX
 * */
aRuleSet * createRuleSetFromArgumentList(int nbRules, ...);
aRuleSet * createRuleSetFromArray(int nbRules, aRule ** rules);

/* prints all inputs and the desiredOutput of each rule of a ruleSet
 * param ruleSet : the ruleSet
 */
void printRuleSet(aRuleSet * ruleSet);

#endif
