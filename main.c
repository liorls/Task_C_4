
#include <stdio.h>
#include <stdlib.h>
#include "trie.h"
int main(int argc,char *argv[] )
{
    node* head = newNode();
// insert words from file: 
    char c;
    size_t n;
    char *word;
    n = 0;
    word = (char *)malloc(sizeof(char));
    word[n++] = '\0';

//    printf( "Enter a word: \n " );
    c = getchar();
    int i=0;
    while (c != EOF && i<1000000) {
        while ( (c != EOF && c!=' '&& c!='\t'&& c != '\n')&& i<10000000) {
            word = realloc(word, (n + 1)*sizeof(char));

            word[n-1] = c;
            word[n++] = '\0';
            c = getchar();
            i++;
        } // end while of word
        i++;
       // lowerCase(word); // to function lowerCase
   //     printf("You've entered \"%s\"\n", word);
        insert(&head, word); // insert word to the tree.
        free(word);
        c = getchar();
	if (c==EOF) break;

        n=1;
        word = (char *)malloc(sizeof(char));

        word[0] = c;

    } // end file
    char* str =(char *)malloc(sizeof(char));
    if (argc==1){
 //printf("Defult \n");
        printWord(head, str, 0);
}
    else if(argv[1][0]=='r'){
    //    printf("Reverse \n");
 	printWordRevers(head, str, 0);

}
free (str);
    free_(head);
}
