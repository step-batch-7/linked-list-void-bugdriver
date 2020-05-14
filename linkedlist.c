#include <stdlib.h>
#include "linkedlist.h"

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(LinkedList));
  if (list == NULL)
  {
    return list;
  }
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return list;
}
