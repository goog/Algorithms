/*
 * classAndStruct.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


using namespace std;
#include <iostream>

//the class X is equivalent to the structure Y:
class X {

  // private by default
  int a;

public:

  // public member function
  int f() { return a = 5; };
};

struct Y {

  // public by default
  int f() { return a = 5; };

private:

  // private data member
  int a;
};

struct XX {
 int a;
 int b;
};

class XX obj_X;

int main() {
  obj_X.a = 0;
  obj_X.b = 1;
  cout << "Here are a and b: " << obj_X.a << " " << obj_X.b << endl;
}

