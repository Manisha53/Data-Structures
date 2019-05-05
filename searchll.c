#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create(struct node** head_ref,int val)         //creation of linked list
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    //while(temp!=NULL){
        temp->data=val;
        temp->next=*head_ref;
        *head_ref=temp;

}

void printlist(struct node *n)                     //creation of linked list
{
    while(n!=NULL)
    {
        printf("%d\t",n->data);
        n=n->next;
    }
}

void search(struct node **head_ref,int val)       //search using iterative call
{
    struct node *temp=*head_ref;
    int pos=0;
    if(temp==NULL)
    {
        printf("Linked list is empty,element can't be found\n");
    }

    while(temp!=NULL)
    {
        if(temp->data == val)
        {
            pos++;
            printf("%d is present at position: %d",val,pos);
            break;
        }
        else{
            printf("element can't be found!\n");
            break;
        }
        temp=temp->next;
            pos++;

    }


}

int main()
{
    int i,n,j,a;
    struct node *head=NULL;
    printf("Enter the no. of terms:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&j);
        create(&head,j);
    }
    printf("The linked list is:\n");
    printlist(head);
    printf("\nEnter the element to be searched from the linked list:\n");
    scanf("%d",&a);
    search(&head,a);
    return 0;
}
