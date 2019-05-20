#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
	char a[20];
	int fd;

	mkfifo("f1",0666);

	fd=open("f1",O_RDONLY);
	read(fd,a,sizeof(a));
	printf("%s\n",a);
	close(fd);

	fd=open("f1",O_WRONLY);
	scanf("%s",a);
	write(fd,a,strlen(a)+1);

	close(fd);
}
