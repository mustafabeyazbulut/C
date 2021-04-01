#include <stdio.h>
#include <stdlib.h>

int main()
{

    int not3,i=0,top=0;
    float ort=0;

    /*while(not3!=-1){
        printf("Lutfen Sayi Giriniz:");
        scanf("%d",&not3);
        if(not3==-1) break;
        top+=not3;
        i++;
    }
    ort=top/(float)i;
    printf("\nORT=%.2f",ort);*/

    do{
        printf("Lutfen Sayi Giriniz:");
        scanf("%d",&not3);
        if(not3==-1) break;
        top+=not3;
        i++;
    }while(not3!=-1);

    ort=top/(float)i;
    printf("\nORT=%.2f",ort);

    return 0;
}
