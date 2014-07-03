
/*
  bforder.c
  CSE305
  Thomas Waring III
  Breadth-first Tree Traversal Problem
*/  


#include <stdlib.h>
#include <stdio.h> 

typedef struct treenode {		// binary tree 
        int value; 
        struct treenode *left; 
        struct treenode *right; 
        } TREE; 

typedef struct tlist { 			// list of binary trees
        TREE *tree; 
        struct tlist *next; 
        } TLIST; 
  
TLIST* cons(TREE *tr, TLIST *tlist) {	// new list: tr is head, tlist is tail
     TLIST *n = (TLIST*) malloc(sizeof(TLIST));         
     n->tree = tr; 
     n->next = tlist; 
     return n;
}
  
TREE* newTree(int v) { 		// new tree: v at root, left = right = NULL
	TREE *tr = (TREE*) malloc(sizeof(TREE));         
	tr->value = v;
	tr->right = tr->left = NULL; 
        return tr;
}

void insert(TREE *tr, int v) { // insert v into binary search tree tr
  if (v == tr->value) return;

  if (v < tr->value)  
	if (tr->left == NULL) 
	     tr->left = newTree(v);
	else insert(tr->left, v);
  else 
	if (tr->right == NULL) tr->right = newTree(v);
	else insert(tr->right, v);
	   
}//end insert


TLIST* append(TLIST *l1, TLIST *l2) { // new list: l1 followed by l2 
  TLIST *n; 
  if (l1 == NULL) return l2;
  else return cons(l1->tree,append(l1->next, l2));
}// append


void bforder(TREE *tr){   	     // breadth-first traversal of tree tr
     void bfo(TLIST *tl) {
        while(tl != NULL) {
          TREE* tr2 = tl->tree;
     	  printf("%d ", tr2->value);  
          TLIST* tl2;
          if (tr2->right != NULL) 
		tl2 = cons(tr2->right, NULL);
          else  tl2 = NULL;
          if (tr2->left != NULL) tl2 = cons(tr2->left, tl2);
          tl = append(tl->next, tl2);
        }
    }
    bfo(cons(tr,NULL));
}//end bforder 


//tree should print in order of value
int main(){ 
    TREE *root = newTree(100);
    insert(root,50); 
    insert(root,150); 
    insert(root,200); 
    insert(root,125); 
    insert(root,175); 
    insert(root,250); 
    insert(root,25); 
    insert(root,75); 
    bforder(root); printf("\n"); 
} 
  
