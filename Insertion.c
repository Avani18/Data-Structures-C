//Performing all the insertions in a single program

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

//Function for initialising a new node while getting data as parameter and adding it to the front of the Linked List 
//This function takes 2 paramters- A reference to the head node and the data of the new node
void push(struct Node** head_ref, int new_data)
{
	//Defining and declaring a new node 
	struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
	//Setting the data of the new node
	new_node->data= new_data;
	//Linking the new node by pointing it to the existing head node
	new_node->next= (*head_ref);
	//Assigning the new node as the head node 
	(*head_ref)= new_node;
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
	struct Node* head= NULL;
	
	// 6
	append(&head, 6);
	// 7->6
	push(&head, 7);
	// 1->7->6
	push(&head, 1);
	// 1->7->6->4
	append(&head, 4);
	// 1->7->8->6->4
	addNodeAfter(head->next, 8);
	
	printf("The created list is: \n");
	printList(head);
	
	return 0;
}
