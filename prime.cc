#include <iostream> // cout
#include <math.h>   // pow
#include <stdlib.h> // exit, EXIT_FAILURE
#include <string.h> // string

using std::cout;
using std::cin;
using std::string;

bool is_number(const std::string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

/* TODO: Find a way to take the digital sum of a
   toTest, and take it modulo 3. If the result
   is 0, the toTest is composite.                */

bool stand(int toTest) /* Test for a non-mersenne toTest */
{
  int fails;
  if (toTest%2 == 0)
  {
    fails = 0;
  }
  else
  {
    fails = 1;
    int max = toTest/2;
    for (int i=2; i<max; i++)
    {
      fails *= toTest % i; /* Iff a modulo is 0, fails will become 0 */
    }
  }
  return fails != 0;
}

bool llt(int exponent) /* Primality test of Mersenne toTests, 
                          using the Lucas-Lehmer algorithm    */
{
    int num = 4;
    int max = pow(2, exponent) - 1;
    for (int i; i < exponent-2; i++)
    {
      num = ( ( num*num ) - 2 ) % max;
    }
    return (num==0);
}

string example = "Eg: 'prime 5' to see if 5 is prime\n    'prime 5 -m' to see if (2^5)-1 is prime\n";

int main(int argc, char* argv[])
{
  bool result;
  if (argc == 1)
  {
    cout << "Enter a toTest to be tested\n" << example;
    exit(EXIT_FAILURE);
  }
  if (argc == 2 && is_number(argv[1]))
  {
    int num;
    num = atoi(argv[1]);
    if (num > 9223372036854775800);
    {
      cout << "Number too large\n";
      exit(EXIT_FAILURE);
    }
    result = stand(num);
    if (result)
      cout << "Prime\n";
    else
      cout << "Composite\n";
    exit(EXIT_SUCCESS);
  }
  if (argc == 3 && is_number(argv[1]) && strcmp(argv[2], "-m") == 0)
  {
    int exp;
    exp = atoi(argv[1]);
    result = llt(exp);
    if (result)
      cout << "Prime\n";
    else
      cout << "Composite\n";
    exit(EXIT_SUCCESS);
  }
  else
  {
    cout << "Invalid arguments\n" << example;
    exit(EXIT_FAILURE);
  }
  if (argc > 3)
  {
    cout << "Too many arguments\n" << example;
    exit(EXIT_FAILURE);
  }
  if (result)
    cout << "Prime\n";
  else
    cout << "Composite\n";
  return 0;
}
