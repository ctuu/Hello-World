#include <stdio.h>
#include <stdlib.h>
#include "17.12.3.h"

void InitializeList(List *plist)
{
    plist->items = 0;
}

bool ListIsEmpty(const List *plist)
{
    if (plist->items == 0)
        return true;
    else
        return false;
}

bool ListIsFull(const List *plist)
{
    bool full;
    if (plist->items == MAXSIZE)
        full = true;
    else
        full = false;

    return full;
}

unsigned int ListItemCount(const List *plist)
{
    return plist->items;
}

bool AddItem(Item item, List *plist)
{
    plist->entries[plist->items] = item;
    plist->items++;
    return true;
}

void Traverse(const List *plist, void (*pfun)(Item item))
{
    int i = 0;

    while (i <( plist->items))
    {
        (*pfun)(plist->entries[i]);
        i++;
    }
}

void EmptyTheList(List *plist)
{
    plist->items = 0;
}