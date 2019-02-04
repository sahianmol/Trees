#include<stdlib.h>
#include<stdio.h>
struct queue
{
        struct tree* arr[50];
        int front;
        int rear;
};
void initializeQueue(struct queue *q)
{
        int i;
        for(i=0;i<50;i++)
        {
                q->arr[i]=NULL;
                q->front=-1;
                q->rear=-1;
        }
}
void add(struct queue* q,struct tree* root)
{
        q->rear++;
        q->arr[q->rear]=root;
        if(q->front==-1)
         q->front=q->rear;
}
struct tree* poll(struct queue* q)
{
        struct tree* temp=q->arr[q->front];
        if(q->front==q->rear)
         q->front=q->rear=-1;
         else
          q->front++;
        return temp;
}
int isEmpty(struct queue* q)
{
        if(q->front==-1 && q->rear==-1)
           return 1;
        else
          return 0;
}
struct tree
{
        int data;
        int val;
        struct tree* left;
        struct tree* right;
};
struct tree* newnode(int d,int hd)
{
        struct tree* nn=(struct tree*)malloc(sizeof(struct tree));
        nn->data=d;
        nn->val=hd;
        nn->left=NULL;
        nn->right=NULL;
        return nn;
}
struct tree* createTree(struct tree* root,int d,int hd)
{
        if(root==NULL)
        {
                return newnode(d,hd);
        }
        if(d<root->data)
           root->left=createTree(root->left,d,hd-1);
        else
           root->right=createTree(root->right,d,hd+1);
        return root;
}
int ar[28];
void topview(struct tree* root,int *l,int* r)
{
        struct queue q;
        initializeQueue(&q);
        add(&q,root);
        while(!isEmpty(&q))
        {
                struct tree* temp=poll(&q);
                if(temp->left)
                  add(&q,temp->left);
                if(temp->right)
                   add(&q,temp->right);
                if(ar[temp->val+14]!=-1)
                   ar[temp->val+14]=temp->data;
                if(*l>(temp->val+14))
                   *l=temp->val+14;
            if(*r<(temp->val+15))
              *r=temp->val+14;
        }
  printf("\n");
    for(int i=*l;i<=*r;i++)
      printf("%d ",ar[i]);
}
void inorder(struct tree* root)
{
        if(root!=NULL)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
        }
}
int main()
{
    int l=14,r=14;
    struct tree *root=NULL;
    root=createTree(root,50,0);
    root=createTree(root,30,0);
    root=createTree(root,20,0);
    root=createTree(root,40,0);
    root=createTree(root,70,0);
    root=createTree(root,60,0);
    root=createTree(root,80,0);
    inorder(root);
    topview(root,&l,&r);
 return 0;
}
