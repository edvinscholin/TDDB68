#ifndef USERPROG_PROCESS_H
#define USERPROG_PROCESS_H

#include "threads/thread.h"
#include "threads/synch.h"

typedef int pid_t;

tid_t process_execute (const char *file_name);
int process_wait (tid_t);
void process_exit (void);
void process_activate (void);

struct parent_child {
    int exit_status;
    int alive_count;
    pid_t child_pid;
    char *fn_copy;
    bool load;

    struct semaphore await_child;
    struct lock lock;

    struct list_elem elem;
};

#endif /* userprog/process.h */
