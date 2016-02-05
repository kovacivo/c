#include "ivocipher_module.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

// function to cipher passed character with specific key
char cipher_char(char character, int key)
{
	// output ciphered character
	char secret_character;

  // turn upper case char into lower case 
	if (isupper(character)) {
		character = tolower(character);
	}

  // if a sum of character ord number and key pass beyond alphabet range, then start from the beginning of alphabet
	if ((character + key) > 'z') {
		secret_character = key - ('z' - character);
		return ('a' - 1 + secret_character);
	}

  // word is within alphabet range
	else {
		return (character + key);
	}
};


// function to cipher passed word
char *cipher_word(char word[])
{
  	// return ciphered word
  	// for every letter in word cipher character and put it into a newly created secret word
    
	int i = 0;
	for(; i < sizeof(word) + 1; i++) {
		word[i] = cipher_char(word[i],10);
	}

	return word;
};


// function to decipher secret character with key
char decipher_char(char secret_character, int key)
{
	// output deciphered character
	char character;

	// turn upper case char into lower case
	if (isupper(secret_character)) {
		secret_character = tolower(secret_character);
	}

  	// if a sum of character ord number and key pass beyond alphabet range, then start from the beginning of alphabet
	if ((secret_character - key) < 'a') {
		character = ('a' - secret_character) + key;
		return ('z' + 1 - character);
	} 
	else {
		return (secret_character - key);
	}
	
};


// function to decipher secret word
char *decipher_word(char secret_word[])
{
   // return deciphered word

    // for every letter in word decipher character and put it into a newly created word
	int i = 0;
    for (; i < sizeof(secret_word) + 1; i++) {
        if (secret_word[i] == ' ') {
            continue;
	}
        secret_word[i] = decipher_char(secret_word[i], 10);
    }

    return secret_word;

};

