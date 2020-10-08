#include<ftw.h>
#include<stdio.h>
#include<stdlib.h>

static int num_dir, num_reg;
static int callback(const char *fpath, const struct stat*sb, int typeflag){
  if(typeflag==FTW_D){
    num_dir++;
  }	
  if(typeflag==FTW_F){ 
    num_reg++;
  }
  return 0; 
}

#define MAX_FTW_DEPTH 16
int main(int argc, char** argv){
  if(argc!=2){ 
    printf("need two arguements");
    exit(1);
  }
  num_reg=0;
  num_dirs=0;  
  ftw(argv[1], callback, MAX_FTW_DEPTH);
  printf("There were %d directories.\n" , num_dirs);
  printf("There were %d regular files.\n", num_regular);
  return 0;
}
