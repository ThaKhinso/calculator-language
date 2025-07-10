#pragma once

typedef struct{
    float left;
    float right;
    char operand;
    float result;
}calc_data;

typedef struct Bst_Node{
    calc_data data;
    Bst_Node* left;
    Bst_Node* right;
}Bst_Node;

calc_data* creat_calcdata(float left, float right, char operand, float result);
Bst_Node* 