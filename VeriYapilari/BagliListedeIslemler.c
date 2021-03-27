#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node * next;
};

struct node * start = NULL;
struct node * temp=NULL;

void basaekle(int veri){
    struct node * eleman;
    eleman= (struct node *)malloc(sizeof(struct node));
    eleman->data=veri;
    eleman->next= start;
    start= eleman;
}
void sonaekle(int veri){
    struct node * eleman;
    eleman= (struct node *)malloc(sizeof(struct node));
    eleman->data=veri;
    eleman->next= NULL;

    if(start==NULL){
        start=eleman;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=eleman;

    }
}
void arayaekle(int n,int veri){
    struct node * eleman;
    eleman= (struct node *)malloc(sizeof(struct node));
    eleman->data=veri;

    temp=start;
    while(temp->next->data !=n){
        temp=temp->next;
    }

    struct node * temp2;
    temp2= (struct node *)malloc(sizeof(struct node));

    temp2=temp->next;
    temp->next=eleman;
    eleman->next=temp2;

}
void yazdir(){
    system("cls");
    if(start!=NULL){
temp=start;
while(temp->next!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
}
printf("%d ",temp->data); // son düðümü yazdýrmak için
    }else printf("Eleman Yok!!");
}

void bastansil(){

    if(start!=NULL){
    temp=start->next;
    free(start);
    start=temp;
    }
    else
        free(start);


}
void sondansil(){
    if(start->next!=NULL){
        temp=start;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
    else
        bastansil();

}

int main()
{
    int sayi,dongu=0,secim,n;
    while(dongu!=10)
        {
        printf("1- Basa eleman ekle \n");
        printf("2- Sona eleman ekle \n");
        printf("3- Araya eleman ekle \n");
        printf("4- Ilk elemani sil \n");
        printf("5- Son elemani sil \n");
        printf("Seciminizi yapiniz :");
        scanf("%d",&secim);

                switch(secim)
                {
                case 1:
                    printf("Basa eklenecek sayi degeri :");
                    scanf("%d",&sayi);
                    basaekle(sayi);
                    yazdir();
                    printf("\n");
                    break;
                case 2:
                    printf("Sona eklenecek sayi degeri :");
                    scanf("%d",&sayi);
                    sonaekle(sayi);
                    yazdir();
                    printf("\n");
                    break;
                case 3:
                    printf("Hangi sayidan once eklenecek :");scanf("%d",&n);
                    printf("Araya eklenecek sayi degeri :");scanf("%d",&sayi);
                    arayaekle(n,sayi);
                    yazdir();
                    printf("\n");
                    break;
                case 4:
                    bastansil();
                    yazdir();
                    printf("\n");
                    break;
                case 5:
                    sondansil();
                    yazdir();
                    printf("\n");
                    break;
                }
        dongu++;
        }

    return 0;
}
