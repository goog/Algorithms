using namespace std;
#include <iostream>
#include <fstream>
#include "String.h"


//  constructor that initializes from an array of char
String::String(char *init)
{
//  find the length of the initializing array (look
//  for null byte)
   len = 0;
   while (init[len] != '\0')
      len++;

//  allocate space and copy chars into invoking obj
   theChars = new char[len];
   for (int i = 0 ; i < len ; i++)
      theChars[i] = init[i];
}


//  destructor
String::~String()
{
   if (len > 0)
      delete [] theChars;
}


//  concatenate the parm and the invoking String and
//  return the resulting String
String String::operator+(const String& two) const
{
   String result;
   int i;

//  if both Strings are empty, result is empty too
   if (len == 0 && two.len == 0)
   {
      result.len = 0;
      result.theChars = NULL;
   }
   else
   {

//  find length of the result and get space for it
      result.len = len + two.len;
      result.theChars = new char[result.len];

//  copy the invoking String into the new String
      for (i = 0 ; i < len ; i++)
	     result.theChars[i] = theChars[i];

//  copy the parm at the end of the new String
      int j = 0;
      while (j < two.len)
	  {
	     result.theChars[i] = two.theChars[j];
	     i++;
	     j++;
	  }
   }
   return result;
}


//  copy the parm into the invoking object
String& String::operator=(const String& two)
{
   if (theChars != 0)
      delete [] theChars;
   len = two.len;
   theChars = new char[len];
   for (int i = 0 ; i < len ; i++)
      theChars[i] = two.theChars[i];
   return *this;
}

const char * String::get(void)
{
	return theChars; 	
}



int main(void)
{
	String a("feiyin.com");
	cout << (a+" top93 on the China Internet market.").get() << endl;
}
