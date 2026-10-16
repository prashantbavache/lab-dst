#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int x){
 if (rear==MAX -1){
    printf("\nQueue overflow\n");
 }
 else if(front==-1 && rear==-1 ){
    front=rear=0;
    queue[rear]=x;
    }
 else{
    rear++;
    queue[rear]=x;
 }
 }

void dequeue(){
if (front==-1){
    printf("\nQueue underflow\n");
}
else if(front==rear){
    front=rear=-1;
}
else{
    printf("\n%d removed from queue\n",&queue[
           front]);
    front++;
}

}

void display(){
 if (front==-1){
    printf("\nQueue empty\n");
 }
 else {
    for (int i=front;i<=rear;i++){
        printf("%d",queue[i]);
        printf("\t");
    }
    printf("\n");
 }

}
int main (){
    int x , choice;
    while(1){
    printf("1.insert 2.delete 3.display 4.exit");
    printf("\nenter the choice :");
    scanf("%d",&choice);

switch(choice){
 case 1:
    printf("enter the value to be inserted:");
    scanf("%d",&x);
    printf("\n");
    enqueue(x);
    break;

 case 2 :
    dequeue();
    break;
 case 3 :
    display();
    break;
 case 4:
    return 0;
 default :
    printf ("\ninvalid choice\n");
}
}
return 0;
}
