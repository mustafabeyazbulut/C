// Checking if a binary tree is height balanced in C

#include <stdio.h>
#include <stdlib.h>
#define bool int

// Node creation
struct node {
  int item;
  struct node *left;
  struct node *right;
};

// Create a new node
struct node *newNode(int item) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->item = item;
  node->left = NULL;
  node->right = NULL;

  return (node);
}

// Check for height balance
int isHeightBalanced(struct node *root) {
        int getMax(int a, int b)
    {
         if(a >= b)
             return a;
         else
             return b;
    }
   int getHeight(struct node *root)
    {
        int leftHeight, rightHeight;
        if(root == NULL) return 0;
        leftHeight = getHeight(root->left);
        rightHeight = getHeight(root->right);

        return getMax(leftHeight, rightHeight) + 1;
    }

    int leftHeight, rightHeight;

   /* Empty Tree is always height balanced */
   if(root == NULL)
       return 1;

   /* Find the height of left and right subtree */
   leftHeight = getHeight(root->left);
   rightHeight = getHeight(root->right);

   /* If both sub trees are height balanced and the
   difference of height of left and right subtree is <= 1,
    then given tree is Height balanced else not */
   if(abs(leftHeight - rightHeight) <= 1 && isHeightBalanced(root->right) && isHeightBalanced(root->left))return 1;
   else return 0;


}


int yaprak_sayisi(struct node *kok){
    if(kok==NULL) return 0;
    if(kok->left==NULL && kok->right == NULL) return 1;
    else return yaprak_sayisi(kok->left)+yaprak_sayisi(kok->right);
}
int main() {



    struct node* root =  newNode(1);

    root->left = newNode(9);
    root->right = newNode(12);

    root->left->left = newNode(4);
    root->left->right = newNode(50);
    root->right->right = newNode(-7);

    root->left->left->left = newNode(18);
    root->left->left->right = newNode(9);
    root->right->right->right = newNode(-9);

/* struct node *root = newNode(1);
  root->left = newNode(2);
  root->left->left = newNode(4);
  root->left->left->left = newNode(5);


  root->left->right = newNode(4);
  root->left->right->right = newNode(4);
  root->left->right->right->right = newNode(4);
  root->left->right->right->right->right = newNode(5);

  root->right = newNode(3);
  root->right->right = newNode(8);
  root->right->right->right = newNode(7);*/


  //printf("gelen :%d \n",isHeightBalanced(root));
  if (isHeightBalanced(root))
    printf("The tree is balanced");
  else
    printf("The tree is not balanced");
}
