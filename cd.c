#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]){
	if(argc<2)
	{
		printf(1," butuh 2 argumen\n");
		exit();
	}

	if(chdir(argv[1])<0)
	{
		printf(1, "Gagal untuk ganti direktori\n");
	}

 	exit();
}
