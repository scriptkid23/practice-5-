#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct{
  char masv[7];
  char hoten[32];
  float dtb;
} Sinhvien;
typedef struct {
  Sinhvien *dssv[80];
  char tenlop[8];
  int siso;
} Lop;

void nhap_dssv(Lop *lop){
  FILE *fq = fopen("text/SV.inp","r");
  fgets(lop->tenlop,sizeof(lop->tenlop),fq);
  char temp[100];
  fgets(temp,sizeof(lop->siso),fq);
  lop->siso = atoi(temp);

  for(int i = 0 ; i < lop->siso; i++){
    lop->dssv[i] = (Sinhvien*)malloc(sizeof(Sinhvien));
    fgets(temp,sizeof(temp),fq);
    strcpy(lop->dssv[i]->masv,temp);
    fgets(temp,sizeof(temp),fq);
    strcpy(lop->dssv[i]->hoten,temp);
    fgets(temp,sizeof(temp),fq);
    lop->dssv[i]->dtb = atof(temp);


    fclose(fq);
  }
}
int main(int argc, char const *argv[]) {

    Lop *class0;
    class0 = (Lop*)malloc(sizeof(Lop));
    nhap_dssv(class0);
    return 0;
}
