#include <stdio.h>
#include "../listlinier.h"

int main()
{
  ElType val;
  int type;
  List l, l1, l2;
  scanf("%d", &type);

  switch (type)
  {
  case 1:
    CreateListLinier(&l);
    if (isEmptyLinier(l))
    {
      displayList(l);
    }
    else
    {
      printf("berisi");
    }
    break;

  case 2:
    CreateListLinier(&l);
    insertFirst(&l, 5);
    insertFirst(&l, 2);
    deleteFirst(&l, &val);
    displayList(l);
    break;

  case 3:
    CreateListLinier(&l1);
    CreateListLinier(&l2);

    insertLastLinier(&l1, 3);
    insertLastLinier(&l1, 2);
    insertLastLinier(&l1, 7);

    insertLastLinier(&l1, 5);
    insertLastLinier(&l1, 1);
    insertLastLinier(&l1, 4);

    CreateListLinier(&l);
    l = concat(l1, l2);
    displayList(l);
    break;

  default:
    break;
  }

  return 0;
}