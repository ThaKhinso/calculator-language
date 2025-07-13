#pragma once

typedef struct{
    float left;
    float right;
    char operand;
    float result;
    char secondary_operand;
}calc_data;

struct Bst_Node{
    calc_data data;
    struct Bst_Node* left;
    struct Bst_Node* right;
};

typedef struct Bst_Node Bst_Node;

calc_data* creat_calcdata(float left, float right, char operand, float result);
Bst_Node* Insert(Bst_Node* root, calc_data* data);