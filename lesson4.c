#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[32];
  int  score;
} INFO;

int readLine(){
  FILE *fname = fopen("text/hoten.txt","r");
  char line[100];
  int counter = 0;
  while(fgets(line,sizeof(line),fname)){
    counter++;
  }
  fclose(fname);
  return counter;
}
void deleteNewline(char prop[]){
      int a = strlen(prop);
      strcpy(&prop[strlen(prop)-1],"");
}
int main(int argc, char const *argv[]) {
  FILE *fname;      fname = fopen("text/hoten.txt","r");
  FILE *fchamcong;  fchamcong = fopen("text/chamcong.txt","r");
  FILE *ftonghop;   ftonghop  = fopen("text/tonghop.txt","w+");
  INFO tonghop[100];
  for(int i = 0; i < readLine();i++){
      fgets(tonghop[i].name,32,fname);
   fscanf(fchamcong,"%d",&tonghop[i].score);

  }
  for(int i = 0; i < readLine();i++){
    deleteNewline(tonghop[i].name);
  }
  for(int i = 0; i < readLine();i++){
    fprintf(ftonghop,"%s %d \n",tonghop[i].name,tonghop[i].score);
  }

  fclose(fname);
  fclose(fchamcong);
  fclose(ftonghop);
  return 0;
}
