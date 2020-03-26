//Declaring nodes and assigning them values

#include<stdio.h>
#include<stdlib.h>

//Defining the node struct
struct Node{
	int data;	//data stored in the node 
	struct Node* next;	//pointer to the next node
};

int main()
{
	//Defining three pointers of Node type 
	struct Node* head= NULL;
	struct Node* second= NULL;
	struct Node* third= NULL;
	
	//Declaring and allocating 3 nodes in the heap
	head= (struct Node*)malloc(sizeof(struct Node));
	second= (struct Node*)malloc(sizeof(struct Node));
	third= (struct Node*)malloc(sizeof(struct Node));
	//The blocks have been allocated to each pointer dynamically
	
	//Initialising and assigning data to the head node and giving the pointer of second node for next
	head->data=1;
	head->next= second;
	
	//Similarly for second
	second->data= 2;
	second->next= third;
	
	//Similarly for third
	third->data= 3;
	third->next= NULL;
	
	//All the blocks have been linked to each other to form a linked list and we ultimately need only the head pointer.
	
	return 0;
}
