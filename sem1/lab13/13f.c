#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

typedef unsigned set_data_elem;

enum {
 bits_per_char = 8,
 bits_per_elem = sizeof(set_data_elem) * bits_per_char,
 datalen = (1 << bits_per_char) / bits_per_elem
};

typedef struct {
 set_data_elem data[datalen];
} set;

void set_clear(set *s) {
 memset(s->data, 0, sizeof(s->data));
}

void set_insert(set *s, int c) {
 s->data[c / bits_per_elem] |= 1u << (c % bits_per_elem);
}

void set_generate(set *s, bool indicator(int)) {
 int i;
 set_clear(s);
 for(i = 0; i != 1 << bits_per_char; i++) {
 if(indicator(i)) {
 set_insert(s, i);
 }
 }
}

set set_intersection(const set *s1, const set *s2) {
 int i;
 set result;
 for(i = 0; i != datalen; i++) {
 result.data[i] = s1->data[i] & s2->data[i];
 }
 return result;
}

bool is_alpha(int c) { return isalpha(c); }
bool is_digit(int c) { return isdigit(c); }

// Является ли гласным
bool is_vowel(int c) {
    char vowels[] = "AEIOUaeiou";
    if (strchr(vowels, c) != NULL && c != '\0') {
        return 1;
    } else {
        return 0;
    }
}

// Является ли согласным
bool is_consonant(int c) {
    char consonants[] = "BCDFGJKLMNPQSTVXZHRWYbcdfgjklmnpqstvxzhrwy";
    if (strchr(consonants, c) != NULL && c != '\0') {
        return 1;
    } else {
        return 0;
    }
}


//Вариант 12
// Есть ли гласная (согласная), входящая в состав всех слов?
//--------------------------------------------
int main()
{
    set temp, vowels, consonants;
    char symbol;
    int flag = 1;
    set_clear(&temp);
    set_clear(&vowels);
    set_clear(&consonants);
    set_generate(&vowels, is_vowel);
    set_generate(&consonants, is_consonant);
    while (scanf("%c", &symbol) != EOF) {
        if ((symbol == ' ' || symbol == ',' || symbol == '\n' || symbol == '\0' || symbol == '\t') && flag == 0) {
            flag = 1;
            vowels = set_intersection(&vowels, &temp);
            consonants = set_intersection(&consonants, &temp);
            set_clear(&temp);
        } else if (is_alpha(symbol) != 0) {
            flag = 0;
            set_insert(&temp, symbol);
        }
    }
    // Гласные
    if (set_size(&vowels) > 0) {
        printf("Vovels: yes, %d\n", set_size(&vowels));
    } else {
        printf("Vovels: no\n");
    }
    // Согласные
    if (set_size(&consonants) > 0) {
        printf("Consonants: yes, %d\n", set_size(&consonants));
    } else {
        printf("Consonants: no\n");
    }
    return 0;
}
