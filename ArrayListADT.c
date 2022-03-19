#include<stdio.h>
#include<conio.h>

#define size 100

int n,arr[size];

void create();
void display();
void search(int element);
void insert();
void delete();


void main(){
  int choice,element;
  do{
printf("****------Menu------*****\n");
printf("1.create\n");
printf("2.display\n");
printf("3.search\n");
printf("4.insert\n");
printf("5.delete\n");
printf("Please enter your choice\n");
scanf("%d",&choice);
switch(choice){
  case 1:
  create();
  break;

  case 2:
  display();
  break;

  case 3:
  printf("Enter the element\n");
  scanf("%d",&element);
  search(element);
  break;

  case 4:
  insert();
  break;

  case 5:
  delete();
  break;
}
}while(choice<=5);


}


void create(){
  int i;
  printf("Enter the size of list\n");
  scanf("%d",&n);
  printf("Enter the element one by one\n");
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  printf("The List is created\n");
}

void display(){
  int i;
  printf("The element in the list are:\n");
  for(i=0;i<n;i++){
    printf("%d\n",arr[i]);
  }

}

void search(int element){
  int i;
  for(i=0;i<n;i++){
    if(arr[i]==element){
      printf("The element exists in %dth position\n",i+1);
      break;
    }
  }
}

void insert(){
  int pos,value,i;
  printf("Enter the position you want to insert\n");
  scanf("%d",&pos);
  printf("Enter the value you want to insert\n");
  scanf("%d",&value);

  n++;
  for(i=n;i>pos-1;i--){
    arr[i]=arr[i-1];
  }
  arr[pos-1]=value;
}

void delete(){
  int pos,i;
  printf("Enter the position you want to delete\n");
  scanf("%d",&pos);
  for(i=pos-1;i<n;i++){
    arr[i]=arr[i+1];
  }
}
