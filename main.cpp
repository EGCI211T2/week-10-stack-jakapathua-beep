#include<iostream>
using namespace std;

#include "stack.h"

int main(int argc, char **argv){
    Stack s;

    int i;
    for(i=1;i<argc;i++){
        if(argv[i][0]==  'x')  s.pop();
        else s.push(atoi(argv[i]));
    }
     



   return 0;
}
