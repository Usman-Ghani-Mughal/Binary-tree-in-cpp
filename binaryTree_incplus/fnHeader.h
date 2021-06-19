#include "node.h"

void find(int item,Node **par, Node **loc);
void insert(int item);
void del(int item);
void case_a(Node *par,Node *loc);
void case_b(Node *par,Node *loc);
void case_c(Node *par,Node *loc);
void preorder(Node *ptr);
void inorder(Node *ptr);
void postorder(Node *ptr);