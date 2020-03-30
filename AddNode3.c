//Appending a node at the end of the Linked List

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

//Function for appending a new node at the end of the Linked List
//This function takes 2 parameters- head node of the list and the data of the new node to be inserted
void append(struct Node** head, int new_data)
{
	//Declare a new node 
	struct Node* new_node= malloc(sizeof(struct Node));
	//Assign data to the new node
	new_node->data= new_data;
	//Since this will be the last node now, we set the next pointer to be NULL
	new_node->next= NULL;
	
	//Create a node to get the value of the last node
	struct Node* last= malloc(sizeof(struct Node));
	
	//Check if the Linked List is empty => head node is NULL
	if (*head==NULL)
	{
		*head= new_node;
		return;
	}
	
	//Get the value of last node by iterating till the end
	last= *head;
	while (last->next!=NULL)
	{
		last= last->next;
	}
	
	//Link the new node by appending it at the end
	last->next= new_node;
}

int main()
{
	struct Node* head= malloc(sizeof(struct Node));
	struct Node* second= malloc(sizeof(struct Node));
	struct Node* third= malloc(sizeof(struct Node));
	
	head->data= 2;
	head->next= second;
	
	second->data= 4;
	second->next= third;
	
	third->data= 6;
	third->next= NULL;
	
	printf("Printing original list \n");
	printList(head);
	printf("Adding new node in between \n");
	append(&head, 8);
	printf("Added new node \n");
	printList(head);
	
	return 0;
}
