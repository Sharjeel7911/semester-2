#include <iostream>
#include <fstream>

using namespace std;

// reads exact number of values from a text file

int main()
{
  ifstream rd("values.txt");
  float values[10] = {0.0};

  for(int i = 0; i < 10; i++)
    {
      rd >> values[i];
    }
  rd.close()
  for(int i = 0; i < 10; i++)
    {
      cout << values[i] << " ";
    }
  cout << endl;

  return 0;
}
