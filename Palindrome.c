#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

int fsize (char testfile[]);               //Function for getting file size, testfile is passed as argument

int main(int argc, char *argv[])           //Main method
{
  char s[1024];   //                       //Creation of an array that can store upto 1024 characters
  strcpy(s, argv[1]);                      //strcpy function to copy char array stored in argv [1] into s.

 
 FILE * file;
    file = fopen(s, "r");              //open the array s as a readable and reference its memory location using file variable.

  int pointer1=0;                          //declaration of pointer variables and
                                           //setting their initial positions
  int pointer2= fsize(s)-1;

  while(pointer1 < pointer2) {
    fseek (file, pointer1, SEEK_SET);      //Move the pointer1 position to first character.
    char a= fgetc (file);                  //Get the character at the position of pointer and assign to variable a.
    fseek (file, pointer2, SEEK_SET);      //Move the pointer2 position to last character.
    char b= fgetc (file);                  //Get the character at the position of pointer and assign to variable b..

    if( a!= b) {                     
      printf("%s is not a palindromic file. It differs at characters %d and %d.", s, pointer1+1 , pointer2+1) ;
      exit(-1);
    }                                      //Comparing the character referenced by Pointer1 and Pointer2 and exiting the program if the characters differ.

    pointer1++;                            //Increasing position of pointer1 by 1
    pointer2--;                            //Decreasing position of pointer2 by 1.
    
  }// Repition of loop comparing characters referenced by pointers as the pointers change position.

  printf(" %s is a palindromic file.", s);
  exit (0);                                //Exiting the loop if the file is palindrome
  
}

int fsize (char filename[])                //Returns filesize when the function is called.
{
  struct stat st;
  if (stat(filename, &st)) {
    return -1;
  }

  return st.st_size;
}  
