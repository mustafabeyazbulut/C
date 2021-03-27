#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*printf("C ile Programlama \n");
    printf("Hafta 1 \n");
    printf("\"\\n Yeni Satira Gecer\"");*/

    int grade=65;
    char *sonuc[16];
    *sonuc=(grade>=60)?"Gecti":"Kaldi";
    printf("%s",*sonuc);

    /*int a = 10, b = 20, c;
    c = (a < b) ? a : b;
    printf("%d\n", c);

    a = 1; b = 2;
    int ans;
    ans = (a == 1 ? (b == 2 ? 3 : 5) : 0);
    printf ("%d\n", ans);*/

    /*int a=3, b=4;
    if(a==4)
        if(b==4)
        printf("XX");*/

    /*int not=85;
    (not<90?(not<80?(not<70?printf("\n F"):printf("\n C")):printf("\n B") ):printf("\n A"));*/

    int yas=63,kb=156;
    ((yas>65&&kb>=125)||(yas<=65&&kb>140)?printf("\nhasta"):printf("\nsaglikli"));

    return 0;
}
