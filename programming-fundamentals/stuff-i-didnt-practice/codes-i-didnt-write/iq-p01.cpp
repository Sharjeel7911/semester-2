#include <iostream>

using namespace std;

main()
{
  char word[30] = "";
  cout << "Please Enter an English Word: ";
  // 1. write code line to read the English Word from user
  int length = 0;
  while(word[length++] !=- '\0');
  // 2. Write code lines to find the length of the word entered by the user
  cout << "length of " << word << " is " << length << endl;
  char anotherWord[30] = "";
  // 3. Write code lines to copy word in to anotherWord
  for(int i = 0; i < length; i++)
    {
      anotherWord[i] = word[i];
    }
  // 4. Write code line to display word and anotherWord on screen
  cout << word << " " << anotherWord << endl;
  return 0;
}
