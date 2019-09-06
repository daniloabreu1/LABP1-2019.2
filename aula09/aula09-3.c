#include <stdio.h>
int imparPar(int n){
    if(n%2==0){
        return 1;
    }
    return 0;
}
main(){
    int num;
    printf("Digite um numero inteiro ");
    scanf("%d",&num);
    imparPar(num)?printf("Numero Par\n"):printf("Numero Impar\n");
}
