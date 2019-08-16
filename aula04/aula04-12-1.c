#include <stdio.h>
main(){
    int ponto_x, ponto_y;
    printf("DIGITE A COORDENADA X >> ");
    scanf("%d",&ponto_x);
    printf("DIGITE A COORDENADA Y >> ");
    scanf("%d",&ponto_y);
    if(ponto_x > 0){
        if(ponto_y>0){
            printf("ESTA NO PRIMEIRO QUADRANTE\n");
        }else{
            if(ponto_y==0){
                printf("ESTA NO EIXO X\n");
            }else{
                printf("ESTA NO QUARTO QUADRANTE\n");
            }
        }
    }else{
        if(ponto_x<0){
            if(ponto_y>0){
                    printf("ESTA NO SEGUNDO QUADRANTE\n");
            }else{
                if(ponto_y==0){
                        printf("ESTA NO EIXO X\n");
                }else{
                    printf("ESTA NO TERCEIRO QUADRANTE\n");
                }
            }
        }else{
            if(ponto_y==0){
                    printf("ESTA NA ORIGEM\n");
            }else{
                printf("ESTA NO EIXO Y\n");
            }
        }
    }
    system("pause");
}
