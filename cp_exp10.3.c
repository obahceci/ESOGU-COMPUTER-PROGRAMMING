/* ******************************************************* 
 * Filename		:	stack_template.c
 * Author		:	Burak Kaleci		
 * Date			:	22.05.2017
 * Description	:	Quiz 3
 * ******************************************************/

#include<stdio.h>
#include<stdlib.h>

// structure definition
// self-referential structure 
typedef struct stackNode { 
	int data; 					// each stackNode contains an integer 
	struct stackNode *nextPtr; 	// pointer to next node
} Node; 

// initially there are no nodes
// So that topPtr points nothing;
Node *topPtr=NULL;

// function prototypes
int isEmpty(void);
void push(int value);
int pop(void);
void printStack(void);
int size(void);

/* function main begins program execution 
 each program must include main function */
int main(void)
{ 
	int num[10]={2,8,3,6,1,5,4,9,0,7};int i;
	
	printf("original order:\n");
	for(i=0;i<10;i++){
		printf("%3d",num[i]);
		if(i%10==9)
			printf("\n");
	}
	
	for(i=0;i<10;i++)
		push(num[i]);
	
	printStack();
	
	for(i=0;i<10;i++)
		num[i]=pop();
		
	printf("reversed order:\n");
	for(i=0;i<10;i++){
		printf("%3d",num[i]);
		if(i%10==9)
			printf("\n");
	}	
			
} 

// return 1 if the stack is empty, 0 otherwise
int isEmpty(void)
{ 
	if (topPtr==NULL)
		return 1;
	else
		return 0;
 	
} 

// add the value at the top of the stack
void push(int value)
{
	if (isEmpty()){		// Case 1: If the stack is empty
	
		Node *newNode=malloc(sizeof(Node)); // create node;
		newNode->data=value;
		newNode->nextPtr=NULL;
		
		topPtr=newNode;
		printf("push first item %d to stack\n",value);
	}
	else { 	// Case 2: If the stack is not empty
		
		Node *newNode=malloc(sizeof(Node)); // create node;
		newNode->data=value;
		newNode->nextPtr=topPtr;
		
		topPtr=newNode;
		printf("push %d to stack\n",value);	
	}	
}

// delete the item at the top of the stack
// return the value of deleted item
int pop(void)
{
	// Local variables to iterate the stack
	Node *tempPtr=topPtr;
	int popValue;
	
	if (isEmpty()){	// Case 1: If the stack is empty
		printf("The stack is empty.\nThere is no item to delete\n");
		return -1;
	}
	else{	// Case 2: If the stack is not empty
		
		popValue=topPtr->data;
		topPtr=tempPtr->nextPtr;
		
		free(tempPtr);
		return popValue;	
	}		
}

// print the stack
void printStack(void)
{
	Node *currentPtr=topPtr;
	
	if (topPtr==NULL)
		printf("The stack is empty\n");
	else{
	
   		printf("The stack is:\n");
		while(currentPtr!=NULL){
			printf("  <----%d",currentPtr->data);
			currentPtr=currentPtr->nextPtr;
		}
		printf("\n");
   }
} 

// returns the size of the stack
int size(void)
{
	int count=0;
	Node *currentPtr=topPtr;
	
	//If the stack is empty
	if (topPtr==NULL)
		return 0;
	else{
	
		while(currentPtr!=NULL){
			currentPtr=currentPtr->nextPtr;
			count++;
		}
		return count;
   }
}





