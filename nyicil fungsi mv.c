/* mv: Move files		Author: Warren Toomey */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Move something to a new location
void do_move(char *from, char *to)
{
  // Unlink whatever is there
  unlink(to);

  // Link old to new
  if (link(from, to)!=0) {
    fprintf(stderr, "Unable to link %s to %s\n", from, to);
    exit(1);
  }

  // Now try to unlink the old one
  if (unlink(from)!=0) {
    fprintf(stderr, "Unable to unlink %s\n", from);
    exit(1);
  }
}




