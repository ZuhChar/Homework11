//
// mmult.c
// Author: Zachary Crimmel
// Date: May 13, 2022
//
// COSC 3750, Homework 11
//
// This is a simple program to calculate the matrix multiplication of two matrices.
//

// I'm going to be honest Dr. Buckner, I would've rather just taken a final exam than do this program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Function to read a file that ended up being useless
// char *readFile(char *fileName)
// {
//     FILE *file = fopen(fileName, "r");
//     char *code;
//     size_t n = 0;
//     int c;

//     if (file == NULL)
//         return NULL; // could not open file
//     fseek(file, 0, SEEK_END);
//     long f_size = ftell(file);
//     fseek(file, 0, SEEK_SET);
//     code = malloc(f_size);

//     while ((c = fgetc(file)) != EOF)
//     {
//         code[n++] = (char)c;
//     }

//     code[n] = '\0';

//     return code;
// }
int c[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}};

int multMat(int **a, int **b)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                c[i][k] += a[i][j] * b[j][k];
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    int buffer = 100;
    int row;
    int column;

    // Make sure right amount of arguments are passed
    if (argc > 5 || argc < 4)
    {
        printf("Incorrect amount of arguments passed\n");
        return 0;
    }
    else
    {
        // Open the three files
        FILE *mat1 = fopen(argv[1], "r");
        FILE *mat2 = fopen(argv[2], "r");
        FILE *mmat = fopen(argv[3], "w");
        int threadCount = 0;

        // Check to see if there is a thread count then store it
        if (argc == 5)
        {
            char *threads = argv[4];
            threadCount = atoi(threads);
        }

        // Tried printing out the contents of file and it says its empty?
        // char *a = readFile("matrix1");
        // printf("%s\n", a);

        int a[3][3] = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}};
        int b[3][3] = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}};

        // My attempt at getting the matrix from the file... it didn't work
        // I'm not sure how the matrix is being stored in the file and opening it with
        // a text editor simply gave me a bunch of giberish that didn't help

        // fread(b, buffer, 1, mat2);

        // Tried print out the matrix to understand how it's stored in the file
        // for(int i = 0; i < 10; i++){
        //     printf("new row");
        //     for(int j = 0; j < 10; j++){
        //         printf("%d\n ", a[i][j]);
        //     }
        // }

        // Declare variable to count up to number of threads provided
        int count = 0;
        int err;

        // Create amount of threads equal to amount provided
        pthread_t tid[threadCount];

        // Tell threads to execute the multMat function until all amount of threads requested are assigned
        while (count < threadCount)
        {
            err = pthread_create(&(tid[count]), NULL, multMat(a, b), NULL);

            // Print an error if thread is not created properly
            if (err != 0)
                printf("\nCan't create thread: [%s]", strerror(err));
            count++;
        }

        // Join all of the threads together
        for (int i = 0; i < count; i++)
        {
            pthread_join(tid[i], NULL);
        }


        // Compute mmult
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    c[i][k] += a[i][j] * b[j][k];
                }
            }
        }

        // Check to make sure mmult was done correctly
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }

        // Update new matrix to file
        fwrite(c, buffer, 1, mmat);

        // Close the files
        fclose(mat1);
        fclose(mat2);
        fclose(mmat);
        printf("Worker threads: %d", threadCount);

        // Just wanted to print out the matrix to make sure it's right
        // for (int i = 0; i < 3; i++)
        // {
        //     for (int j = 0; j < 3; j++)
        //     {
        //         for (int k = 0; k < 3; k++)
        //         {
        //             c[i][k] += a[i][j] * b[j][k];
        //         }
        //     }
        // }
    }
}