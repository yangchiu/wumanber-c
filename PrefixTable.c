#include <stdlib.h>
#include "PrefixTable.h"

PrefixTable PrefixTableFactory() {

  int length = 65536;
  PrefixTable prefixTable = malloc(sizeof(PatternNodeStruct) * length);

  for(int i=0;i<length;i++) {
    prefixTable[i] = NULL;
  }

  return prefixTable;
}
