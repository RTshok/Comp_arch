#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node 
{
	int key;
	struct Node *left,*right;
}Node;
/* Function that creates new BST node */
struct Node * newNode(int);
struct Node * insert (struct Node * , int);
void inorder ( struct Node * , int **);
int * tree_sort(int* ,int );