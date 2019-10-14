#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
	int height;
}*root=NULL;
int height(struct node* temp)
{
	if(temp==NULL)return 0;
	return temp->height;
}
struct node* newnode(int x)
{
	struct node*temp=(struct node*)malloc(sizeof(struct node*));
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	//temp->height=1;
	return temp;
}
int bal(struct node* temp)
{
	if(temp==NULL)return 0;
	return (height(temp->left)-height(temp->right));
}
int max(int x,int y)
{
	if(x>y)return x;
	else return y;
}
struct node*rr(struct node*y)
{
	struct node *x,*t;
	x=y->left;
	t=x->right;
	x->right=y;
	y->left=t;
	y->height=max(height(y->left),height(y->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	return x;
}
struct node*ll(struct node*x)
{
	struct node *y,*t;
	y=x->right;
	t=y->left;
	y->left=x;
	x->right=t;
	x->height=max(height(x->left),height(x->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	return y;
}
struct node*insert(struct node*node,int x)
{
	if(node==NULL)return newnode(x);
	if(x<node->data)node->left=insert(node->left,x);
	else if(x>node->data)node->right=insert(node->right,x);
	return node;
	node->height=max(height(node->left),height(node->right))+1;
	if((bal(node)>1)&&(x<node->left->data))return rr(node);
	if((bal(node)<-1)&&(x>node->right->data))return ll(node);
	if((bal(node)>1)&&(x>node->left->data))
	{
		node=ll(node->left);
		return rr(node);
	}
	if((bal(node)<-1)&&(x<node->right->data))
	{
		node=rr(node->right);
		return ll(node);
	}
}
void preorder(struct node *root) 
{ 
    if(root != NULL) 
    {  
        preorder(root->left);
        printf("%d ", root->data); 
        preorder(root->right); 
    } 
} 
int main()
{
	while(1)
	{
		int x;
		printf("enter your choice\n1 for insert\n2 for show\n3 for exit\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:{
				int num;
			        printf("enter data to be inserted\n");
			        scanf("%d",&num);
			        root=insert(root,num);break;}
			case 2:printf("data are::\n");preorder(root);break;
			case 3:exit(0);
			default:printf("Wrong choice\n");break;
		}
	}
}
