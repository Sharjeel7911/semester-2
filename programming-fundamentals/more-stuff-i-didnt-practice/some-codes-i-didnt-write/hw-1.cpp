#include <iostream>

using namespace std;

/*
  1.	A complete C++ program that does the following steps:
**/

main()
{
  //  a.	read an English word (word one) from the user and display on screen
  char wordOne[30] = "";
  cout << "a. Please enter an English word: ";
  cin >> wordOne;
  
  // b.	finds and displays the length of the word on screen
  int lengthOne = 0;
  while(wordOne[lengthOne++] != '\0');
  cout << "b. length of " << wordOne << " is " << lengthOne << endl;
  // c.	Copy the word in to another word (word two)and display both words on screen
  char wordTwo[30] = "";
  for(int i = 0; i < lengthOne; i++)
    {
      wordTwo[i] = wordOne[i];
    }
  cout << "c.After copying both words: "
       << wordOne << " " << wordTwo << endl;
  // d.	Convert both words all to UPPERCASE and display both words on screen
  int lengthTwo = 0;
  while(wordTwo[lengthTwo++] != '\0');
  for(int i = 0; i < lengthOne - 1; i++)
    {
      if(wordOne[i] >= 'a' && wordOne[i] <= 'z')
	{
	  wordOne[i] -= ('a' - 'A'); 
	}
    }
  for(int i = 0; i < lengthTwo; i++)
    {
      if(wordTwo[i] >= 'a' && wordTwo[i] <= 'z')
	{
	  wordTwo[i] -= ('a' - 'A'); 
	}
    }
  cout << "d. After Conversion of both words to all UPPERCASE: "
       << wordOne << " " << wordTwo << endl;
  
  // e.	Read another word (word 3)from the user and display on screen
  char wordThree[30] = "";
  cout << "e. Please enter an English word: ";
  cin >> wordThree;
  cout << wordThree << endl;
  // f.	Append the first word to the last word (3rd word) and display first and 3rd words
  int lengthThree = 0;
  while(wordThree[lengthThree++] != '\0');
  char wordThreeCopy[30] = "";
  for(int i = 0; i < lengthThree; i++)
    {
      wordThreeCopy[i] = wordThree[i];
    }

  for(int i = 0; i < lengthOne; i++)
    {
      wordThree[lengthThree - 1 + i] = wordOne[i];
    }
    cout << "f. after appending first word \""
	 << wordOne << "\" to 3rd word \""
	 << wordThreeCopy << "\":\n";
    cout << wordOne << " " << wordThree << endl;
  // g.	Insert a space in the 3rd word after the first word and display the 3rd word
    for(int i = lengthOne + lengthThree - 1; i >=lengthThree -1; i--)
      {
	wordThree[i] = wordThree[i - 1];
      }
    wordThree[lengthThree - 1] = ' ';
    cout << "g. After insertion of space after the word \""
	 << wordThreeCopy << "\": "
	 << wordThree << endl;
  // h.	Read a single character from the user and display if that character is present in the 3rd words or not
    char ch = '\0';
    cout << "h. please enter a single character to find: ";
    cin >> ch;
    bool isFound = false;
    for(int i = 0; i < lengthThree; i++)
    {
      if(wordThree[i] == ch)
	{
	  isFound = true;
	  break;
	}
    }
    if(isFound)
      {
	cout << ch << " is present in the 3rd word \""
	     << wordThree << "\"\n";
      }
    else
      {
	cout << ch << " is NOT present in the 3rd word \""
	     << wordThree << "\"\n";
      }
    
  // i.	Now display  the number of times the single character is present in the 3rd word
    int frequency = 0;
    for(int i = 0; i < lengthThree; i++)
    {
      if(wordThree[i] == ch)
	{
	  frequency++;
	}
    }
    cout << "i. " << ch << " is present " << frequency
	 << " times in the 3rd word \""
	 << wordThree << "\"" << endl;
  return 0;
}
