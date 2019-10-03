#include <stdio.h> 
#include "hey.h" 
int main() 
{ 
    add(4, 6); 
  
    /*This calls add function written in myhead.h   
      and therefore no compilation error.*/
    multiply(5, 5); 
  
    // Same for the multiply function in myhead.h 
    printf("BYE!See you Soon"); 
    return 0; 
} 
