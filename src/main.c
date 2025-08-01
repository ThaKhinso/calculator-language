#define MAX_INPUT   1024

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// headers from here are custom headers we add
#include "evaluator.h"

int main() {
    char* test_string = "12 + 34 - 56";
    // make a char array with the maxium length for input to be stored and initialized it to zero.
    // Note that initializing to zero is necessary if you are using the msvc compiler or else
    // it will be undefined behaviour.
    char input[MAX_INPUT] = {0};

    // This is the welcome text.
    printf("Welcome to CalculatorLang CL! Type 'exit' to quit.\n");
	enum Errors error_code = GOOD; // Initialize the error code to NO_INPUT
    // This make an endless loop which takes input from the user.
    while (1) {
        // This line is necessary so that the input line looks different from the output line.
        printf(">> ");

        // The fgets function here read the string from somewhere, in this case it is input. And store that into the variable we created earlier.
        /*
            fgets(input, MAX_INPUT, stdin) == NULL basically means that
            if the output returned from fgets function is NULL, that
            basically means that the reading the input failed for somereason
            so that we terminate the loop
        */
        if (fgets(input, MAX_INPUT, stdin) == NULL) {
            break;
        }

        /*
            This is the place we check whether the user press entered and if the user did,
            we make the input string to terminate
        */
        input[strcspn(input, "\n")] = '\0';

        // We check if the input is exit, and exit the program.
        if(strcmp(input, "exit") == 0) {
            break;
        }

        // After all those steps, we need to validate the input to see if it match our language specifications or not.
        if (strcmp(input, "tests") == 0 ){
            printf("Error: WRONG SYNTAX\n");
        }
        else {
            // We will do our control logic after here. Right now, we print whatever the user write to the console.
            if (evaluate(input, error_code) == 0) {
                continue;
            };
            printf("You said %s\n", input);

        }


    }
}