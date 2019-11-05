#include<stdio.h>
#include<stdlib.h>

void insert();
void delete();
void display();
void search();

int front=0,rear=-1,array[5];
void main(){
	int ch;
	
	do{
		printf("Enter 1 for insert\nEnter 2 for delete\nEnter 3 for display\nEnter 4 for search\nEnter 5 for exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
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
	}while(ch!=4);
	getch();
}
void insert(){
	int data,i;
	for(i=0;i<5;i++){
		printf("Enter data %d:",i+1);
		scanf("%d",&data);
		
		if(rear>=10){
			printf("overflow");
			break;
		}
		else{
			++rear;
			array[rear] = data;
		}
	}	
}
void delete(){
	int data;
	if(rear<front){
		front=0;
		rear=-1;
		printf("underflow\n");
	}
	else{
		data=array[front];
		printf("%d is deleted\n",data);
		front++;
	}	
}
void display(){
	int x=front;
	printf("\nthis is the queue:\n");
	for(;x<=rear;x++){
		printf("%d\n",array[x]);
	}
}
void search(){
	int id,i;
	i=front;
	printf("Enter ID:");
	scanf("%d",&id);
	
	for(;i<=rear;i++){
		if(array[i]==id){
			printf("The position of %d is %d",id,i+1);
			break;
		}
		
	}
	if(i>rear){
		printf("This id number doesn't exit in this queue.");
	}
}
