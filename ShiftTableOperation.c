#include <stdlib.h>
#include "ShiftTableOperation.h"

void put(ShiftTable shiftTable, char subString[2], int shift) {

  int key = subString[0] * 256 + subString[1];

  // new subString
  if(shiftTable[key] == -1) {
    shiftTable[key] = shift;
  }
  // already have the same subString
  // select min
  else {
    if(shiftTable[key] > shift) {
      shiftTable[key] = shift;
    }
  }
}

int get(ShiftTable shiftTable, char subString[2]) {
  int key = subString[0] * 256 + subString[1];
  return shiftTable[key];
}

ShiftTableOperation ShiftTableOperationFactory() {
  static ShiftTableOperation shiftTableOperation = NULL;
  if(!shiftTableOperation) {
    shiftTableOperation = malloc(sizeof(ShiftTableOperationStruct));
    shiftTableOperation->put = put;
    shiftTableOperation->get = get;
  }
  return shiftTableOperation;
}
