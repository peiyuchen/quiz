#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int index;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct StackNode {
    struct TreeNode* node;
    struct StackNode* pre;
    struct StackNode* next;
} StackNode;

void flatten(TreeNode *root);
void do_recursive(TreeNode* cur, StackNode* tail);
struct TreeNode* createNode(TreeNode* parent, int index, int position);

int LEFT = 0;
int RIGHT = 1;

int main()
{
    struct TreeNode* root = createNode( NULL, 1, -1 );
    struct TreeNode* root_left_child  = createNode( root, 2, 0 );
    struct TreeNode* root_right_child = createNode( root, 5, 1 );
    createNode( root_left_child,  3, 0 );
    createNode( root_left_child,  4, 1 );
    createNode( root_right_child, 6, 1 );
    flatten( root );
}

void flatten(TreeNode *root)
{
    struct TreeNode* cur = root;
    struct StackNode* tail = NULL;

    do_recursive( root, tail );

    free(cur);
    free(tail);
}

int i = 0;

void do_recursive(TreeNode* cur, StackNode* tail)
{
    if(cur->left != NULL) {
        if(cur->right != NULL) {
            if(tail == NULL) {
                tail = malloc(sizeof(StackNode));
                tail->pre = NULL;
                tail->next = NULL;
                tail->node = cur->right;
            } else {
                tail->next = malloc(sizeof(StackNode));
                tail->next->node = cur->right;
                tail->next->pre = tail;
                tail = tail->next;
            }
        }
        cur->right = cur->left;
        cur->left = NULL;
    } else {
        if(cur->right == NULL) {
            cur->right = tail->node;
            if(tail->pre == NULL) {
                tail = NULL;
            } else {
                tail = tail->pre;
                tail->next = NULL;
            }
        }
    }
    printf("%d ", cur->index);
    cur = cur->right;
    if(cur->left != NULL || cur->right != NULL || tail != NULL) {
        do_recursive( cur, tail );
    } else {
        printf("%d \n", cur->index);
    }
}

TreeNode* createNode(TreeNode* parent, int index, int position)
{
    struct TreeNode* child = malloc(sizeof(TreeNode));
    child->index = index;
    child->left = NULL;
    child->right = NULL;
    if(parent != NULL) {
        if(position == LEFT)
            parent->left = child;
        else
            parent->right = child;
    }
    return child;
}
