#ifndef WUMANBEROPERATION_H_INCLUDED
#define WUMANBEROPERATION_H_INCLUDED

#include <stdlib.h>
#include "WuManber.h"
#include "MatchingResult.h"

typedef struct {

  void (*buildShiftTable)(WuManber, char**, int);
  void (*buildPrefixTable)(WuManber, char**, int);
  MatchingResult (*search)(WuManber, char*);
  void (*destroy)(WuManber);

} WuManberOperationStruct, * WuManberOperation;

void buildShiftTable(WuManber, char**, int);

void buildPrefixTable(WuManber, char**, int);

MatchingResult search(WuManber, char*);

void destroy(WuManber);

WuManberOperation WuManberOperationFactory();

#endif // WUMANBEROPERATION_H_INCLUDED
