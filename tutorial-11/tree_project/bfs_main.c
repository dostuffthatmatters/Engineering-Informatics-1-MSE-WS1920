
#include <stdio.h>

#include "bfs.h"

int main() {

    struct TreeNode *root = init_node('A');


    // Left: Subtree B
    add_left_child(root, 'B');

    add_left_child(root->left, 'D');
    add_right_child(root->left, 'E');

    add_left_child(root->left->left, 'F');
    add_right_child(root->left->left, 'G');
    add_left_child(root->left->right, 'H');
    add_right_child(root->left->right, 'I');

    add_left_child(root->left->right->left, 'J');

    add_left_child(root->left->right->left->left, 'K');
    add_right_child(root->left->right->left->left, 'L');

    add_left_child(root->left->right->left->left->left, 'M');
    add_right_child(root->left->right->left->left->left, 'N');


    // Right: Subtree of C
    add_right_child(root, 'C');

    add_left_child(root->right, 'O');
    add_right_child(root->right, 'P');

    add_left_child(root->right->left, 'Q');
    add_right_child(root->right->left, 'R');
    add_left_child(root->right->right, 'S');
    add_right_child(root->right->right, 'T');

    print_tree(root);

    printf("\n\n------------------------------\n\nBFS\n");
    bfs_print(root);

    return 0;
}
