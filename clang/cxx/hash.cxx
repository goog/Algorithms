/*
 * hash.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


using namespace std;
#include <iostream>
#include <string>
#include <vector>


class Record

{
public:
	Record();
	Record(string na, string id, int rank1);
	string getKey();
	void setKey(string key);
	int getHash(int M);
	
	//friend istream& operator >>(istream& in, Record& right);
	//friend ostream& operator <<(ostream& out, Record& right);
	
private:
	string name;
	string id_number;
	int rank;
	
};

// constructor
Record::Record(string na, string id, int rank1)
{
	name = na;
	id_number = id;
	rank = rank1;
}

string Record::getKey()
{
	return name;
}


void Record::setKey(string key)
{
	name = key;
}

int Record::getHash(int M)
{
	string key = getKey();
	int index = 0;
	for(unsigned int i=0; i < key.length(); i++)
	{
		index += (int) key[i];
	}
	
	index = index % M;
	return index;
	
}

template <typename T, typename K>
class Hashmap
{
public:
	Hashmap(int tableSize);
	void insert(T newRecord);
	T* find(K key);
	void erase(T *pos);
	template <typename T1, typename K1>
	friend ostream& operator<< (ostream& out, const Hashmap<T1,K1>& right); // overload to output new types of data;
	
private:
	vector<vector<T> > table;
	
};

template <typename T, typename K>
Hashmap<T,K>::Hashmap(int tableSize)
{
	table.resize(tableSize);	
}

template <typename T, typename K>
void Hashmap<T,K>::insert(T newRecord)
{	
	int index = newRecord.getHash(table.size());
	table[index].push_back(newRecord);
}

template <typename T, typename K>
T * Hashmap<T,K>::find(K key)
{
	T tempRecord;
	tempRecord.setKey(key);
	int index = tempRecord.getHash(table.size());
	for(int i = 0; i < table[index].size(); i++)
		{
			if( table[index][i].getKey() == key )
				return &table[index][i];
		}

	return NULL;
	
}

// print a hash table
template <typename T1, typename K1>
ostream& operator << (ostream& out, const Hashmap<T1,K1>& right)
{

	for(int i =0 ; i< right.table.size();i++)
		for(int j = 0; j < right.table[i].size();j++)
		{
			out << "Bucket " << i << " ,Record " << j <<"\n" << right.table[i][j];
		}	
	return out;
}


ostream& operator << (ostream& out,Record right)
{
	out << right.getKey();
	return out;
}




int main()
{
	Hashmap<Record,string> myHash(50);
	Record stu = Record("lucy","123",2);
	
	myHash.insert(stu);
	cout << myHash << endl;
	
	return 0;
}

