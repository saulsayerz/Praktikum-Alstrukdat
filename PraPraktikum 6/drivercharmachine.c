#include "wordmachine.c"
#include <stdio.h>

int main() {
    endWord = false;
    int k;
    startWord();
    int baris = 1;
    if (tape != NULL) {
        while (!endWord) {
            for (k=0; k< currentWord.length; k++) {
                printf("%c", currentWord.contents[k]);
                if (currentWord.contents[k] == '\n') {
                    baris ++ ;
                }
            }
            printf(" ");
            advWord();
        }
    }
    printf("\nini barisnya ada sebanyak %d", baris);
    return 0;
}

