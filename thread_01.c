#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<pthread.h>
void* myturn(void* args){
int *ptr=(int*)args;

	for(int i=0;i<*ptr;i++){
		sleep(1);
		printf("My turn %d\n",i);
		
	}
	return NULL;
}
void yourturn( ){
	for(int i=0;i<4;i++){
		sleep(2);
		printf("Your turn %d\n",i);
	}
	return;
}
int main(){
 // myturn();
 // yourturn();
 pthread_t p1;
 int v=4;
 pthread_create(&p1,NULL,myturn,&v);
// pthread_create(&p2,NULL,yourturn,NULL);

yourturn();
pthread_join(p1,NULL);
	return 0;
}
