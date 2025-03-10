#include "push_swap.h"
#include <stdio.h>

static int	check_overflow(int m)
{
	if (m == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	n;
	int		m;

	i = 0;
	n = 0;
	m = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			m *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (n > (LONG_MAX - (str[i] - '0')) / 10)
			return (check_overflow(m));
		n = (n * 10) + (str[i++] - 48);
	}
	return (n * m);
}
void	s_fill(char *argv,int argc ,t_list **stack) 
{
	/*momkin ikon mochkil hna  */

	/*argv++; 		*/

	/*push(NULL, ft_atoi(argv--));*/
	while (argc--)
	{
		push(stack, ft_atoi(argv++));
	}	
}
int main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list *stack_b;
	/*char b[]={'1', '2', '3', '4'};*/
	/*s_fill(b,4 , &stack_b);*/
	s_fill(*argv, argc, &stack_a);

	while (stack_a) {
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;	
	}

	/*while (stack_b) {*/
	/*	printf("%d\n", stack_b->content);*/
	/*	stack_b = stack_b->next;	*/
	/*}*/

}
