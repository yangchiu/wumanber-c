#ifndef PREFIXTABLEOPERATION_H_INCLUDED
#define PREFIXTABLEOPERATION_H_INCLUDED

#include "PrefixTable.h"

typedef struct {

  void (*push)(PrefixTable, char[2], char*);
  PatternNode (*pop)(PrefixTable, char[2]);

} PrefixTableOperationStruct, * PrefixTableOperation;

void push(PrefixTable, char[2], char*);

PatternNode pop(PrefixTable, char[2]);

PrefixTableOperation PrefixTableOperationFactory();

#endif // PREFIXTABLEOPERATION_H_INCLUDED
