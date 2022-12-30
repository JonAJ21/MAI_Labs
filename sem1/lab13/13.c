#include <string.h>	// Lab 13
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

void set_erase(set *s, int c) {
 s->data[c / bits_per_elem] &= ~(1u << c % bits_per_elem);
}

bool set_in(const set *s, int c) {
 return (s->data[c/ bits_per_elem] & (1u << c % bits_per_elem)) != 0;
}

int set_size(const set *s) {
 int i, size = 0;
 for(i = 0; i != 1 << bits_per_char; i++) {
 if(set_in(s, i)) {
 size++;
 }
 }
 return size;
}

bool set_equal(const set *s1, const set *s2) {
 int i;
 for(i = 0; i != datalen; i++) {
 if(s1->data[i] != s2->data[i]) {
 return false;
 }
 }
 return true;
}

bool set_includes(const set *s1, const set *s2) {
 int i;
 for(i = 0; i != datalen; i++) {
 if((s1->data[i] | s2->data[i]) != s1->data[i]) {
 return false;
 }
 }
 return true;
}

set set_union(const set *s1, const set *s2) {
 int i;
 set result;
 for(i = 0; i != datalen; i++) {
 result.data[i] = s1->data[i] | s2->data[i];
 }
 return result;
}

set set_intersection(const set *s1, const set *s2) {
 int i;
 set result;
 for(i = 0; i != datalen; i++) {
 result.data[i] = s1->data[i] & s2->data[i];
 }
 return result;
}

set set_difference(const set *s1, const set *s2) {
 int i;
 set result;
 for(i = 0; i != datalen; i++) {
 result.data[i] = s1->data[i] & ~(s2->data[i]);
 }
 return result;
}

set set_symmetric_difference(const set *s1, const set *s2) {
 int i;
 set result;
 for(i = 0; i != datalen; i++) {
 result.data[i] = s1->data[i] ^ s2->data[i];
 }
 return result;
}

bool is_alpha(int c) { return isalpha(c); }
bool is_digit(int c) { return isdigit(c); }

//--------------------------------------------
int main()
{
    set s1, s2;
    
    return 0;
}
