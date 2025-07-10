#include <iostream>
#include <fstream>

using namespace std;

/*
2. A complete C++ program that copy a text file (contains any data type values) to another text file
**/

main()
{
  cout << "a. Please enter the input file path: ";
  char path1[20] = "";
  char cstr[20] = "";
  cin >> path1;
  ifstream rd(path1);
  cout << "Please enter the output file path: ";
  char path2[20] = "";
  cin >> path2;
  ofstream wr(path2);
  cout << "The following is read from file \""
       << path1 << "\"";
  cout << " and written to file \"" << path2 << "\":\n";
  while(rd >> cstr)
    {
      cout << cstr << ' ';
      wr << cstr << ' ';
    }
  rd.close();
  wr.close();
   return 0;
}
