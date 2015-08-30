/**
 * @file   avl.h
 * @author  http://www.geeksforgeeks.org/
 * @date   Sun Aug 30 11:17:07 2015
 * 
 * @brief  declarations and definitions for AVL example implementation http://www.geeksforgeeks.org/avl-tree-set-1-insertion/
 * 
 * 
 */
// An AVL tree node
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};


struct node* insert(struct node* node, int key);
void preOrder(struct node *root);

