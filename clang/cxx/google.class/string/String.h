#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <fstream>

class String
{
public:
  //  constructors and destructor
  String() : theChars(NULL) { }
  String(const char *);
  String(const String&);
  ~String();
  //  mutators
  String& operator=(const String&);
  const char * const get();
  friend ostream& operator << (ostream& out,String right);

  
private:
  char *theChars;
};

#endif
