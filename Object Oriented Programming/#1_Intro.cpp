OOPs - #1

CLASSES - Give the blueprint to build objects.
OBJECTS - Are the entities.

eg : Car Factory - Is a CLASS containing the blueprint to build cars which are the objects

Syntax:
class Name{
    //properties or attributes
    string variable;
    // Methods
    void fucntion(string newvariable){
        variable = newvariable;
    }
};

ACCESS MODIFIERS:
Private : Data and methods accessible only by class
Public : Data and methods accessible by everyone
Protected : Data can be accessible by derived class by inheritance when v can choose which private attribute to make accessible

GETTER - SETTER 
Even tho a attribute is private (eg. salary) . We can define a public method to update the salary (setter) or to print the salary (getter).

Syntax : 

//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Teacher{
	// properties  or  Attributes
private:
	double salary;

public:
	string name;
	string dept;

	// functions
	void changedept(string newdept){
		dept = newdept;
	}

	void changesalary(double s){
		salary = s;
	}

	void getsalary(){
		cout<<salary;
	}
};



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Teacher t1;
	t1.name = "CSSC";
	//t1.salary = 3000000.00; WIll throw error. Not a getter fucntion
	t1.dept = "Chemistry";

	t1.changesalary(3100000.01); // setter
	t1.getsalary(); // getter
	cout<<endl;
	t1.changedept("Organic Chem");
	cout<<t1.name << " " << t1.dept;

}







