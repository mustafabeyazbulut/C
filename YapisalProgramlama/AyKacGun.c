#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    printf("cikis icin 0'i tuslayiniz\n");
    printf("Ay no gir :");
    for(;;){

        scanf("%d",&n);

        switch(n){
        case 0: exit(0);
        case 2: printf("%d.ay 28 gun icerir\n",n );printf("Ay no gir :"); break;
        case 4: case 6: case 9: case 11: printf("%d.ay 30 gun icerir\n" ,n);printf("Ay no gir :"); break;
        case 1: case 3: case 5:case 7:case 8: case 10: case 12: printf("%d.ay 31 gun icerir\n",n );printf("Ay no gir :"); break;
        default: printf("Hata, Tekrar gir:");
        }

    }


    return 0;
}


