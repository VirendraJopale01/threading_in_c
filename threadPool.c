#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define QUEUE_SIZE 10
#define THREADS_SIZE 4

typedef struct {
	void (*function)(void*);
	void *args;
}task_t;

task_t thread_que[QUEUE_SIZE];
int front=0, back=0,cnt=0;

pthread_mutex_t queue_mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t queue_not_empty=PTHREAD_COND_INITIALIZER;
pthread_cond_t queue_not_full=PTHREAD_COND_INITIALIZER;

void* worker_thread(void* args){
	while(1){
		pthread_mutex_lock(&queue_mutex);
		while(cnt==0){
			pthread_cond_wait(&queue_not_empty,&queue_mutex);
		}
		task_t task=thread_que[front];
	front=(front+1)%QUEUE_SIZE;
	cnt--;
	pthread_cond_signal(&queue_not_full);
	pthread_mutex_unlock(&queue_mutex);

	task.function(task.args);
	}
	return NULL;
}

void addTask(void (*func)(void*),void* args){
	pthread_mutex_lock(&queue_mutex);

	while(cnt==QUEUE_SIZE){
		pthread_cond_wait(&queue_not_full,&queue_mutex);
		
	}
	thread_que[back].function=func;
	thread_que[back].args=args;
	back=(back+	1)%QUEUE_SIZE;
	cnt++;
	pthread_cond_signal(&queue_not_empty);
	pthread_mutex_unlock(&queue_mutex);

}

void printMsg(void *args){
	int id=*(int*)args;
	printf("The running task is %d on thrad %ld\n",id,pthread_self());
	sleep(1);
}

int main(){
	pthread_t threads[THREADS_SIZE];
	for(int i=0;i<THREADS_SIZE;i++){
		pthread_create(&threads[i],NULL,worker_thread,NULL);
	}
   printf("Code\n");
	for(int i=0;i<20;i++){
		int *taskid=malloc(sizeof(int));
		*taskid=i;
		addTask(printMsg,taskid);
	}
	sleep(10);
	return 0;
}
