
#include "composer.h"
#include <algorithm>
#include <cstring>

// Our database holds 100 composers, and no more.
const int kMaxComposers = 100;

class Database {
public:
	Database();
	//~Database();
	// manage the records
	Composer& AddComposer(std::string name, int in_yob , int rank1 = 10);
	int GetComposer(std::string name);
	
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
	
	Composer cp(name,in_yob,rank1);
	if(next_slot_ >=100)
		{
			std::cout << "array length exceed.";
			exit(1);	
		}
	composers_[next_slot_] = cp;
	next_slot_ +=1;
	return composers_[next_slot_ - 1];

}


int Database::GetComposer(std::string name)
{
	for(int i =0; i < next_slot_;i++)
		{
			if(! name.compare(composers_[i].get_name()))
				return i;
		}
	return -1;
}


void Database::DisplayAll()
{
	for(int i =0; i < next_slot_;i++)
		composers_[i].Display();
}



bool compare_on_descending_value(const Composer& first, const Composer& second)
{
	return first.getRank() > second.getRank();
}

// the effient number of num_elements
void mysort(Composer* array, std::size_t num_elements)
{
	std::sort(array, array+num_elements, compare_on_descending_value);
	std::cout << "sort completed ." << std::endl;
}


void Database::DisplayByRank()
{
	Composer pcomposers[kMaxComposers];
	memcpy(pcomposers,composers_, sizeof(composers_));
	
	// sort by the rank field
	mysort(pcomposers,next_slot_);
	for(int i =0; i < next_slot_;i++)
		pcomposers[i].Display();
		
}
