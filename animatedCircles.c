#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int tam;

int mess=0;

char screen [800][800];

void clear (){
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            screen [i][j] = ' ';
        }
    }
}

void printCircleOnScreen(){
    for (int y = 0; y < tam; y+=2){
        for (int x = 0; x < tam; x++){
             printf("%c",screen [x][y]);
        }
        printf("\n");
    }

    printf("\n");

    for (int y = 0; y < tam; y+=1){
        for (int x = 0; x < tam; x++){
             printf("%c",screen [x][y]);
        }
        printf("\n");
    }
}

void circlePythagoras(int raio){
    if (raio <= tam){
        for (int y = -tam; y < tam; y++){
            for (int x = -tam; x < tam; x++){
                if ((x*x)+(y*y) < (raio*raio)){
                    screen [x+((tam-1)/2)][y+((tam-1)/2)] = '@';
                }
            }
        }
    }
}

void circlePoints(int gap, int radius){
    int x,y;
    for (int i = 1; i <= 360; i+=1){
        x = ( cos(i)* radius ) + ((tam-1)/2);
        y = ( sin(i)* radius ) + ((tam-1)/2);
        screen [x][y] = ' ';
    }
}

void animatedCircles(int raio){
    for (int i = 0; i <= raio; i++){
        clear();
        circlePythagoras(raio);
        circlePoints(0,i);
        printCircleOnScreen();
        system ("cls");
    }
}

int main(){

    if ( mess ==0 ){
        printf("if you cant see all of the content, resize your window\n");

        system ("pause");
        mess = 1;
    }
    tam = 40;
    animatedCircles(tam/2);
    return main();
}
