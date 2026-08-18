#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* check if parent is NULL */
	if (parent == NULL)
		return (NULL);

	/* create the new node */
	new_node = binary_tree_node(parent, value);

	if (new_node == NULL)
		return (NULL);

	/* handle existing right-child pointer updates */
	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}

	/* connect parent to new node and return */
	parent->right = new_node;

	return (new_node);
}
