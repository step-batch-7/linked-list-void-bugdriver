#include "test.h"
#include "../linkedlist.c"
#include "tester.c"
#include "linkedlist_test.c"

int main(void)
{
  printf("\nTEST START..............\n\n");

  describe("create_list()");
  it("should create empty list", assert_create_list());

  describe("add_to_list()");
  it("should add to list in empty list", assert_add_to_list_if_list_empty());
  it("should add to list in list", assert_add_to_list());

  describe("add_to_start()");
  it("should add to start in empty list", assert_add_to_start_in_empty_list());
  it("should add to start in list", assert_add_to_start());

  describe("insert_at()");
  it("should insert_at given position in list", assert_insert_at());
  it("should insert_at last position in list", assert_insert_at_last());
  it("should not insert at invalid position", assert_insert_at_wrong_position());

  describe("reverse()");
  it("should reverse list", assert_reverse_list());
  it("should reverse empty list", assert_empty_reverse_list());

  describe("remove_from_start()");
  it("should remove from start in list", assert_remove_from_start());
  it("should give null if empty list passed", assert_remove_from_start_empty_list());

  describe("remove_from_end()");
  it("should remove from end in list", assert_remove_from_end());
  it("should give null if empty list passed", assert_remove_from_end_empty_list());

  describe("remove_at()");
  it("should remove from 0th position in list", assert_remove_at_0th_position());
  it("should remove from middle position in list", assert_remove_at());
  it("should remove from last position in list", assert_remove_at_last_position());
  it("should remove only element from list", assert_remove_at_one_element_list());
  it("should give null if invalid position passed", assert_remove_at_invalid_position());

  describe("remove_first_occurrence()");
  it("should remove first occurence of element from middle of the list", assert_remove_first_occurrence());

  describe("remove_all_occurrences()");
  it("should remove all occurence of element from the list", assert_remove_all_occurrences());
  it("should remove all occurence of element from the single element list", assert_remove_all_occurrences_single_element_list());

  describe("add_unique()");
  it("should not add if number exist in list", assert_add_unique_if_exist());
  it("should add to end if number doesn't exist in list", assert_add_unique_does_not_exist());

  describe("map()");
  it("should increament all numbers by 1", assert_map_increment_by_1());

  describe("filter()");
  it("should filter even numbers", assert_filter_evens());
  it("should filter empty list", assert_filter_empty_list());

  describe("reduce()");
  it("should add all the numbers", assert_reduce_sum());
  it("should add numbers along with initial value", assert_reduce_sum_with_initial());

  describe("clear_list()");
  it("should not clear if list is empty", assert_clear_empty_list());
  it("should remove all elements from list", assert_clear_list_with_elements());

  printf("\nTEST END..............");
  return 0;
}