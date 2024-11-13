#include <stdio.h>
#include <string.h>

#define MOD 26

// Function to convert a character to a number (A=0, B=1, ..., Z=25)
int charToNum(char ch) {
    return ch - 'A';
}

// Function to convert a number to a character (0=A, 1=B, ..., 25=Z)
char numToChar(int num) {
    return num + 'A';
}

// Function to calculate modular inverse
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

// Encrypt a single pair of characters
void encryptPair(char *pair, int key[2][2]) {
    int x1 = charToNum(pair[0]);
    int x2 = charToNum(pair[1]);

    // Apply key matrix to the character pair
    int y1 = (key[0][0] * x1 + key[0][1] * x2) % MOD;
    int y2 = (key[1][0] * x1 + key[1][1] * x2) % MOD;

    // Convert the result back to characters
    pair[0] = numToChar(y1);
    pair[1] = numToChar(y2);
}

// Decrypt a single pair of characters
void decryptPair(char *pair, int key[2][2]) {
    int x1 = charToNum(pair[0]);
    int x2 = charToNum(pair[1]);

    // Compute the determinant of the key matrix modulo 26
    int det = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % MOD;
    if (det < 0) det += MOD;  // Ensure non-negative determinant

    // Find the modular inverse of the determinant
    int detInv = modInverse(det, MOD);
    if (detInv == -1) {
        printf("Error: Matrix is not invertible\n");
        return;
    }

    // Compute the inverse matrix
    int inverseKey[2][2];
    inverseKey[0][0] = (detInv * key[1][1]) % MOD;
    inverseKey[0][1] = (-detInv * key[0][1] + MOD) % MOD;
    inverseKey[1][0] = (-detInv * key[1][0] + MOD) % MOD;
    inverseKey[1][1] = (detInv * key[0][0]) % MOD;

    // Apply the inverse matrix to decrypt the character pair
    int y1 = (inverseKey[0][0] * x1 + inverseKey[0][1] * x2) % MOD;
    int y2 = (inverseKey[1][0] * x1 + inverseKey[1][1] * x2) % MOD;

    // Convert the result back to characters
    pair[0] = numToChar(y1);
    pair[1] = numToChar(y2);
}

// Function to encrypt the entire text
void encryptText(char *text, int key[2][2]) {
    // Pad the text if it's an odd length
    if (strlen(text) % 2 != 0) {
        strcat(text, "X");  // Add 'X' to make the length even
    }
    for (int i = 0; i < strlen(text); i += 2) {
        encryptPair(&text[i], key);
    }
}

// Function to decrypt the entire text
void decryptText(char *text, int key[2][2]) {
    for (int i = 0; i < strlen(text); i += 2) {
        decryptPair(&text[i], key);
    }
}

int main() {
    // Define a key matrix
    int key[2][2] = {{3, 3}, {2, 5}};

    // Example plaintext
    char plaintext[] = "HELP";
    char ciphertext[20];

    // Encrypt the plaintext
    strcpy(ciphertext, plaintext);
    encryptText(ciphertext, key);
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    decryptText(ciphertext, key);
    printf("Decrypted Text: %s\n", ciphertext);

    return 0;
}

