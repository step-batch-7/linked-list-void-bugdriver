#include "test.h"
#include "../linkedlist.c"
#include "tester.c"
#include "linkedlist_test.c"

int main(void)
{
  printf("\nTEST START..............\n\n");

  describe("create_list()");
  it("should create empty list", assert_create_list());

  printf("\nTEST END..............");
  return 0;
}