#include <iostream>

using namespace std;

// An given Cstring "sentence" is copied in a reverseSentence array in reverse-word i.e. last word first
// Finally displayh the each individual word of the reverseSentence
main()
{
  char sentence[100] = "This is good.";
  char reverseSentence[100] = {'@'};
  int lenS = 0;
  char word[30] = "";
  while(sentence[lenS++] != '\0');
  int j = 0;
  int i = 0;
  int y = 0;
  while(i < lenS - 2)
    {
      // extract word from sentence
      j = 0;
      while(sentence[i] != ' ' && sentence[i] != '\0')
	{
	  word[j] = sentence[i];
	  j++;
	  i++;
	}
      i++;
      // copy word in reverseSentence from end and in reverse
      for(int x = j - 1; x >= 0; x--)
	{
	  reverseSentence[lenS - 2 - y] = word[x];
	  y++;
	}
      reverseSentence[lenS - 2 - y] = ' ';
      y++;
    }
  cout << endl;
  reverseSentence[lenS - 2 - y] = '\0';
  cout << reverseSentence << endl;

  for(int ii = 0; ii < lenS - 1; ii++)
    {
      if(reverseSentence[ii] != ' ')
	{
	  cout << reverseSentence[ii];
	}
      else
	{
	  cout << endl;
	}
    }

  return 0;
}
