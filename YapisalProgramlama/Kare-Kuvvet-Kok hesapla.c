#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float Kok_Carp();
int Kare_Hesapla(int);
int Kuvvet(int, int );
int main()
{

    int s;
    printf("Karesi alinacak sayiyi giriniz :");
    scanf("%d",&s);
    printf("Sonuc=%d\n",Kare_Hesapla(s));

    int x,y;
    printf("x'i giriniz :");
    scanf("%d",&x);
    printf("y'i giriniz :");
    scanf("%d",&y);
    printf("x^^y :%d \n",Kuvvet(x,y));

    printf("Sonuc=%.2f\n",Kok_Carp());

    return 0;
}
int Kare_Hesapla(int x){
    return x*x;
}

int Kuvvet(int x, int y){
    int s=x;
    if(y==0) return 1;
    if(y==1||x==0) return x;
    else for(int i=0;i<y-1;i++) x=x*s;

    return x;

}
float Kok_Carp(){
    float a,sonuc;
    printf("Sayi gir=");
    scanf("%f",&a);
    sonuc=sqrt(a);
    return sonuc*a;
}

