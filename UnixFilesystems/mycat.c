#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFSZ 512

int main(int argc, char argv)
{
	char buf[BUFSZ];
	int ifd, ofd, nread;

	get_fds(argc, argv, &ifd, &ofd);
	while ((nread = read(ifd, buf, BUFSZ)) != 0) {
		write(ofd, buf, nread);
	}

	return 0;
}