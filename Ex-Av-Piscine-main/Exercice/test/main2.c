typedef struct s_people {
	char *name;
	int age;
	struct s_people *next;
	struct s_people *previous;
} t_people;


int total = 0;
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv){
	t_people node;
	node.name = argv[1];
	node.age = atoi(argv[2]);
	node.previous = NULL;

	t_people node2;
	node2.name = argv[3];
	node2.age = atoi(argv[4]);
	node.next = &node2;
	node.previous = &node;
	node.next = &node2;
	
	t_people node3;
	node3.name = argv[5];
	node3.age = atoi(argv[6]);
	node3.next = NULL;
	node3.previous = &node2;
	node2.previous = &node;
	node2.next = &node3;

	t_people *head = &node;
	while (head != NULL){
		write(1,"Name:",5);
		puts(head->name);
		write(1,"Age:", 4);
		printf("%d\n", head->age);
		head = head->next;
		}
		
		int count = 0;
		head = &node;
		while (head != NULL){
			count++;
			head = head->next;
		}
		printf("%d\n",count);
		return(0);
		
}
// ./a.out "Name" "age" "name" "age" "stop"
	// ex : ./a.out "alice" 18 "bertrand" 16 "gael" 89 "stop"  






	

	/*
		------------------ PEOPLES ------------------
		Name: <nom>
		Age: <age> 

		^^ pour chaque personne


		Total : %d peoples
	*/