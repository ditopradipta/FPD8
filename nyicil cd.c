#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h> 
#include <libgen.h> 
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <syscall.h>

#define TAM 1000 

void  parseo(char *line, char **argv);

int main(void) {

    char  cad[TAM];             
    char  *argv[TAM]; 
    char  *gdir;
    char  *dir;
    char  *to;
    char buf[TAM];
    pid_t pid;
    int status;

    while (1) {                   

        printf("user@PC: ");    
        fgets(cad, 1000, stdin);

        // Jika kita menemukan jeda baris (tekan enter)
        if (cad[strlen(cad) - 1] == '\n')                                                           
            cad[strlen(cad) - 1] = '\0';    // Tanda sebagai akhir kalimat            

        parseo(cad, argv);


        // Untuk keluar dari shell
        if (!strcmp(argv[0], "exit")) exit(0);  

        if (!strcmp(argv[0], "cd")){

            gdir = getcwd(buf, sizeof(buf));
            dir = strcat(gdir, "/");
            to = strcat(dir, argv[1]);

            chdir(to);
            //printf("Akses ke folder yang dibuat\n");

        }            

    }
    return 0;
}

