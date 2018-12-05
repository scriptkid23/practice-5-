#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 80;

typedef struct{
  char masv[7];
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
    fgets(temp,sizeof(temp),fq);
    strcpy(sv[i].masv,temp);
    fgets(temp,sizeof(temp),fq);
    strcpy(sv[i].hoten,temp);
    fgets(temp,sizeof(temp),fq);
    sv[i].dtb = atof(temp);


  }
  printf("%3.2f\n",sv[2].dtb);
    return 0;
}
