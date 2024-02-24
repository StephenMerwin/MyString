/**************************************************
* author: Stephen Merwin
**************************************************/
#include "main.h"
int main(){
    cout << "Creating my_str str1 as \"hello\".  Printing str1..." << endl;
    my_str str1 = "hello";
    cout << str1 << endl;
    
    cout << "Creating my_str str2 as copy of str1.  Printing str2..." << endl;
    my_str str2 = str1;
    cout << str2 << endl;
    cout << "Is str1 == str2? " << ((str1 == str2)?"Yes!":"No!") << endl;
    
    cout << "Please enter new value for str2: ";
    cin >> str2;
    cout << "Is str1 == str2? " << ((str1 == str2)?"Yes!":"No!") << endl;
    
    cout << "Creating my_str str3 as concat of str1 + str2.  Printing str3..." << endl;
    my_str str3 = str1 + str2;
    cout << str3 << endl;
    
    cout << "Testing my_str::reverse() on str3." << endl;
    cout << ((test_Reverse(str3))?"Success!":"Fail ;_;") << endl;
    
    cout << "The first occurance of the letter o in " << str3 << " happens at index " << str3.indexOf('o') << "." << endl;
    
    my_str pat = "wor";
    
    cout << "The first occurance of the pattern \"" << pat << "\" in \"" << str3 << "\" happens at index " << str3.indexOf(pat) << "." << endl;
    
    cout << "First letter of str3 is " << str3[0] << endl;
    
    cout << "All tests complete :)" << endl;
    
return 0;
 }
