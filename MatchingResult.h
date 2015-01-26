#ifndef MATCHINGRESULT_H_INCLUDED
#define MATCHINGRESULT_H_INCLUDED

typedef struct MatchingResultStruct MatchingResultStruct, * MatchingResult;

struct MatchingResultStruct {

  char* pattern;
  int start;
  int end;
  MatchingResult next;

};

#endif // MATCHINGRESULT_H_INCLUDED
