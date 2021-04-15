#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <math.h>

/* Conner Duling
*  CS350
*/

int main(int argc, char *argv[])
{
    //Used to take input arguments to allow for varied thread usage
    if(argc != 3){
        printf("Usage %s: number_of_points number_of_threads", argv[0]);
        exit(1);
    }

    double beginning = omp_get_wtime();

    //Master counter to track how many total points are within the circle
    double inCircle = 0;

    //Tells the program that a parallel thread sharing should be started here
    //Specifies that all threads share the same inCircle value
    //Specifies the number of threads to use based command line arguements
    #pragma omp parallel shared(inCircle) num_threads(atoi(argv[2]))
    {
        //Internal counter that each thread will have, and NOT share with eachother
        double counter = 0;

        //Seeds the random number generator with the current time + the thread ID
        //to ensure random outputs between all concurrent threads
        srand(time(NULL)+omp_get_thread_num());

        //Loops through the number of N divided by the thread count, to ensure
        //the threads only do the amount of work necessary
        //I.e. only (N / thread_count) iterations need to be made per thread,
        //equaling N when added at the very end
        for(int i = 0; i < atoi(argv[1])/omp_get_num_threads(); i++){

            //Randomly makes two points between 0 and 1, and finds the hypotenus.
            //If this is <= 1, the thread increments its own private counter variables 
            if(sqrt(pow(((double)rand() / (double)RAND_MAX),2)+pow(((double)rand() / (double)RAND_MAX),2)) <= 1){
                counter += 1;
            }
        }
        
        //IMPORTANT!
        //This section of code informs the threads that inCircle needs to be shared,
        //and only accessed by one thread at a time to avoid overwriting another value
        #pragma omp critical
            inCircle += counter;
    }

    double ending = omp_get_wtime();

    //Parallel threads merge back to the Master Thread,
    //and the final calculation is performed before being printed to the user.
    printf("Approximation of pi is: %.2f\n", 4 * inCircle / atoi(argv[1]));
    printf("Time betweening beginning and end is: %f", ending - beginning);
}






