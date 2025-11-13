#include <iostream>
#include <fstream>

using namespace std;

/*
3.	Write a complete C++ program that does the following steps
**/

main()
{
  // a.	reads an English Paragraph from a file (file path is provided by the user)

  cout << "a. Please enter the input file path: ";
  char path1[20] = "";
  char cstr[20] = "";
  cin >> path1;
  ifstream rd(path1);
  cout << "Please enter the output file path: ";
  char path2[20] = "";
  cin >> path2;
  ofstream wr(path2);
  // b.	convert all words of the paragraph to all UPPERCASE and write to another text file (file path is provided by the user)
  cout << "Read following paragraph from file \"" << path1 << "\"\n\n";
  while(rd >> cstr)
    {
      cout << cstr << " ";
      for(int i = 0; cstr[i] != '\0'; i++)
	{
	  if(cstr[i] >= 'a' && cstr[i] <= 'z')
	    {
	      cstr[i] -= 32;
	    }
	}
      wr << cstr << ' ';
    }
  cout << endl << endl;
  cout << "Written above paragraph to file in all UPPERCASE \"" << path2 << "\"\n";
  rd.close();
  wr.close();
  return 0;
}
