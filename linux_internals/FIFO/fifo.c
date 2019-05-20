#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
int main()
{
	char str[20];
	int fd;

	mkfifo("f1",0666);
	perror("mkfifo");
	printf("before pid %d\n",getpid());

	fd=open("f1",O_WRONLY);
	
	printf("after %d\n",getpid());

	printf("enter the data\n");
	scanf("%s",str);
	write(fd,str,strlen(str)+1);

	close(fd);

	fd=open("f1",O_RDONLY);
	read(fd,str,sizeof(str));
	printf("%s\n",str);
	close(fd);
	printf("Done\n");
}

