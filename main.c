#include <stdio.h>
#include <stdlib.h>
#include "WuManber.h"
#include "WuManberOperation.h"
#include "MatchingResult.h"
#include "RawOperation.h"

int main(int argc, const char* argv[]) {

  char** pattern;
  int numberOfPattern;
  char* content;

  if(argc != 3) {
    printf("# of arguments should be 2.\n");
    printf("usage: ./a.out patternFile payloadFile\n");
    return 0;
  }

  RawOperation rawOperation = RawOperationFactory();

  printf("\n - Reading pattern file ...\n\n");

  numberOfPattern = rawOperation->countLines(argv[1]);
  pattern = rawOperation->readLines(argv[1], numberOfPattern);

  printf(" - Reading pattern file succeed.\n\n");

  printf(" - Total %d patterns:\n", numberOfPattern);

  for(int i=0;i<numberOfPattern;i++) {
    printf("   - %s\n", pattern[i]);
  }

  printf("\n - Reading content file ...\n\n");

  Raw raw = rawOperation->readBytes(argv[2]);
  content = raw->data;

  printf(" - Reading content file succeed.\n\n");
  printf(" - Content:\n");
  printf("   - %s\n\n", content);

  WuManber wuManber = malloc(sizeof(WuManberStruct));
  WuManberOperation wuManberOperation = WuManberOperationFactory();

  wuManberOperation->buildShiftTable(wuManber, pattern, numberOfPattern);

  wuManberOperation->buildPrefixTable(wuManber, pattern, numberOfPattern);

  MatchingResult res = wuManberOperation->search(wuManber, content);

  MatchingResult temp = res;
  res = res->next;
  free(temp);
  if(!res) printf(" - no results\n");
  else {
    while(res) {
      printf(" - find %s at position %d ~ %d\n", res->pattern, res->start, res->end);
      temp = res;
      res = res->next;
      free(temp);
    }
  }

  printf("\n - Done!\n");

  wuManberOperation->destroy(wuManber);
  rawOperation->gc(raw);

  return 0;
}
