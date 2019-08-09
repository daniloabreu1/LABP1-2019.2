#include <stdio.h>
main(){
    float num;
    int i;
    printf("Digite um numero ");
    scanf("%f",&num);
    i=(int)num;
    printf("Parte inteira %d\n",i);
    printf("Parte fracionaria %.2f\n",num-i);
}
