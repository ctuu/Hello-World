#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>

#define SLEN 20
#define TSIZE 45
#define MAXITEMS 10

typedef struct item
{
    char petname[SLEN];
    char petkind[SLEN];
} Item;

typedef struct node
{
    char petkind[SLEN];
    struct node *next;
} Node;

typedef Node *List;

typedef struct trnode
{
    char petname[SLEN];
    List list;
    int ct;
    struct trnode *left;
    struct trnode *right;
} Trnode;

typedef struct tree
{
    Trnode *root;
    int size;
} Tree;

void InitializeTree(Tree *ptree);
bool TreeIsEmpty(const Tree *ptree);
bool TreeIsFull(const Tree *ptree);
int TreeItemCount(const Tree *ptree);
bool TreeAddItem(const Item *pi, Tree *ptree);
bool InTree(const Item *pi, const Tree *ptree);
bool DeleteItem(const Item *pi, Tree *ptree);
void TreeTraverse(const Tree *ptree, void (*pfun)(Item item));
void DeleteAll(Tree *ptree);

//======================================================

void InitializeList(List *plist);
bool ListIsEmpty(const List *plist);
bool ListIsFull(const List *plist);
unsigned int ListItemCount(const List *plist);
bool ListAddItem(Item item, List *plist);
void ListTraverse(const List *plist, void (*pfun)(Item item));
void EmptyTheList(List *plist);

#endif