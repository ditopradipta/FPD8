#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "syscall.h"

int main(int argc, char *argv[])
{
	
if(argc < 2){
	printf(2, "butuh 2 argument\n");
	}

for(int i=0;i<=argc;i++)
{
int f;	
	if((f = open(argv[i], O_CREATE | O_RDWR)) < 0)
	{
		printf(1, "touch: %s tidak berhasil dibuat\n", argv[i]);
	}

	close(f);
}	
	exit();
}

