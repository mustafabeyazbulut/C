#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct node
{
    int data;
    struct node* left;
    struct node* right;
};



int isBST(struct node* root)
{
    static struct node *prev = NULL;

    if (root)
    {
        if (!isBST(root->left))                                return 0;

        // Allows only distinct valued nodes
        if (prev != NULL && root->data <= prev->data)          return 0;

        prev = root;

        return isBST(root->right);
    }

    return 1;
}
int halfcount(struct node* root){
   if (root == NULL)
        return 0;
   int result = 0;
   if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right ==NULL))
   {
       result++;
   }


   result += (halfcount(root->left) + halfcount(root->right));
   return result;
}

int tek_cocuklu_dugum_sayisi(struct dugum *kok){
    if (kok == NULL) return 0;
    int tekCocukluDugumSayisi = 0;
    if ((kok-> sol_link == NULL && kok-> sag_link != NULL) || (kok-> sol_link != NULL && kok-> sag_link ==NULL))
        tekCocukluDugumSayisi ++;
    tekCocukluDugumSayisi += (tek_cocuklu_dugum_sayisi (kok-> sol_link) + tek_cocuklu_dugum_sayisi (kok-> sag_link));
    return tekCocukluDugumSayisi;
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


int main()
{
   struct node *root = newNode(10);
   root->left = newNode(20);
   root->right = newNode(30);
   root->left->left = newNode(40);
   root->left->right = newNode(50);
   root->left->left->right = newNode(60);
   root->left->right->right = newNode(70);


  /*struct node *root = newNode(2);
  root->left        = newNode(3);
  root->right       = newNode(5);
  root->left->left  = newNode(7);
  root->right->left  = newNode(8);
  root->right->right  = newNode(6);*/

  //root->left->right = newNode(3);
  //root->left->left->left = newNode(0);

  printf("%d",halfcount(root)) ;
  getchar();
  return 0;
}
