#include<stdio.h>

/*
Find time complexity for the following examples:

Ex [1]:


int i;
for ( i = 1 to n)
print("Hello World");



answer: O(n)

---------------------------------

Ex [2]:


int i;
for( i = 1 to n)
    for( j = 1 to n)
        print("Hello World");


answer: O(n^2)

---------------------------------

Ex [3]:


int i;
for(i = 1; i < n; i = i*2)
    print("Hello World");


answer: O( log n )
              2

---------------------------------

Ex [4]:


int i:
for (i = 1; i < n; i = i/5)
    print("Hello World");


answer: O( log n )
              5

---------------------------------

Ex [5]:


int i;
for( i = 1; i < n^3; i = i*5)
    print("Hello World");


answer: O( log n^3 )
              5

---------------------------------

Ex [6]:


int i;
for(i = 1; i^2 <= n; i++ )
    print("Hello World");


answer: O{ Root(n) }

---------------------------------

Ex [7]:

int i = 1,k = 1:
while(k <= n){
    i++;
    k=k+i;
    print("Hello World");
}

answer: O{ Root(n) }


*/
