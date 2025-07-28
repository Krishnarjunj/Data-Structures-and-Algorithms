ECAPSULATION
1. Its just wrapping up of data attributes and methods inside a class.
2. Helps in hiding data with use of Private access modifier.

CONSTRUCTOR
1. A special method invoked automatically during the time of object creation.
2. If no constructor is made in a class. The complier Automatically makes one for the user.
3. But, the programmer can also build a constructor.
4. A class by itself does not use much memory. Its the object which is made by the constructor which occupies memory.
Uses and Rules:
1. Constructor is used for initialization. 
2. Constructor has no return mode. See the Syntax below
class Teacher{
  private:
    double salary;
  public:
    string name;
    Teacher(){ // Constructor
        cout<<"I am a constructor";
        salary = 10000; // initialization
    }
};
3. Constructor is always Public.
4. Constructor is called automatically at the time of object creation only once.
5. Has the same name as the class.

                  -----> Parameterized
Constructor -----<-----> Non- Parameterized
                  -----> Copy

Non - Parameterized constructor is being used in the syntax above. Where we passed no value.
Parameterized Constructor :
public:
  Teacher(string n, string d, double sal){
      name = n;
      dept = d;
      salary = sal;
}

int main(){
      Teacher t1("CSSC" , "CHEM", "1000.00");
}

6. There can be multiple constructors of various types which can be used in anyway inside int main. This phenomenon of having various constructor types is called as constructor overloading. This is one example 
of polymorphism.
