#include <stdio.h>
#include <stdlib.h>
#include "avl.h"


/** 
 * 
 * @brief main program to insert some nodes in the avl tree
 *        and perform some basic tests of the finding 
 *        common lowest parent of two nodes in the tree
 * 
 *
 * @return 
 */
int main()
{
  struct node *root = NULL;
 
  /* Constructing tree given in the above figure */
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
  root = insert(root, 35);
 
  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \  /  \
       10  25 35   50
  */
 
  printf("Pre order traversal of the constructed AVL tree is \n");
  preOrder(root);
 
  return 0;
}
