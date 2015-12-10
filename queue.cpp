#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Listnode
{
    int data;
    struct Listnode* next;
};
struct Queue
{
    struct Listnode* frnt;
    struct Listnode* rear;
};
struct Queue *createqueue()
{
    struct Queue *Q=(struct Queue*)malloc(sizeof(struct Queue));
    Q->frnt=Q->rear=NULL;
    return Q;
}
void enqueue(struct Queue *Q,int k)
{
    struct Listnode *newnode=(struct Listnode*)malloc(sizeof(struct Listnode));
    newnode->data=k;
    newnode->next=NULL;
    if(Q->rear)
    {
        Q->rear->next=newnode;
    }
    Q->rear=newnode;
    if(Q->frnt==NULL)
    {
        Q->frnt=Q->rear;
    }
}
void dequeue(struct Queue *Q)
{
    if(Q->frnt==NULL)
    {
        cout<<"Underflow";
        return;
    }
    struct Listnode *temp=(struct Listnode *)malloc(sizeof(struct Listnode));
    temp=Q->frnt;
    Q->frnt=Q->frnt->next;
    free(temp);
}
void printqueue(struct Queue *Q)
{
    if(Q->frnt==Q->rear)
    {
        return;
    }
    struct Listnode* temp=Q->frnt;
    cout<<"\n";
    while(temp!=Q->rear)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data;
}
int main()
{
    struct Queue *Q=createqueue();
    enqueue(Q,10);
    enqueue(Q,1);
    enqueue(Q,5);
    enqueue(Q,6);
    enqueue(Q,9);
    printqueue(Q);
    dequeue(Q);
    printqueue(Q);
    dequeue(Q);
    printqueue(Q);
}
