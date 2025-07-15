#pragma once

typedef enum {
    NODE_NUMBER,
    NODE_OPERATOR
} NodeType;

typedef struct ASTNode {
    NodeType type;

    union {
        int number;  // For NODE_NUMBER
        struct {
            char operator;
            struct ASTNode* left;
            struct ASTNode* right;
        } op;
    };
} ASTNode;

ASTNode* create_number_node(int value);
ASTNode* create_operator_node(char op, ASTNode* left, ASTNode* right);
ASTNode* get_main_node();
int evaluate(ASTNode* node);