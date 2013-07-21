#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "rules.h"

aRule * createRuleFromArgumentList (int nbInputs, ...) {
  aRule * rule = malloc (sizeof(aRule));
  int i = 0;
  va_list ap;

  va_start(ap, nbInputs);
    
  rule->inx = malloc(nbInputs * sizeof(float)); 
  for (i = 0; i < nbInputs; i++) {
    rule->inx[i] = va_arg(ap, double);
  }

  rule->desiredOutput = va_arg(ap, double);
  rule->nbInputs = nbInputs;

  return rule;
}

aRule * createRuleFromArray (int nbInputs, float * inputs) {
  aRule * rule = malloc (sizeof(aRule));
  int i = 0;
    
  rule->inx = malloc(nbInputs * sizeof(float)); 
  for (i = 0; i < nbInputs; i++) {
    rule->inx[i] = inputs[i];
  }

  rule->desiredOutput = inputs[i];
  rule->nbInputs = nbInputs;

  return rule;
}

aRule * createRuleFromMatrix (int character[CHAR_HEIGHT][CHAR_WIDTH], float desiredOutput) {
  int i = 0,
      j = 0;
  float * tabInput = malloc((CHAR_HEIGHT * CHAR_WIDTH + 1) * sizeof(float));
  aRule * rule = NULL;

  for (i = 0; i < CHAR_HEIGHT; i++) {
    for (j = 0; j < CHAR_WIDTH; j++) {
      tabInput[i * CHAR_WIDTH + j] = character[i][j];
    }
  }
  tabInput[CHAR_HEIGHT * CHAR_WIDTH] = desiredOutput;

  rule =  createRuleFromArray(CHAR_HEIGHT * CHAR_WIDTH, tabInput);
  free(tabInput);
  return rule;
}

void freeRule(aRule * rule) {
  free((rule)->inx);
  free(rule);
}

aRuleSet * createRuleSetFromArgumentList (int nbRules, ...) {
  aRuleSet * ruleSet = malloc(sizeof(aRuleSet));
  int i = 0;
  va_list ap;

  va_start(ap, nbRules);
  ruleSet->rules = malloc(nbRules * sizeof(aRule *));
  for (i = 0; i < nbRules; i++) {
    ruleSet->rules[i] = va_arg(ap, aRule*);
  }
  ruleSet->nbRules = nbRules;

  return ruleSet;
}

aRuleSet * createRuleSetFromArray(int nbRules, aRule ** rules) {
  aRuleSet * ruleSet = malloc(sizeof(aRuleSet));
  int i = 0;

  ruleSet->rules = malloc(nbRules * sizeof(aRule *));
  for (i = 0; i < nbRules; i++) {
    ruleSet->rules[i] = rules[i];
  }
  ruleSet->nbRules = nbRules;

  return ruleSet;
}

void printRuleSet(aRuleSet * ruleSet) {
  int i = 0;
  int j = 0;

  for (i = 0; i < ruleSet->nbRules; i++) {
    printf("Rule %d : ", i);
    for (j = 0; j < ruleSet->rules[i]->nbInputs; j++) {
      printf("%f ", ruleSet->rules[i]->inx[j]);
    }
    printf("--> %f\n", ruleSet->rules[i]->desiredOutput);
  }
}
