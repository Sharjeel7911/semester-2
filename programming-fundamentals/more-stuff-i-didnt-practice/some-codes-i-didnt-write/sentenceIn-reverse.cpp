#include <iostream>

using namespace std;
// reads an English sentence from the user and stores in a "char" array or Cstring
// Then copies the sentence in a reverseSentence array in reverse-word i.e. last word first
// Finally displayh the each individual word of the reverseSentence

main()
{
  // read an English sentence from the user
  // 1. declare a sufficient size "char" array to hold the sentence
  // and initialize
  char sentence[100] = "";
  // 2. declare a char array to hold a single Enlish word
  char word[30] = "";
  // 3. tell user what to do
  cout << "Enter an English Sentence ending in \'.\': ";
  // 4. In a loop read word by word until a word contains fullstop
  // 5. Append each read word in the Cstring sentence
  // 6. Insert a space at the end of cstring sentence

  bool isFound = false;
  int lenS = 0;
  while(!isFound)
    {
      cin >> word;
      // append word to sentence
      int lenW = 0;
      while(word[lenW++] != '\0');
      while(sentence[lenS++] != '\0');
      for(int i = 0; i < lenW;i++)
	{
	  sentence[lenS - 1 + i] = word[i];
	}
      sentence[lenS + lenW - 2] = ' ';
      // check if word has fullstop
      for(int i = 0; word[i] != '\0'; i++)
	{
	  if(word[i] == '.')
	    {
	      isFound = true;
	      sentence[lenS + lenW - 2] = '\0';
	      break; // loop ends when a fullstop is found
	    }
	}
    }
  // display sentence
  cout << sentence << endl;
  // display each individual word of sentence ins a separate line
  // Find length of sentence

  while(sentence[lenS++] != '\0');
  // display each character and enter a newline when space
  for(int i = 0; i < lenS - 1; i++)
    {
      if(sentence[i] != ' ')
	{
	  cout << sentence[i];
	}
      else
	{
	  cout << endl;
	}
    }
  // display each individual word of sentence in reverse in separate lines
  // copy sentence in reverse in a another cstring
  cout << endl;
  char reverseSentence[100] = {'@'};
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
  cout << endl;
  return 0;
}
