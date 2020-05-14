#include "test.h"
#include "../linkedlist.h"

Element create_int_object(int value)
{
  int *number = malloc(sizeof(int));
  *number = value;
  return number;
}

int cast_to_int(Element element)
{
  return (*(int *)element);
}

test_status assert_create_list()
{
  List_ptr list = create_list();
  if (list != NULL && list->first == NULL && list->last == NULL && list->length == 0)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_add_to_list_if_list_empty()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_object(10));
  if (list->first != NULL && list->first == list->last &&
      cast_to_int(list->first->element) == 10 &&
      list->length == 1)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_add_to_list()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_object(10));
  add_to_list(list, create_int_object(20));
  if (cast_to_int(list->first->element) == 10 &&
      cast_to_int(list->last->element) == 20 &&
      list->length == 2)
  {
    return Pass;
  }
  return Fail;
}
