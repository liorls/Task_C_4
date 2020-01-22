
#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

int main(int argc, char *argv[]){

	node *Root = newNode(); //root of trie
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
		word = realloc(word, index + 2); // +2 beacuse '\0'
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


// #include <stdio.h>
// #include <stdlib.h> /* malloc, realloc */
// #include <string.h> /* strcmp */
// #include "trie.h"

// #define BLOCK_SIZE 50
// #define REVERSE_LETTER "r"
// #define SPACE_CHAR ' '
// #define EXIT_SUCCESS 0
// #define EXIT_FAILURE 1
// #define NULL_TERMINATOR '\0'
// #define NEW_LINE_SIGN '\n'

// static int ParseWords(node *trie, const char *line);

// int main(int argc, char *argv[])
// {
// 	// validate args
// 	if(argc > 2 || (argc == 2 && strcmp(argv[1], REVERSE_LETTER)))
// 	{
// 		fprintf(stderr, "wrong argument num/usage. usuage: no args or one arg 'r' \n");
// 		return EXIT_FAILURE;
// 	}

// 	node* trie = newNode();
// 	if(!trie)
// 	{
// 		fprintf(stderr, "failed to create trie\n");
// 		return EXIT_FAILURE;
// 	}

// 	char *userStr = (char*) malloc (BLOCK_SIZE);
// 	// reads from standard input dynamically
// 	if(!userStr)
// 	{
// 		fprintf(stderr, "allocation for input string failed\n");
// 		TrieDestroy(&trie);
// 		return EXIT_FAILURE;
// 	}

// 	unsigned int index = 0, userStrLength = BLOCK_SIZE;
// 	/* dynamically read from user input (unknown size) */
// 	char c;
// 	while((c = (char)getchar()) != NEW_LINE_SIGN)
// 	{
// 		userStr[index++] = (char)c;
// 		if(index >= userStrLength)
// 		{
// 			userStrLength += userStrLength; //double the string length
// 			userStr = (char*) realloc (userStr, userStrLength);
// 			if(!userStr)
// 			{
// 				fprintf(stderr, "allocation for input string failed\n");
// 				TrieDestroy(&trie);
// 				return EXIT_FAILURE;
// 			}
// 		}
// 	}
// 	userStr[index] = NULL_TERMINATOR;

// 	// parse into words and insert to the Trie one by one
// 	if (ParseWords(trie, userStr) != EXIT_SUCCESS)
// 	{
// 		fprintf(stderr, "an error occurred during word parsing");
// 		free(userStr);
// 		TrieDestroy(&trie);
// 		return EXIT_FAILURE;
// 	}

// 	TraverseOrder order = (argc == 2) ? REVERSE_ORDER : NORMAL_ORDER;
// 	if (printWord(trie, order, strlen(userStr)) != TRIE_SUCCESS)
// 	{
// 		fprintf(stderr, "an error occurred during Trie printing");
// 		free(userStr);
// 		TrieDestroy(&trie);
// 		return EXIT_FAILURE;
// 	}

// 	free(userStr);
// 	TrieDestroy(&trie);
// 	return EXIT_SUCCESS;
// }

// /**
//  * this funcs parse a line of input into seperate words and inserts to the Trie one by one
//  * @param trie Trie to be insert to
//  * @param line the line recieved from the user standard input
//  */
// static int ParseWords(node *trie, const char *line)
// {
// 	unsigned long bufferEnd = strlen(line) + 1, i, currentWordCounter = 0;
// 	char *currentWord = (char*) calloc (1, strlen(line) + 1);
// 	if(!currentWord)
// 	{
// 		fprintf(stderr, "an error occurred during Trie printing");
// 		return EXIT_FAILURE;
// 	}

// 	for(i = 0; i < bufferEnd; i++)
// 	{
// 		// if reached end of word: insert into trie
// 		if(line[i] == SPACE_CHAR || line[i] == NULL_TERMINATOR)
// 		{
// 			currentWord[currentWordCounter] = NULL_TERMINATOR;
// 			if(insert(trie, currentWord) != TRIE_SUCCESS)
// 			{
// 				fprintf(stderr, "error: failed to insert word");
// 				free(currentWord);
// 				return EXIT_FAILURE;
// 			}
// 			currentWordCounter = 0;
// 		}
// 		else
// 		{
// 			currentWord[currentWordCounter] = line[i];
// 			currentWordCounter++;
// 		}
// 	}
// 	free(currentWord);
// 	return EXIT_SUCCESS;
// }