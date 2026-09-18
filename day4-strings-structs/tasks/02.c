#include <limits.h>
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 4096


size_t split_words(char *line, char *words[], size_t max_words) {
    size_t word_count = 0;
    char *last_word_idx = line;
    while (*line != '\0' && word_count < max_words) {
        if (*line == ' ' || *line == '\n' || *line == '\t') {
            *line = '\0';
            words[word_count++] = last_word_idx;
            last_word_idx = line+1;
        }
        line++;
    }
    return word_count;
};

int main() {
    char line[4096];
    while (fgets(line, sizeof line, stdin) != NULL) {
        char *longest = NULL;
        size_t longest_len = 0;
        // printf(" %s\n", line);
        char *words[MAX_WORDS];
        size_t word_count = split_words(line, words, MAX_WORDS);

        if (strlen(line) > 0) {
            for (size_t i = 0; i < word_count; i++) {
                size_t len = strlen(words[i]);
                printf(" слово: %s (%ld)\n", words[i], len);
                if (longest_len < len) {
                    longest = words[i];
                    longest_len = len;
                }
            }

            printf(" самое длинное: %s (%ld)\n", longest, longest_len);
        } else {
            printf(" слов нет\n");
        }
    }

    return 0;
}
