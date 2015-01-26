#ifndef PATTERNNODE_H_INCLUDED
#define PATTERNNODE_H_INCLUDED

typedef struct PatternNodeStruct PatternNodeStruct, * PatternNode;

struct PatternNodeStruct {
  char* pattern;
  int length;
  PatternNode next;
};

#endif // PATTERNNODE_H_INCLUDED
