#include <iostream>
#include <fstream>

using namespace std;

/*
  1.	A complete C++ program that does the following steps:
**/

main()
{
  //  a. read all the prices from a text file (file path is provided by the user)
  cout << "a. Please enter the input file path: ";
  char path[20] = "";
  cin >> path;
  ifstream rd(path);
  float prices[100] = {0.0};
  int no = 0;
  while(rd >> prices[no++]);
  no--;
  rd.close();
  cout << "The following values are read from file \""
       << path << "\": ";
  for(int i = 0; i < no; i++)
    {
      cout << prices[i] << " ";
    }
  cout << endl;
  // b.	calculate and write to a text file (file path is provided by the user) sum, average, maximum, minimum, frequency of each price.
  
  float sum = 0.0;
  float max = prices[0];
  float min = prices[0];
  float avg = 0.0;
  int neq = 0;
  int ng = 0;
  int sn = 0;
  float singlePrices[100] = {0.0};
  int freqs[100] = {0};
  int nsm = 0;
  // sum, avg, max, min calculations
  sum += prices[0];
  for(int i = 1; i < no; i++)
    {
      sum += prices[i];
      if(prices[i] > max)
	{
	  max = prices[i];
	}
      if(prices[i]< min)
	{
	  min = prices[i]; 
	}
    }

  avg = sum / no;
  for(int i = 0; i < no; i++)
    {
      if(prices[i] == avg)
	{
	  neq++;
	}
      if(prices[i] > avg)
	{
	  ng++;
	}
      if(prices[i] < avg)
	{
	  nsm++;
	}
    }
        
  // copies single values from prices to singlePrices
  for(int i = 0; i < no; i++)
    {
      bool isFound = false;
      for(int ii = 0; ii < sn; ii++)
	{
	  if(prices[i] == singlePrices[ii])
	    {
	      isFound = true;
	      break;
	    } 
	}
      if(!isFound)
	{
	  singlePrices[sn] = prices[i];
	  sn++;
	}
    }
  sn--;
  // frequency calculations
  for(int ii = 0; ii < sn; ii++)
    {
      for(int i = 0; i < no; i++)
	{
	  if(singlePrices[ii] == prices[i])
	    {
	      freqs[ii]++;
	    }
	}
    }
  // Write result to file
  cout << "Please enter the output file path: ";
  cin >> path;
  ofstream wr(path);
  cout << "The following is written to the text file \""
       << path << "\": \n";
  cout << "Sum = " << sum << endl;
  cout << "Average = " << avg << endl;
  cout << "Maximum = " << max << endl;
  cout << "Minimum = " << min << endl;
  wr << "Sum = " << sum << endl;
  wr << "Average = " << avg << endl;
  wr << "Maximum = " << max << endl;
  wr << "Minimum = " << min << endl;
  for(int i = 0 ; i < sn; i++)
    {
      cout << "Frequency of " << singlePrices[i]
	   << " is " << freqs[i] << endl;
      wr << "Frequency of " << singlePrices[i]
	   << " is " << freqs[i] << endl;
    }
  wr.close();

  // c. Display on screen the number of prices equal to, greater or smaller than the average
  
  cout << "c. Number of prices equal to average of = "
       << avg << " is "
       << neq << endl;;
  cout << "Number of prices smaller than average of = "
       << avg << " is "
       << ng << endl;;
  cout << "Number of prices greater than average of = "
       << avg << " is "
       << nsm << endl;;
  
   return 0;
}
