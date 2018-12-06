#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct{
  char masv[10];
  char hoten[32];
  float dtb;
} Sinhvien;
typedef struct {
  Sinhvien *dssv[80];
  char tenlop[8];
  int siso;
} Lop;
void deleteNewline(char prop[]){
      int a = strlen(prop);
      strcpy(&prop[strlen(prop)-1],"");
}
void nhap_dssv(Lop *lop){
  FILE *fq = fopen("text/SV.inp","r");
  fgets(lop->tenlop,sizeof(lop->tenlop),fq);
  char number[100];
  fgets(number,sizeof(lop->siso),fq);
  lop->siso = atoi(number);
  char temp[100];
  for(int i = 0 ; i < lop->siso; i++){
      lop->dssv[i] = (Sinhvien*)malloc(sizeof(Sinhvien));
      fgets(lop->dssv[i]->masv,sizeof(lop->dssv[i]->masv),fq);
      deleteNewline(lop->dssv[i]->masv);
      fgets(lop->dssv[i]->hoten,sizeof(lop->dssv[i]->hoten),fq);
      deleteNewline(lop->dssv[i]->hoten);
      fgets(temp,sizeof(lop->dssv[i]->hoten),fq);
      lop->dssv[i]->dtb  = atof(temp);

  }
  fclose(fq);
}
void splaceNumber(float a, float b){
  float temp;
  temp = a;
  a = b;
  b =temp;
}
void splaceString(char a[], char b[]){
  char temp[100];
  strcpy(temp,a);
  strcpy(a,b);
  strcpy(b,temp);
}
void sapxep_dssv(Lop *lop){
    for(int i = 0; i < lop->siso-1;i++){
      for(int j = i+1; j < (lop->siso);j++){
        if(lop->dssv[i]->dtb < lop->dssv[j]->dtb){
            splaceNumber(lop->dssv[i]->dtb,lop->dssv[j]->dtb);
            splaceString(lop->dssv[i]->hoten,lop->dssv[j]->hoten);
            splaceString(lop->dssv[i]->masv,lop->dssv[j]->masv);

        }
      }
    }
}
void in_dssv(Lop *lop) {
  printf("%-32s%-32s%-32s\n","Ma so sinh vien","Ho ten","Diem trung binh");
  for(int i = 0; i <lop->siso;i++){
    printf("%-32s%-32s%-32.1f\n",lop->dssv[i]->masv,lop->dssv[i]->hoten,lop->dssv[i]->dtb);
  }
}
int main(int argc, char const *argv[]) {

    Lop *class0;
    class0 = (Lop*)malloc(sizeof(Lop));
    nhap_dssv(class0);
    in_dssv(class0);


    return 0;
}
