
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *routine(){

    printf("Start: THREAD\n");
    sleep(3);
    printf("STOP: Thread\n");

    return NULL;
}

int main(int argc, char *argv[]){
    
    // thread handle
    pthread_t t1, t2;

    /*
    pthread_create parameters:
        pointer to thread handle,
        attributes for thread,
        routine/function,
        attributes for routine
    */
    pthread_create(&t1, NULL, routine, NULL);
    pthread_create(&t2, NULL, routine, NULL);

    // wait for threads to end
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0; //end the process
}