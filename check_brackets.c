#include <string.h>
#include "stack.h"

int main() {
    int max_line = 105000;
	char input_buffer[max_line];
	int input_len = 0;

	fgets(input_buffer, max_line, stdin);
	input_buffer [strcspn (input_buffer, "\r\n")] = '\0';  //remove end-of-line characters

    input_len = strlen(input_buffer);
    printf("%d characters were read.\n",input_len);
    // printf("The input was: '%s'\n",input_buffer);
	fflush(stdout);
    Stack * opening_brackets_stack = createStack(max_line);
    for (int position = 0; position < input_len; ++position) {
        char next = input_buffer[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket item;
            // Process opening bracket, write your code here
            if (next == '(') {
                item.type = ROUND;
            }
            else if (next == '[') {
                item.type = SQUARE;
            }
            else {
                item.type = CURLY;
            }
            item.position = position;
            push(opening_brackets_stack, item);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if (isEmpty(opening_brackets_stack)) {
                printf("%d\n", position + 1);
                return 0;
            }
            
            Bracket item;
            if (next == ')') {
                item.type = ROUND;
            }
            else if (next == ']') {
                item.type = SQUARE;
            }
            else {
                item.type = CURLY;
            }

            Bracket top = pop(opening_brackets_stack);
            if (item.type != top.type) {
                printf("%d\n", position + 1);
                return 0;
            }
        }
    }

    // Printing answer, write your code here
    Bracket bottom;
    if (!isEmpty(opening_brackets_stack)) {
        while (!isEmpty(opening_brackets_stack)) {
            bottom = pop(opening_brackets_stack);
        }
        printf("%d\n", bottom.position + 1);
        return 0;
    }
	printf("Success\n");
    return 0;
}
