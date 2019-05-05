#include<stdio.h>
#include<stdlib.h>

struct node{                                               //node creation
    int data;
    struct node* next;
};

void create(struct node** head_ref,int val)             //creation of linked list
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=*head_ref;
    *head_ref=temp;
}
void printlist(struct node* n)                  //print the linked list
{
    while(n!=NULL)
    {
        printf("%d\t",n->data);
        n=n->next;
    }
}

void reverse(struct node** head_ref)         //reversal function
{
   struct node *temp=(*head_ref)    ;
    struct node *prev=NULL;
   struct node *nex=NULL;
    while(temp!=NULL)
    {
        nex=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nex;
    }
    *head_ref=prev;
}

int main()                                  //main
{
    struct node* head=NULL;
    int n,i,x;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the numbers you want to create list of:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        create(&head,x);
    }
    printlist(head);
    printf("\n");
    printf("THE REVERSED LINKED LIST IS:\n");
    reverse(&head);
    printlist(head);
    return 0;
}
