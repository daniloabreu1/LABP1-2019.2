#include <stdio.h>
main(){
    int n;
    printf("digite um numero ");
    scanf("%d",&n);
    if(n%2==0){
        printf("Numero par\n");
    }else{
        printf("Numero impar\n");
    }
    //n%2==0?printf("Numero par\n"):printf("Numero impar\n");
}
