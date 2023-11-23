#include <stdio.h>
#include "../listlinier.h"

int main()
{
  int type;
  List l, l1, l2;
  scanf("%d", &type);

  switch (type)
  {
  case 1:
    CreateListLinier(&l);
    Address first = FIRST(l);
    for (int i = 0; i < 3; i++)
    {
      Address p = newNode(i);
      NEXT(first) = p;
      first = NEXT(first);
    }
    displayList(l);
    break;

  case 2:
    ElType val;
    CreateListLinier(&l);
    insertFirst(&l, 5);
    insertFirst(&l, 2);
    deleteFirst(&l, &val);
    break;

  case 3:
    CreateListLinier(&l1);
    CreateListLinier(&l2);

    insertLastLinier(&l1, 3);
    insertLastLinier(&l1, 2);
    insertLastLinier(&l1, 7);
    displayList(l1);

    insertLastLinier(&l1, 5);
    insertLastLinier(&l1, 1);
    insertLastLinier(&l1, 4);
    displayList(l2);

    CreateListLinier(&l);
    l = concat(l1, l2);
    displayList(l);
    break;

  default:
    break;
  }

  return 0;
}