//Removing the first node of a Linked List 

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

//Function for deleting the first node of a Linked List 
//This function takes 1 parameter- the head of the Linked List 
void removeFirstNode(struct Node** head)
{
	//Check if the Linked List is empty
	if (*head==NULL)
	{
		printf("The Linked List is empty. \n");
		return;
	}
	
	//Initialise a new node to store the new head which is the second node
	struct Node* head_new= (*head)->next;
	//Store the original head node in a variable to free its memory
	struct Node* to_delete= *head;
	//Assign the head its new node
	*head= head_new;
	//Free the memory of the old head node
	free(to_delete);
}

int main()
{
	struct Node* head= malloc(sizeof(struct Node));
	struct Node* second= malloc(sizeof(struct Node));
	struct Node* third= malloc(sizeof(struct Node));
	struct Node* fourth= malloc(sizeof(struct Node));
	
	head->data= 0;
	head->next= second;
	
	second->data= 2;
	second->next= third;
	
	third->data= 4;
	third->next= fourth;
	
	fourth->data= 6;
	fourth->next= NULL;
	
	printf("Original list is \n");
	printList(head);
	printf("Removing first node \n");
	removeFirstNode(&head);
	printf("First node removed \n");
	printList(head);
	
	return 0;
}
