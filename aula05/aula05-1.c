#include <stdio.h>
//questao 02
main(){
    int n=1, p=0,soma=0;
    while(n<=50){
        if(p%2==0){
            printf("%d >>> %d\n",n,p);
            soma=soma+p;
            n++;
        }
        p++;
    }
    printf("A soma de todos os numeros = %d\n",soma);
}
