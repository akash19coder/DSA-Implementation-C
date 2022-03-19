#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

//Creationg of node
struct node {
  int data;
  struct node *next;
};
//Function declaration section
struct node* create();
void display(struct node *head);
void search(struct node *head, int value);
struct node* insert_begining(struct node *head,int value);
struct node* insert_end(struct node* head, int value);
struct node* insert_middle(struct node* head,int value);
struct node* del_beg(struct node* head);


//Main method goes here
void main(){
struct node *ptr = create();
ptr = del_beg(ptr);
display(ptr);
// search(ptr,5);


}

//Create() function goes here
struct node* create(){
  struct node *new,*temp,*head;
  int flag=1;
  char ans='y';

 do{
   new=(struct node*) malloc(sizeof(struct node));
   new->next=NULL;
   printf("Enter the value you want to store in node\n");
   scanf("%d",&new->data);
   if(flag==1){ //node is being created for the first time
     head=new;
     new->next=head;
     temp=head;
     flag=0;
   }
   else{        //node is not  being create for the first time
     temp->next=new;
      new->next=head;
     temp = temp->next;

   }
   printf("Do you want to insert more nodes?(y/n)\n");
   ans=getch();

 }while(ans=='y'||ans=='Y');
 return head;
}

//Display() function goes here
void display(struct node *head){
  struct node *temp=head;
  printf("The data in the Circular Singly Linked List are:\n");
do  {
    printf("%d\n",temp->data);
    temp=temp->next;
  }while(temp!=head);
  getch();
}

void search(struct node* head,int value){
  struct node *temp = head;
  do{
    if(temp->data==value){
      printf("The exists in the Circular Linked List");
    }
    else{
      printf("Data is missing");
    }
  }while(temp!=head);
  getch();

}

//Insert begining function goes here
struct node* insert_begining(struct node *head,int value){
  struct node *new = (struct node*) malloc(sizeof(struct node));
  new->data=value;
  new->next=NULL;
  struct node *temp=head;
  while(temp->next!=head){
    temp=temp->next;
  }
  temp->next=new;
  new->next=head;
  head=new;

  return head;
}

//insert end function goes here
struct node* insert_end(struct node *head,int value){

struct node *new = (struct node*) malloc(sizeof(struct node));
new->data=value;
new->next=NULL;

struct node *temp = head;
 while(temp->next!=head){
     temp=temp->next;
 }

 new->next = head;
 temp->next=new;
 temp=temp->next;

 return head;
}

//insert middle function goes here
     struct node* insert_middle(struct node* head,int value){
     struct node *new =(struct node*) malloc(sizeof(struct node));
     new->data=value;
     new->next=NULL;
     struct node *temp=head;
     int key;
     printf("Enter the key after which you want to enter the data\n");
     scanf("%d",&key);
   do {
     if(temp->data==key){
       new->next=temp->next;
       temp->next=new;
     }
     else{
       temp=temp->next;
     }
   } while(temp!=head);


    return head;
}

//delete begining function goes here
struct node* del_beg(struct node *head){
  struct node *temp = head;
  struct node *temp1 = head;
  while(temp1->next!=head){
    temp1=temp1->next;
  }
  head=head->next;
  temp1->next=head;
  free(temp);
  getch();
  return head;
}

//delete the node in the end function goes here
struct node* del_end(struct node* head){
  struct node* temp=head;
  struct node* temp1=head;
  while(temp->next!=head){
    temp=temp->next;
  }

}
