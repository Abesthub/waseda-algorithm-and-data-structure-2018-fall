#include <stdlib.h>
#include "Item.h"

typedef struct STnode* link;

struct STnode
{
  Item item;
  link l, r;
  int N;
};

static link head, z;

link NEW(Item item, link l, link r, int N)
{
  link x = malloc(sizeof *x); 
  x->item = item;
  x->l = l;
  x->r = r;
  x->N = N;
  return x;
}

void STinit()
{
  head = (z = NEW(NULLitem, 0, 0, 0));
}

int STcount(void)
{
  return head->N;
}

Item searchR(link h, Key v)
{
  Key t = key(h->item);
  if (h == z)
    return NULLitem;
  if eq(v, t)
    return h->item;
  if less(v, t)
    return searchR(h->l, v);
  else 
    return searchR(h->r, v);
}

Item STsearch(Key v) 
{
  return searchR(head, v); 
} 

link insertR(link h, Item item)
{
  Key v = key(item), t = key(h->item);
  if (h == z) 
    return NEW(item, z, z, 1);
  if less(v, t) 
	  h->l = insertR(h->l, item);
  else 
    h->r = insertR(h->r, item);
  (h->N)++;
  return h;
}

void STinsert(Item item)
{
  head = insertR(head, item);
}

void sortR(link h, void (*visit)(Item))
{ 
  if (h == z) 
    return;
  sortR(h->l, visit);
  visit(h->item); 
  sortR(h->r, visit);
}

void STsort(void (*visit)(Item))
{
  sortR(head, visit);
}

// Homework

int max(int a, int b)
{
  if (a >= b)
    return a;
  return b;
}

int heightR(link h)
{
  if (h->N == 0)
    return 1;
  return 1 + max(heightR(h->l), heightR(h->r));
}

int Stheight()       // 木の高さ
{
  return heightR(head) - 1;
}

int ipathlengthR(link h, int depth)
{
  if (h->N == 0)
    return 0;
  return ipathlengthR(h->l, depth + 1) + ipathlengthR(h->r, depth + 1) + depth;
}

int Stipathlength()  // 木の内部道長
{
  return ipathlengthR(head, 0);
}

int epathlengthR(link h, int depth)
{
  if (h->N == 0)
     return depth;
  return epathlengthR(h->l, depth + 1) + epathlengthR(h->r, depth + 1) + depth;
}

int Stepathlength()  // 木の外部道長
{
  return epathlengthR(head, 0);
}