//Adding a node after a given node

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

//Function for adding a new node with the given data after the given node
//This function takes 2 parameters- The node after which the node has to be added and the data of the new node.
void addNodeAfter(struct Node* prev_node, int new_data)
{
	//Add check for NULL of previous node
	if(prev_node==NULL)
	{
		printf("Previous node cannot be NULL \n");
		return;
	}
	
	//Declaring the new node
	struct Node* new_node= malloc(sizeof(struct Node));
	//Setting the data value of the new node
	new_node->data= new_data;
	//Linking the new node to point to the next node
	new_node->next= prev_node->next;
	//Linking the previous node to point to the new node
	prev_node->next= new_node;	 
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
	
	third->data= 8;
	third->next= NULL;
	
	printf("Printing original list \n");
	printList(head);
	printf("Adding new node in between \n");
	addNodeAfter(second, 6);
	printf("Added new node \n");
	printList(head);
	
	return 0;
}
