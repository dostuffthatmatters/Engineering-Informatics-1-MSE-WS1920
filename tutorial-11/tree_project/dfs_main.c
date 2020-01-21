
#include <stdio.h>

#include "dfs.h"

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

    printf("\n\n------------------------------\n\nPreorder DFS\n");
    printf("A B D F G E H J K M N L I C O Q R P S T (Solution)\n");
    preorder_dfs_print(root);

    printf("\n\nIn-Order DFS\n");
    printf("F D G B M K N J L H E I A Q O R C S P T (Solution)\n");
    in_order_dfs_print(root);

    printf("\n\nPostorder DFS\n");
    printf("F G D M N K L J H I E B Q R O S T P C A (Solution)\n");
    postorder_dfs_print(root);

    return 0;
}
