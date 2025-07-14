#include "lexer.h"

ASTNode* create_number_node(int value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_NUMBER;
    node->number = value;
    return node;
}

ASTNode* create_operator_node(char op, ASTNode* left, ASTNode* right) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_OPERATOR;
    node->op.operator = op;
    node->op.left = left;
    node->op.right = right;
    return node;
}
