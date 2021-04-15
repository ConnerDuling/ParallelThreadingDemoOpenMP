#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Conner Duling
*  CS350
*  HW6
*/

int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("Usage %s: number_of_points", argv[0]);
        exit(1);
    }

    srand(time(NULL));

    double inCircle = 0;

    for(int i = 0; i < atoi(argv[1]); i++){
        if(sqrt(pow(((double)rand() / (double)RAND_MAX),2)+pow(((double)rand() / (double)RAND_MAX),2)) <= 1){
            inCircle += 1;
        }
    }

    printf("Approximation of pi is: %.2f", 4 * inCircle / atoi(argv[1]));
}