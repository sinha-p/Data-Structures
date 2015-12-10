#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Binarytreenode
{
    int data;
    struct Binarytreenode *left;
    struct Binarytreenode *right;
};
struct Listnode
{
    struct Binarytreenode *node;
    struct Listnode *next;
};
struct Queue
{
    struct Listnode *frnt;
    struct Listnode *rear;
};
struct Queue *createqueue()
{
    struct Queue *Q=(struct Queue*)malloc(sizeof(struct Queue));
    Q->frnt=NULL;
    Q->rear=NULL;
}
void enqueue(struct Queue *Q,struct Binarytreenode *node)
{
    // cout<<"enqueue f()";
    struct Listnode *newnode=(struct Listnode*)malloc(sizeof(struct Listnode));
    newnode->node=node;
    newnode->next=NULL;
    if(Q->rear)
        Q->rear->next=newnode;
    Q->rear=newnode;
    if(Q->frnt==NULL)
        Q->frnt=Q->rear;
}
struct Binarytreenode *dequeue(struct Queue *Q)
{
    if(Q->frnt==NULL)
    {
        cout<<"Underflow";
        return NULL;
    }
    struct Binarytreenode *temp=(struct Binarytreenode*)malloc(sizeof(struct Binarytreenode));
    temp=Q->frnt->node;
    Q->frnt=Q->frnt->next;
    return temp;
}
struct Binarytreenode *newNode(int k)
{
    struct Binarytreenode *node=(struct Binarytreenode*)malloc(sizeof(struct Binarytreenode));
    node->data=k;
    node->left=NULL;
    node->right=NULL;
    return node;
}
bool isQueueEmpty(struct Queue *Q)
{
    if(Q->frnt==NULL)
        return true;
    return false;
}
void printLevelOrder(struct Binarytreenode *root)
{
    struct Queue *Q=createqueue();
    struct Binarytreenode *temp=(struct Binarytreenode *)malloc(sizeof(struct Binarytreenode));
    if(root==NULL)
    {
        return;
    }
    enqueue(Q,root);
    while(!isQueueEmpty(Q))
    {
        temp=dequeue(Q);
        cout<<" "<<temp->data<<" ";
        if(temp->left!=NULL)
        {
            enqueue(Q,temp->left);
        }
        if(temp->right!=NULL)
        {
            enqueue(Q,temp->right);
        }
    }
}
int main()
{
    struct Binarytreenode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    printLevelOrder(root);
}
