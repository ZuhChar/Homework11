//
// mmult.c
// Author: Zachary Crimmel
// Date: May 13, 2022
//
// COSC 3750, Homework 11
//
// This is a simple program to calculate the matrix multiplication of two matrices.
//


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

int main(int argc, char *argv[]){
    if(argc >= 6){
        perror("Incorrect usage of mmult.c.: ");
        return 0;
    }
    char *mat1 = argv[1];

    printf("%s\n", mat1);

    // for(int i = 0; i < 5; i++){
    //     for(int j = 0; j < 10; j++){
    //         for(int k = 0; k < 6; k++){
    //             c[i][k] += a[i][j] * b[j][k];
    //         }
    //     }
    // }
}