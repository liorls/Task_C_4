#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

typedef struct node
{
    char letter;
    struct node *children[NUM_LETTERS];
    long unsigned count;
    boolean isEndOfWord;
} node;


node* newNode(){
    node *Pnode = NULL;
    Pnode = (node*)malloc(sizeof(node));
    if(!Pnode)
       printf("Memory allocation error\n");
    for (int i = 0; i < NUM_LETTERS; i++){
        Pnode->children[i] = NULL;
    }
    Pnode->isEndOfWord = FALSE;
    Pnode->count = 0;

    return Pnode;
}

void insert(node *root, char *letter ){
    int i;
    int index;
    int length = strlen(letter);
    node *p = root;
    for(i=0; i<length; i++){
        index = CHAR_TO_INDEX(letter[i]);
        if(!p->children[index]){
            p->children[index] = newNode();
           p = p->children[index];
        }else {
            p = p->children[index];
    }
    p->count ++;
    p->isEndOfWord = TRUE;
}
}

void printWord(node *head,char *word, int level){
   node *p = head;
    if (p->isEndOfWord == TRUE){
        word[level] = '\0';
        printf("%s\t%ld\n", word, p->count);
    }
    for (int i = 0; i < NUM_LETTERS; i++){
        if(p->children[i]){
            word[level] = i + 'a';
            printWord(p->children[i], word, level+1);
        }
    }
}
 


void printWordRevers(node *head,char *word, int level){
    node *p = head;
    if (p->isEndOfWord == TRUE){
        word[level] = '\0';
        printf("%s\t%ld\n", word, p->count);
    }
    for (int i = NUM_LETTERS-1; i >= 0; i--){
        if(p->children[i]){
            word[level] = i + 'a';
            printWordRevers(p->children[i], word, level+1);
        }
    }
}

void free_(node *root){
    node *p = root;
    if(p->isEndOfWord == TRUE){
        free(p);
    }else{
        for (int i = 0; i < NUM_LETTERS; i++){
            if(p->children[i] != NULL){
            free_(p->children[i]);
            free(p);

            }
        }
        
    }
    
}


int main(int argc, char *argv[]){
    
    node *trie = newNode();
    insert(trie, "abc");
    insert(trie, "bac");
    insert(trie, "bac");
    insert(trie, "abc");
    insert(trie, "ddd");
    insert(trie, "aaa");
    // insert(trie, "ala");
    // insert(trie, "alad");
    // insert(trie, "aladin");
    char str[NUM_LETTERS];
   printWord(trie, str, 0);
      free_(trie);
    printf("\n");
    printWordRevers(trie, str, 0);
    free_(trie);
    return 0;
}
