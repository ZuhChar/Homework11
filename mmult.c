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
    // Make sure right amount of arguments are passed
    if(argc > 5 || argc < 4){
        printf("Incorrect amount of arguments passed\n");
        return 0;
    }
    // Store names of matrices
    FILE *mat1 = fopen(argv[1], "r");
    FILE *mat2 = fopen(argv[2], "r");
    FILE *multMat = fopen(argv[3], "w");

    // Check to see if there is a thread count then store it
    if(argc == 5){
        char *threads = argv[4];
        int threadCount = atoi(threads);
    }

    int a[1000][1000];
    int b[1000][1000];
    in c[1000][1000];

    // for(int i = 0; i < 5; i++){
    //     for(int j = 0; j < 10; j++){
    //         for(int k = 0; k < 6; k++){
    //             c[i][k] += a[i][j] * b[j][k];
    //         }
    //     }
    // }
}