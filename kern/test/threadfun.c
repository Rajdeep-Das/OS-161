#if OPT_A2
#include <types.h>
#include <lib.h>
#include <synch.h>
#include <thread.h>
#include <test.h>

#define THREAD_RUNTIME 20000

static void talkingThread(void* whatever, unsigned long threadNum){
	/* what this thread will print out */
	int wat = '0' + threadNum;
	
	/* get rid of the junk */
	(void)whatever;

	int i;
	for(i = 0; i < THREAD_RUNTIME; i++)
		kprintf("%d", wat);
}

static void threadfun(int numThreads){
	char name[16];

	int i, result;
	for(i = 0; i < numThreads; i++){
		kprintf("Thread fun! Starting number %d\n", i);

		snprintf(name, sizeof(name), "threadfun%d", i);

		result = thread_fork(
				name,
				NULL,
				i,
				talkingThread,
				NULL
			);

		if(result)
			panic(
				"threadtest: thread_fork failed %s)\n",
				strerror(result)
			);
	}
}

#endif /* OPTA2 */
