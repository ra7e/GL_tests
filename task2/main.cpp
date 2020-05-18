#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
  int sum = 0;
  for(int i = 0; i <= atoi(argv[1]); i++)
  {
        sum += i * atoi(argv[2]);
  }
  cout << sum << endl;

  return 0;
}
