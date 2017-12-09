#include <dirent.h>
#include <stdio.h>
#include <string.h>

void find(char *argv,char *argu){
	int i;
	DIR *dir;
	struct dirent *ent;

	if((dir=opendir(argv))!=NULL){
		while((ent=readdir(dir))!=NULL){
			if(ent->d_type==DT_DIR) 
			continue;

			else if(strcmp(ent->d_name,".")==0)
			continue;

			else if(strcmp(ent->d_name,"..")==0)
			continue;

			else if(strcmp(ent->d_name,argu)==0)
			printf("%s\n",argu);
			}

		closedir(dir);
	}
}

void main(int argc,char *argv[]){
	char arg[100];
	sprintf(arg,".");
	if((opendir(arg))!=NULL){
		for(int i=1;i<argc;i++)
		find(arg,argv[i]);

	}
}
