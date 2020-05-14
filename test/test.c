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

  printf("\nTEST END..............");
  return 0;
}