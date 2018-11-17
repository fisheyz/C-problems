#include <iostream>
#include <fstream>
using namespace std;

int writeFile ()
{
  ofstream myfile;
  myfile.open ("test_11.txt");
  for (int i = 0; i < 100000 ; i++){
    myfile << "100000 ";
  }
  myfile.close();
  return 0;
}

int main()
{
    writeFile();
}