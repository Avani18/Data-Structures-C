//Ading a node to the front of the Linked List

#include<stdio.h>
#include<stdlib.h>

//Declaring the node struct
struct Node{
	int data;
	struct Node* next;
};

//Function for printing the Linked List
void printList(struct Node* n)
{
	while (n!=NULL)
	{
		printf("%d \t",n->data);
		n= n->next;
	}
	printf("\n");
}

//Function for adding a predefined node in main func and adding it to the front of Linked List 
//This function takes 2 parameters- The existing head node and the new initialised node that has to added at the front 
void push1(struct Node* head, struct Node* add)
{
	//Linking the new node by pointing it to the existing head node
	add->next= head;
	printf("Inside push1 \n");
	printList(add);
}

//Function for initialising a new node while getting data as parameter and adding it to the front of the Linked List 
//This function takes 2 paramters- A reference to the head node and the data of the new node
void push2(struct Node** head_ref, int new_data)
{
	//Defining and declaring a new node 
	struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
	//Setting the data of the new node
	new_node->data= new_data;
	//Linking the new node by pointing it to the existing head node
	new_node->next= (*head_ref);
	//Assigning the new node as the head node 
	(*head_ref)= new_node;
	printf("Inside push2 \n");
	printList(*head_ref);
}

int main()
{
	struct Node* head= NULL;
	struct Node* second= NULL;
	struct Node* third= NULL;
	struct Node* add= NULL;
	
	head= (struct Node*)malloc(sizeof(struct Node));
	second= (struct Node*)malloc(sizeof(struct Node));
	third= (struct Node*)malloc(sizeof(struct Node));
	add= (struct Node*)malloc(sizeof(struct Node));
	
	head->data= 4;
	head->next= second;
	
	second->data= 6;
	second->next= third;
	
	third->data=8;
	third->next= NULL;
	
	add->data= 2;
	add->next= NULL;
	
	push1(head, add);
	push2(&head, 2);
	
	return 0;
}
