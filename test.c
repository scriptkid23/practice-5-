#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 80;

typedef struct{
  char masv[10];
  char hoten[32];
  float dtb;
} Sinhvien;
/*
typedef struct {
  Sinhvien *dssv[MAX];
  char tenlop[8];
  int siso;
} Lop;
*/
void deleteNewline(char prop[]){
      int a = strlen(prop);
      strcpy(&prop[strlen(prop)-1],"");
}
int main(int argc, char const *argv[]) {

  Sinhvien sv[100];
  FILE *fq = fopen("text/SV.inp","r");
  char className[100];
  char iMember[100];
  char temp[100];
  int num;

  fgets(className,sizeof(className),fq);
  fgets(iMember,sizeof(iMember),fq);
  num = atoi(iMember);
for(int i = 0 ; i < num; i++){

  fgets(sv[i].masv,sizeof(sv[i].masv),fq);
  fgets(sv[i].hoten,sizeof(sv[i].hoten),fq);
  fgets(temp,sizeof(sv[i].hoten),fq);
  sv[i].dtb  = atof(temp);
  }



    printf("%s\n",sv[0].hoten);
    return 0;
}
