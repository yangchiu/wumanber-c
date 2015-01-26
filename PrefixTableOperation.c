#include <stdlib.h>
#include <string.h>
#include "PrefixTableOperation.h"

void push(PrefixTable prefixTable, char subString[2], char* pattern) {

  int key = subString[0] * 256 + subString[1];

  PatternNode node = malloc(sizeof(PatternNodeStruct));
  node->pattern = pattern;
  node->length = strlen(pattern);
  node->next = NULL;
  // new prefix
  if(!prefixTable[key]) {
    prefixTable[key] = node;
  }
  // have the same prefix
  else {
    PatternNode current = prefixTable[key];
    while(current->next) {
      current = current->next;
    }
    current->next = node;
  }
}

PatternNode pop(PrefixTable prefixTable, char subString[2]) {

  int key = subString[0] * 256 + subString[1];

  return prefixTable[key];
}

PrefixTableOperation PrefixTableOperationFactory() {
  PrefixTableOperation prefixTableOperation = NULL;
  if(!prefixTableOperation) {
    prefixTableOperation = malloc(sizeof(PrefixTableOperationStruct));
    prefixTableOperation->push = push;
    prefixTableOperation->pop = pop;
  }
  return prefixTableOperation;
}
