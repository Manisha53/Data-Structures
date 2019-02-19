//Insertion in linked list(all options included)
#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* next;
};

 void printlist(struct node *n)
 {
        while(n!=NULL)
            {
            printf("%d\t",n->data);
            n=n->next;
            }
    }
void insert_beg(struct node** head_ref ,int val )
{
    struct node* beg=(struct node** )malloc(sizeof(struct node));   //node to be inserted in beginning
    beg->data=val;
    beg->next=*head_ref;
    *head_ref=beg;
}

void insert_end(struct node** head_ref,int val )
{
    struct node* end=(struct node* )malloc(sizeof(struct node)); //node to be inserted at end
     struct node* last=*head_ref;

    end->data=val;
    end->next=NULL;

    if(*head_ref == NULL){
        head_ref=end;
        return;
    }

    while(last->next != NULL)
    {
         last=last->next;
    }
    last->next=end;
    //end->next=NULL;
    return;
}

void insert_mid(struct node* prev,int val)
{
    if(prev == NULL){
        //insert_end(&head,val);
        printf("PREVIOUS CAN NOT BE NULL\n");
        return;
    }
    struct node* mid=(struct node* )malloc(sizeof(struct node));
    mid->data=val;
    mid->next=prev->next;
    prev->next=mid;

}

int main()
{   int v,i,w,pos;
    struct node* head=NULL;
    struct node* sec=NULL;
    struct node* third=NULL;

    head=(struct node* )malloc(sizeof(struct node));
    sec=(struct node* )malloc(sizeof(struct node));
    third=(struct node* )malloc(sizeof(struct node));

    head->data=1;
    head->next=sec;

    sec->data=2;
    sec->next=third;

    third->data=3;
    third->next=NULL;

    printf("Enter\n 1--Insertion at beginning\n 2--Insertion after some node\n 3--Insertion at end\n");
    scanf("%d",&i);
    switch(i)
    {
        case 1:printf("Enter the value you want to add on:\n");
               scanf("%d",&v);
               insert_beg(&head,v);
               break;
        case 3:printf("Enter the value you want to insert at end:\n");
               scanf("%d",&w);
               insert_end(&head,w);
               break;
        case 2://printf("Enter the location where you want to insert\n");
               //scanf("%d",&pos);
               printf("Enter the value you want to insert after the second element\n");
               scanf("%d",&v);
               insert_mid(head->next,v);
               break;
    }

    printlist(head);

    return 0;

}
