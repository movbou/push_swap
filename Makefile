src = push_swap.c utils.c main.c 

all :
	gcc $(src) && ./a.out 
debug:	
	gcc -ggdb $(src) && gdb ./a.out 
