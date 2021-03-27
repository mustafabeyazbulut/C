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

void heapAlanOlustur(struct heap** heap){

    *heap=(struct heap*)malloc(sizeof(struct heap));
    if(*heap==NULL){
        printf("heapte gerekli yer ayrilamadi... exit ...\n");
        exit(1);
    }


    (*heap)->kok=NULL;

}

void ekle(struct heap *heap,int key){
    struct dugum *geri;


    heap->en_son_eklenen=heap->kok;
    while(heap->en_son_eklenen!=NULL){
        geri=heap->en_son_eklenen;
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

    if(key < geri->anahtar) geri->sol_link = dugum;
    else geri->sag_link = dugum;

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
    struct heap* heap=(struct heap*)malloc(sizeof(struct heap));
    heap->kok=NULL;

    //heapAlanOlustur(&heap);

    ekle(heap,50);

    ekle(heap,20);

    ekle(heap,10);

    ekle(heap,35);

    ekle(heap,30);

    ekle(heap,40);

    ekle(heap,70);

    ekle(heap,60);

    ekle(heap,80);

    ekle(heap,90);
    ekle(heap,25);
    ekle(heap,100);
ekle(heap,95);
    preorder(heap);



    return (EXIT_SUCCESS);
}
