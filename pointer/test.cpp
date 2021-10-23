#include<iostream>
using namespace std;
void swap (char *x, char *y)    // copy of the address x and y is stored so 
{
   cout<<x << " "<<y << endl;

    x = "AAAAA";
  char *t = x;
  x = y;
  y = t;
   cout<<x << " "<<y << endl;

}

int main()
{
   char *x = "geeksquiz";
   char *y = "geeksforgeeks";
   char *t;
   swap(x, y);
   cout<<x << " "<<y;
   t = x;
   x = y;
   y = t; 
   cout<<" "<<x<< " "<<y;
   return 0;
}