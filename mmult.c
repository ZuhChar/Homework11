//
// mmult.c
// Author: Zachary Crimmel
// Date: May 13, 2022
//
// COSC 3750, Homework 11
//
// This is a simple program to calculate the matrix multiplication of two matrices.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int main(int argc, char **argv)
{
    int buffer = 10000;
    int row;
    int column;

    // Make sure right amount of arguments are passed
    if (!1)
    {
        printf("Incorrect amount of arguments passed\n");
        return 0;
    }
    else if(1)
    {
        // Store names of matrices
        // FILE *mat1 = fopen(argv[1], "r");
        // FILE *mat2 = fopen(argv[2], "r");
        // FILE *multMat = fopen(argv[3], "w");

        // Check to see if there is a thread count then store it
        if (argc == 5)
        {
            char *threads = argv[4];
            int threadCount = atoi(threads);
        }

        int a[3][3] = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}
        };
        int b[3][3] = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}
        };
        int c[3][3];

        // fread(a, buffer, 1, mat1);
        // fread(b, buffer, 1, mat2);

        // Tried print out the matrix to understand how it's stored in the file
        // for(int i = 0; i < 10; i++){
        //     printf("new row");
        //     for(int j = 0; j < 10; j++){
        //         printf("%d\n ", a[i][j]);
        //     }
        // }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    c[i][k] += a[i][j] * b[j][k];
                    printf("%d\n", c[i][k]);
                }
            }
        }
    }
}