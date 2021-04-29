#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu();
int AsalSayi(int,int);
int main()
{

 for(;;)
    menu();


    return 0;
}

void menu(){
    int islem,sayi1,sayi2,sonuc;
    printf("1- Asal Sayi Bulma\n");
    printf("2- Sayi Carpimi\n");
    printf("3- Kuvvet Bulma\n");
    printf("4- Sayi Toplami\n");
    printf("Lutfen Bir islem seciniz :");
    scanf("%d",&islem);
    switch(islem){
                case 1:
                    printf("\nAsal Kontrolu Yapilacak Sayi :");
                    scanf("%d",&sayi1);
                    sonuc=AsalSayi(sayi1,sayi1/2);
                    if(sonuc==0) printf("%d asaldir. \n",sayi1 );
                    else printf("%d asal degildir. \n\n",sayi1 );
                    sayi1=0;
                    sayi2=0;
                    sonuc=0;
                    break;
                case 2:
                    sayi1=rastgele(1,20);
                    sayi2=rastgele(2,100);
                    sonuc=SayiCarpimi(sayi1,sayi2);
                    printf("\n%d x %d = %d \n\n",sayi1,sayi2,sonuc);
                    break;
                case 3:
                    printf("\nHangi Sayinin Ussu Alinacak :");
                    scanf("%d",&sayi1);
                    printf("Ussu Kac Olacak :");
                    scanf("%d",&sayi2);
                    sonuc= KuvvetBulma(sayi1,sayi2);
                    printf("%d ussu %d = %d \n\n",sayi1,sayi2,sonuc);
                    break;
                case 4:
                    sayi1=rastgele(1,100);
                    sayi2=rastgele(100,200);
                    sonuc=SayiToplami(sayi1,sayi2);
                    printf("\n%d + %d = %d \n\n",sayi1,sayi2,sonuc);
                    break;
                case -1: exit(0);
                default:  break;
            }
}
int AsalSayi(int sayi,int bolen){
    if(bolen==1 ) return 0;
    if(sayi<=1 || sayi%bolen==0 ) return 1;
    else AsalSayi(sayi,bolen-1);
}
int SayiCarpimi(int sayi1,int sayi2){
    int toplam=0;
    if(sayi1==1) return sayi2;
    toplam=sayi2+SayiCarpimi(sayi1-1,sayi2);
    return toplam;
}
int KuvvetBulma(int x, int us){
    if(us==0) return 1;
    if(us==1) return x;
    if(us%2==0) return KuvvetBulma(x*x,us/2);
    else return x*KuvvetBulma(x*x,us/2);

}
int SayiToplami(int sayi1,int sayi2){

    if(sayi1!=0 && sayi2!=0) return 2+SayiToplami(sayi1-1,sayi2-1);
    else if(sayi1!=0 && sayi2==0 ) return 1+SayiToplami(sayi1-1,sayi2);
    else if(sayi1==0 && sayi2!=0 ) return 1+SayiToplami(sayi1,sayi2-1);
}
int rastgele(int a,int b){/*srand(time(NULL));*/ return a+rand() % (b-a+1) ;}
