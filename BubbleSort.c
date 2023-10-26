#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int len = 100;
int table[100]; //Unfortunately, you can't use a variable to define a table's length

void populate(){ // fills the table
    for (int i=0;i<len;++i) {
        table[i] = rand();
    }
}

void sort(){ // sorts the table
    int errors = 1;
    while (errors>0) {
        errors = 0;
        for (int i=0;i<len-1;++i) {
            if (table[i]>table[i+1]){
                ++errors;
                int temp = table[i+1];
                table[i+1] = table[i];
                table[i] = temp;
            }
        }
    }
}

void proveSort(){ // Prints the table values out
    for (int i=0;i<len;++i) {
        printf("%i: %i\n",i,table[i]); 
    }
}

int main() {
    long int START, END; //define START and END variables
    START = time(NULL);
    
    populate();
    sort();
    
    END = time(NULL);
    float ticks = clock(); //clock() returns the number of clock ticks elapsed
    
    proveSort();
    printf("Time to sort in seconds: %li\nClock ticks: %f\n",END-START,ticks); //Print out time
    
    return 0;
}
