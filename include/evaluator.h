#pragma once
#include <stdbool.h>

typedef enum {
	GOOD,
	LOW_MEMORY,
	WRONG_SYNTAX,
	NO_INPUT
}Errors;


int evaluate(const char* const input, Errors code);