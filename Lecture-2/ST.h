void STinit(int);
int STcount(void);
void STinsert(Item);
Item STsearch(Key);
void STdelete(Item);
Item STselect(int);
void STsort(void (*visit)(Item));

// Homework

int Stheight();       // 木の高さ
int Stipathlength();  // 木の内部道長
int Stepathlength();  // 木の外部道長