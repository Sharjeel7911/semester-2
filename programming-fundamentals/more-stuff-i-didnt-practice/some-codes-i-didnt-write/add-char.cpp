#include <iostream>

using namespace std;

main()
{
  // Add a character in a Cstring at the desired position
  char cstr[20] = "";
  char ch = '\0';
  int pos = 0;
  cout << "Enter a cstring, a character to add and position:";
  cin >> cstr >> ch >> pos;
  // pos must be less than length of cstr, so find length first
  int length = 0;
  for(int i = 0; cstr[i] != '\0'; i++)
    {
      length++;
    }
  if(pos >= length)
    {
      cout << pos << " is more than " << length
	   << " of " << cstr << endl;
      return 0;
    }
  // first make room for the character in cstr
  for(int i = length + 1; i >= pos; i--)
    {
      cstr[i] = cstr[ i - 1];
    }
  // now insert
  cstr[pos] = ch;
  cout << cstr << endl;
  return 0;
}
