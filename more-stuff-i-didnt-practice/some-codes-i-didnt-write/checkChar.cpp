#include <iostream>

using namespace std;

main()
{
  // how to check if a given character is in a Cstring
  bool isFound = false;
  char cstr[20] = "";
  char ch = '\0';
  cout << "Enter a cstring and a character to find:";
  cin >> cstr >> ch;
  for(int i = 0; cstr[i] != '\0'; i++)
    {
      if(cstr[i] == ch)
	{
	  isFound = true;
	  break;
	}
    }
  if(isFound)
    {
      cout << ch << " is in " << cstr << endl;
    }
  else
    {
      cout << ch << " is NOT in " << cstr << endl;
    }
  return 0;
}
