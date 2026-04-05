#include "libft.h"
#include <stdio.h>


int main()
{
	t_list *a = ft_lstnew(ft_strdup("sahbaz"));
	t_list *b = ft_lstnew(ft_strdup("merhaba"));

	t_list *s1 = ft_lstnew(ft_strdup("tekin"));
	t_list *s2 = ft_lstnew(ft_strdup("hello"));

	t_list *temp;
	temp = ft_lstnew(ft_strdup("istanbul"));

	ft_lstadd_back(&a, b);
	ft_lstadd_back(&a, s1);
	ft_lstadd_back(&a, s2);

	ft_lstadd_front(&a, temp);
	
	t_list *temp1;

	temp1 = temp;
	while(temp1)
	{
		printf("%s\n", (char *)temp1->content);
		temp1 = NULL;
	}
	/* 	
	temp = a;
	while(temp)
	{
		printf("%s\n",(char *)temp->content);
		temp = temp -> next;
	} */
}