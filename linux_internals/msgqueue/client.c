#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct mesg_buffer
{
	long mesg_type;
	char mesg_text[100];
}message;

int main()
{
	key_t key;
	int msgid;
	int i=0;
	key=ftok("progfile",65);

	msgid=msgget(key,0660|IPC_CREAT);

	msgrcv(msgid,&message,sizeof(message),1,0);

	 printf("Data Received is : %s \n",
                    message.mesg_text);

	 for(i=0;message.mesg_text[i]!='\0';i++)
	 {
		 if(message.mesg_text[i] >='a' && message.mesg_text[i]<='z')
		 {
			 message.mesg_text[i]=message.mesg_text[i]-32;
		 }
	}

	 msgsnd(msgid,&message,sizeof(message),0);

	 printf("message send:%s\n",message.mesg_text);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
