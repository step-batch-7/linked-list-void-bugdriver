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
  it("should not insert at invalid position", assert_insert_at_wrong_position());

  describe("reverse()");
  it("should reverse list", assert_reverse_list());
  it("should reverse empty list", assert_empty_reverse_list());

  printf("\nTEST END..............");
  return 0;
}