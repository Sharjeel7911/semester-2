// This file containg 9 main functions dealin with files
// Each main is explained using a cout
// To use a particular main enter an integer between  1 to 9
#include <iostream>
#include <fstream>

using namespace std;

int main9()
{
  cout << "******* main9 *******\n";
  cout << "\t reads course data from \"courses.txt\",";
  cout << " calculates CGPA and append to the same file\n";
  cout << "*********************\n\n";
  int no = 0;
  char heading[15] = "";
  char course[15] = "";
  char grade[3] = "";
  float gpa[5] = {0.0};
  float crh[5] = {0.0};
  float tcrh = 0.0;
  float cgpa = 0.0;
  int cn = 1;
  ifstream file("courses.txt");
  cout << "Reading data of courses from file: \n";
  // first read and display the column headings:
  file >> heading; // No.
  cout << heading << "\t";
  file >> heading; // Course
  cout << heading << "\t";
  file >> heading; // Grade
  cout << heading << "\t";
  file >> heading; // Cr.Hr
  cout << heading << "\t"; 
  file >> heading; // GPA
  cout << heading << "\n"; 
  float ch = 0.0;
  float gp = 0.0;
  while(file >> no >> course >> grade >> ch >> gp)
    {
      cout << no << "\t"
	   << course << "\t"
	   << grade << "\t"
	   << ch << "\t"
	   << gp << "\n";
      crh[cn] = ch;
      gpa[cn] = gp;
      cn++;
    }
  file.close();
  for(int i = 0; i < cn; i++)
    {
      cgpa += crh[i] * gpa[i];
      tcrh += crh[i];
    }
  cgpa /= tcrh;
  ofstream wr("courses.txt", ios::app);
  wr << "CGPA = " << cgpa << endl;
  wr.close();
  return 0;
}

int main8()
{
  cout << "******* main8 *******\n"
       << "\treads students data from \"students.txt\","
       << " calculates Sum, average, maximum and minimum CGPA values on screen and writes to a file \"results.txt\"\n";
  cout << "*********************\n\n";
  int no = 0;
  char heading[15] = "";
  char reg[15] = "";
  char fn[15] = "";
  char ln[15] = "";
  float cgpa = 0.0;
  float sum = 0.0;
  float avg = 0.0;
  float max = -1.0;
  float min = 4.0;
  int sn = 0;
  ifstream file("students.txt");
  cout << "Reading data of students from file: \n";
  // first read and display the column headings:
  file >> heading; // No.
  cout << heading << "\t";
  file >> heading; // Registration
  cout << heading << "\t";
  file >> heading;// First
  cout << heading << " ";
  file >> heading; // Name
  cout << heading << "\t";
  file >> heading; // Last
  cout << heading << " ";
  file >> heading; // Name
  cout << heading << "\t";
  file >> heading; // CGPA
  cout << heading << "\n";

  while(file >> no >> reg >> fn >> ln >> cgpa)
    {
      cout << no << "\t"
	   << reg << "\t"
	   << fn << "\t\t"
	   << ln << "\t\t"
	   << cgpa << "\n";
      sum += cgpa;
      if(max < cgpa)
	{
	  max = cgpa;
	}
      sn++;
      if(min > cgpa)
	{
	  min = cgpa;
	}

    }
  file.close();
  ofstream wr("results.txt");
  avg= sum/sn;
  cout << "CGPA:\tSum\tAverage\tMaximum\tMinimum\n";
  cout << "    \t" << sum << "\t" << avg << "\t" << max 
       << "\t" << min << endl; 
  wr << "CGPA:\tSum\tAverage\tMaximum\tMinimum\n";
  wr << "    \t" << sum << "\t" << avg << "\t" << max 
       << "\t" << min << endl; 
  wr.close();
  return 0;
}

int main7()
{
  cout << "******* main7 *******\n"
       << "\treads rooms data from \"rooms.txt\","
       << " calculates cost of paintingthe room and display on screen\n";
  cout << "*********************\n\n";
  int length = 0;
  int width = 0;
  int depth = 0;
  float cost = 0.0;
  int no = 1;
  int sufaceArea = 0;
  ifstream file("rooms.txt");
  cout << "Reading data of rooms from file: \n";
  while(file >> length >> width >> depth >> cost)
    {
      cout << "Room " << no
	   << ": length is " << length
	   << ": width is " << width
	   << ": depth is " << depth
	   << " and cost is " << cost << endl;;
      sufaceArea = 2*((length * width)
		      + (length * depth)
		      + (width * depth));
      cost = sufaceArea * cost;
      cout << "Room " << no << ": "
	   << ": Surface Area is " << sufaceArea
	   << ": Paint cost is " << cost << endl;
      no++;
    }
  file.close();

  return 0;
}

int main6()
{
  cout << "******* main6 *******\n"
       << "\treads rectangles data from \"rectangles.txt\","
       << " calculates and displays area and perimeter on screen\n";
  cout << "*********************\n\n";
  int length = 0;
  int width = 0;
  int no = 1;
  int area = 0;
  int perimeter = 0;
  ifstream file("rectangles.txt");
  cout << "Reading length and width of rectangles from file: \n";
  while(file >> length >> width)
    {
      cout << "rectangle " << no << ": length is "
	   << length << " and width is " << width << endl;;
      area = length * width;
      perimeter = 2*(length + width);
      cout << "rectangle " << no << ": "
	   << "area is " << area << " and perimeter is "
	   << perimeter << endl;
      no++;
    }
  file.close();

  return 0;
}

int main5()
{
  cout << "******* main5 *******\n"
       << "\treads values from \"v.csv\","
       << " calculates and displays sum and average on screen\n";
  cout << "Furthermore appends to file \"prices.csv\"\n";
  cout << "*********************\n\n";
  char v[30] = "";
  float value = 0.0;
  int no = 0;
  char comma = ',';
  float sum = 0.0;
  float average = 0.0;
  ifstream rd("v.csv");
  ofstream wr("prices.csv", ios::app);
  cout << "Reading values from file: ";
  while(rd >> value >> comma)
    {
      cout << value << " ";
      no++;
      wr << value << ',';
    }
  rd.close();
  wr.close();
  cout << endl;
  cout << "Total values read are " << no << endl;
  cout << "Appended to file\n";
  return 0;
}

int main4()
{
  cout << "******* main4 *******\n"
       << "\treads values from \"values.txt\","
       << " calculates and displays sum and average on screen\n";
  cout << "*********************\n\n";
  float value = 0.0;
  int no = 0;
  float sum = 0.0;
  float average = 0.0;
  ifstream file("values.txt");
  cout << "Reading values from file: ";
  while(file >> value)
    {
      cout << value << " ";
      no++;
      sum += value;
    }
  file.close();
  cout << endl;
  float avg = sum/no;
  cout << "Total values read are " << no << endl;
  cout << "Sum is " << sum << " and Average is  " << avg << endl;

  return 0;
}

int main3()
{
  cout << "******* main4 *******\n"
       << "\treads 5 values from \"values.txt\","
       << " write these 5 values oin reverse in file \"coopy.txt\"\n";
  cout << "*********************\n\n";
  float values[5] = {0.0};
  ifstream file("values.txt");
  cout << "Reading values from file \"values.txt\": ";
  for(int i = 0; i < 5; i++)
    {
      file >> values[i];
      cout << values[i] << " ";
    }
  file.close();
  cout << endl;
 
  cout << "Writing Values in reverse to file \"copy.txt\": ";
  ofstream file2("copy.txt");
  for(int i = 0; i < 5; i++)
    {
      cout << values[4 - i] << " ";
      file2 << values[4 - i] << " ";
    }
  file2.close();
  return 0;
}

int main2()
{
  cout << "******* main2 *******\n"
       << "\treads 5 values from \"values.txt\","
       << "Calculates and displays sum and average on screen\n";
  cout << "*********************\n\n";
  float value = 0.0;
  float sum = 0.0;
  float average = 0.0;
  ifstream file("values.txt");
  cout << "Reading values from file: ";
  for(int i = 0; i < 5; i++)
    {
      file >> value;
      cout << value << " ";
      sum += value;
    }
  file.close();
  cout << endl;
  float avg = sum/5.0;
  cout << "Sum is " << sum << " and Average is  " << avg << endl;

  return 0;
}
main1()
{
  cout << "******* main2 *******\n"
       << "\treads 5 values from user, "
       << "Calculates and displays sum and average on screen\n";
  cout << "*********************\n\n";
  
  float value = 0.0;
  float sum = 0.0;
  float average = 0.0;
  cout << "Pleasse enter 5 decimal values: ";
  for(int i = 0; i < 5; i++)
    {
      cin >> value;
      cout << value << " ";
      sum += value;
    }
  cout << endl;
  float avg = sum/5.0;
  cout << "Sum is " << sum << " and Average is  " << avg << endl;

  return 0;
}

int main()
{
  int n = 0;
  cout << "Enter an integer between 1 to 9: ";
  cin >> n;
  switch(n)
    {
    case 1: n = main1(); 
      break;
    case 2: n = main2(); 
      break;
    case 3: n = main3(); 
      break;
    case 4: n = main4(); 
      break;
    case 5: n = main5(); 
      break;
    case 6: n = main6(); 
      break;
    case 7: n = main7(); 
      break;
    case 8: n = main8(); 
      break;
    case 9: n = main9(); 
      break;
     }
  return n;
}
