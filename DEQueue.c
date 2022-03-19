// Header file declaration
#include<stdio.h>
#include<conio.h>

#define size 5
int arr[size];
int rear=-1,front=-1;

// Global function goes here
void enqueue(int item);
int dequeue();
int isFull();
int isEmpty();
void display();


// Main fuction goes here
void main(){
enqueue(5);
display();
}


// Enqueue function goes here
void enqueue(int item){
  if(isFull()){
    printf("The Queue is full/n");
  }
  if(rear==-1){
    rear++;
  }
  arr[rear++]=item;
}
// Dequeue function goes here
int dequeue(){
  if(isEmpty()){
    printf("The Queue is empty/n");
  }
  int item;
  if(front==-1){
    front++;
  }
  item=arr[front];
  front++;

  return item;
}
// isFull function goes here
int isFull(){
  if(front>size-1){
    return 1;
     }
  else {
    return 0;
  }

}
// isEmpty function goes here
int isEmpty(){
  if(front==-1 && rear==-1){
    return 1;
  }
  else {
    return 0;
  }

}

// Display function goes here
void display(){
  if(front==-1){
    front++;
  }
  int pos = front;
  while(pos<rear){
  printf("%d",arr[pos]);
  pos++;
  }


}
