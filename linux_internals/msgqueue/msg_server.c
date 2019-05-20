#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>


struct mesg_buffer
{
	long mesg_type;
	char mesg_text[100];
}message;
int main()
{
	key_t key;
	int id;
	 key=ftok("progfile",65);

	id=msgget(key,0660|IPC_CREAT);

	message.mesg_type=1;

	printf("write data\n");
	gets(message.mesg_text);

	msgsnd(id,&message,sizeof(message),0);

	printf("data send is %s\n",message.mesg_text);

	return 0;

}


