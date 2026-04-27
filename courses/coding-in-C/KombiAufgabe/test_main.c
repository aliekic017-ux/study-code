#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "werkzeuge.h"


void test_init_list (void)
{
    ToolList test;
    init_list(&test);

    assert(test.p_head == NULL);
}


void test_append_tool (void)
{
    ToolList test;
    init_list(&test);

    assert(test.p_head == NULL);
    Tool *werk = create_tool(121, "Hammer", "OK");
    append_tool(&test, werk);

    assert(test.p_head != NULL);
    assert(test.p_head->id == 121);
    assert(strcmp(test.p_head->bezeichnung, "Hammer") == 0);
    assert(strcmp(test.p_head->zustand, "OK") == 0);
    assert(test.p_head->p_next == NULL);

    delete_list(&test);

}

void test_delete_first_tool (void)
{
    ToolList test;
    init_list(&test);

    assert(test.p_head == NULL);
    Tool *werk = create_tool(132, "Schrauben", "Nicht in Ordnung");
    Tool *werk2 = create_tool (194, "Kompressor", "GEBRAUCHT");
    append_tool(&test, werk);
    append_tool(&test, werk2);

    assert(test.p_head != NULL);
    assert(test.p_head->id == 132);
    assert(strcmp(test.p_head->bezeichnung, "Schrauben") == 0 );
    assert(strcmp(test.p_head->zustand, "Nicht in Ordnung") == 0);
    assert(test.p_head->p_next != NULL);

    delete_first_tool(&test);

    assert(test.p_head != NULL);
    assert(test.p_head->id == 194);
    assert(strcmp(test.p_head->bezeichnung, "Kompressor") == 0);
    assert(strcmp(test.p_head->zustand, "GEBRAUCHT") == 0);
    assert(test.p_head->p_next == NULL);

    delete_list(&test);

}

void test_delete_list (void)
{
    ToolList test;
    init_list(&test);

    append_tool(&test, create_tool(101, "Hammer", "OK"));
    append_tool(&test, create_tool(102, "Zange", "Defekt"));

    assert(test.p_head != NULL);

    delete_list(&test);
    assert(test.p_head == NULL);
}

    int main (void)
    {
        test_init_list();
        test_append_tool();
        test_delete_first_tool();
        test_delete_list();

        printf(" Alle Assert-Tests wurden erfolgreich durchgeführt.");

        return 0;

    }