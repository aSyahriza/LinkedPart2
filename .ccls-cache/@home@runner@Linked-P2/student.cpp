#include "student.h"

Student::Student(){
  name = new char[80];
  id = 0;
  gpa = 0;
}

Student::Student(char* pName, int pId, float pGpa){
  name = new char[80];
  id = 0;
  gpa = 0;
}

Student::~Student(){
  delete name;
}

char* Student::getName(){
  return name;
}

int Student::getId(){
  return id;
}

float Student::getGpa(){
  return gpa;
}

void Student::setName(char* pName){
  strcpy(name,pName);
}

void Student::setId(int pId){
  id = pId;
}

void Student::setGpa(float pGpa){
  gpa = pGpa;
}

/*
class Student{
  public:
    Student();
    Student(char* pName, int pId, float pGpa);
    ~Student();
    char* getName();
    int getId();
    float getGpa();

  private:
    char* name;
    int id;
    float gpa;
    
};

*/