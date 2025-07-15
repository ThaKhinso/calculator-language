#include "evaluator.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define C_VECTOR_IMPLEMENTATION
#include "c_vector.h"
#include "lexer.h"

void helperfunction(char*** tempvalues, int *temp_index, int* char_index, Errors *code) {
	// Managing pointers in C looks really weird
	(*tempvalues)[*temp_index][*char_index] = '\0'; // Null-terminate the string
	(*temp_index)++; // Move to the next temporary value
	(*tempvalues)[*temp_index] = malloc(sizeof(char) * 103);
	if ((*tempvalues)[*temp_index] == NULL) {
		*code = LOW_MEMORY;
	}
}

// This is the function we check for syntax errors
int evaluate(const char* const input, Errors code) {
	ASTNode* root = get_main_node();
	char** tempvalues = malloc(sizeof(char*)* 10241);
	char* signs = malloc(sizeof(char) * 1024);
	int sign_index = 0;
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
		if (!isValid(input[i])) {
			printf("ERROR: Invalid character '%c' at position %d\n", input[i], i);
			return 0;
		}
		
		 // Store the character in the temporary value
		if (input[i] == ' ' || input[i] == '\n' || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
			if (input[i] == ' ') {
				continue;
			}
			if (char_index > 0) {
				//tempvalues[temp_index][char_index] = '\0'; // Null-terminate the string
				//temp_index++; // Move to the next temporary value
				//tempvalues[temp_index] = malloc(sizeof(char) * 103);
				//if (tempvalues[temp_index] == NULL) {
				//	code = LOW_MEMORY;
				//}
				helperfunction(&tempvalues, &temp_index, &char_index, &code); // Call the helper function to handle the temporary value
				char_index = 0;
				

				
			}

			switch (input[i]) {
			case '+':
				signs[sign_index] = '+';
				sign_index++;
				break;
			case '-':
				signs[sign_index] = '-';
				sign_index++;
				break;
			case '*':
				signs[sign_index] = '*';
				sign_index++;
				break;
			case '/':
				signs[sign_index] = '/';
				sign_index++;
				break;
				break;
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
	printf("Here are signs:\n");
	for (int i = 0; i < sign_index; i++)
	{
		printf("%c\n", signs[i]); // Print the signs
	}
}

// I wrote like this cause it is faster this way than already existing functions.
bool isValid(int character) {
	switch (character)
	{
	case '0':
		return true;
		break;
	case '1':
		return true;
		break;
	case '2':
		return true;
		break;
	case '3':
		return true;
		break;
	case '4':
		return true;
		break;
	case '5':
		return true;
		break;
	case '6':
		return true;
		break;
	case '7':
		return true;
		break;
	case '8':
		return true;
		break;
	case '9':
		return true;
		break;
	case '+':
		return true;
		break;
	case '-':
		return true;
		break;
	case '*':
		return true;
		break;
	case '/':
		return true;
		break;
	case '\0':
		return true;
		break;
	case ' ':
		return true;
		break;
	case '\n':
		return true;
		break;
	default:
		break;
	}
	return false;
}