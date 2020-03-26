//Traversing and prinitng the nodes sequentially from a given node 

#include<stdio.h>
#include<stdlib.h>

//Defining the node struct
struct Node{
	int data;
	struct Node* next;
};

//Prints contents of linked list starting from the node which is passed
void printList(struct Node* n)
{
	while (n!=NULL)
	{
		printf("%d \t",n->data);
		n= n->next;
	}
	printf("\n");
}

int main()
{
	struct Node* head= NULL;
	struct Node* second= NULL;
	struct Node* third= NULL;
	
	head= (struct Node*)malloc(sizeof(struct Node));
	second= (struct Node*)malloc(sizeof(struct Node));
	third= (struct Node*)malloc(sizeof(struct Node));
	
	head->data= 2;
	head->next= second;
	
	second->data= 4;
	second->next= third;
	
	third->data= 6;
	third->next= NULL;
	
	printList(head);
	
	return 0;
}
