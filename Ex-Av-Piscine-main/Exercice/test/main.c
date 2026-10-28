typedef struct s_data{
	char *str;
	struct s_data *next;
	struct s_data *previous;
}t_data;

#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
	t_data node;
	node.str = argv[1];
	node.next = NULL;
	node.previous = NULL;

	t_data node2;
	node2.str = argv[2];
	node2.next = NULL;
	node.previous = &node;

	node.next = &node2;

	t_data *head = &node;
	while (head != NULL){
		puts(head->str);
		head = head->next;
	}
	int count = 0;
	head = &node;
	while (head != NULL){
		count ++;
		head = head->next;
	}
	printf(%d')

}