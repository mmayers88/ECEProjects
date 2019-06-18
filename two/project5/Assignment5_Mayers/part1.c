#include "sortHelp.h"

void *printIds(void *arg)
{
    unsigned long tid;
    tid = pthread_self();
    printf("Thread %s ID#: %d\n", (char *)arg, tid);
    return NULL;
}

int main()
{
    pthread_t p1, p2, p3, p4;
    int rc;
    printf("main: begin\n");
    rc = pthread_create(&p1, NULL, printIds, "A");
    everythingWorking(rc, "17");
    rc = pthread_create(&p2, NULL, printIds, "B");
    everythingWorking(rc, "19");
    rc = pthread_create(&p3, NULL, printIds, "C");
    everythingWorking(rc, "21");
    rc = pthread_create(&p4, NULL, printIds, "D");
    everythingWorking(rc, "23");
    // join waits for the threads to finish
    rc = pthread_join(p1, NULL);
    everythingWorking(rc, "25");
    rc = pthread_join(p2, NULL);
    everythingWorking(rc, "27");
    rc = pthread_join(p3, NULL);
    everythingWorking(rc, "30");
    rc = pthread_join(p4, NULL);
    everythingWorking(rc, "32");
    return 0;
}