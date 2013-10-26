
#include <iostream>
#include "database.h"

using namespace std;

int main() {

 Database myDB;

 // Remember that AddComposer returns a reference to the new record.
 Composer comp1 = myDB.AddComposer("Ludwig van",1770,10);
 comp1.Promote(7);

 Composer comp2 = myDB.AddComposer("Johann Sebastian", 1685,7);
 comp2.Promote(5);

 Composer comp3 = myDB.AddComposer("Wolfgang Amadeus",1756,7);
 comp3.Promote(2);

 cout << endl << "all Composers: " << endl << endl;
 myDB.DisplayAll();
 myDB.DisplayByRank();
 
}
