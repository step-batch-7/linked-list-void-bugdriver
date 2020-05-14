#include <stdlib.h>
#include "linkedlist.h"

Node_ptr create_node(Element element)
{
  Node_ptr node = malloc(sizeof(Node));
  if (node != NULL)
  {
    node->element = element;
    node->next = NULL;
  }
  return node;
}

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

Status add_to_list(List_ptr list, Element element)
{
  if (list == NULL)
  {
    return Failure;
  }
  Node_ptr node = create_node(element);
  Node_ptr *ptr_to_set = &list->first;
  if (list->first != NULL)
  {
    ptr_to_set = &list->last->next;
  }
  (*ptr_to_set) = node;
  list->last = node;
  list->length += 1;
  return Success;
}

Status add_to_start(List_ptr list, Element element)
{
  Node_ptr node = create_node(element);
  if (list == NULL)
  {
    return Failure;
  }
  if (list->first == NULL)
  {
    list->last = node;
  }
  node->next = list->first;
  list->first = node;
  list->length += 1;
  return Success;
}

Status insert_at(List_ptr list, Element element, int position)
{
  Node_ptr node = create_node(element);
  if (node == NULL || list == NULL || position < 0 || position >= list->length + 1)
  {
    return Failure;
  }
  if (position == 0)
  {
    return add_to_start(list, element);
  }
  Node_ptr p_walk = list->first;
  for (int index = 0; index < position - 1; index++)
  {
    p_walk = p_walk->next;
  }
  node->next = p_walk->next;
  p_walk->next = node;
  list->length += 1;
  return Success;
}

List_ptr reverse(List_ptr list)
{
  List_ptr reversed_list = create_list();
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    add_to_start(reversed_list, p_walk->element);
    p_walk = p_walk->next;
  }
  return reversed_list;
}

Element remove_from_start(List_ptr list)
{
  if (list == NULL || list->first == NULL)
  {
    return NULL;
  }
  Node_ptr element_to_remove = list->first;
  list->first = list->first->next;
  list->length -= 1;
  return element_to_remove->element;
}