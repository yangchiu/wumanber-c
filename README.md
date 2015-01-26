# wu-manber-string-matching
- Wu-Manber algorithm C implementation
- only for 7-bits ASCII
- minimum pattern length should greater than 3

#### Usage
execute make:
```python
$ make
# print
# $ make
# gcc -g -Wall -std=gnu99 -c main.c
# gcc -g -Wall -std=gnu99 -c ShiftTable.c
# gcc -g -Wall -std=gnu99 -c ShiftTableOperation.c
# gcc -g -Wall -std=gnu99 -c PrefixTable.c
# gcc -g -Wall -std=gnu99 -c PrefixTableOperation.c
# gcc -g -Wall -std=gnu99 -c WuManberOperation.c
# gcc -g -Wall -std=gnu99 -c RawOperation.c
# gcc -o a.out main.o ShiftTable.o ShiftTableOperation.o PrefixTable.o PrefixTableOperation.o WuManberOperation.o RawOperation.o
```
The first argument is the pattern file,
and the second argument is the content to be searched:

