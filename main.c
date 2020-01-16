
#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

int main(int argc, char *argv[]){

	node *Root = newNode(); //Root of trie
	char letter;
	char *word = NULL; //word we want to insert
	word = (char *)malloc(2 * (sizeof(char))); //initialize to size 2
	*word = 0; //get rid of garbage
	*(word+1) = 0; //get rid of garbage
	int index = 0; //index of word
	int word_length=0; 
	int max_length = 0; //save max word -> needed for print functions
	

	while ((scanf("%c", &letter)) == 1){ // gets each word and check if something went wrong with scanf function
		if ((letter == '\n') || (letter == '\t') || (letter == '\0') || (letter == ' ') || (letter == ',')){ //end of word
			
			if(word_length > max_length)
				max_length = word_length;

			word[index] = '\0';
			index = 0;
			insert(Root, word);
			free(word); //finished with specific word after insert
			word = (char *)malloc(2 * (sizeof(char))); //initialize new word
			*word = 0;
			*(word+1) = 0;
			word_length = 0;
			continue;
		}

		if (letter >= 'A' && letter <= 'Z'){ //turns uppercase to lowercase
			letter = letter + 32;
		}
		if(letter >= 'a' && letter <= 'z'){ //only if its a letter it gets added to 'word'
		word[index] = letter;
		index++;
		word = realloc(word, index + 2);
		for(int i=index;i<index+2;i++){
			*(word+index) =0;
		}
		word_length++;
		}
	}
			insert(Root, word);
			free(word);
			word = (char *)malloc(2 * (sizeof(char)));
			*word = 0;
			*(word+1) = 0;
			word_length = 0;
			
	free(word);

	char w[max_length];

	if (argc == 1) // prints a -> z
	{
		int i=0;
		printWord(Root,  w, i);
	} 
	
	else if (argc == 2) // prints z -> a
	{

		int i=0;
		printWordRevers(Root, w, i);
	}

	 free_(Root);

	return 0;
}