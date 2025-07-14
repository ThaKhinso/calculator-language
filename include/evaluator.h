#pragma once
#include <stdbool.h>

typedef enum {
	GOOD,
	LOW_MEMORY,
	WRONG_SYNTAX,
	NO_INPUT
}Errors;

bool isValid(int character);
int evaluate(const char* const input, Errors code);