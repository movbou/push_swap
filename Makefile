src = push_swap.c utils.c 

all :
	gcc $(src) && ./a.out 
debug:	
	gcc -g $(src) && gdb ./a.out 
