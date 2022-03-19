#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
//Global declaration section
#define size 5
int que[size];
int front,rear=-1;

void insert(int value);
void delete();
void display();


void main(){
int choice,value;
do{
  printf("1.Enqueue\n");
  printf("2.Dequeue\n");
  printf("3.Display\n");
  printf("4.Quit\n");
  printf("Enter the your choice\n");
  scanf("%d",&choice);
  switch(choice){
    case 1:
    printf("Enter the value you want to enqueue\n");
    scanf("%d",&value);
    insert(value);
    break;

    case 2:
    delete();
    break;

    case 3:
    display();
    break;

    case 4:
    exit(1);
  }
}while(1);

}

//Insert function goes here
void insert(int value){
  if(front==-1){
    front++;
  }

  que[++rear]=value;
}
//Dislay function goes here
void display(){
  int i;

    for(i=front;i<=rear;i++){
      printf("%d\n",que[i]);
    }
}
//Delete function goes here
void delete(){
  ++front;
}
