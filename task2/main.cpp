#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
  int sum = 0;
  int first = 1;

  sum = (atoi(argv[2]) * atoi(argv[1]) * (1 + atoi(argv[1]))) / 2;
  // it`s a arithmetic progression - S = n*(A1 + An)/2.
  // Also we need to consider distance between bank and first span, thats why
  // we have n+1.
  cout << sum << endl;

  return 0;
}
