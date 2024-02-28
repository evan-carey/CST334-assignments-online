
#include <criterion/criterion.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

#include "../src/process_scheduling.h"
#include "../src/student_code.h"

Test(STCF, e0) {
    PROCESS *p0 = create_process(1.0f, 0.0f, 0.0f);
    PROCESS_LIST *pl = create_process_list();
    add_process_to_tail(pl, p0);

    PROCESS *selected = stcf_process_selector(pl);
    cr_assert(selected == p0);
}

Test(STCF, e0_e1) {
    PROCESS *p0 = create_process(1.0f, 0.0f, 0.0f);
    PROCESS *p1 = create_process(1.0f, 0.0f, 1.0f);
    PROCESS_LIST *pl = create_process_list();
    add_process_to_tail(pl, p0);
    add_process_to_tail(pl, p1);

    p0->time_remaining = 0.5;

    PROCESS *selected = stcf_process_selector(pl);

    cr_assert(selected == p0);
    cr_assert(selected != p1);
    cr_assert(selected != NULL);
}

Test(STCF, e1_e0) {
    PROCESS *p0 = create_process(1.0f, 0.0f, 1.0f);
    PROCESS *p1 = create_process(1.0f, 0.0f, 0.0f);
    PROCESS_LIST *pl = create_process_list();
    add_process_to_tail(pl, p0);
    add_process_to_tail(pl, p1);

    p1->time_remaining = 0.5;

    PROCESS *selected = stcf_process_selector(pl);

    cr_assert(selected == p1);
}

Test(STCF, e0_e1_1) {
    PROCESS *p0 = create_process(1.0f, 0.0f, 0.0f);
    PROCESS *p1 = create_process(1.0f, 0.0f, 1.0f);
    PROCESS *p2 = create_process(1.0f, 0.0f, 1.0f);
    PROCESS_LIST *pl = create_process_list();
    add_process_to_tail(pl, p0);
    add_process_to_tail(pl, p1);
    add_process_to_tail(pl, p2);

    p0->time_remaining = 0.5;

    PROCESS *selected = stcf_process_selector(pl);
    cr_assert(selected == p0);
}

Test(STCF, e1_e0_e1) {
    PROCESS *p0 = create_process(1.0f, 0.0f, 1.0f);
    PROCESS *p1 = create_process(1.0f, 0.0f, 0.0f);
    PROCESS *p2 = create_process(1.0f, 0.0f, 1.0f);
    PROCESS_LIST *pl = create_process_list();
    add_process_to_tail(pl, p0);
    add_process_to_tail(pl, p1);
    add_process_to_tail(pl, p2);

    p1->time_remaining = 0.5;

    PROCESS *selected = stcf_process_selector(pl);
    cr_assert(selected == p1);
}

Test(STCF, e1_e1_e0) {
    PROCESS *p0 = create_process(1.0f, 0.0f, 1.0f);
    PROCESS *p1 = create_process(1.0f, 0.0f, 1.0f);
    PROCESS *p2 = create_process(1.0f, 0.0f, 0.0f);
    PROCESS_LIST *pl = create_process_list();
    add_process_to_tail(pl, p0);
    add_process_to_tail(pl, p1);
    add_process_to_tail(pl, p2);

    p2->time_remaining = 0.5;

    PROCESS *selected = stcf_process_selector(pl);
    cr_assert(selected == p2);
}