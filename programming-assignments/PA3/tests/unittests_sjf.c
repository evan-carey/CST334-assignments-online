
#include <criterion/criterion.h>
#include <unistd.h>
#include <sys/wait.h>

#include "../src/process_scheduling.h"
#include "../src/student_code.h"

Test(SJF, e0) {
    PROCESS *p0 = create_process(1.0f, 0.0f, 0.0f);
    PROCESS_LIST *pl = create_process_list();
    add_process_to_tail(pl, p0);

    PROCESS *selected = sjf_process_selector(pl);
    cr_assert(selected == p0);
}

Test(SJF, l1_l2) {
    PROCESS *p0 = create_process(1.0f, 0.0f, 0.0f);
    PROCESS *p1 = create_process(2.0f, 0.0f, 0.0f);
    PROCESS_LIST *pl = create_process_list();
    add_process_to_tail(pl, p0);
    add_process_to_tail(pl, p1);

    PROCESS *selected = sjf_process_selector(pl);

    cr_assert(selected == p0);
    cr_assert(selected != p1);
    cr_assert(selected != NULL);
}

Test(SJF, l2_l1) {
    PROCESS *p0 = create_process(2.0f, 0.0f, 0.0f);
    PROCESS *p1 = create_process(1.0f, 0.0f, 0.0f);
    PROCESS_LIST *pl = create_process_list();
    add_process_to_tail(pl, p0);
    add_process_to_tail(pl, p1);

    PROCESS *selected = sjf_process_selector(pl);

    cr_assert(selected == p1);
}

Test(SJF, l1_l2_l2) {
    PROCESS *p0 = create_process(1.0f, 0.0f, 0.0f);
    PROCESS *p1 = create_process(2.0f, 0.0f, 0.0f);
    PROCESS *p2 = create_process(2.0f, 0.0f, 0.0f);
    PROCESS_LIST *pl = create_process_list();
    add_process_to_tail(pl, p0);
    add_process_to_tail(pl, p1);
    add_process_to_tail(pl, p2);

    PROCESS *selected = sjf_process_selector(pl);
    cr_assert(selected == p0);
}

Test(SJF, l2_l1_l2) {
    PROCESS *p0 = create_process(2.0f, 0.0f, 0.0f);
    PROCESS *p1 = create_process(1.0f, 0.0f, 0.0f);
    PROCESS *p2 = create_process(2.0f, 0.0f, 0.0f);
    PROCESS_LIST *pl = create_process_list();
    add_process_to_tail(pl, p0);
    add_process_to_tail(pl, p1);
    add_process_to_tail(pl, p2);

    PROCESS *selected = sjf_process_selector(pl);
    cr_assert(selected == p1);
}

Test(SJF, l2_l2_l1) {
    PROCESS *p0 = create_process(2.0f, 0.0f, 0.0f);
    PROCESS *p1 = create_process(2.0f, 0.0f, 0.0f);
    PROCESS *p2 = create_process(1.0f, 0.0f, 0.0f);
    PROCESS_LIST *pl = create_process_list();
    add_process_to_tail(pl, p0);
    add_process_to_tail(pl, p1);
    add_process_to_tail(pl, p2);

    PROCESS *selected = sjf_process_selector(pl);
    cr_assert(selected == p2);
}