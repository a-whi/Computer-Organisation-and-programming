/*
1. Count the number of vowels and consonants in all words.
2. Count the number of times each alphabet appears in all words. What is the most commonly
used alphabet? How about least commonly used?
3. Sort the alphabet counts by decreasing order.
4. Print out the sorted histogram from above. For example:
E ************ 
A *********
S ******
*/
#include <stdio.h>
#include <ctype.h>

int main() {
    char sentence[1000]; // Assuming sentence length would not exceed 1000 characters
    int frequency[26] = {0}; // frequency of each alphabet (case insensitive)
    int vowels = 0;
    int consonants = 0;

    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin); // read input
    // could also use scanf("%999s", sentence);

    for (int i = 0; sentence[i] != '\0'; i++) {
        if (isalpha(sentence[i])) { // check if character is an alphabet
            char c = tolower(sentence[i]); // convert to lowercase for case insensitive comparison
            frequency[c-'a']++; // increment frequency count
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    // Print sorted histogram
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (frequency[i] < frequency[j]) {
                int temp = frequency[i];
                frequency[i] = frequency[j];
                frequency[j] = temp;
            }
        }
        if (frequency[i] > 0) {
            printf("%c ", i+'A');
            for (int j = 0; j < frequency[i]; j++) {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}
