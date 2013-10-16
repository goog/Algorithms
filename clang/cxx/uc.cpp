
using namespace std;
#include <iostream>
#include <cstring>

class CStudent
{
public:
	CStudent()
	{
	}
	
	
	~CStudent()
	{
		delete name; // name is a pointer;
	}


	void setName(const char * newName)
	{
		if (newName) {
			int len = strlen(newName);
			name = new char[len+1];
			strcpy(name, newName);
		}
	}


	void setAge(const unsigned short newAge)
	{
		age = newAge;
	}


	//static char *  getName()
	char*  getName()
	{
		return name;
	}

	unsigned short getAge()
	{
		return age;
	}

	/* data */

private:
	char *name;
	unsigned short age;

};

// 
CStudent *createStudent(const char *name, const unsigned short age)
{
	CStudent *student = new CStudent;
	student->setName(name);
	student->setAge(age);
	//cout << "Name: " << student.getName() << ";Age :" << student.getAge() << endl;
	return student;
}


int main()
{
	CStudent studentA;
	CStudent *studentB;

	studentA.setName("zhangsan");
	studentA.setAge(23);
	cout << "Name: " << studentA.getName() << ";Age :" << studentA.getAge() << endl;
	
	
	studentB = createStudent("lisi", 23);
	cout << "Name: " << studentB->getName() << ";Age :" << studentB->getAge() << endl;
	delete studentB;
	return 0;
}


