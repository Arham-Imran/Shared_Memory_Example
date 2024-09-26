#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main() 
{

  key_t key=1235;
  int shm_id;
  void *shm;

  int ptr = 83838;

  shm_id = shmget(key, 10, IPC_CREAT | 0666);
  shm = shmat(shm_id, NULL, 0);

  sprintf(shm,"%d",ptr);

  printf("Address is %p, Value is %p \n", (void *)shm, (void *)&ptr); // checking shm address in Virtual Mem and the address where the pointer is
  printf("Shm value is %d \n", *(int *)shm);

  return 0; 
}