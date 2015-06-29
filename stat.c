#include <sys/types.h>
#include <sys/stat.h>
/* #include <sys/dirent.h> */
#include <sys/unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>

#define BUFSZ 1024

 main()
 {
 struct dirent *dir;
 struct stat st;
 struct passwd *pw;
 struct group *grp;
 char buf[BUFSZ], *bp, *ftime;
 int dfd, fd, nread;

 dfd = open(".", O_RDONLY);
 bzero(buf, BUFSZ);

 while (nread = getdents(dfd, (struct dirent *)&buf, BUFSZ) != 0) {
	 bp = buf;
	 dir = (struct dirent *)buf;
	 do {
		 if (dir->d_reclen != 0) {
			 stat(dir->d_name, &st);
			 ftime = ctime(&st.st_mtime);
			 ftime[16] = '\0'; ftime += 4;
			 pw = getpwuid(st.st_uid);
			 grp = getgrgid(st.st_gid);
			 perms(st.st_mode);
			 printf("%3d %-8s %-7s %9d %s %s\n", st.st_nlink, pw->pw_name, grp->gr_name, st.st_size, ftime, dir->d_name);
	 }
	 bp = bp + dir->d_reclen;
	 dir = (struct dirent *)(bp);
	} while (dir->d_ino != 0);
	bzero(buf, BUFSZ);
	}
}