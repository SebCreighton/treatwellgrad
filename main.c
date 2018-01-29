//
//  main.c
//  test
//
//  Created by Seb Creighton on 29/01/2018.
//  Copyright © 2018 Seb Creighton. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BASE 10

int main(void) {
    char rows[2], cols[2];
    char *endptr;
    int numberrow, numbercol, i, j;
    
    printf("Enter number of rows: ");
    scanf("%s", rows);
    
    
    numberrow = strtol(rows, &endptr, BASE); /* Converts  'rows' string into integer */
    
    if (*endptr != '\0' || endptr == numberrow) /* Check for non-integers */
    {
        fprintf(stderr,"'%s' contains non-integers\n", rows);
        exit(-1);
    }
    
    if (strlen(rows) > 3) /* Max value for rows is 999 */
    {
        fprintf(stderr, "%s's length is too long.\n", rows);
        exit (-1);
    }
    
    if (numberrow <= 1)
    {
        fprintf(stderr, "Value needs to be 2 or greater\n");
        exit(-1);
    }
    
    
    printf("Enter number of cols: ");
    scanf("%s", cols);
    
    numbercol = strtol(cols, &endptr, BASE); /* Converts 'cols' string into integer */
    
    if (*endptr != '\0' || endptr == cols)
    {
        fprintf(stderr,"'%s' contains non-integers\n", cols);
        exit(-1);
    }
    
    if (strlen(cols) > 3) /* Max value for cols is 999 */
    {
        fprintf(stderr, "%s's length is too long.\n", cols);
        exit (-1);
    }
    
    if (numbercol <=1)
    {
        fprintf(stderr, "Value needs to be 2 or greater\n");
        exit(-1);
    }
    
    
    
    /* Row iterator for loop */
    for(i = 0; i < numberrow; i++){
        /* Column iterator for loop */
        for(j = 0; j < numbercol; j++){
            /* Check if currely position is a boundary position */
            if(i==0 || i==numberrow-1 || j==0 || j==numbercol-1){
                if(i == 0 && j ==0) /* Top left corner */
                {
                    printf("┌\t");
                }
                else if (i == 0 && j == numbercol-1) /* Top right corner */
                {
                    printf("┐\t");
                }
                else if (i ==numberrow-1 && j == 0) /* Bottom left corner */
                {
                    printf("└\t");
                }
                
                else if (i == numberrow-1 && j == numbercol-1) /* Bottom right corner */
                {
                    printf("┘\t");
                }
                
                else if ((i==0 || i == numberrow-1)) /*Horizontal edges */
                {
                    printf("-\t");
                    
                }
                else /* Vertical edges */
                {
                    printf("|\t");
                }
                
            }
            
            else /* Remaining space */
            {
                printf("\t");
            }
            
        }
        printf("\n"); /* New column */
    }
    return 0;
}

