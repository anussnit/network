#include <stdio.h>
#include <string.h>

int main() {
  char str[100], rev_string[100];

  printf("Enter a string: ");
  scanf("%s", str);

  strcpy(rev_string, str);
  strrev(rev_string);

  if (strcmp(str, rev_string) == 0) {
    printf("%s is a palindrome.\n", str);
  } else {
    printf("%s is not a palindrome.\n", str);
  }

  return 0;
}


/*
indrome string program in cC
#include <stdio.h>
#include <string.h>
 
int main()
{
    char s[1000];  
    int i,n,c=0;
 
    printf("Enter  the string : ");
    gets(s);
    n=strlen(s);
 
    for(i=0;i<n/2;i++)  
    {
    	if(s[i]==s[n-i-1])
    	c++;
 
 	}
 	if(c==i)
 	    printf("string is palindrome");
    else
        printf("string is not palindrome");
 
 	 
     
    return 0;
}
*/