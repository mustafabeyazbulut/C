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



    struct dugum *dugum;
    struct dugum *d;
    struct dugum *geri;

    d=heap->kok;
    while(d!=NULL){
        geri=d;
        if(key < d->anahtar) d=d->sol_link;
        else if(key > d->anahtar) d= d->sag_link;
        else return;
    }


    struct dugum *temp = (struct dugum*)malloc(sizeof(struct dugum));
    if(temp==NULL){
        printf("Heapte gerekli yer ayrilamadi... exit ...\n");
        exit(1);
    }
    temp->anahtar = key;
    temp->sol_link=temp->sag_link=NULL;

    dugum=temp;


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
    struct heap* heap;
    heapAlanOlustur(&heap);
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
    ekle(heap,100);


    preorder(heap);



    return (EXIT_SUCCESS);
}
