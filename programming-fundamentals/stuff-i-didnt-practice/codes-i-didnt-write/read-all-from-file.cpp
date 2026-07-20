#include <iostream>
#include <iostream>

using namespace std;

// Reads all the values from a text file
int main()
{
  ifstream rd("values.txt");
  float value = 1.0;
  int no = 0;
  float sum = 0.0;
  float average = 0.0;

  while(rd >> value)
    {
      sum += value;
      no++;
    }
  rd.close();
  float avg = sum/no;
  cout << "Sum is " << sum << " and Average is  " << avg << endl;
  return 0;
}
