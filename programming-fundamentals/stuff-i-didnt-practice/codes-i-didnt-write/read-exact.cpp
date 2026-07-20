#include <iostream>

using namespace std;

// reads exact number of values from the user
int main()
{
  float values[10] = {0.0};
  cout << "Enter 10 prices: ";
  for(int i = 0; i < 10; i++)
    {
      cin >> values[i];
    }
  for(int i = 0; i < 10; i++)
    {
      cout << values[i] << " ";
    }
  cout << endl;

  return 0;
}
