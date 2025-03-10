src = push_swap.c utils.c 

all :
	gcc $(src) 
debug:	
	gcc -g $(src)  
