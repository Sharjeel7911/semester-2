#include <iostream>

using namespace std;

main()
{
  // append a cstring in another
  char cstrA[20] = "";
  char cstrB[20] = "";

  cout << "Enter two cstrings: ";
  cin >> cstrA >> cstrB;
  cout << " You entered: " << cstrA << " and " << cstrB << endl;
  // find lengths os each cstring
  int lenA = 0;
  int lenB = 0;
  for(int i = 0; cstrA[i] != '\0'; i++)
    {
      lenA++;
    }
  for(int i = 0; cstrB[i] != '\0'; i++)
    {
      lenB++;
    }
  // append cstrA in cstrB
  for(int i = 0; i < lenA; i++)
    {
      cstrB[lenB + i] = cstrA[i];
    }
  // make cstrB a cstring
  cstrB[lenA + lenB] = '\0';
  cout << cstrA << " " << cstrB << endl;
  return 0;
}
