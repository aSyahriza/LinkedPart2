#include <iostream>
#include <cstring>

using namespace std;

#include "node.h"
#include "student.h"

void addStudent(Node<Student>* next,Node<Student>* &head,Node<Student>* &newNode);
void printList(Node<Student>* next,Node<Student>* head);
void deleteStudent(Node<Student>* next,Node<Student>* &head,int &inputId);
void average(Node<Student>* next,Node<Student>* head,float averageGpa,float numStudents);


int main() {
  
  bool loop = true;
  // Creates head of linked list.
  Node<Student>* head = NULL;
  // Char array to hold user input
  char command[10];
  char* inputName = new char[80];
  int inputId;
  float inputGpa;
  
  cout << "Enter ADD, DELETE, PRINT, AVERAGE, or QUIT" << endl;
  
  // Loops program
  while(loop == true){
    // Gets input from user
    cin.get(command,10,'\n');
    cin.clear();
    cin.ignore(99999,'\n');
    
    
    
    // Checks if the user wants to ADD students to list
    if(strcmp(command, "ADD") == 0){

      // Asks user for information of student.
      inputName = new char[80];
      cout << "Enter name of student: " << endl; 
      cin.get(inputName,80);

      cout << "Enter ID of student: " << endl;
      cin >> inputId;

      cout << "Enter GPA of student: " << endl;
      cin >> inputGpa;

      // Creates new student
      Node<Student>* tempNode = new Node<Student>(new Student());
      tempNode->val()->setName(inputName);
      tempNode->val()->setId(inputId);
      tempNode->val()->setGpa(inputGpa);
      

      addStudent(head,head,tempNode);
      cout << "Student has been added." << endl;
      cout << "\n" << endl;
      
      
    }
    // Checks if the user wants to DELETE students to list
    else if(strcmp(command, "DELETE") == 0){

      int inputId;
      deleteStudent(head,head,inputId);
      
      cout << "\n" << endl;
    }
    // Checks if the user wants to PRINT the current list
    else if(strcmp(command, "PRINT") == 0){

      
      printList(head,head);
      cout << "\n" << endl;
      
    }
    // Checks if user wants to AVERAGE student GPA
    else if(strcmp(command, "AVERAGE") == 0){

      
      float averageGpa=0;
      float numStudents=0;
      average(head,head,averageGpa,numStudents);
      cout << "\n" << endl;
      
    }
    else if(strcmp(command, "QUIT") == 0){

      // Breaks the loop, quits program
      loop = false;
      
    }    
  }
  cout << "Program ended." << endl;
  return 0;
}

void addStudent(Node<Student>* next,Node<Student>* &head,Node<Student>* &newNode){

  // if the list is empty
  if(((next==NULL)&&(next==head))){
    head = newNode;
  }
  // if the new node has a smaller id than the current head
  else if((next==head)&&(next->val()->getId()>newNode->val()->getId())){
    newNode->setNext(head);
    head = newNode;
  }
  // If the new node has a larger id than current node, or next is at the end of the list
  else{
    if(((next->getNext()==NULL))||((next->val()->getId()<newNode->val()->getId())&&(next->getNext()->val()->getId()>newNode->val()->getId()))){
      newNode->setNext(next->getNext());
      next->setNext(newNode);

    }
    // Otherwise, move onto the next node.
    else{
      next = next->getNext();
      addStudent(next,head,newNode);
    }
  }
}

void deleteStudent(Node<Student>* next,Node<Student>* &head,int &inputId){
  // Checks if list is empty
  if(((next==NULL)&&(next==head))){
    cout<< "List is empty." << endl;
    return;
  }
  
  // CHecks if this is the recursion of the function
  // Asks user for id.
  if(next==head){
    cout << "Enter ID of student: " << endl;
    cin >> inputId;
    if(next->val()->getId()==inputId){
      cout <<"Student has been deleted." << endl;
      head = next->getNext();
      delete next;
      return;
    }
  }

  // Checks if the next node is the node to be deleted
  if(next->getNext()->val()->getId()==inputId){
    cout <<"Student has been deleted." << endl;
    Node<Student>* temp = next->getNext();
    next->setNext(next->getNext()->getNext());
    delete temp;
    return;
    
  }
  // If the end of the list has been reached
  else if(next->getNext()==NULL){
    cout << "Unable to find student." << endl;
    return;
  }

  // Moves onto next node
  else{ 
    next = next->getNext();
    deleteStudent(next,head,inputId);
  }
  
}

void printList(Node<Student>* next,Node<Student>* head){
  // Checks if list is empty
  if(head == NULL){
    cout << "List is empty." << endl;
    return;
  }
  // Checks if first recursion of function
  if(next == head){
    cout << "List: " << endl;
  } 
  // Prints out student information
  cout << next->val()->getName() << ", " << next->val()->getId() << ", " << next->val()->getGpa() << endl;
  // Moves onto next node
  if(next->getNext()!=NULL){
    next = next->getNext();
    printList(next,head);
  }
}
  
void average(Node<Student>* next,Node<Student>* head,float averageGpa,float numStudents){
  // Checks if list is empty
  if(head == NULL){
    cout << "List is empty." << endl;
    return;
  }
  // Takes a total of all students gpa
  // Keeps track of how many students there are
  averageGpa+=float(next->val()->getGpa());
  numStudents+=1;

  // Checks if at the end of the list
  // Averages students gpa
  if(next->getNext()==NULL){
    averageGpa = averageGpa/numStudents;
    cout << "Average GPA: " << averageGpa << endl; 
  }
  // Moves onto next node.
  else{
    next = next->getNext();
    average(next,head,averageGpa,numStudents);
  }
}