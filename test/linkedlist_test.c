#include "test.h"
#include "../linkedlist.h"

test_status assert_create_list()
{
  List_ptr list = create_list();
  if (list != NULL && list->first == NULL && list->last == NULL && list->length == 0)
  {
    return Pass;
  }
  return Fail;
}