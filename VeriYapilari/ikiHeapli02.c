#include <stdio.h>
#include <stdlib.h>


struct dugum {
    int anahtar;
    struct dugum *parent, *sol_link, *sag_link;
};
struct heap{
    struct dugum *kok;
    struct dugum *en_son_eklenen;
};

void heapAlanOlustur(struct heap** heaps){

    *heaps=(struct heap*)malloc(sizeof(struct heap));
    if(*heaps==NULL){
        printf("heapte gerekli yer ayrilamadi... exit ...\n");
        exit(1);
    }


    (*heaps)->kok=NULL;
}
void remove_largest(struct heap * root)
{
	if (root == NULL) return 0;
	struct heap *temp = root, *prev = NULL;
	while (temp->kok->sag_link != NULL) {
		prev = temp;
		temp = temp->kok->sag_link;
	}

	if (prev == NULL) //didn't have a right child
		root = root->kok->sol_link; //therefore delete root and move the pointer to left child
	else prev->kok->sag_link = NULL; //delete the largest
	return 1;
}
void delete_max(struct heap *root){
    printf("addasd");
}

void heap_insert(struct heap *heap,int key){

    heap->en_son_eklenen = heap->kok;
    while(heap->en_son_eklenen !=  NULL){
        heap->kok->parent  =  heap->en_son_eklenen;
        if     (key < heap->en_son_eklenen->anahtar)
            heap->en_son_eklenen = heap->en_son_eklenen->sol_link;
        else if(key > heap->en_son_eklenen->anahtar)
            heap->en_son_eklenen = heap->en_son_eklenen->sag_link;
        else return;
    }

    struct dugum *dugum = (struct dugum*)malloc(sizeof(struct dugum));
    if(dugum==NULL){printf("Heapte gerekli yer ayrilamadi... exit ...\n"); exit(1); }
    dugum->anahtar  = key;
    dugum->sol_link = dugum->sag_link = NULL;

    if(heap->kok == NULL){  heap->kok = dugum; return;  }

    if   (key < heap->kok->parent->anahtar) heap->kok->parent->sol_link = dugum;
    else                                    heap->kok->parent->sag_link = dugum;

}
void heap_insert2(struct heap *heap,int key){

    struct dugum *parent;


    heap->en_son_eklenen=heap->kok;
    while(heap->en_son_eklenen!=NULL){
        parent=heap->en_son_eklenen;
        if(key < heap->en_son_eklenen->anahtar) heap->en_son_eklenen=heap->en_son_eklenen->sol_link;
        else if(key > heap->en_son_eklenen->anahtar) heap->en_son_eklenen= heap->en_son_eklenen->sag_link;
        else return;
    }


    struct dugum *dugum = (struct dugum*)malloc(sizeof(struct dugum));
    if(dugum==NULL){
        printf("Heapte gerekli yer ayrilamadi... exit ...\n");
        exit(1);
    }
    dugum->anahtar = key;
    dugum->sol_link=dugum->sag_link=NULL;

    if(heap->kok==NULL){
        heap->kok = dugum;
        return;
    }

    if(key < parent->anahtar) parent->sol_link = dugum;
    else parent->sag_link = dugum;

}


void print_heap(struct heap *heap){
    int i;
    for(i=0; i<11; i++) printf("%4d",heap->kok[i].anahtar);
    printf("\n");

}
void inorder_yardimci(struct dugum *kok){

    if(kok==NULL) return;
    inorder_yardimci(kok->sol_link);
    printf("%4d ",kok->anahtar);
    inorder_yardimci(kok->sag_link);

}
void inorder(struct heap *heap){
    if(heap==NULL) return;
    inorder_yardimci(heap->kok);
    printf("\n");
}

void preorder_yardimci(struct dugum *kok){

    if(kok==NULL) return;
    printf("%4d ",kok->anahtar);
    preorder_yardimci(kok->sol_link);
    preorder_yardimci(kok->sag_link);

}
void preorder(struct heap *heap){
    if(heap==NULL) return;
    preorder_yardimci(heap->kok);
    printf("\n");
}


int main()
{
    struct heap* heap;

    heapAlanOlustur(&heap);

    heap_insert(heap,50);
    heap_insert(heap,20);
    heap_insert(heap,10);
    heap_insert(heap,35);
    heap_insert(heap,30);
    heap_insert(heap,40);
    heap_insert(heap,70);
    heap_insert(heap,60);
    heap_insert(heap,80);
    heap_insert(heap,90);
    heap_insert(heap,25);
    heap_insert(heap,26);
heap_insert(heap,65);
heap_insert(heap,100);
    preorder(heap);

    remove_largest(heap);
    preorder(heap);
    return (EXIT_SUCCESS);
}
