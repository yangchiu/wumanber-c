flags = -g -Wall -std=gnu99

a.out: main.o ShiftTable.o ShiftTableOperation.o PrefixTable.o PrefixTableOperation.o WuManberOperation.o RawOperation.o
	gcc -o a.out main.o ShiftTable.o ShiftTableOperation.o PrefixTable.o PrefixTableOperation.o WuManberOperation.o RawOperation.o
main.o: main.c WuManber.h WuManberOperation.h MatchingResult.h RawOperation.h
	gcc $(flags) -c main.c
ShiftTable.o: ShiftTable.c ShiftTable.h
	gcc $(flags) -c ShiftTable.c
ShiftTableOperation.o: ShiftTableOperation.c ShiftTableOperation.h
	gcc $(flags) -c ShiftTableOperation.c
PrefixTable.o: PrefixTable.c PrefixTable.h
	gcc $(flags) -c PrefixTable.c
PrefixTableOperation.o: PrefixTableOperation.c PrefixTableOperation.h
	gcc $(flags) -c PrefixTableOperation.c
WuManberOperation.o: WuManberOperation.c WuManberOperation.h ShiftTable.h ShiftTableOperation.h PrefixTable.h PrefixTableOperation.h
	gcc $(flags) -c WuManberOperation.c
RawOperation.o: RawOperation.c RawOperation.h
	gcc $(flags) -c RawOperation.c