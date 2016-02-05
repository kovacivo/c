#include <stdio.h>
#include "ivocipher_module.h"

int main()
{
	// this program wants to test caesar cipher
	printf("Sample cipher/decipher program to test crypto functions for Caesar cipher.\n");
	printf("The key used is of value: 10.\n");

	printf("Cipher letter 's' to get: %c", cipher_char('s', 10)); 
	printf("\nDecipher letter 'c' to get: %c\n", decipher_char('c',10));
	printf(" ------------------------- \n");

    char secret_word[] = "hello";
	printf("Cipher word 'hello' to get: %s\n", cipher_word(secret_word));
	char secret_word2[] = "rovvy";
	printf("Decipher word 'rovvy' to get: %s\n", decipher_word(secret_word2));

	//std::cout << " ------------------------- " << std::endl;
	printf("Try it out together - using two function at once - for character 'e' first: %c\n", decipher_char(cipher_char('e',10), 10));
    char secret_word3[] = "este";
	printf("Try it out together - using two function at once - for word 'este' then: %s\n", decipher_word(cipher_word(secret_word3))); 
    char secret_word4[] = "hovno";
	printf("Try it out together - using two function at once - for word 'hovno' then: %s\n", decipher_word(cipher_word(secret_word4))); 

	char slovo[] = "prdmakovy";
	printf("Decipher word 'slovo' to get: %s\n", decipher_word(slovo));

	return 0;
}
