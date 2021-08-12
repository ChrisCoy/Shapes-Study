#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int tam;

char screen [800][800];

void clear (){
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            screen [i][j] = ' ';
        }
    }
}

void printCircleOnScreen(){
    for (int y = 0; y < tam; y+=3){
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
    for (int i = 0; i <= 360; i+=1){
        x = ( cos(i)* radius ) + ((tam)/2);
        y = ( sin(i)* radius ) + ((tam)/2);
        screen [x][y] = '#';
    }
}

void circlePythagorasShades(int raio){
    if (raio <= tam){
        for (int y = -tam; y < tam; y++){
            for (int x = -tam; x < tam; x++){

                if ((x*x)+(y*y) < (raio*raio)/5){
                    screen [x+((tam-1)/2)][y+((tam-1)/2)] = '-';
                }
                else if ((x*x)+(y*y) < (raio*raio)/3){
                    screen [x+((tam-1)/2)][y+((tam-1)/2)] = '$';
                }
                else if ((x*x)+(y*y) < (raio*raio)/2){
                    screen [x+((tam-1)/2)][y+((tam-1)/2)] = '@';
                }
                else if ((x*x)+(y*y) < (raio*raio)){
                    screen [x+((tam-1)/2)][y+((tam-1)/2)] = '#';
                }
            }
        }
    }
}

int main(){
    int radius;
    char cmd[99];
    printf("Radius: ");
    scanf("%d",&radius);
    tam = radius*2;
    clear();
    circlePythagoras(radius);
    printCircleOnScreen();

    printf("\n\n\n");

    clear();
    circlePoints(3, radius);
    printCircleOnScreen();

    printf("\n\n\n");
    clear();
    circlePythagorasShades(radius);
    printCircleOnScreen();

    //scanf(" %[^\n]s",&cmd);
    //system (cmd);
    return main();
}
