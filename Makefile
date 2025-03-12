src = push_swap.c utils.c main.c 

all :
	gcc $(src) && ./a.out 
debug:	
	gcc -g $(src) && gdb ./a.out 
