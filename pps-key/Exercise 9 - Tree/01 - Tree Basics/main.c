#include <stdio.h>
#include <stdlib.h>
#include "integer_tree.h"

int tree_height(TREE t);
void print_in_order(TREE t);
void print_pre_order(TREE t);
void print_post_order(TREE t);
int total_nodes(TREE t);
int leaf_nodes(TREE t);

void free_tree(TREE *t);

int main()
{
	TREE t = NULL;
	insert_node(&t, 4);
	insert_node(&t, 2);
	insert_node(&t, 5);
	insert_node(&t, 7);
	insert_node(&t, 1);

	printf("Height = %d\n", tree_height(t));

	printf("In-order ="); print_in_order(t); printf("\n");
	printf("Pre-order ="); print_pre_order(t); printf("\n");
	printf("Post-order ="); print_post_order(t); printf("\n");

	printf("Total-nodes = %d\n", total_nodes(t));
	printf("Leaf-nodes = %d\n", leaf_nodes(t));

	//free
	free_tree(&t);

	return 0;
}

void free_tree(TREE *t)
{
	if((*t) != NULL)
	{
		if((*t)->leftptr == NULL && (*t)->rightptr == NULL && (*t) != NULL)
		{
			free(*t);
			*t = NULL;
		}
		else
		{
			free_tree(&((*t)->leftptr));
			free_tree(&((*t)->rightptr));
			free_tree(t);
		}
	}
}

int tree_height(TREE t)
{

	if(t == NULL) return 0;

	int left_height = tree_height(t->leftptr);
	int right_height = tree_height(t->rightptr);

	if(left_height > right_height)
		return 1+left_height;

	return 1+right_height;
}

void print_in_order(TREE t)
{
	if(t != NULL)
	{
		print_in_order(t->leftptr);
		printf(" %d", t->data);
		print_in_order(t->rightptr);
	}
}

void print_pre_order(TREE t)
{
	if(t != NULL)
	{
		printf(" %d", t->data);
		print_pre_order(t->leftptr);
		print_pre_order(t->rightptr);
	}
}

void print_post_order(TREE t)
{
	if(t != NULL)
	{
		print_post_order(t->leftptr);
		print_post_order(t->rightptr);
		printf(" %d", t->data);
	}
}

int total_nodes(TREE t)
{
	if(t == NULL) return 0;
	return 1 + total_nodes(t->leftptr) + total_nodes(t->rightptr);
}

int leaf_nodes(TREE t)
{
	if(t == NULL) return 0;
	if(t != NULL && t->leftptr == NULL && t->rightptr == NULL) return 1;
	return leaf_nodes(t->leftptr) + leaf_nodes(t->rightptr);
}
