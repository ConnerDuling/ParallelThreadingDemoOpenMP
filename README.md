# ParallelThreadingDemoOpenMP
A small showcase of how parallel threading can be used to speed up computation involving repeated operations

This is done by using the Monte Carlo method to approximate how many random points are within a circle, when said circle is within a square that is just big enough to contain the circle. If N points are added to the square, but only M of those points fall within the circle, then this method states that (4 * M / N) will give us an approximate value of pi.

These programs simulate what this is like with only one thread working on the problem, as shown in serial.c with a given value of N.

The other program, parallel.c, allows a user to specify some value of N, as well as the number of threads they want to have work on the task. It then gives a print out of the time in seconds it took to perform the operation.

---

openmp is linked to parallel.c at compile time with:

gcc -o parallel parallel.c -fopenmp
