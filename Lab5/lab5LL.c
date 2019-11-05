#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *front,*rear,*newNode,*cur;
void enQueue();
void deQueue();
void traverse();
void search();

void main(){
	int ch;
	do{
		printf("\nEnter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for traverse\nEnter 4 for search\nEnter 5 for exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				enQueue();
				break;
			case 2:
				deQueue();
				break;
			case 3:
				traverse();
				break;
			case 4:
				search();
				break;
			case 5:
				exit(1);
				break;
			default:
				printf("wrong choice.");
				break;
		}
	}while(ch!=5);		
}
void enQueue(){
	int node;
	newNode=(struct node *)malloc(sizeof(struct node));
	printf("enter node:");
	scanf("%d",&node);
	newNode->data = node;
	newNode->next = NULL;
	if(rear==NULL){
		
		rear=newNode;
	}
	else{
		cur=rear;
		while(cur->next!=NULL)
		{
			cur=cur->next;	
		}
			
		cur->next= newNode;
	}
	
	
}
void deQueue(){
	if(rear==NULL){
		printf("underflow");
	}
	else{
		front=rear;
		rear=rear->next;
		front->next=NULL;
		printf("%d is deleted",front->data);
		free(front);
	}
}
void traverse(){
	front=rear;
	printf("the Queue is\n ");
	while(front!=NULL){
		printf("%d<-",front->data);
		front=front->next;
	}
}
void search(){
	int id,k=0;
	printf("Enter ID:");
	scanf("%d",&id);
	while(rear->next!=NULL){
		if(rear->data==id){
			printf("the position of %d in the queue is  %d.\n",id,k+1);
			break;
		}
		else
			rear=rear->next;
		k++;	
	}
	if(rear->next==NULL){
		printf("the id number doesn't exit in the queue.\n");
	}
}
