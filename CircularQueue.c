#include<conio.h>
#include<stdio.h>

#define size 4
int arr[size];
int front=-1;
int rear=-1;

void delete();
void insert(int value);
void display();

void main(){
insert(10);
display();
}

//Insert function goes here
void insert(int value){
  // if(isFull()){
  //   printf("The stack is full\n");
  // }

  if(front==-1){
    front++;
  }
  rear=(rear+1)%size;
  arr[rear]=value;
}


//Delete function goes here
void delete(){
  int item=arr[front];
  if(front==rear){
    front=rear=-1;
  }
  front=(front+1)%size;
}

void display(){
  int i=front;
  while(i!=rear){
    printf("%d\n",arr[i]);
    i=(i+1)%size;
  }
  printf("%d",arr[i]);
}
