#ifndef __ivocipher_module__
#define __ivocipher_module__

char cipher_char(char character, int key);
char *cipher_word(char word[]);
char decipher_char(char secret_character, int key);
char *decipher_word(char secret_word[]);

#endif
