//Deleting the first occurence of a node in the Linked List  

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

//Function for deleting the first occurence of a node with the given data 
//This function takes 2 parameters- head node of the list and the data of the node which has to be deleted 
void delete(struct Node** head, int del_data)
{
	//Declare a temp node to iterate the list
	struct Node* temp= *head;
	//Declare a node which will store the value of previous node
	struct Node* prev;
	
	//Check if the head node has the data to be deleted 
	if (temp!=NULL && temp->data==del_data)
	{
		//Assign the next node as the new head node
		*head= temp->next;
		//Free the memory of the deleted node
		free(temp);
		return;
	}
	
	//Iterate the Linked List till the node with given data is found or till it reaches the end of the List
	while (temp!=NULL && temp->data!=del_data)
	{
		//Store the previous node in this
		prev= temp;
		//Move to the next for iteration
		temp= temp->next;
	}
	
	//If the loop terminates because of this, this means that the given data node is not present in the list
	if (temp==NULL)
	{
		printf("The node with given data is not present in the list \n");
		return;
	}
	
	//If the loop terminates after given data is found, assign the pointer of previous node to link to the next node of the node to be deleted
	prev->next= temp->next;
	//Free the memory of the deleted node
	free(temp);
}

int main()
{
	struct Node* head= malloc(sizeof(struct Node));
	struct Node* second= malloc(sizeof(struct Node));
	struct Node* third= malloc(sizeof(struct Node));
	struct Node* fourth= malloc(sizeof(struct Node));
	
	head->data= 2;
	head->next= second;
	
	second->data= 4;
	second->next= third;
	
	third->data= 5;
	third->next= fourth;
	
	fourth->data= 6;
	fourth->next= NULL;
	
	printf("Original list: \n");
	printList(head);
	printf("Deleting third node \n");
	delete(&head,5);
	printf("Node deleted \n");
	printList(head);
	
	return 0;
}
