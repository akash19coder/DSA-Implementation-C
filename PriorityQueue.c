/*Header Files*/
#include<stdio.h>
#include<conio.h>

#define size 5
int arr[size];
int rear=-1,front=-1;

// Global functions declaration goes here
void delete(int item);


//Main Function starts here
void main(){

}

void delete(int item){
  if(front==-1){
    front++;
  }
  int pos = rear;
  while(pos>=0 && arr[pos]>item){
    arr[pos+1]=arr[pos];
    pos--;
  }
  arr[pos+1]=item;
  rear=rear+1;

}
