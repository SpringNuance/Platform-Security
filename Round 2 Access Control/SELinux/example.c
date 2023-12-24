#include <stdio.h> 
#include <stdlib.h> 

FILE *f = NULL;
int main() { 
 
    char buf[255]; 

    f = fopen("tmp/myfile.txt", "r"); 
    if (f == NULL) { 
        printf("No cigar!\n"); 
        exit(1); 
    } 
    fread(buf, 258, 1, f); 
    printf("xs\n",buf); 
    
    fclose(f); 
    sleep(15);
} 