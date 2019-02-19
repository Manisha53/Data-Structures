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
            printf("%d\t\n",n->data);
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
void deletenode(struct node ** head_ref,int key)      //deletion of node OF GIVEN VALUE from linked list
{
    struct node* temp=*head_ref,*prev;

    if( temp!=NULL && temp->data==key ){
        *head_ref=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp == NULL){
        return;
    }
    prev->next=temp->next;
        //temp->next=NULL;
        free(temp);
}

void deletepos(struct node ** head_ref,int pos)   //delete the element present at a particular position
{
    int i;
    struct node *temp=*head_ref,*prev;
    if(*head_ref == NULL)
    {
        printf("linkedlist does not exists\n");
    }
    for(i=0;temp!=NULL && i<pos;i++)
    {    prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
        return;
    prev->next=temp->next;
    free(temp);
}

void dellist(struct node** head_ref)               //delete full list
{
    struct node* temp=*head_ref;
    struct node* nex;
    while(temp!=NULL)
        {
            nex=temp->next;
            free(temp);
            temp=nex;
        }

        *head_ref=NULL;
}

int main()
{
    int i,j,n,e,pos;
    struct node* head=NULL;
    //head=(struct node* )malloc(sizeof(struct node));
    printf("enter the number of elements you want to insert\n");
    scanf("%d",&n);
    printf("enter the elements:\n");
    for(j=0;j<n;j++){
        scanf("%d",&e);
        insert_beg(&head,e);
    }

    printf("The linked list is:\n");
    printlist(head);
    printf("enter choice\n1--delete a particular key.\n2--delete a node at particular location.\n3--Delete the whole list\n");
    scanf("%d",&j);
    switch(j)
    {
        case 1:
            printf("Enter the key to be deleted:\n");
            scanf("%d",&i);
            deletenode(&head,i);
            printf("\n");
            printlist(head);
        break;
       case 2:
           printf("Enter the position:\n");
            scanf("%d",&pos);
            deletepos(&head,pos);         //indexing starts from 0
            printf("\n");
            printlist(head);
            break;
       case 3:
            dellist(&head);
            printf("The list is deleted\n");
            printlist(head);
        break;

    }

    return 0;

}
