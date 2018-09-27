#include "tree_sort.h"

struct Node * insert (struct Node * node, int key){
    /* If the tree is empty, return a new Node */
    if (node == NULL) return newNode(key);
    /* Otherwise, recur down the tree */
    if (key <= node->key)
        node->left  = insert(node->left, key);
    else if (key >= node->key)
        node->right = insert(node->right, key);
    /* return the (unchanged) Node pointer */
    return node;

}

struct Node * newNode(int item)
{
	struct Node *temp = malloc(sizeof(*temp));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder ( struct Node * root, int **array)
{ /* Traverses the bst in inorder way */
    if ( root != NULL )
    {
        inorder ( root -> left, array) ;
        **array = root -> key ;
        ++*array;
        inorder ( root -> right, array) ;
    }
}

int * tree_sort(int* arr,int amount)
{
    struct Node *root = NULL;
 
    // Construct the BST
    root = insert(root, arr[0]);
    for (int i=1; i<amount; i++)
        insert(root, arr[i]);
 
    // Store inorder traversal of the BST
    inorder(root, &arr);
    free(root);
    return arr;
}
 