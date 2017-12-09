#include <syscall.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
  int i;

  if(argc < 2){
    fprintf(stderr, "Usage: rm (file apa yg mau didelete?)\n");
    sysexit();
  }

  //buat hapus folder(di terminal jalan, di xv6 ga ngaruh->bisa hapus folder tanpa -r)
if (strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "-R") == 0) { // with -r
    if (argc != 3) { // wrong usage
      fprintf(stderr, "rm: terlalu banyak argumen\n");
      sysexit();
    } else { // remove folder yang gaada isinya
      if (remove(argv[2]) < 0) {
        fprintf(stderr, "rm: %s bukan direktori kosong\n", argv[2]);
        sysexit();
      }
    }
  }
else

  for(i = 1; i < argc; i++){
    if(unlink(argv[i]) < 0){
      fprintf(stderr, "rm: %s gagal dihapus\n", argv[i]);
      break;
    }
  }

  sysexit();
}
