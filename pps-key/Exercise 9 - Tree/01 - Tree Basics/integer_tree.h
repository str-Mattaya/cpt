#include <stdio.h>
#include <stdlib.h>

struct treenode{ 
	struct treenode *leftptr;
	int data;
	struct treenode *rightptr;
	};
typedef struct treenode TREENODE;
typedef TREENODE *TREE;

TREE mkEmpty(void) { return NULL;}
int isEmptyTree(TREE t) { return t == NULL; }
TREE mkTree(int x,TREE leftT, TREE rightT) {
	TREE t;
	t = malloc(sizeof(TREENODE));
	t->data = x;
	t->leftptr = leftT;
	t->rightptr = rightT;
	return t;
}
void insert_node(TREE *tp, int value) {
	/* tp is a pointer to a BST */
	if (*tp == NULL) {
		*tp = malloc(sizeof(TREENODE));
		(*tp)->data = value;
		(*tp)->leftptr = NULL;
		(*tp)->rightptr = NULL;
	}else if (value < (*tp)->data )
		insert_node(&((*tp)->leftptr), value);
	else if (value > (*tp)->data )
		insert_node(&((*tp)->rightptr), value);
	else
		printf("duplicate node\n");
}