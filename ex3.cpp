#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    const char word1 = *(const char *)a;
    const char word2 = *(const char *)b;

    int length_diff = strlen(word2) - strlen(word1);
    if (length_diff != 0)
        return length_diff;

    return strcmp(word1, word2);
}

int main() {
    char sentence[1000];
    char *words[100];
    int word_count = 0;

    printf("Enter a sentence: ");
    scanf("%[^\n]", sentence);

    char *token = strtok(sentence, " ");
    while (token != NULL) {
        words[word_count++] = strdup(token);
        token = strtok(NULL, " ");
    }

    qsort(words, word_count, sizeof(char *), compare);

    printf("Sorted words:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }

    return 0;
}
