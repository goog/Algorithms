
#include "composer.h"
#include <algorithm>
#include <cstring>

// Our database holds 100 composers, and no more.
const int kMaxComposers = 100;

class Database {
public:
	Database();
	~Database();
	
	Composer& AddComposer(std::string name, int in_yob , int rank1 = 10);
	Composer& GetComposer(std::string name);
	
	 // Display all composers in the database.
	 void DisplayAll();
	 // Sort database records by rank and then display all.
	 void DisplayByRank();

private:

	Composer composers_[kMaxComposers];
    // Track the next slot in the array to place a new record.
	int next_slot_;
};


Database::Database()
{
	next_slot_ = 0;	
}


Composer& Database::AddComposer(std::string name, int in_yob,int rank1)
{
	
	Composer cp = Composer(name,in_yob,rank1);
	if(next_slot_ >=100)
		{
			std::cout << "array length exceed.";
			exit(1);	
		}
	composers_[next_slot_] = cp;
	next_slot_ +=1;
	return composers_[next_slot_ - 1];

}

// can't return NULL;
Composer& Database::GetComposer(std::string name)
{
	for(int i =0; i < next_slot_;i++)
		{
			if (composers_[i].get_name() == name)
				return composers_[i];
		}
	throw "No found.";
}


void Database::DisplayAll()
{
	
	for(int i =0; i < next_slot_;i++)
		composers_[i].Display();

}



bool compare_on_descending_value(Composer& first, Composer& second)
{
	return first.getRank() > second.getRank();
}


void mysort( Composer* array, std::size_t num_elements)
{
	std::sort(array, array+num_elements, compare_on_descending_value);
}

void Database::DisplayByRank()
{
	Composer composers_cp[kMaxComposers];
	memcpy(composers_cp,composers_, sizeof(composers_));
	// sort by the rank field
	mysort(composers_cp,next_slot_ );
	
	for(int i =0; i < next_slot_;i++)
		composers_cp[i].Display();
		
}
