/* ******************************************************* 
 * Filename		:	queue_template.c
 * Author		:	Burak Kaleci		
 * Date			:	22.05.2017
 * Description	:	Quiz 3
 * ******************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// structure definition
// self-referential structure 
typedef struct queueNode { 
	int data; 					// each queueNode contains an integer 
	struct queueNode *nextPtr; 	// pointer to next node
} Node; 

// initially there are no nodes
// So that headPtr and tailPtr point nothing;
Node *headPtr=NULL;
Node *tailPtr=NULL;

// function prototypes
int isEmpty(void);
void enqueue(int value);
int dequeue(void);
void printQueue(void);
int size(void);

void wait(int seconds) {
    
	time_t start, end;
    double elapsed;
 
    time(&start);  /* start the timer */
 	printf("Waiting %d seconds\n",seconds);
 	
    do {
		time(&end);
        elapsed = difftime(end, start);
    } while(elapsed < seconds);  /* run for ten seconds */
}

/* function main begins program execution each program must include main function */
int main(void)
{
	int customer=1,age;
	
	while(customer<=50){
	
		age=10+rand()%26;
		printf("\nEntering person's age %d\n",age);
	
		if(age<18){
			printf("This person can not be a customer\n");
			wait(3);
		}
		else if(size()<10 && age>18){
			enqueue(age);
			printQueue();
			customer++;
		}
		
		else if(size()==10){
			wait(3);
			dequeue();
			printQueue();
		}
		while(size()>0){
			wait(3);
			dequeue();
			printQueue();
		}
	}

} 

// return 1 if the queue is empty, 0 otherwise
int isEmpty(void)
{ 
	if (headPtr==NULL)
		return 1;
	else
		return 0;
 	
} 

// add the value at the tail of the queue
void enqueue(int value)
{
	if (isEmpty()){		// Case 1: If the queue is empty
	
		Node *newNode=malloc(sizeof(Node)); // create node;
		newNode->data=value;
		newNode->nextPtr=NULL;
		
		headPtr=newNode;
		tailPtr=newNode;
		printf("enqueue first item %d to queue\n",value);
	}
	else { 	// Case 2: If the queue is not empty
		
		Node *newNode=malloc(sizeof(Node)); // create node;
		newNode->data=value;
		newNode->nextPtr=NULL;
		tailPtr->nextPtr=newNode;
		
		tailPtr=newNode;
		printf("enqueue %d to queue\n",value);	
	}	
}

// delete the item at the head of the queue
// return the value of deleted item
int dequeue(void)
{
	// Local variables to iterate the queue
	Node *tempPtr=headPtr;
	int popValue;
	
	if (isEmpty()){	// Case 1: If the queue is empty
		printf("The queue is empty.\nThere is no item to delete\n");
		return -1;
	}
	else{	// Case 2: If the queue is not empty
		
		popValue=headPtr->data;
		headPtr=tempPtr->nextPtr;
		
		printf("dequeue %d to queue\n",popValue);	
		free(tempPtr);
		return popValue;	
	}		
}

// print the queue
void printQueue(void)
{
	Node *currentPtr=headPtr;
	
	if (headPtr==NULL)
		printf("The queue is empty\n");
	else{
	
   		printf("The queue is:\n");
		while(currentPtr!=NULL){
			printf("  <----%d",currentPtr->data);
			currentPtr=currentPtr->nextPtr;
		}
		printf("\n\n");
   }
} 

// returns the size of the queue
int size(void)
{
	int count=0;
	Node *currentPtr=headPtr;
	
	//If the queue is empty
	if (headPtr==NULL)
		return 0;
	else{
	
		while(currentPtr!=NULL){
			currentPtr=currentPtr->nextPtr;
			count++;
		}
		return count;
   }
}





