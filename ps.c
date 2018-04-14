#include "types.h"
#include "stat.h"
#include "user.h"

//From proc.h Proc structure
// Per-process state
enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };
struct proc {
  enum procstate state;        // Process state
  int pid;            // Process ID
  int ppid ;          // Parent process ID
  char name[16];               // Process name
  int priority;
};

#define MAX_PROC 10

int
main(int argc, char *argv[]){  
  struct proc ptable[MAX_PROC];
  struct proc *p;
  int err;
  
  err = getptable(10*sizeof(struct proc),&ptable);
  if(err !=0)
    printf(1,"Error getting ptable");
  
  p = &ptable[0];
  printf(1, "PID  STATE     PRIORITY  NAME\n");
  while(p != &ptable[MAX_PROC-1] && p->state != UNUSED){
    char num_str[10];
    char p_format[5];
    itoa(p->pid, num_str);
    int num_len = strlen(num_str);
    *p_format = '%';
    *(p_format +1) = (char) (0x33 - num_len);
    *(p_format +2) = 'd';
    *(p_format +3) = ' ';
    *(p_format +4) = 0x0;
    //memset((void*)format, 2, 1);
    printf(1,p_format, p->pid);
      
  	switch(p->state){
  	case UNUSED:
  		printf(1," %s ", "UNUSED  ");
  		break;
  	case EMBRYO:
  		printf(1," %s ", "EMBRYO  ");
  		break;
  	case SLEEPING:
  		printf(1," %s ", "SLEEPING");
  		break;
  	case RUNNABLE:
  		printf(1," %s ", "RUNNABLE");
  		break;
  	case RUNNING:
  		printf(1," %s ", "RUNNING ");
  		break;
  	case ZOMBIE:
  		printf(1," %s ", "ZOMBIE  ");
  		break;
  	}
    char num_str2[10];
    char p_format2[5];
    itoa(p->pid, num_str2);
    int num_len2 = strlen(num_str2);
    *p_format2 = '%';
    *(p_format2 +1) = (char) (0x39 - num_len2);
    *(p_format2 +2) = 'd';
    *(p_format2 +3) = ' ';
    *(p_format2 +4) = 0x0;

    printf(1, p_format2, p->priority);
  	printf(1," %s \n", p->name);
  	p++;
  }
  	  
  exit();
}
