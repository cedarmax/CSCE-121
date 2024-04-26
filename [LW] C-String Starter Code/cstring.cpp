#include <iostream>
#include "cstring.h"

unsigned int length(char str[]) {
  // returns the length of the string including zero (0)
  int i;
  unsigned int length = 0;
  for (i = 0; str[i] != '\0'; ++i) {
  	length += 1;
  }
  return length;
}

unsigned int find(char str[], char character) { 
// returns 
// - the index of the first occurence of character in str 
// - the size if the character is not found 
	int maxLen=length(str); 
	for(int x;x<maxLen;x++){ 
		if(str[x]==character) { 
	return x; 
	} 
} 
return maxLen; 
} 

bool equalStr(char str1[], char str2[]) { 
	if(length(str1)!=length(str2)){ 
	return false; 
} 

bool equal=true; 
int maxLen=length(str1); 

for(int x=0;x<maxLen;x++){ 
if(str1[x]==str2[x]){ 
equal=true; 
} 
else{ 
equal=false; 
break; 
} 
} 
return equal; 
} 
