#include <stdio.h>
//let me use tolower
#include <ctype.h>

// My struct keeps one letter and how many times it showed up
struct Counter {
    char letter;
    int count;
};

 // pretty much sets my alpbabet and loops the counter on every letter init at 0 which should be a
void countfun(struct Counter counts[]) {
    for (int i = 0; i < 26; i++) {
        counts[i].letter = 'a' + i;
        counts[i].count = 0; 
    }
}

// Send any chars to lowercase so I dont have to worry about any capitilazation cases 
void lowercaseFunc(struct Counter counts[], char ch) {
    char lower = tolower(ch);

    if (lower >= 'a' && lower <= 'z') {
        int index = lower - 'a';
        counts[index].count++;
    }
    // if it's not a letter, do nothing
}

int main() {
    struct Counter counts[26];
    countfun(counts);

    char ch;
    // scanf returns 1 if it successfully read a character, 
    while (scanf("%c", &ch) == 1) { //goes until null terminal is read should let me go through text file entirely
        lowercaseFunc(counts, ch);//lowercase char gets read
    }

    // print the results
    for (int i = 0; i < 26; i++) {
        printf("The letter %c was read %d times\n", counts[i].letter, counts[i].count);
        
    }
printf("wow so many char :3 very cool ");
    return 0;
}