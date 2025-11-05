/* ISC license. */

#include <skalibs/buffer.h>
#include <skalibs/strerr.h>

#include "s6-internal.h"

#define MAIN_HELP_MESSAGE "This is the main help message.\n"

#define PROCESS_HELP_MESSAGE "This is the process help message.\n"

#define SERVICE_HELP_MESSAGE "This is the service help message.\n"

static int print_help (char const *msg)
{
  if (!buffer_putsflush(buffer_1, msg))
    strerr_diefu1sys(111, "write to stdout") ;
  return 0 ;
}

// NEW: updated signatures to match commands[] declaration:
int process_help (char const* const *argv, const process_options *opts)
{
  (void)argv ;
  (void)opts ;
  return print_help(PROCESS_HELP_MESSAGE) ;
}

int service_help (char const* const *argv)
{
  (void)argv ;
  return print_help(SERVICE_HELP_MESSAGE) ;
}

int help (char const *const *argv)
{
  (void)argv ;
  return print_help(MAIN_HELP_MESSAGE) ;
}
