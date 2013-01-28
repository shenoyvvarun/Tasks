#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc,char * argv[])
{
	char s[100];
	int n,count=1;
	struct stat i;
	while(argc!=0)
	{
		n = stat(argv[count],&i);
		++count;
		--argc;	
	  	printf("Information for %s\n",argv[1]);
   		printf("---------------------------\n");
  		printf("File Size: \t\t%d bytes\n",i.st_size);
		printf("Number of Links: \t%d\n",i.st_nlink);
		printf("File inode: \t\t%d\n",i.st_ino);
		if(S_ISREG(i.st_mode)) printf("-");
		else if(S_ISDIR(i.st_mode)) printf("d");
		else if(S_ISLNK(i.st_mode)) printf("l");
 		printf( (i.st_mode & S_IRUSR) ? "r" : "-");
    		printf( (i.st_mode & S_IWUSR) ? "w" : "-");
    		printf( (i.st_mode & S_IXUSR) ? "x" : "-");
    		printf( (i.st_mode & S_IRGRP) ? "r" : "-");
    		printf( (i.st_mode & S_IWGRP) ? "w" : "-");
    		printf( (i.st_mode & S_IXGRP) ? "x" : "-");
    		printf( (i.st_mode & S_IROTH) ? "r" : "-");
    		printf( (i.st_mode & S_IWOTH) ? "w" : "-");
    		printf( (i.st_mode & S_IXOTH) ? "x" : "-");
//    printf("The file %s a symbolic link\n", (S_ISLNK(i.st_mode)) ? "is" : "is not");
	}
	
}
