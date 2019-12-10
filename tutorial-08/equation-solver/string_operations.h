
#ifndef TUTORIALS_STRING_OPERATIONS_H
#define TUTORIALS_STRING_OPERATIONS_H

#define STRING_LENGTH 256

char *deepcopy_string(char *string);
char *slice_string(char *string, int from_index, int to_index);

void replace(char *equation, char old, char new);
void swap(char *string, char char_1, char char_2);

int char_in_string(char character, char *string);
int chars_in_string(char *characters, int char_count, char *string);

#endif
