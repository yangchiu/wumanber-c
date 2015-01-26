#include <stdlib.h>
#include "ShiftTable.h"

ShiftTable ShiftTableFactory() {

  int length = 65536;
  ShiftTable table = malloc(sizeof(int) * length);

  for(int i=0;i<length;i++) {
    table[i] = -1;
  }

  return table;
}
