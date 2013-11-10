/*
 * bitset.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


using namespace std;
#include <iostream>
#include <bitset>
#include <climits>

int main()
{
    union
    {
         float input;   // assumes sizeof(float) == sizeof(int)
         int   output;
    }    data;

    data.input = 5.2;

    bitset<sizeof(float) * CHAR_BIT>   bits(data.output);


    cout << bits << std::endl;
    cout << "BIT 4: " << bits[4] << std::endl;
    cout << "BIT 7: " << bits[7] << std::endl;
}
