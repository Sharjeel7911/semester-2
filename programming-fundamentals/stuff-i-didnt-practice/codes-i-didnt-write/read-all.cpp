#include <iostream>

using namespace std;

// Reads all the values from the user until user enters a negative values
int main()
{
  float value = 1.0;
  int no = 0;
  float sum = 0.0;
  float average = 0.0;
  cout << "Please  enter decimals or enter negative value to quit: ";
  while(value > 0.0)
    {
      cin >> value;
      if(value > 0.0)
	{
	  sum += value;
	}
      no++;
    }
  float avg = sum/no;
  cout << "Sum is " << sum << " and Average is  " << avg << endl;
  return 0;
}
