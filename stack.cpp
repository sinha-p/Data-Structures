#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Listnode{
int data;
struct Listnode *next;
};
struct Stack{
struct Listnode *top;
};
struct Stack *createStack()
{
 struct Stack *S=(struct Stack *)malloc(sizeof(struct Stack));
 S->top=NULL;
}
void push(struct Stack *S,int k)
{
    struct Listnode *newnode=(struct Listnode *)malloc(sizeof(struct Listnode));
    newnode->data=k;
    newnode->next=NULL;
    if(S->top==NULL)
        S->top=newnode;
    else
    {
        struct Listnode *temp=(struct Listnode *)malloc(sizeof(struct Listnode));
        temp=S->top;
        S->top=newnode;
        S->top->next=temp;
    }
}
void printstack(struct Stack *S)
{
    if(S->top==NULL)
    {
        cout<<"Stack Empty\n";
        return;
    }
    struct Listnode *temp=(struct Listnode *)malloc(sizeof(struct Listnode));
    temp=S->top;
    cout<<"\n";
    while(temp)
    {
        cout<<temp->data<<"|";
        temp=temp->next;
    }
}
void pop(struct Stack *S)
{
    if(S->top==NULL)
    {
        cout<<"Underflow";
        return;
    }
    struct Listnode *temp=(struct Listnode *)malloc(sizeof(struct Listnode));
    temp=S->top;
    S->top=S->top->next;
    free(temp);
}
int main()
{
    struct Stack *S=createStack();
    printstack(S);
    cout<<"Inserting...";
    push(S,10);
    push(S,1);
    push(S,5);
    push(S,6);
    push(S,9);
    printstack(S);
    cout<<"\nPopping...";
    pop(S);
    printstack(S);
}
