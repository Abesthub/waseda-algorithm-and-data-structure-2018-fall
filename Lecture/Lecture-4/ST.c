#include <stdlib.h>
#include <stdio.h>
#include "Item.h"

#define hl  h->l
#define hr  h->r
#define hll h->l->l
#define hlr h->l->r
#define hrl h->r->l
#define hrr h->r->r

typedef struct STnode* link;

struct STnode
{
  Item item;
  link l, r;
  int N;
  int red;
};

static link head, z;

link NEW(Item item, link l, link r, int N, int red)
{
  link x = malloc(sizeof *x);
  x->item = item;
  x->l = l;
  x->r = r;
  x->N = N;
  x->red = red;
  return x;
}

void STinit ()
{
  head = (z = NEW(NULLitem, 0, 0, 0, 0));
}

int STcount(void) 
{
  return head->N;
}

Item searchR(link h, Key v)
{
  Key t = key(h->item);
  if (h==z)
    return NULLitem;
  if eq(v, t)
    return h->item;
  if less(v, t)
    return searchR(hl, v);
  else
    return searchR(hr, v);
}

Item STsearch(Key v) 
{
  return searchR(head, v);
} 

link rotR(link h)
{
  int tmp = hr->N + hlr->N + 1;
  link x = hl;
  hl = x->r;
  x->r = h;
  x->N = h->N;
  h->N = tmp;
  return x;
}

link rotL(link h)
{
  int tmp = hl->N + hrl->N + 1;
  link x = hr;
  hr = x->l;
  x->l = h;
  x->N = h->N;
  h->N = tmp;
  return x;
}

link RBinsert(link h, Item item, int sw)
{
  Key v = key(item);
  if (h==z)
    return NEW(item, z, z, 1, 1);
  if ((hl->red)&&(hr->red))
  {
    h->red = 1;
    hl->red = 0;
    hr->red = 0;
  }
  if (less(v, key (h->item)))
  {
    hl = RBinsert(hl, item, 0);
    if (h->red && hl->red && sw)
      h = rotR(h);
    if (hl->red && hll->red)
    {
      h = rotR(h);
	    h->red = 0;
	    hr->red = 1;
    }
    (h->N)++;
  }
  else
  {
    hr = RBinsert(hr, item, 1);
    if (h->red && hr->red && !sw)
      h = rotL(h);
    if (hr->red && hrr->red)
    {
      h = rotL(h);
      h->red = 0;
      hl->red = 1;
    }
    (h->N)++;
  }
  return h;
}

void STinsert(Item item)
{
  head = RBinsert (head, item, 0);
  head->red = 0;
}

void sortR(link h, void (*visit)(Item))
{ 
  if (h==z)
    return;
  sortR(hl, visit);
  visit(h->item); 
  sortR(hr, visit);
}

void STsort(void (*visit)(Item))
{
  sortR(head, visit);
}

void STshow(link h, int l)
{
  int i=0;
  if(h != NULL)
  {
    STshow(hr, l+1);
    for(i=0; i<l; i++)
      printf("\t");
    printf("(%d,%d)\n",key(h->item), h->N);
    STshow(hl, l+1);
  }
}

void STshowAll(void)
{
  STshow(head, 0);
}