#include <stdio.h> 
#include <stdlib.h> 
struct node 
{ 
	int data; 
	struct node* left, *right; 
}*root=NULL; 
int a[100],n=0;
struct node* newNode(int data) 
{ 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return(node); 
} 
struct node*insert(struct node*node,int x)
{
	if(node==NULL)
	{
		return newNode(x);
	}
	if(node->data<x)node->left=insert(node->left,x);
	else if(node->data>x)node->right=insert(node->right,x);
	return node;
}
void atlevel(struct node* root, int level);
int height(struct node* node); 
struct node* newNode(int data); 
void levelorder(struct node* root) 
{ 
	int h = height(root);  
	for (int i=1; i<=h; i++) 
		atlevel(root, i); 
} 
void atlevel(struct node* root, int level) 
{ 
	if (root == NULL) 
		return; 
	if (level == 1){ 
		a[n]=root->data;
		n++;
		} 
	else if (level > 1) 
	{ 
		atlevel(root->left, level-1); 
		atlevel(root->right, level-1); 
	} 
} 
int height(struct node* node) 
{ 
	if (node==NULL) 
		return 0; 
	else
	{ 
		int lh = height(node->left); 
		int rh = height(node->right); 
		if (lh > rh) return(lh+1); 
		else return(rh+1); 
	} 
} 
void printreverse()
{
	printf("\n");
	printf("The reverse order traversal of the BST is: ");
	for(int i=n-1;i>=0;i--)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
}
int main() 
{ 
	int  num;
	printf("Enter the number of keys to be inserted:");
	scanf("%d",&num);
	printf("Enter the keys to be inserted in order:\n");
	for(int i=0;i<num;i++)
	{
		int key;
		scanf("%d",&key);
		root=insert(root,key);
	}
	levelorder(root);
	printreverse(); 
	return 0; 
} 
