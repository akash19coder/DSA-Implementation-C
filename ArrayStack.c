#include<conio.h>
#include<stdio.h>
#include<stdlib.h>



#define size 10
int arr[size];
int is_overflown=0;
int is_underflown=0;
int top=-1;

void push(int value);
void pop();
void stack_overflow();
void stack_underflow();
void display();

void main(){
push(3);
push(10);
push(15);
push(3);
push(10);

display();

// pop();

}

void push(int value){
  if(is_overflown==1){
    printf("Stack is overflown\n");
  }
  else{
    top++;
    arr[top]=value;
    printf("The pushed element is:%d\n",value);
  }
}

void pop(){
  if(is_underflown==1){
    printf("The stack is empty");
  }
  else{
    int ppd_element = arr[top];
    top--;
    printf("The popped element is:%d",ppd_element);

  }

}

void stack_overflow(){
  if(top>size){
    is_overflown=1;

  }
}

void stack_underflow(){
  if(top==-1){
    is_underflown=1;

  }
}

void display(){
  int i;
  if(is_overflown!=1 && is_underflown!=1){
    printf("Displaying the elements in the stack\n");
    for(i=top;i>=0;i--){
      printf("%d\n",arr[top]);
  }

  }
}
