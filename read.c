#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

int main() 
{

  key_t key=1235;
  int shm_id;
  void *shm;

  int *p = (int *)malloc(sizeof(int));
  shm_id = shmget(key, 10, 0);
  shm = shmat(shm_id, NULL, 0);
  if(shm == NULL)
  {
    printf("error");
  }
  sscanf(shm,"%d",p);
  printf("Address is %p %p %p %d\n",(void *)shm, (void *)p, (void *)&p, *p);
  printf("Shared value is %d \n", *(int *)shm);
  
  return 0;
}