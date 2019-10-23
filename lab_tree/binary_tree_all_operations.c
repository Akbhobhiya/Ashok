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
	struct node *temp=(struct node*)malloc(sizeof(struct node));
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
struct node*predecessor(struct node*node1)
{
	struct node*curr;
	node1=node1->left;
	while(node1)
	{
		curr=node1;
		node1=node1->right;
	}
	return curr;
}
int min(struct node*node1)
{
	struct node*curr;
	while(node1)
	{
		curr=node1;
		node1=node1->left;
	}
	return curr->data;
}
int max(struct node*node1)
{
	struct node*curr;
	while(node1)
	{
		curr=node1;
		node1=node1->right;
	}
	return curr->data;
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
struct node*search(struct node*node1,int key)
{
	struct node*temp;
	if(node1==NULL)
	{
		printf("element is not present in the tree\n");
		return node1;
	}
	if(key<node1->data)node1->left=search(node1->left,key);
	else if(key>node1->data)node1->right=search(node1->right,key);
	else
	{
		if(node1->data==key)
	    {
		    printf("node is present in the tree\n");
		    return node1;
	    }
	    else if((node1->left==NULL)&&(node1->right==NULL)&&(node1->data!=key))
	    {
	    	printf("element is not present in the tree\n");
	    	return node1;
	    }
	}
}
int main()
{
	int choice;
	while(1)
	{
		int num,del;
		printf("\nBST TREE MENU::\n");
		printf("1 for build the tree\n2 for insert a node\n3 for delete a node\n4 for search a element in tree\n");
		printf("5 for minmum value node\n6 for maximum value node\n7 for successor\n8 for predecessor\n");
		printf("9 for inorder traversal\n10 for exit the prog\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				int n;
				printf("how node you want in tree\n");
				scanf("%d",&n);
				for(int i=0;i<n;i++)
				{
					int num;
					scanf("%d",&num);
					root=insert(root,num);
				}
				break;
			}
			case 2:printf("enter a number for insert\n");scanf("%d",&num);root=insert(root,num);break;
			case 3:printf("enter key to delete\n");scanf("%d",&del);root=delete(root,del);break;
			case 4:
			{
				int x;
				printf("enter a value for searching\n");
				scanf("%d",&x);
				struct node*temp=search(root,x);
				break;
			}
			case 5:printf("minimum value node is %d\n",min(root));break;
			case 6:printf("maximum value node is %d\n", max(root));break;
			case 7:printf("successor value of tree is %d\n",successor(root)->data);break;
			case 8:printf("predecessor value of the tree is %d\n",predecessor(root)->data);break;
			case 9:printf("data in the tree::\n");inorder(root);break;
			case 10:exit(0);
			default:printf("WRONG CHOICE!! CHOOSE BETWEEN (1-10)\n");break;
		}
	}
}
