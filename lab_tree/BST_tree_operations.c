#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *right;
	struct node *left;
}*root=NULL;
struct node *newNode(int a)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node*));
	temp->data=a;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void inorder(struct node*root)
{
	if(root==NULL)return;
	inorder(root->left);
	printf("%d  ",root->data);
	inorder(root->right);
}
struct node* insert(struct node *root,int x)
{
	struct node* temp=newNode(x);
	if(root==NULL)
	{
		root=temp;return temp;
	}
	if(x<root->data)root->left=insert(root->left,x);
	else root->right=insert(root->right,x);
	return root;
}
struct node* successor(struct node*node1)
{
	struct node*curr;
	node1=node1->right;
	while(node1)
	{
		curr=node1;
		node1=node1->left;
	}
	return curr;
}
struct node* delete(struct node*root,int key)
{
	if(root==NULL)return root;
	if(key<root->data)root->left = delete(root->left, key);
	else if(key>root->data)root->right=delete(root->right,key);
	else
	{
		if(root->right==NULL)
		{
			struct node*temp=root->left;
			free(root);
			return temp;
		}
		else if(root->left==NULL)
		{
			struct node*temp=root->right;
			free(root);
			return temp;
		}
		else
		{
			struct node*temp=successor(root);
			root->data=temp->data;
			root->right=delete(root->right,temp->data);
		}
		return root;
	}
}
int main()
{
	int choice;
	while(1)
	{
		int num,del;
		printf("\n1 for insert\n2 for print\n3 for delete a element\n4 for exit\n5 for min\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter a number for insert\n");scanf("%d",&num);root=insert(root,num);break;
			case 2:inorder(root);break;
			case 3:printf("enter key to delete\n");scanf("%d",&del);root=delete(root,del);break;
			case 4:exit(0);
			case 5:printf("successor value of tree is %d\n",successor(root)->data);break;
			default:printf("wrong choice\n");break;
		}
	}
}
