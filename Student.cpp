#include <iostream>
#include <cassert>
#include <string>

using std::string;
using std::cout;

class Student{
    private:
    string name_;
    float gpa_;
    int grade_;

    public:
    Student(string name, float gpa, int grade):name_(name), gpa_(gpa), grade_(grade){Validate();};
    //setter functions
    void SetName(string name);
    void SetGpa(float gpa);
    void SetGrade(int grade);

    //getter functions
    string GetName();
    float GetGpa();
    int GetGrade();

    //ValidateFunction
    void Validate(){
    (name_.length()>50)?throw std::overflow_error("Name too long"): 1;
    (gpa_<0||gpa_>4.0)?throw std::invalid_argument("GPA Value not correct"): 1;
    (grade_<1||grade_>12)?throw std::invalid_argument("Invalid grade value"): 1;
    }
};
//defining setter functions
void Student::SetName(string name){Student::name_ = name; Student::Validate();}
void Student::SetGpa(float gpa){Student::gpa_ = gpa; Student::Validate();}
void Student::SetGrade(int grade){Student::grade_ = grade; Student::Validate();}

//defining getter functions
string Student::GetName(){return Student::name_;}
float Student::GetGpa(){return Student::gpa_;}
int Student::GetGrade(){return Student::grade_;}

//testing
int main(){
    float gpa=3.3;
    Student student("Banana Borona",gpa,11);
    assert(student.GetName() == "Banana Borona");
    assert(student.GetGpa() == gpa);
    assert(student.GetGrade() == 11);
    cout<<"The student, "<<student.GetName()<<", in "<<student.GetGrade()<<"th grade, has a GPA of "<<student.GetGpa()<<"\n";
    bool catcher = false;
    try
    {
        Student wrongStudent("Banana Borona",gpa,13);
    }catch(...){
        catcher = true;
    }
    assert(catcher);
}
