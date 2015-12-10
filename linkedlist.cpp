#include<iostream>
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void insertatbegin( struct Node** head,int k)
{
    struct Node* node=( struct Node*)malloc(sizeof( struct Node));
    node->data=k;
    node->next=*head;
    *head=node;
}
void insertatend(struct Node** head,int k)
{
    struct Node* node=( struct Node*)malloc(sizeof( struct Node));
    if(*head==NULL)
    {
        node->data=k;
        node->next=NULL;
        *head=node;
    }
    else
    {
        struct Node*  temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        node->data=k;
        node->next=NULL;
        temp->next=node;
    }
}
void insertafter(struct Node** head,int ele,int k)
{
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp=*head;
    while(temp->next!=NULL)
    {
        if(temp->data==ele)
        {
            node->data=k;
            node->next=temp->next;
            temp->next=node;
            return;
        }
        temp=temp->next;
    }
    printf("\nCannot find element in the list...\n");
}
void printlist( struct Node* head)
{
    while(head!=NULL)
    {
        printf("%d-->",head->data);
        head=head->next;
    }
}
int main()
{
    struct Node* head=NULL;
    insertatbegin(&head,2);
    insertatbegin(&head,4);
    insertatbegin(&head,7);
    insertatbegin(&head,9);
    insertatbegin(&head,12);
    insertatend(&head,23);
    insertatend(&head,45);
    insertafter(&head,9,79);
    insertafter(&head,2,76);
    printlist(head);
}
