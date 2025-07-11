#include "evaluator.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define C_VECTOR_IMPLEMENTATION
#include "c_vector.h"
// This is the function we check for syntax errors
int evaluate(const char* const input, Errors code) {
	char** tempvalues = malloc(sizeof(char*)* 10241);
	if (tempvalues == NULL) {
		code = LOW_MEMORY;
	}
	
	if (input == NULL || strlen(input) == 0) {
		code = NO_INPUT; // If input is NULL or empty, return false
	}
	cvector_vector_type(int) numbers_to_be_added = NULL; // Allocate memory for numbers to be added
	int temp_index = 0;
	int char_index = 0;
	tempvalues[temp_index] = malloc(sizeof(char) * 103);
	if (tempvalues[temp_index] == NULL) {
		code = LOW_MEMORY;
	}
	
	if (tempvalues[temp_index] == NULL) {
		// Handle memory allocation failure
		code = LOW_MEMORY;
	}
	for (int i = 0; i <= strlen(input); i++)
	{
		
		 // Store the character in the temporary value
		if (input[i] == ' ' || input[i] == '\n' || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
			if (char_index > 0) {
				tempvalues[temp_index][char_index] = '\0'; // Null-terminate the string
				temp_index++; // Move to the next temporary value
				tempvalues[temp_index] = malloc(sizeof(char) * 103);
				if (tempvalues[temp_index] == NULL) {
					code = LOW_MEMORY;
				}
				
				char_index = 0; // Reset character index
				if (input[i] == '+') 
				{

				}
			}
		}
		else {
			tempvalues[temp_index][char_index] = input[i]; // Store the character in the temporary value
			if (char_index >= 102) { // Check if we are about to overflow the temporary value
				tempvalues[temp_index][char_index] = '\0'; // Null-terminate the string
				temp_index++; // Move to the next temporary value
				tempvalues[temp_index] = malloc(sizeof(char) * 103);
				if (tempvalues[temp_index] == NULL) {
					code = LOW_MEMORY;
				}

				char_index = 0; // Reset character index
			}
			char_index++;
		};
	}
	for (int i = 0; i < temp_index + 1; i++)
	{
		printf("%s\n", tempvalues[i]); // Print the temporary values
	}
}