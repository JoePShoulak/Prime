# Prime #
## Archived ##

This is an older project of mine from earlier in my coding career. I don't feel like making it private or deleting it, but this project does not necessarily reflect my current methodology as a developer. No further changes have been made. 

## About ##
This tests to see if numbers are prime using the Lucas-Lehmer test for Mersenne Primes, and iterated divisions for non-mersenne numbers. The non-mersenne number function needs to be refined.

## Usage ##
Use the `-m` flag to indicate the number is the exponent for the statement `(2^n)-1`.
```
$ make
$ ./prime 5
  // Prime
$ ./prime 6
  // Composite
$ ./prime 17 -m
  // Composite
$ ./prime 5 -m
  // prime
```
