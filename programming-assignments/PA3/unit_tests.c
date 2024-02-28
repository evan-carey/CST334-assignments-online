#include <criterion/criterion.h>
#include <signal.h>
#include "src/common.h"

#include "tests/unittests_helpers.c"
#include "tests/unittests_fifo.c"
#include "tests/unittests_priority.c"
#include "tests/unittests_lifo.c"
#include "tests/unittests_sjf.c"
#include "tests/unittests_stcf.c"
#include "tests/unittests_rr.c"
#include "tests/unittests_end2end.c"


TestSuite(HelperFunctions, .disabled=false);
TestSuite(STCF, .disabled=false);
TestSuite(SJF, .disabled=false);
TestSuite(PRIORITY, .disabled=false);
TestSuite(LIFO, .disabled=false);
TestSuite(FIFO, .disabled=false);


// From: https://github.com/codewars/criterion-hooks/blob/main/criterion-hooks.c
// PRE_TEST: occurs after the test initialization, but before the test is run.
ReportHook(PRE_TEST)(struct criterion_test *test) {
  log_debug("Starting test: %s\n", test->name)
}

// From: https://github.com/codewars/criterion-hooks/blob/main/criterion-hooks.c
// TEST_CRASH: occurs when a test crashes unexpectedly.
ReportHook(TEST_CRASH)(struct criterion_test_stats *stats) {
  log_error("Test Crashed.  Caught unexpected signal: ");
  switch (stats->signal) {
    case SIGILL:
      log_error("SIGILL (%d). %s\n", stats->signal, "Invalid instruction.");
      break;

    case SIGFPE:
      log_error("SIGFPE (%d). %s\n", stats->signal, "Erroneous arithmetic operation.");
      break;

    case SIGSEGV:
      log_error("SIGSEGV (%d). %s\n", stats->signal, "Invalid memory access.");
      break;

    default:
      log_error("%d\n", stats->signal);
  }
}
