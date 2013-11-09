
const int kDefaultRanking = 10;

class Composer
{

public:
	Composer();
	Composer(std::string na,int birtherday,int rank1);
	
	void set_name(std::string na);
	std::string get_name();
	
	void set_rank(int rank1);
	int getRank () const;
	
	void set_yob(int birthday);
	int get_yob();
	
	void Promote(int increment);
	void Demote(int increment);
	
	void Display();


private:
	std::string name;
	int rank;
	int yob;
	
};

Composer::Composer()
{
	name = "Test";
	yob = 2010;
	rank = 4;
}

Composer::Composer(std::string na,int birthday,int rank1)
{
	name = na;
	yob = birthday;
	rank = rank1;
};


void Composer::set_name(std::string na)
{
	name = na;
}

std::string Composer::get_name()
{
	return name;
} 


void Composer::set_rank(int rank1 = kDefaultRanking)
{
	rank = rank1;
}

int Composer::getRank() const
{
	return rank;
} 

void Composer::set_yob(int birthday)
{
	yob = birthday;
}

int Composer::get_yob()
{
	return yob;
} 

// constraint the rank to 1-10
void Composer::Promote(int increment)
{
	rank = rank - increment;
	if(rank <1)
		rank = 1;
}

void Composer::Demote(int increment)
{
	rank = rank + increment;
	if(rank > 10)
		rank = 10;
}
	
	
void Composer::Display()
{
	std::cout << "The composer name : " << name <<" rank: " << rank << " . " << std::endl;
}
