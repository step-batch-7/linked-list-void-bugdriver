#include "test.h"
#include "../linkedlist.h"

Element create_int_object(int value)
{
  int *number = malloc(sizeof(int));
  *number = value;
  return number;
}

Element add_int(Element first_number, Element second_number)
{
  int *fn = (int *)first_number;
  int *sn = (int *)second_number;
  return create_int_object((*fn) + (*sn));
}

int cast_to_int(Element element)
{
  return (*(int *)element);
}

Status is_even(Element element)
{
  int value = *((int *)element);
  return value % 2 == 0;
}

Element increment_by_1(Element element)
{
  int number = *((int *)element);
  return create_int_object(number + 1);
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

test_status assert_add_to_start_in_empty_list()
{
  List_ptr list = create_list();
  Status status = add_to_start(list, create_int_object(10));
  if (cast_to_int(list->first->element) == 10 && status)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_add_to_start()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_object(10));
  Status status = add_to_start(list, create_int_object(20));
  if (cast_to_int(list->first->element) == 20 && list->first != list->last && status)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_insert_at()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_object(10));
  Status status = insert_at(list, create_int_object(20), 0);
  if (cast_to_int(list->first->element) == 20 && status)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_insert_at_wrong_position()
{
  List_ptr list = create_list();
  Status status1 = insert_at(list, create_int_object(10), 2);
  Status status2 = insert_at(list, create_int_object(20), -2);
  if (list->length == 0 && !status1 && !status2)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_reverse_list()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_object(10));
  add_to_list(list, create_int_object(20));
  add_to_list(list, create_int_object(30));
  List_ptr reversed_list = reverse(list);
  if (cast_to_int(reversed_list->first->element) == 30 &&
      cast_to_int(reversed_list->first->next->element) == 20 &&
      cast_to_int(reversed_list->last->element) == 10)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_empty_reverse_list()
{
  List_ptr list = create_list();
  List_ptr reversed_list = reverse(list);
  if (reversed_list->first == NULL && reversed_list->length == 0)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_remove_from_start()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_object(10));
  add_to_list(list, create_int_object(20));
  add_to_list(list, create_int_object(30));
  Element removed_element = remove_from_start(list);
  if (cast_to_int(removed_element) == 10 && list->length == 2)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_remove_from_start_empty_list()
{
  List_ptr list = create_list();
  Element removed_element = remove_from_start(list);
  if (removed_element == NULL)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_remove_from_end()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_object(10));
  add_to_list(list, create_int_object(20));
  add_to_list(list, create_int_object(30));
  Element removed_element = remove_from_end(list);
  if (cast_to_int(removed_element) == 30 && list->length == 2 &&
      cast_to_int(list->last->element) == 20)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_remove_from_end_empty_list()
{
  List_ptr list = create_list();
  Element removed_element = remove_from_end(list);
  if (removed_element == NULL)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_remove_at()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_object(10));
  add_to_list(list, create_int_object(20));
  add_to_list(list, create_int_object(30));
  Element removed_element = remove_at(list, 1);
  if (cast_to_int(removed_element) == 20 && list->length == 2)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_remove_at_0th_position()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_object(10));
  add_to_list(list, create_int_object(20));
  add_to_list(list, create_int_object(30));
  Element removed_element = remove_at(list, 0);
  if (cast_to_int(removed_element) == 10 && list->length == 2)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_remove_at_last_position()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_object(10));
  add_to_list(list, create_int_object(20));
  add_to_list(list, create_int_object(30));
  Element removed_element = remove_at(list, 2);
  if (cast_to_int(removed_element) == 30 && list->length == 2)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_remove_at_one_element_list()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_object(10));
  Element removed_element = remove_at(list, 0);
  if (cast_to_int(removed_element) == 10 && list->length == 0)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_remove_at_invalid_position()
{
  List_ptr list = create_list();
  Element element = remove_at(list, 1);
  if (element == NULL && list->length == 0)
  {
    return Pass;
  }
  return Fail;
}

Status match_int(Element element1, Element element2)
{
  return cast_to_int(element1) == cast_to_int(element2);
}

test_status assert_remove_first_occurrence()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_object(10));
  add_to_list(list, create_int_object(20));
  add_to_list(list, create_int_object(30));
  add_to_list(list, create_int_object(20));
  Element removed_element = remove_first_occurrence(list, create_int_object(20), &match_int);
  if (cast_to_int(removed_element) == 20 && list->length == 3)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_remove_all_occurrences()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_object(10));
  add_to_list(list, create_int_object(20));
  add_to_list(list, create_int_object(30));
  add_to_list(list, create_int_object(20));
  List_ptr removed_elements = remove_all_occurrences(list, create_int_object(20), &match_int);
  if (cast_to_int(removed_elements->first->element) == 20 &&
      cast_to_int(removed_elements->first->next->element) == 20 &&
      removed_elements->length == 2 &&
      list->length == 2 &&
      cast_to_int(list->first->next->element) == 30)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_remove_all_occurrences_single_element_list()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_object(10));
  List_ptr removed_elements = remove_all_occurrences(list, create_int_object(10), &match_int);
  if (cast_to_int(removed_elements->first->element) == 10 &&
      removed_elements->length == 1 &&
      list->length == 0)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_add_unique_if_exist()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_object(10));
  Status status = add_unique(list, create_int_object(10), &match_int);
  if (list->length == 1 && !status)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_add_unique_does_not_exist()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_object(10));
  Status status = add_unique(list, create_int_object(20), &match_int);
  if (list->length == 2 && status)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_map_increment_by_1()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_object(10));
  add_to_list(list, create_int_object(20));
  List_ptr incremented_by_one = map(list, &increment_by_1);
  if (incremented_by_one->length == 2 &&
      cast_to_int(incremented_by_one->first->element) == 11 &&
      cast_to_int(incremented_by_one->last->element) == 21)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_filter_evens()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_object(1));
  add_to_list(list, create_int_object(2));
  add_to_list(list, create_int_object(3));
  add_to_list(list, create_int_object(4));
  List_ptr evens = filter(list, &is_even);
  if (evens->length == 2 &&
      cast_to_int(evens->first->element) == 2 &&
      cast_to_int(evens->last->element) == 4)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_filter_empty_list()
{
  List_ptr list = create_list();
  List_ptr evens = filter(list, &is_even);
  if (evens->length == 0)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_reduce_sum()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_object(1));
  add_to_list(list, create_int_object(2));
  add_to_list(list, create_int_object(3));
  add_to_list(list, create_int_object(4));
  Element sum = reduce(list, create_int_object(0), &add_int);
  if (cast_to_int(sum) == 10)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_reduce_sum_with_initial()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_object(1));
  add_to_list(list, create_int_object(2));
  add_to_list(list, create_int_object(3));
  add_to_list(list, create_int_object(4));
  Element sum = reduce(list, create_int_object(2), &add_int);
  if (cast_to_int(sum) == 12)
  {
    return Pass;
  }
  return Fail;
}