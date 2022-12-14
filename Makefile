Linkedlist: Huvud.o list.o driv.o
	gcc Huvud.c list.c driv.c -o Linkedlist

Huvud.o: Huvud.c
	gcc -c Huvud.c

list.o: list.c
	gcc -c list.c

driv.o: driv.c
	gcc -c driv.c

clean:
	rm: *.Linkedlist
