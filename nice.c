#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int pid, priority;
  
  if(argc < 3)
  {
    printf(2, "nice\nUsage: nice <pid> <priority>(0-20)\n");
    exit();
  }
  pid = atoi(argv[1]);
  priority = atoi(argv[2]);
  if(priority < 0 || priority > 20)
  {
    printf(2, "%d is not a valid priority(0-20)\n", priority);
    exit();
  }
  chpr(pid, priority);
  exit();
}

