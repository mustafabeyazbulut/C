#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main()
{
    int input,r;

    printf("Tahmin gir :");
    r=rastgele();
    for(;;){
        scanf("%d",&input);
        if(r<input) printf("Daha Kucuk Tahmin Yap\n");
        if(r>input) printf("Daha Buyuk Tahmin Yap\n");

        if (r==input)r=Tebrikler();
    }

    return 0;
}
int Tebrikler(){
    int i;
    printf("Tebrikler Bildiniz.\n");
    for(;;){
        printf("Devam (1) Cikis(-1) :");
        scanf("%d",&i);
        switch(i){
                case 1: printf("Tahmin gir :"); return rastgele(); break;
                case -1: exit(0);
                default:  break;
            }
    }
}
int rastgele(){srand(time(NULL)); return rand() % 100 + 1;}
