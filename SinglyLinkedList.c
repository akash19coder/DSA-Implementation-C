#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

struct node {
  int data;
  struct node *link;
};

struct node* create();
void display();
struct node* search();
struct node* insert_beg(struct node *head);
struct node* insert_last(struct node *head);
struct node* insert_after(struct node *head);
struct node* delete_beg(struct node *head);
struct node* delete_end(struct node *head);


void main(){

struct node *ptr;
int choice,val;
char ans='y';
do{
  printf("Enter your choice\n");
  printf("1.Create\n");
  printf("2.Search\n");
  printf("3.Insert at the beginning\n");
  printf("4.Insert at the last\n");
  printf("5.Insert at the middle\n");
  printf("6.Delete at the begining\n");
  printf("7.Delete at the last\n");
  printf("8.Display\n");
  scanf("%d",&choice);
  switch (choice) {
    case 1:
    ptr=create();
    break;

    case 2:
    printf("Enter the value you want to search\n");
    scanf("%d",&val);
    search(ptr,val);
    break;

    case 3:
    ptr=insert_beg(ptr);
    break;

    case 4:
    ptr=insert_last(ptr);
    break;

    case 5:
    ptr=insert_after(ptr);
    break;

    case 6:
    ptr=delete_beg(ptr);
    break;

    case 7:
    ptr=delete_end(ptr);
    break;

    case 8:
    display();
    break;

    default:
    
    printf("Please enter the valid option\n");

  }
 printf("Do you want to try again\n");
 ans=getch();
}while(ans=='y'||ans=='Y');
// search(ptr,5);
// ptr=insert_beg(ptr);
// display(ptr);
//  ptr=insert_last(ptr);
// display(ptr);
// ptr=insert_after(ptr);
// ptr=delete_beg(ptr);
// ptr=delete_end(ptr);
// display(ptr);

}


/** create() function defination**/
struct node* create(){
struct node *head,*temp, *new;
int value, flag=1;
char ans='y';

do{
new= (struct node*)malloc(sizeof(struct node));
new->link=NULL;
printf("Enter the data you want to store\n");
scanf("%d",&value);
new->data=value;
if(flag==1){
  head=new;
  temp=head;
  flag=0;
}
else{

    temp->link=new;
    temp=new;
}
printf("Do you want to add more nodes?(y/n)\n");
ans=getch();
} while(ans=='y'||ans=='Y');

return head;
}


/** display() function defination**/
void display(struct node *head){
 struct node *temp = head;

 if(temp==NULL){
   printf("The Linked List does not exists");
   getch();

   return;
 }
     printf("The datas in the linked list are:\n");
     while(temp!=NULL){
       printf("%d\n", temp->data);
       temp=temp->link;
     }
     printf("NULL\n");
     getch();
}



/** search() function defination**/
struct node* search(struct node *head,int element){
  printf("The element you want to search is %d\n",element);

struct node* temp;
int found=FALSE;
temp=head;

if(temp==NULL){
  printf("The Linked List doesn't exists");
  getch();
  return NULL;
}

while(temp!=NULL && found==FALSE){
  if(temp->data!=element){
    temp=temp->link;
  }
  else{
    found=TRUE;
  }
  if(found==TRUE){
    printf("The element is present in the list\n");
    getch();
    return temp;

  }
  else{
    printf("The element doesn't exists in the list\n");
    return NULL;
  }

  }

}


/** insert_beg() function defination**/
struct node* insert_beg(struct node *head){
  struct node *new =(struct node*) malloc(sizeof(struct node));
  new->link=NULL;
  printf("Please enter the data in new node\n");
  scanf("%d",&new->data);

new->link=head;
head=new;

return head;
}



/** insert_last() function defination**/
struct node* insert_last(struct node* head){
   struct node *temp = head;
   struct node *new = (struct node*) malloc(sizeof(struct node*));
   new->link=NULL;

   printf("Enter the data into the new node\n");
   scanf("%d",&new->data);

   while(temp->link!=NULL){
    temp = temp->link;
   }
   temp->link=new;
   temp=new;

   return head;

}


/** insert_after() function defination**/
struct node* insert_after(struct node *head){

 int key;
 struct node *temp=head;
 struct node *new =(struct node*) malloc(sizeof(struct node*));
 new->link=NULL;

 printf("Enter the data you want to insert in new node\n");
 scanf("%d",&new->data);

 printf("Enter the key after which you want to insert data\n");
 scanf("%",&key);

do{
   if(temp->data==key){
     new->link=temp->link;
     temp->link=new;
     return head;

   }
   else{
     temp=temp->link;
   }

}while(temp!=NULL);
}

/** delete_beg() function defination**/
struct node* delete_beg(struct node *head){
  struct node* temp=head;
  head=temp->link;
  free(temp);
  return head;
}

/** delete_end() function defination**/
struct node* delete_end(struct node *head){
struct node *temp=head;

while(temp->link!=NULL){
  temp=temp->link;
}
free(temp);
return head;
}
