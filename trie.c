#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include <stdbool.h>

node *newNode()
{
    node *Pnode = NULL;
    Pnode = (node *)malloc(sizeof(node));
    if (!Pnode)
        printf("Memory allocation error\n");
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        Pnode->children[i] = NULL;
    }
    Pnode->isEndOfWord = FALSE;
    Pnode->count = 0;

    return Pnode;
}

void insert(node *root, char *letter)
{
    int index;
    if (*letter != '\0' && *letter != ' ' && *letter != '\n' && *letter != '\t')
    {
        node *p = root;
        while (*letter != '\n' && *letter != '\t' && *letter != ' ' && *letter != '\0')
        {
            // if ((*letter >= 'a' && *letter <= 'z') || (*letter >= 'A' && *letter <= 'Z'))
            // {
                index = CHAR_TO_INDEX(*letter);

                if (p->children[index] == NULL)
                {
                    p->children[index] = newNode();
                    p->children[index]->letter = *letter;
                }
                else
                { //next node
                    p = p->children[index];
                }
                letter++;
            }
            p->count++;
            p->isEndOfWord = TRUE;
        }
    }

void printWord(node *head, char *word, int index)
{
    node *p = head;
    if (p->isEndOfWord == TRUE)
    {
        word[index] = '\0';
        printf("%s\t%ld\n", word, p->count);
    }
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        if (p->children[i])
        {
            word[index] = i + 'a';
            printWord(p->children[i], word, index++);
        }
    }
}

void printWordRevers(node *head, char *word, int index)
{
    node *p = head;
    if (p->isEndOfWord == TRUE)
    {
        word[index] = '\0';
        printf("%s\t%ld\n", word, p->count);
    }
    for (int i = NUM_LETTERS - 1; i >= 0; i--)
    {
        if (p->children[i])
        {
            word[index] = i + 'a';
            printWordRevers(p->children[i], word, index++);
        }
    }
}

void free_(node *root)
{
    node *p = root;
    if (p->isEndOfWord == TRUE)
    {
        free(p);
    }
    else
    {
        for (int i = 0; i < NUM_LETTERS; i++)
        {
            if (p->children[i] != NULL)
            {
                free_(p->children[i]);
                free(p);
            }
        }
        free(p);

    }
    
}
