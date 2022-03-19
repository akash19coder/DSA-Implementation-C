#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

//Creation of a node
struct node {
  struct node *prev;
  int data;
  struct node *next;
};

//Functions declaration
struct node* create();
void display(struct node *head);
struct node* search(struct node *head,int key);
struct node* insert_beginning(struct node * head);
struct node* insert_end(struct node *head,int value);
struct node* insert_middle(struct node *head, int value);


void main(){
struct node* ptr = create();
ptr=insert_middle(ptr,5);
display(ptr);
// search(ptr,5);

}
// Create function goes here
struct node* create(){
    struct node *head,*new,*temp;
    int value, flag = 1;
    char ans='y';

    do{
      new = (struct node*) malloc(sizeof(struct node));
      new->next=NULL;
      new->prev=NULL;
      printf("Enter the data you want to enter in the node\n");
      scanf("%d",&value);
      new->data=value;
      if(flag==1){

        head=new;
        temp=head;

        flag=0;

      }
      else{
        temp->next=new;
        new->prev=temp;
        temp=new;
      }
      printf("Do you want to add more datas?(y/n)\n");
      ans=getch();
    }while(ans=='y'||ans=='Y');
    return head;
}

//Display function goes here
void display(struct node* head){
struct node *temp = head;
struct node *temp1 = head;
printf("Printing the data in forward order\n");
while(temp!=NULL){
  printf("%d\n",temp->data);
  temp=temp->next;
}
getch();

printf("Printing the data in reverse order\n");
while(temp1->next!=NULL){
  temp1=temp1->next;
}
while(temp1!=NULL){
  printf("%d\n",temp1->data);
  temp1=temp1->prev;

}
getch();

}

//Search function goes here
struct node* search(struct node *head,int key){
  struct node *temp=head;
  int found = TRUE;
  if(temp==NULL){
    printf("The linked list doesn't exists");
  }
  found=FALSE;
  while(temp!=NULL && found==FALSE){
    if(temp->data!=key){
      temp=temp->next;
    }
    else{
      found=TRUE;
    }
  }
    if(found==TRUE){
      printf("The data  exists in the linked List");
      return temp;
    }
    else{
      printf("The data does not exists in the linked list");
    }

}

//insert beginning function goes here
struct node* insert_beginning(struct node * head){
  int value;
  struct node *new =(struct node*) malloc(sizeof(struct node));
  new->next=NULL;
  new->prev=NULL;
  printf("Enter the data you want to store in the beginning of list\n");
  scanf("%d",&value);
  new->data=value;

  new->next=head;
  head->prev=new;
  head=new;

  return head;
}

//insert end function goes here
struct node* insert_end(struct node *head,int value){
  struct node *temp=head;
  struct node *new = (struct node*) malloc(sizeof(struct node));
  new->prev = NULL;
  new->data=value;
  new->next = NULL;


  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=new;
  new->prev=temp;

  return head;
}

//insert middle function begins here
struct node* insert_middle(struct node *head, int value){
  int key;
  printf("Enter the key after which you want to insert the data\n");
  scanf("%d",&key);
struct node *new = (struct node*) malloc(sizeof(struct node));
new->prev = NULL;
new->data = value;
new->next = NULL;

struct node *temp=head;
do{
  if(temp->data==key){
    new->next=temp->next;
    temp->next=new;
    new->prev=temp;
    return head;
  }
  else{
    temp=temp->next;
  }
}while(temp->next!=NULL);

 
}
