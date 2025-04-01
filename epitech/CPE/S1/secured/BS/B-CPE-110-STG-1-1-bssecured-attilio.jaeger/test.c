#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt_decrypt_xor(const char *input, char *output, const char *key) {
    size_t input_length = strlen(input);
    size_t key_length = strlen(key);

    for (size_t i = 0; i < input_length; i++) {
        output[i] = input[i] ^ key[i % key_length];
    }
    output[input_length] = '\0';
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <plaintext>\n", argv[0]);
        return 1;
    }

    const char *key = "SecretKey";
    const char *plaintext = argv[1];
    char ciphertext[256];
    char decryptedtext[256];

    // Encryption
    encrypt_decrypt_xor(plaintext, ciphertext, key);
    printf("Encrypted: %s\n", ciphertext);

    // Decryption
    encrypt_decrypt_xor(ciphertext, decryptedtext, key);
    printf("Decrypted: %s\n", decryptedtext);

    return 0;
}
