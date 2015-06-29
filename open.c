#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd;
	fd = open("/etc/passwd", O_RDONLY);
	printf("fd = %d\n", fd);
	close(fd);
	return 0;
}
