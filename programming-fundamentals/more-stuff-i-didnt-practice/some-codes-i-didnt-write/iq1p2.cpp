// Solution of Informal Quiz 1 Part 2
#include <iostream>
#include <fstream>

using namespace std;

main()
{
  char words[60] = "";
  char w1[30] = "";
  char w2[30] = "";
  // 1. write code to read 2 words from file "words.txt" [30 seconds]
  rd >> w1 >> w2;
  rd.close();
  int len1 = 0;
  int len2 = 0;
  // 2. Write Code to find lengths of both words  [1 minute]
  while(w1[len1++] != '\0');
  while(w2[len2++] != '\0');
  cout << "length of \"" << w1 << " \"is " << len1
       << " and length of \"" << w2 << " \"is " << len2
       << endl;
  // 3. write code to copy w1 and w2 to arary words  [1.5 minutes]
  for(int i = 0; i < len1 - 1; i++)
    {
      words[i] = w1[i];
    }
  for(int i = 0; i < len2; i++)
    {
      words[i + len1 - 1] = w2[i];
    }
  // 4. Write code to display cstring words on screen  [30 seconds]
  cout << words << endl;
  // 5. write code to display words in reverse on screen  [3 minutes]
  // Bonus: Also Include code to write words in reverse in a file "reverse.txt"
  ofstream wr("reverse.txt");
  for(int i = 0; words[i] != '\0'; i++)
    {
      cout << words[(len1 - 2)+ (len2 - 1) - i];
      wr << words[(len1 - 2)+ (len2 - 1) - i];
    }
  cout << endl;
  wr << endl;
  wr.close();
  return 0;
}
    
  
