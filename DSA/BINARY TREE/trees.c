// Its not an linear data structure
// immediate predecessor is bacially parent node and immediate succesor is child node
// trees are collection to entites(nodes) linked together to stimulate a hierarchy
// node which dont have any child is called leaf node or external node
// Non leaf node are which have atleast one child or also called as internal node
// Root is the very first node
// path is continuous sequence of edges to the node fom root
// Ancestor node is any predecessor node on the path from root to the node
// degree of node is the no .of child of that node
// degree of tree is max degree of node present in tree
// depth of node is length from root to that node(no of edges) (level of node is also same)
// depth of root node is always zero
// decant is any succesor node on the path from that node to leaf node
// height of node is max length(edges) till its leaf node
// binary tree is tree which  have atmost have 2 child .
// max no of nodes possible at level(height) n is 2^n.
// total max number of nodes for height h is 2^(h+1)-1 and min is h+1.
// max height is n-1 (n=no .of nodes).
// min height is log(n+1)-1(for base 2).

// full or strict binary tree is that all nodes have 0 or 2 child.
// perfect binary tree is that all leaf node are at same level and all internal node has 2 child
// complete binary tree is all level are completely filled except the last level and last level must be left align
// degenerate tree is each  parent node has 1 child
// skewed tree i.e all node are on left align or right align

// NOTE:--->(binary trees inoder traversal is always sorted array in ascending order only.)

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{

  int data;
  struct node *left;
  struct node *right;

} tree;

tree *create(int x)
{
  tree *root = (tree *)malloc(sizeof(tree));
  // printf("Enter value of node:-\n");
  // scanf("%d",&x);
  root->data = x;
  root->left = NULL;
  root->right = NULL;
}

void *ASSIGNATION(tree *root, tree *l, tree *r)
{
  root->left = l;
  root->right = r;
}

// tree* insertion(int val, tree *root)
// {
//   tree *prev = NULL;
//   if (root == NULL)
//   {
//     return;
//   }

//   if (root->data = val)
//   {
//     printf("THE DATA CANNOT BE ENTERED AS ALREADY PRESENT\n");
//     return;
//   }
//   if (val > root->data)
//   {
//     // root = insertion(root->right,val);
//     root= root->right;
//   }
//   else
//   {
//     // root = insertion(root->left,val);
//     root= root->right;
//   }

//   if(prev->data<val){
//     prev->right= val;
//   }
//   else
//   {
//     prev->left= val;
//   }
//   return root;
// }

void insertion(tree *root, int val)
{
  tree *prev = NULL;
  while (root != NULL)
  {
    prev = root;

    if (val == root->data)
    {
      printf("the value cannot be entered\n");
      return;
    }

    else if (val < root->data)
    {
      root = root->left;
    }

    else
    {
      root = root->right;
    }
  }
  tree *new = create(val);
  if (prev->data > val)
  {
    prev->left = new;
  }
  else
  {
    prev->right = new;
  }
}

tree *inOrderPredecessor(tree *root)
{
  root = root->left;
  while (root->right != NULL)
  {
    root = root->right;
  }
  return root;
}

struct node *deleteNode(struct node *root, int value)
{
  struct node *iPre=NULL;
  // corner cases
  if (root == NULL)
  {
    return NULL;
  }
  if (root->left == NULL && root->right == NULL)
  {
    free(root);
    return NULL;
  }

  // searching for the node to be deleted
  if (value < root->data)
  {
    root->left=deleteNode(root->left, value);
  }
  else if (value > root->data)
  {
    root->right=deleteNode(root->right, value);
  }
  // deletion strategy when the node is found
  else
  {
    iPre = inOrderPredecessor(root);
    root->data = iPre->data;
    deleteNode(root->left, iPre->data);
  }
}

void preorder(tree *root)
{
  if (root != NULL)
  {
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(tree *root)
{
  if (root != NULL)
  {
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
  }
}

void inorder(tree *root)
{

  if (root != NULL)
  {

    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
  }
}

// Here tree is
//           4
//         /   \
//       1       6
//     /   \
//   2       3

void main()
{
  int choice, option,x;
  tree *root = create(4);
  tree *p1 = create(1);
  tree *p2 = create(3);
  tree *p3 = create(2);
  tree *p4 = create(6);
  // root->left=p1;
  // p1->left=p3;
  // p1->right=p2;
  // root->right=p4;

  ASSIGNATION(root, p1, p4);
  ASSIGNATION(p1, p3, p2);

  do
  {

    printf("ENTER 1 FOR INORDER TRAVERSAL:-\n");
    printf("ENTER 2 FOR PREORDER TRAVERSAL:-\n");
    printf("ENTER 3 FOR POSTORDER TRAVERSAL:-\n");
    printf("ENTER 4 FOR INSERING ELEMENT:-\n");
    printf("ENTER 5 FOR DELETION ELEMENT:-\n");

    printf("ENTER YOUR OPTION:-\n");
    scanf("%d", &option);
    switch (option)
    {

    case 1:
      inorder(root);
      printf("\n");
      break;

    case 2:
      preorder(root);
      printf("\n");
      break;

    case 3:
      postorder(root);
      printf("\n");
      break;

    case 4:
      printf("before:-\n");
      inorder(root);
      printf("ENTER THE VALUE TO BE INSERTED :-");
      scanf("%d", &x);
      insertion(root, x);
      printf("after:-\n");
      inorder(root);
      break;

    case 5:
      printf("before:-\n");
      inorder(root);
      printf("ENTER THE VALUE TO BE DELETED :-");
      scanf("%d", &x);
      deleteNode(root, x);
      printf("after:-\n");
      inorder(root);
      break;

    default:
      printf("WRONG OPTION SELECTION\n");
      break;
    }
    printf("do you want to continue:(if no then press 0 else 1)\n");
    scanf("%d", &choice);
  } while (choice != 0);
}
