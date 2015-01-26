#ifndef SHIFTTABLEOPERATION_H_INCLUDED
#define SHIFTTABLEOPERATION_H_INCLUDED

#include "ShiftTable.h"

typedef struct {

  void (*put)(ShiftTable, char[2], int);
  int (*get)(ShiftTable, char[2]);

} ShiftTableOperationStruct, * ShiftTableOperation;

void put(ShiftTable, char[2], int);

int get(ShiftTable, char[2]);

ShiftTableOperation ShiftTableOperationFactory();

#endif // SHIFTTABLEOPERATION_H_INCLUDED
