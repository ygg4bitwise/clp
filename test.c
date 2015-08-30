#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "avl.h"

typedef enum{
	Clp_found = 0,
	Clp_go_left = 1,
	Clp_go_right = 2,
	Clp_not_found = 3
}clp_next_step_t;

#define NOT_FOUND -1 /*special value to init the searched key*/

/** 
 * 
 * @brief depending on the values of the current key and the provided search elements keys
 *        decide in which direction to continue the search within the balanced binary tree and if
 *        to continue search at all
 *
 * @param value_a 
 * @param value_b 
 * @param curr_key 
 *
 * @return 
 */
static clp_next_step_t get_next_clp_direction(int value_a, int value_b, int curr_key)
{
	if((value_a < curr_key) && (value_b < curr_key))
		return Clp_go_left;
	if((value_a > curr_key) && (value_b > curr_key))
		return Clp_go_right;
	if((value_a == curr_key) ||(value_b == curr_key))
		return Clp_not_found;
	return Clp_found;
}

/** 
 * 
 * @brief function to find the common lowest parent of two nodes 
 *       in the tree, described by there key values
 *
 * @param node - pointer to the current node of the tree that we traverse
 * @param value_a - one of the values describing first node
 * @param value_b - the other value describing second node
 * @param clp_key - pointer where to store the found node's key
 *
 * @return 
 * NOTE: presumption that the passed values for a and b are always present in the tree, 
 *       so there is no case of not fount element we should handle
 */
void find_clp_value(struct node *node, int value_a, int value_b, int *clp_key)
{
	clp_next_step_t next = Clp_found;

	if((node == NULL) || (clp_key == NULL))
		return;

	next = get_next_clp_direction(value_a, value_b, node->key);
	switch(next){
	case Clp_found:
		*clp_key = node->key;
		return;
	case Clp_go_left:
		*clp_key = node->key;
		return find_clp_value(node->left, value_a, value_b, clp_key);
	case Clp_go_right:
		*clp_key = node->key;
		return find_clp_value(node->right, value_a, value_b, clp_key);
	default:
		return;
	}
	
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
  int clp_key = NOT_FOUND;
 
  /* Constructing tree given in the above figure */
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
  root = insert(root, 35);
  root = insert(root, 8);
  root = insert(root, 11);
  root = insert(root, 21);
  root = insert(root, 26);
  root = insert(root, 33);
  root = insert(root, 37);
  root = insert(root, 45);
  root = insert(root, 53);
 
  /* The constructed AVL Tree would be
              30
           /     \
         20       40
        /  \     /   \
       10  25    35   50
	  / \  / \  / \   / \
	8  11 21 26 33 37 45 53
  */
  printf("\n=================================================== \n");
  printf("Pre order traversal of the constructed AVL tree is: \n");
  preOrder(root);
  printf("\n=================================================== \n");

  /*basic test for common parent of two nodes*/
  clp_key = NOT_FOUND;
  find_clp_value(root, 20, 40, &clp_key);
  assert( clp_key == 30);

  /*basic test for common parent of two nodes*/
  clp_key = NOT_FOUND;
  find_clp_value(root, 10, 25, &clp_key);
  assert( clp_key == 20);

  /*basic test for common parent of two leaf nodes*/
  clp_key = NOT_FOUND;
  find_clp_value(root, 53, 45, &clp_key);
  assert( clp_key == 50);

  /*test for common parent of leftmost and rightmost leaves - should be root*/
  clp_key = NOT_FOUND;
  find_clp_value(root, 53, 8, &clp_key);
  assert( clp_key == 30);

  /*test for common parent of parent and child - should be parent's parent*/
  clp_key = NOT_FOUND;
  find_clp_value(root, 53, 50, &clp_key);
  assert( clp_key == 40);
 
  /*test for common parent of root and one of its children - should be NOT_FOUND*/
  clp_key = NOT_FOUND;
  find_clp_value(root, 30, 40, &clp_key);
  assert( clp_key == NOT_FOUND);
 
  printf("\nTests passed OK!\n");
  return 0;
}
