/****************************************************************
* author: Stephen Merwin
* class: CS1D
* date: 10/09/18
* function: my string class using linked lists
****************************************************************/
#ifndef HEADER_H
#define HEADER_H

#include "my_str.h"

inline ostream& operator<<(ostream& out, my_str& str){
    str.print(out);
    return out;
}
inline istream& operator>>(istream& in, my_str& str){
    str.read(in);
    return in;
}

bool test_Reverse(my_str str){
    try{
        my_str rev = str.reverse();
        cout << "Printing reversed str3..." << endl << rev << endl;
    }catch(...){
        cout << "Reverse failed :c" << endl;
    }
    return true;
}
    
#endif
