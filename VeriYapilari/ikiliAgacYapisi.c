#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node * left;
struct node * right;
};

struct note * kokdugumolustur(int veri)
{

struct node * root=(struct note *)malloc(sizeof(struct node));
root->data=veri;
root->left=NULL;
root->right=NULL;
return root;
};

struct node * elemanekle(struct node * root, int veri)
{
    if(root==NULL){
        root=kokdugumolustur(veri);
    }
    else
    {
        if(veri<root->data){

            root->left=elemanekle(root->left,veri);
        }else{
            root->right=elemanekle(root->right,veri);
        }
    }
return root;

};

void preorder(struct node * root) // kök baþta
{
    if(root!=NULL)
    {
    printf("%d   ",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}
void inorder(struct node * root) // kök ortada
{
    if(root!=NULL)
    {
    inorder(root->left);
    printf("%d   ",root->data);
    inorder(root->right);
    }
}
void postorder(struct node * root) // kök ortada
{
    if(root!=NULL)
    {
    postorder(root->left);
    postorder(root->right);
    printf("%d   ",root->data);

    }
}



int main()
{
    struct node * eleman =NULL;

    int sayi,i=0;
srand(time(0));
    while(i<11)
    {
        printf(" Sayi girin : \n"); scanf("%d",&sayi);
        eleman=  elemanekle(eleman,sayi);
        i++;
    }

   printf("\npreOrder  :"); preorder(eleman);
    printf("\ninOrder   :"); inorder(eleman);
    printf("\npostOrder :"); postorder(eleman);


    return 0;
}
