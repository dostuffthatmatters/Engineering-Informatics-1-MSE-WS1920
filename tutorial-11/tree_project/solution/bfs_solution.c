
#include "../bfs.h"
#include <stdio.h>

void bfs_recursion_util(struct TreeNode *node, int depth_left);
int get_tree_height(struct TreeNode *root);

void bfs_print(struct TreeNode *node){
    int tree_height = get_tree_height(node);

    // Loop over all levels
    for (int i = 0; i<=tree_height; i++) {
        bfs_recursion_util(node, i);
    }
}

void bfs_recursion_util(struct TreeNode *node, int depth_left){
    if (depth_left == 0) {
        printf("%c ", node->value);
    } else {
        if (node->left != 0) {
            bfs_recursion_util(node->left, depth_left - 1);
        }
        if (node->right != 0) {
            bfs_recursion_util(node->right, depth_left - 1);
        }
    }
}

int get_tree_height(struct TreeNode *root) {
    int height = 0;

    if (root->left != 0) {
        height = 1 + get_tree_height(root->left);
    }

    if (root->right != 0) {
        int height_right = 1 + get_tree_height(root->right);
        if (height_right > height) {
            height = height_right;
        }
    }

    return height;
}
