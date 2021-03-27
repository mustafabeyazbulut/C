#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int isBSTUtil(struct node* node, int min, int max);

/* Returns true if the given tree is a binary search tree
 (efficient version). */
/*int isBST(struct node* node)
{
  return(isBSTUtil(node, INT_MIN, INT_MAX));
}*/

int isBST(struct node* node)
{
  if (node == NULL) return 1;
  if (node->left != NULL && node->left->data > node->data || node->right != NULL && node->right->data < node->data )  return 0;
  if (!isBST(node->left) || !isBST(node->right)) return 0;
  return 1;
}

struct node* newNode(int data)
{
  struct node* node = (struct node*)
malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

/* Driver program to test above functions*/
int main()
{
  struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3);
  root->left->left->left = newNode(8);

  if(isBST(root))
    printf("Is BST");
  else
    printf("Not a BST");

  getchar();
  return 0;
}
