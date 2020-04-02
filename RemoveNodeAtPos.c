//Removing the node at a given position of a Linked List 

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
void removeFirstNode(struct Node** head)
{
	if (*head==NULL)
	{
		printf("The Linked List is empty. \n");
		return;
	}
	struct Node* head_new= (*head)->next;
	struct Node* to_delete= *head;
	*head= head_new;
	free(to_delete);
}


//Function for deleting a node at a given position
//This function takes 2 parameters- head of the Linked List and the position of the node to be deleted
void removeNode(struct Node* head, int position)
{
	//Check if the given node is the head node
	if (position==1)
	{
		//Remove first node if it is the case
		removeFirstNode(&head);
		return;
	}
	//Counter for checking position
	int i=2;
	//Declare a variable to store the previous node
	struct Node* prev_node= head;
	//Start iteration from next node since head node has already been checked
	head= head->next;
	//Iterate the Linked List till the node of given position is found or till it reaches the end of the List
	while (head!=NULL && position!=i)
	{
		//Store the previous node in this
		prev_node= head;
		//Move to the next node
		head= head->next;
		//Increment the counter of the position
		++i;
	}
	//If the loop terminates because of this, this means that the given position of the node is not present in the list
	if (head==NULL)
	{
		printf("The position is not present in the Linked List\n");
		return;
	}

	//If the loop terminates after given position node is found, assign the pointer of previous node to link to the next node of the node to be deleted
	prev_node->next= head->next;
	//Free the memory of deleted node
	free(head);
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
	
	printf("Original list is \n");
	printList(head);
	printf("Removing node at third position\n");
	removeNode(head,3);
	printf("Node removed \n");
	printList(head);

	return 0;
}
