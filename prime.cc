#include <stdlib.h> // exit, EXIT_FAILURE
#include <string.h> // string
#include <math.h>   // pow
#include <iostream> // cout

using std::cout;
using std::string;

void Crash() {
  printf("%s", "Usage: prime [number] [options]\n\n"
               "Options:\n"
               "  -m    the number (X) is to be interpreted as (2^X)-1\n");
  exit(EXIT_FAILURE);
}

// user-defined functions
bool IsNumber(const std::string& s) {
  string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit(*it)) ++it;
  return !s.empty() && it == s.end();
}

// TODO: Find a way to take the digital sum of a
// toTest, and take it modulo 3. If the result
// is 0, the toTest is composite

// Test for a non-mersenne prime
bool stand(int toTest) {
  int fails;
  if (toTest%2 == 0) {
    fails = 0;
  } else {
    fails = 1;
    int max = toTest/2;
    for (int i=2; i<max; i++) {
      // If (and only if) any of the modulo results is 0, 'fails' will become 0
      fails *= toTest % i;
    }
  }
  return fails != 0;
}

// Tests for Mersenne primes
bool llt(int exponent) {
  // The Lucas-Lehmer algorithm
  int num = 4;
  int max = pow(2, exponent) - 1;
  for (int i; i < exponent-2; i++) {
    num = ( ( num*num ) - 2 ) % max;
  }
  return (num==0);
}


int main(int argc, char* argv[]) {
  bool result;
  if (argc == 1) {
    Crash();
  } else if (argc == 2 && IsNumber(argv[1])) {
    int num;
    num = atoi(argv[1]);
    if (num > 9223372036854775800); {
      cout << "Number too large\n";
      exit(EXIT_FAILURE);
    }
    result = stand(num);
    if (result) {
      printf("%s", "Prime\n");
    } else {
      printf("%s", "Composite\n");
    }
    exit(EXIT_SUCCESS);
  }
  if (argc == 3 && IsNumber(argv[1]) && strcmp(argv[2], "-m") == 0) {
    int exp;
    exp = atoi(argv[1]);
    result = llt(exp);
    if (result) {
      printf("%s", "Prime\n");
    } else {
      printf("%s", "Composite\n");
    }
    exit(EXIT_SUCCESS);
  } else {
    Crash();
  }
  if (argc > 3) {
    Crash();
  }
  if (result) {
    printf("%s", "Prime\n");
  } else {
    printf("%s", "Composite\n");
  }
  return 0;
}
