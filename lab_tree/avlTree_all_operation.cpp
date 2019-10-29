#include<bits/stdc++.h> 
using namespace std; 
  
// An AVL tree node  
class Node  
{  
    public: 
    int key;  
    Node *left;  
    Node *right;  
    int height;  
};  

Node* search(Node *root,int data)                                //function overloading
             {
                if(root==NULL) return NULL;
                if(data<root->key) return(search(root->left,data));
                else if(data>root->key) return(search(root->right,data));
                else return root;
             }
  
// A utility function to get maximum 
// of two integers  
int max(int a, int b);  
  
// A utility function to get height  
// of the tree  
int height(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  
  
// A utility function to get maximum 
// of two integers  
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
  
/* Helper function that allocates a  
   new node with the given key and  
   NULL left and right pointers. */
Node* newNode(int key)  
{  
    Node* node = new Node(); 
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; // new node is initially 
                      // added at leaf  
    return(node);  
}  
  
// A utility function to right 
// rotate subtree rooted with y  
// See the diagram given above.  
Node *rightRotate(Node *y)  
{  
    Node *x = y->left;  
    Node *T2 = x->right;  
  
    // Perform rotation  
    x->right = y;  
    y->left = T2;  
  
    // Update heights  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
    x->height = max(height(x->left),  
                    height(x->right)) + 1;  
  
    // Return new root  
    return x;  
}  
  
// A utility function to left  
// rotate subtree rooted with x  
// See the diagram given above.  
Node *leftRotate(Node *x)  
{  
    Node *y = x->right;  
    Node *T2 = y->left;  
  
    // Perform rotation  
    y->left = x;  
    x->right = T2;  
  
    // Update heights  
    x->height = max(height(x->left),  
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
    // Return new root  
    return y;  
}  
  
// Get Balance factor of node N  
int getBalance(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->left) -  
           height(N->right);  
}  
  
Node* insert(Node* node, int key)  
{  
    /* 1. Perform the normal BST rotation */
    if (node == NULL)  
        return(newNode(key));  
  
    if (key < node->key)  
        node->left = insert(node->left, key);  
    else if (key > node->key)  
        node->right = insert(node->right, key);  
    else // Equal keys not allowed  
        return node;  
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),  
                           height(node->right));  
  
    /* 3. Get the balance factor of this  
        ancestor node to check whether  
        this node became unbalanced */
    int balance = getBalance(node);  
  
    // If this node becomes unbalanced, 
    // then there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 && key < node->left->key)  
        return rightRotate(node);  
  
    // Right Right Case  
    if (balance < -1 && key > node->right->key)  
        return leftRotate(node);  
  
    // Left Right Case  
    if (balance > 1 && key > node->left->key)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && key < node->right->key)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    /* return the (unchanged) node pointer */
    return node;  
}  
  
/* Given a non-empty binary search tree,  
return the node with minimum key value  
found in that tree. Note that the entire  
tree does not need to be searched. */
Node * minNode(Node* node)  
{  
    Node* current = node;  
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
}  
 int minimum(Node *root)
             {
                Node *temp=root;
                if(root==NULL) {cout<<"Tree is Empty\n"; return -1;}
                while(temp->left!=NULL)
                    temp=temp->left;
                return temp->key;
             }

 int maximum(Node *root)                     //Function overloading
             {
                Node *temp=root;
                if(root==NULL) {cout<<"Tree is Empty\n"; return -1;}
                while(temp->right!=NULL)
                    temp=temp->right;

                return temp->key;
             }
  
 
Node* deleteNode(Node* root, int key)  
{  
      
    // STEP 1: PERFORM STANDARD BST DELETE  
    if (root == NULL)  
        return root;  
  
    if ( key < root->key )  
        root->left = deleteNode(root->left, key);  
  
    else if( key > root->key )  
        root->right = deleteNode(root->right, key);  
  
  
    else
    {  
        // node with only one child or no child  
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            Node *temp = root->left ?  
                         root->left :  
                         root->right;  
  
            // No child case  
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else // One child case  
            *root = *temp; // Copy the contents of  
                           // the non-empty child  
            free(temp);  
        }  
        else
        {  
            // node with two children: Get the inorder  
            // successor (smallest in the right subtree)  
            Node* temp = minNode(root->right);  
  
            // Copy the inorder successor's  
            // data to this node  
            root->key = temp->key;  
  
            // Delete the inorder successor  
            root->right = deleteNode(root->right,  
                                     temp->key);  
        }  
    }  
  
    // If the tree had only one node 
    // then return  
    if (root == NULL)  
    return root;  
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE  
    root->height = 1 + max(height(root->left),  
                           height(root->right));  
  
    int balance = getBalance(root);  
  
    // Left Left Case  
    if (balance > 1 &&  
        getBalance(root->left) >= 0)  
        return rightRotate(root);  
  
    // Left Right Case  
    if (balance > 1 &&  
        getBalance(root->left) < 0)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 &&  
        getBalance(root->right) <= 0)  
        return leftRotate(root);  
  
    // Right Left Case  
    if (balance < -1 &&  
        getBalance(root->right) > 0)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
}  

void preOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        cout << root->key << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
    //else cout<<"tree is Empty\n";
}
void findPreSuc(int key,Node *root)
             {
                 Node *pre=NULL,*suc=NULL;
                 void findPreSucx(Node *r,Node*&,Node*&,int);
                 findPreSucx(root,pre,suc,key);
                 if(pre)
                 cout<<"Predecessor = "<<pre->key<<endl;
                 else
                  cout<<"Predecessor not exist\n";
                   if(suc)
                 cout<<"Successor = "<<suc->key<<endl;
                 else
                  cout<<"Successor not exist\n";
             }

void findPreSucx(Node* root, Node*& pre, Node*& suc, int key) 
{ 
    if (root == NULL)  return ;  
    if (root->key == key)      // If key is present at root
    { 
        // the maximum value in left subtree is predecessor 
        if (root->left != NULL) 
        { 
            Node* tmp = root->left; 
            while (tmp->right) 
                tmp = tmp->right; 
            pre = tmp ; 
        } 
  
        // the minimum value in right subtree is successor 
        if (root->right != NULL) 
        { 
            Node* tmp = root->right ; 
            while (tmp->left) 
                tmp = tmp->left ; 
            suc = tmp ; 
        } 
        return ; 
    } 
  
    // If key is smaller than root's key, go to left subtree 
    if (root->key > key) 
    { 
        suc = root ; 
        findPreSucx(root->left, pre, suc, key) ; 
    } 
    else 
    { 
        pre = root ; 
        findPreSucx(root->right, pre, suc, key) ; 
    } 
}   

int main()
{    int q,temp;
    Node* root=NULL;
    cout<<"Enter to perform\n1.Insert\n2.Display\n3.Search\n4.Maximum Element\n5.Minimum Element\n6.Successor and Predecessor\n8.Delete\n0.Exit\n";
    cin>>q;
    while(q)
    {
        switch(q)
        {
            case 1: cout<<"Enter key to insert : ";
                     cin>>temp;
                   root=insert(root,temp);
                     break;
            case 2:preOrder(root);
                     cout<<"\n";
                     break;
            case 3:cout<<"Enter element to search  :  ";
                   cin>>temp;
                    if(search(root,temp)!=NULL) cout<<"Match Found\n";
                    else cout<<"Match not found\n";
                    break;
            case 4: temp=maximum(root);
                    if(temp!=-1) cout<<"Maximum element is "<<temp<<"\n";
                    break;
            case 5: temp=minimum(root);
                    if(temp!=-1) cout<<"Minimum element is "<<temp<<"\n";
                    break;
            case 6:cout<<"Enter element :  ";
                   cin>>temp;
                    findPreSuc(temp,root);break;
            case 8: cout<<"Enter element to delete : ";
                    cin>>temp;
                   root=deleteNode(root,temp);
                    preOrder(root);
                    break;
        }
        cout<<"Enter to perform\n1.Insert\n2.Display\n3.Search\n4.Maximum Element\n5.Minimum Element\n6.Successor and Predecessor\n8.Delete\n0.Exit\n";
        cin>>q;
    }

}
