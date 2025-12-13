#include <iostream>
#include <cstring>
#include "stack.h"
using namespace std;


using namespace std;

int main(int argc, char **argv){
    
    // Starting from i=1 because argv[0] is the program name
    for(int i = 1; i < argc; i++){
        Stack s; 
        bool valid = true; // Flag to track if the current string is valid so far

        cout << "argv " << i << " "; // Print the argument index

        for(int j = 0; j < strlen(argv[i]); j++){ 
            char c = argv[i][j];

            if(c == '[' || c == '{'){
                s.push(c);
            }
            else if(c == ']' || c == '}'){
                // Case 1: Stack is empty but we found a closing bracket
                if(s.get_size() == 0){
                    valid = false;
                    cout << "incorrect: too many closed parentheses"; // Optional specific error
                    break;
                }
                else {
                    char open = s.pop();
                    // Case 2: Mismatch check
                    if((c == ']' && open != '[') || (c == '}' && open != '{')){
                        valid = false;
                        cout << "incorrect: mismatch detected"; // Optional specific error
                        break; 
                    }
                }
            }
        }

        // Final Validation after reading the whole string
        if(valid == true){
            if(s.get_size() > 0){
                cout << "incorrect: too many open parenthesis" << endl;
            }
            else{
                cout << "correct" << endl;
            }
        }
        else{
            // If we broke out of the loop early, just print a newline or simple "incorrect"
            // purely to match the image style if specific errors aren't required:
             cout << endl; 
        }
    }

    return 0;
}
