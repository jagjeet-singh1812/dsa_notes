// Its not an linear data structure
// immediate predecessor is bacially parent node and immediate succesor is child node 
// trees are collection to entites(nodes) linked together to stimulate a hierarchy
// node which dont have any child is called leaf node or external node 
// Non leaf node are which have atleast one child or also called as internal node 
// Root is the very first node 
// path is continuous sequence of edges to the node fom root
// Ancestor node is any predecessor node on the path from root to the node 
// degree of node is the no .of child of that node 
// degree of tree max degree of node present tree
// depth of node is length from root to that node(no of edges) (level of node is also same)
// depth of root node is always zero
//decant is any succesor node on the path from that node to leaf node 
// height of node is max length(edges) till its leaf node
//binary tree is tree which  have atmost have 2 child .
// max no of nodes possible at level(height) n is 2^n.
// total max number of nodes for height h is 2^(h+1)-1 and min is h+1.
// max height is n-1 (n=no .of nodes).
// min height is log(n+1)-1(for base 2).
//full or strict binary tree is that all nodes have 0 or 2 child.
//perfect binary tree is that all leaf node are at same level and all internal node has 2 child 
//complete binary tree is all level are completely filled except the last level and last level must be left align
//degenerate tree is each  parent node has 1 child
//skewed tree i.e all node on left align or right align
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
int data;
struct tree *left;
struct tree *right;
}tree;

// tree* create()
// {
// int x;
//   tree * newnode= (tree*)malloc(sizeof(tree));
//   printf("Enter value you want to enter(-1 for no node):-\n");
//   scanf("%d",&x);
//   if(x==-1){
//     return 0;
//   }
//   else{
//   newnode->data=x;
//  printf("The left child of node %d\n",x);
//  newnode->left=create();
//  printf("The right child of node  %d\n",x);
//  newnode->right=create();
//   }
//  return newnode;
// }
tree * create(){
   int x;
  tree * root= (tree*)malloc(sizeof(tree));
  printf("Enter value of root node:-\n");
  scanf("%d",&x);
  root->data=x;
  root->left=NULL;
  root->right=NULL;
}
void main()
{ int x;
  tree * root= create();
}