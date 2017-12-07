#include "types.h" 
#include "stat.h" 
#include "user.h"
char buf[1024];
void tail(char* filepath) 
{ int fd, n, m, count; 
  char *p, *q; 
  memset(buf, 0, sizeof(char)*1024); 	//			
  if((fd = open(filepath, 0)) < 0){ 	//
	printf(1, "tail: cannot open %s\n", filepath); 
	exit(); 
  } 
  m = 0; 
  count = 0; 
  while((n = read(fd, buf+m, sizeof(buf)-m)) > 0){ 
	m += n; 
        p = buf; 
	  while((q = strchr(p, '\n')) != 0){ 
 	    *q = 0;
             p = q+1;
             count++; 
	  } 
  } 
close(fd);
}

int main(int argc, char *argv[]) { 
     if(argc < 2){ 
	printf(2, "usage: tail filename ...\n"); 
	exit(); 
    }
    tail(argv[1]); 
    exit(); 
}
