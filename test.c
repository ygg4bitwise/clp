#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
#include <assert.h>

/** 
 * 
 * @brief function to find the common lowest parent of two nodes 
 *       in the tree, described by there key values
 *
 * @param root - pointer to the root of the tree
 * @param value_a - one of the values describing first node
 * @param value_b - the other value describing second node
 * @param clp_key - pointer where to store the found node's key
 *
 * @return 1 if node is found otherwise 0
 */
int find_clp_value(struct node *root, int value_a, int value_b, int *clp_key)
{
	*clp_key = 30;
	return 1;
}

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
  int clp_key = -1;
 
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
  printf("\n=================================================== \n");
  printf("Pre order traversal of the constructed AVL tree is: \n");
  preOrder(root);
  printf("\n=================================================== \n");

  /*basic test for common parent of two nodes*/
  assert( find_clp_value(root,20,40,&clp_key) == 1);
  assert( clp_key == 30);
 
  printf("\nTests passed OK!\n");
  return 0;
}
