#include <stdio.h>

#define SIZE 100

void enqueue();
void dequeue();
void show();

int inp_arr[SIZE];
int Rear = -1;
int Front = -1;

main(){
    int ch;
    while(1){
        printf("Menu, 1 enqueue, 2 dequeue, 3 display queue, 4 exit, elige una op");
        scanf("&d",&ch);
        switch(ch){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3: 
                show();
                break;
            case 4:
                exit(0);
            default:
                printf("Opcion incorrecta");
        }
    }

}