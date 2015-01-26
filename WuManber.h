#ifndef WUMANBER_H_INCLUDED
#define WUMANBER_H_INCLUDED

#include "ShiftTable.h"
#include "PrefixTable.h"

typedef struct {

  ShiftTable shiftTable;
  PrefixTable prefixTable;
  int minPatternLength;

} WuManberStruct, * WuManber;

#endif // WUMANBER_H_INCLUDED
