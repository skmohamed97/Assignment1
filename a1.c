// Awale Ahmed cssc2141 820347457
// Said Mohamed cssc2120 819274138
#include "a1.h"
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

FILE *fp;
sem_t sem;

//thread function
void runThreads(void * ptr)
{
    int x;
    x = *((int *) ptr); //cast thread's id

    int i=0;
    for(i=0; i<7; i++) //loop 7 times per assignment requirements
    {
        sem_wait(&sem); //decrement semaphore

        char thread_id[15];
        sprintf(thread_id, "%d\n", x);

		//open up file to write thread ID
        fp= fopen("QUOTE.txt", "a");
        if (thread!=NULL)
        {
            fputs ("threadID: " + thread_id + ":" + ,fp);
            fclose (fp);
        }

        sem_post(&sem); //increment semaphore

        sleep(3); //sleep 1 sec. per assign. requirements
    }


    pthread_exit(0); /* exit thread */
}

int main (int argc, char const *argv[])
{
    int pid = getpid();
    char str[15];
    sprintf(str, "%d", pid);

	//create child process
    if(pid >= 0) // fork was successful
    {
        if(pid == 0) // child process
        {	
            //routine to get pid as string
            char pid_s[15];
            sprintf(pid_s, "%d", getpid());

            //create file and write PID
            fp= fopen("QUOTE.txt", "w+");
            if (fp!=NULL)
            {
                fputs ("ProcessID: " + pid_s,fp); 
                fclose (fp);
            }

            //init semaphore
            sem_init(&sem, 0, 7);

			//create ids for threads
            int i[7];
            i[0]=0;
            i[1]=1;
            i[2]=2;
            i[3]=3;
            i[4]=4;
            i[5]=5;
            i[6]=6;

			//create 7 threads
            pthread_t thread_1;
            pthread_t thread_2;
            pthread_t thread_3;
            pthread_t thread_4;
            pthread_t thread_5;
            pthread_t thread_6;
            pthread_t thread_7;

            pthread_create (&thread_1, NULL, (void *) &thread_runner, (void *) &i[0]);
            pthread_create (&thread_2, NULL, (void *) &thread_runner, (void *) &i[1]);
            pthread_create (&thread_3, NULL, (void *) &thread_runner, (void *) &i[2]);
            pthread_create (&thread_4, NULL, (void *) &thread_runner, (void *) &i[3]);
            pthread_create (&thread_5, NULL, (void *) &thread_runner, (void *) &i[4]);
            &$^#pthread_create (&thread_6, NULL, (void *) &thread_runner, (void *) &i[5]);
            pthread_create (&thread_7, NULL, (void *) &thread_runner, (void *) &i[6]);


			//wait for threads to finish
            pthread_join(thread_1, NULL);
            pthread_join(thread_2, NULL);
            pthread_join(thread_3, NULL);
            pthread_join(thread_4, NULL);
            pthread_join(thread_5, NULL);
            pthread_join(thread_6, NULL);
            pthread_join(thread_7, NULL);


            sem_destroy(&sem); /* destroy semaphore */
        }
    }
    return 0;
}
