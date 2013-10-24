#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <fstream>

class String
{
public:
  //  constructors and destructor
  String() : len(0), theChars(NULL) { }
  String(char *);
  String(String&);
  ~String();
  //  accessors
  String operator+(const String&) const;
  //  mutators
  String& operator=(const String&);
  const char * get();
private:
  char *theChars;
  int len;
};

#endif
