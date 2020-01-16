/*
Author : Lior 
Task 4 of Course C
*/

#define NUM_LETTERS ((int)26)

// Converts key current character into index 
// use only 'a' through 'z' and lower case 
 #define CHAR_TO_INDEX(c) ((int)c - (int)'a') 

typedef enum {FALSE=0, TRUE=1} boolean;


typedef struct node
{
    char letter;
    struct node *children[NUM_LETTERS];
    long unsigned count;
    boolean isEndOfWord;
} node;



node *newNode();
void insert(node *root, char *letter );
void printWord(node *head,char *word, int level);
void printWordRevers(node *head,char *word, int level);
void free_(node *root);