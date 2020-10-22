#include<stdlib.h>
#include<stdio.h>

struct binarytree
{
    int data;
    struct binarytree * right, * left;
};

typedef struct binarytree node;

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}


int count(node *tree)
{
    int c=0;

    if (tree ==NULL)
        return 0;

    else
    {
        c += count(tree->left);
        c += count(tree->right);
        return c;
    }
}
/*
 Returns the count of leaf nodes in a binary tree
*/
int countLeafNode( node *root){
    /* Empty(NULL) Tree */
    if(root == NULL)
        return 0;
    /* Check for leaf node */
    if(root->left == NULL && root->right == NULL)
       return 1;
    /* For internal nodes, return the sum of
    leaf nodes in left and right sub-tree */
    return countLeafNode(root->left) + countLeafNode(root->right);
}
int countleftchild(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL)
    {
        //No keft child
        return countleftchild(root->right);
    }
    else
    {

        return countleftchild(root->left) + countleftchild(root->right)+1;
    }
}
int countrightchild(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->right==NULL)
    {
        //No keft child
        return countrightchild(root->left);
    }
    else
    {

        return countrightchild(root->right) + countrightchild(root->left)+1;
    }
}

int main()
{

    node *root;
    node *tmp;
    int c;

    root = NULL;
    /* Inserting nodes into tree */
    insert(&root, 9);
    insert(&root, 10);
    insert(&root, 15);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 17);
    insert(&root, 2);

    /* Printing nodes of tree */
    printf("Number of node %d \n",c);
    printf("Number of leaf Node : %d\n", countLeafNode(root));
    printf("Number of left child Node : %d\n", countleftchild(root));
    printf("Number of right child Node : %d\n", countrightchild(root));
}
