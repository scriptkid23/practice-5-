#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct{
  char masv[32];
  //về cơ bản nếu mã số sv có 7 ký tự thì ta nên cho thêm  ít nhất 10 ô bộ nhớ để tránh lỗi xảy ra
  // ở đây cho  thêm 32 ô bộ nhớ tránh lỗi xảy ra
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
/*
  hàm deleteNewline() này cho phép xóa bỏ ký tự \n trong hàm fgets
  vì khi sử dụng hàm fgets thì nó sẽ lưu cả ký tự \n vào trước mỗi ký tự ,
  điều này là không mong muốn với trường hợp ta muốn in dữ liệu ra màn hình
  các giá trị cùng 1 dòng
  nên phải sử dụng hàm deleteNewline() để xóa bỏ ký tự xuống dòng hay newline(\n)
*/
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
void splaceNumber(float *a, float *b){
  float temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
void splaceString(char a[], char b[]){

    char temp[100];
    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);

}
void sapxep_dssv(Lop *lop){
    for(int i = 0; i < (lop->siso)-1;i++){
      for(int j = i+1; j < (lop->siso);j++){
        if(lop->dssv[i]->dtb < lop->dssv[j]->dtb){
            splaceNumber(&lop->dssv[i]->dtb,&lop->dssv[j]->dtb);
            splaceString(lop->dssv[i]->masv,lop->dssv[j]->masv);
            splaceString(lop->dssv[i]->hoten,lop->dssv[j]->hoten);
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
void tim_diemtb(Lop *lop,float d){
    FILE * f_print = fopen("text/sv.out","w");
    int counter = 0;
    fprintf(f_print,"%-32s%-32s%-32s\n","Ma so sinh vien","Ho ten","Diem trung binh");
    for(int i = 0; i < lop->siso;i++){
      if( lop->dssv[i]->dtb > d){
        printf("%-32s%-32s%-32.1f\n",lop->dssv[i]->masv,lop->dssv[i]->hoten,lop->dssv[i]->dtb);
        fprintf(f_print,"%-32s%-32s%-32.1f\n",lop->dssv[i]->masv,lop->dssv[i]->hoten,lop->dssv[i]->dtb);
      }
      else{
        counter++;
      }

    }
    if(counter == lop->siso){
      printf("KHONG CO AI THOA MAN YEU CAU\n");
    }

}
int main(int argc, char const *argv[]) {

    Lop *class0;
    class0 = (Lop*)malloc(sizeof(Lop));
    nhap_dssv(class0);
    sapxep_dssv(class0);
    in_dssv(class0);
    tim_diemtb(class0,2.0);



    return 0;
}
