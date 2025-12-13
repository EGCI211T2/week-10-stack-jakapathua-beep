#ifndef stack_h
#define stack_h
#include "node.h"
#include <iostream>
#include <cstring>
#include "stack.h"
using namespace std;

class Stack {
    NodePtr top;
    int size;
public:
    void push(char);
    char pop();
    Stack();
    ~Stack();
    int get_size();
};


void Stack::push(char x){
  NodePtr new_node=new NODE(x);
  if(new_node){
            new_node->set_next(top);
            top= new_node;
            size++;
   }
   else cout<<"Not enough memory."<<endl;
    
}

char Stack::pop(){
        NodePtr t=top;
    if(t!=NULL){
        char value;
        value=t->get_value();

        //move top to the next one
        top=top->get_next();
        
        --size;
        

        delete t;
        return value;
    
    }
   cout<<"Empty stack"<<endl;
    return 0;
}

Stack::Stack(){
    //initialize stack
    top = NULL;
    size = 0;
    
}
Stack::~Stack(){
    //delete all remaning stack (i.e. pop all) 
    cout<<"Clear the stack"<<endl;
    int n = size;
    while(n>0){
    pop();
    n--;
    }
}

int Stack::get_size(){
    return size;
}


#endif