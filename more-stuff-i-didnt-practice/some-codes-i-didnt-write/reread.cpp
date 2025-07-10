#include <iostream>
#include <fstream>

using namespace std;

// This code first reads all the values to get the total number of values in the file
// Then uses command " rd.seekg (0, ios::beg);" to go back to the begininng of the file and read exact number of values

int main()
{
  float value = 1.0;
  int no = 0;
  float sum = 0.0;
  float average = 0.0;
  // First Find the Number of values in File
  ifstream rd("values.txt");
  while(rd >> value)
    {
      no++;
    }
  cout << "Number of values: " << no << endl;
  // Now Go to the Begininng of File
  rd.seekg (0, ios::beg);
  // and read exact number of values
  for(int i = 0; i < no; i++)
    {
      rd >> value;
      sum += value;
    }
  rd.close();
  float avg = sum/no;
  cout << "Sum is " << sum << " and Average is  " << avg << endl;
  return 0;
}
