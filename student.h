#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

class Student{
  public:
    Student();
    Student(char* pName, int pId, float pGpa);
    ~Student();
    char* getName();
    int getId();
    float getGpa();
    
    void setName(char* pName);
    void setId(int pId);
    void setGpa(float pGpa);

  private:
    char* name;
    int id;
    float gpa;
    
};


#endif