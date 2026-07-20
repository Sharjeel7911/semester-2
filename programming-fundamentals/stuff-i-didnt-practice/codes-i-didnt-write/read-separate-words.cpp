#include <iostream>

using namespace std;

// reads a sentence from the user, stores in a array and display individual words on screen
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
  // display each individual word of sentence in a separate line
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
  cout << endl;
  return 0;
}
