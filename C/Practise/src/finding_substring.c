#include <stdio.h>
#include <stdlib.h>

// finds a substring within a string

// Helper function to search for a word within a string
int findWord(char* str, char* word) {
    int strLen = 0, wordLen = 0;

    // Calculate lengths
    while (str[strLen] != '\0') strLen++;
    while (word[wordLen] != '\0') wordLen++;

    for (int i = 0; i <= strLen - wordLen; i++) {
        int j;
        for (j = 0; j < wordLen; j++) {
            if (str[i + j] != word[j])
                break;
        }
        // If the entire word was found
        if (j == wordLen) 
            return 1;
    }

    // Word not found
    return 0;
}

int *keyword_detection(char **input_strings, int input_count) {
    int *result = (int*)malloc(input_count * sizeof(int));

    for (int i = 0; i < input_count; i++) {
        result[i] = findWord(input_strings[i], "dQw4w9WgXcQ") + findWord(input_strings[i], "oHg5SJYRHA0");
    }

    return result;
}

int main() {
    char *emails[] = {
        "Look at this totally not suspicious link: https://youtu.be/dQw4w9WgXcQ",
        "Totally safe link: https://youtu.be/oHg5SJYRHA0",
        "Check this out: https://youtu.be/dQw4w9WgXcQ and https://youtu.be/oHg5SJYRHA0",
        "No links here",
        "Look at this: https://youtu.be/dQw4w9WgXcQ"
    };
    int email_count = sizeof(emails) / sizeof(emails[0]);

    int *results = keyword_detection(emails, email_count);

    for (int i = 0; i < email_count; i++) {
        printf("Email %d contains %d keyword(s)\n", i + 1, results[i]);
    }

    free(results);

    return 0;
}
