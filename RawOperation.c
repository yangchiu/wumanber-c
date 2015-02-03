#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RawOperation.h"

Raw readBytes(const char* filename) {

  FILE* file = fopen(filename, "rb");

  fseek(file, 0, SEEK_END);

  Raw raw = malloc(sizeof(RawStruct));
  raw->length = ftell(file);
  raw->data = (char*) malloc((raw->length + 1) * sizeof(char));

  fseek(file, 0, SEEK_SET);
  fread(raw->data, 1, raw->length, file);
  fclose(file);

  raw->data[raw->length] = '\0';

  return raw;
}

void writeBytes(const char* filename, Raw raw) {

  FILE* file = fopen(filename, "wb");

  fwrite(raw->data, sizeof(char), raw->length, file);

  fclose(file);
}

int countLines(const char* filename) {

  FILE* file = fopen(filename, "r");
  int byte, count = 0;

  do {
    byte = fgetc(file);
    if(byte == '\n') {
      count++;
    }
  } while(byte != EOF);

  // last line doesn't end with a new line!
  // but there has to be a line at least before the last line
  if(byte != '\n' && count != 0) count++;

  fclose(file);

  return count;
}

char** readLines(const char* fileName, int numberOfLines) {

  char** arr = malloc(numberOfLines * sizeof(char*));
  int line = 0;

  int bufferSize = 1024, position;
  int byte;
  char* buffer = malloc(bufferSize);

  FILE* file = fopen(fileName, "r");
  if(file) {
    do { // read all lines in file

      position = 0;

      do { // read one line
        byte = fgetc(file);
        if(byte != EOF && byte != '\n') {
          buffer[position++] = (char) byte;
        }
        if(position >= bufferSize - 1) { // increase buffer length - leave room for 0
          bufferSize *= 2;
          buffer = realloc(buffer, bufferSize);
        }
      } while(byte != EOF && byte != '\n');

      buffer[position] = 0;
      // line is now in buffer
      arr[line] = malloc(strlen(buffer) + 1);
      strcpy(arr[line++], buffer);

    } while(byte != EOF);

    fclose(file);
  }

  free(buffer);
  return arr;
}

void gc(Raw raw) {
  free(raw->data);
  free(raw);
}

RawOperation RawOperationFactory() {
  static RawOperation rawOperation = NULL;
  if(!rawOperation) {
    rawOperation = malloc(sizeof(RawOperationStruct));
    rawOperation->readBytes = readBytes;
    rawOperation->writeBytes = writeBytes;
    rawOperation->countLines = countLines;
    rawOperation->readLines = readLines;
    rawOperation->gc = gc;
  }
  return rawOperation;
}
