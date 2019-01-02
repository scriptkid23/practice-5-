#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[256];
    float prize[100];
} ELEMENT;
//đếm số khoảng cách có trong 1 chuỗi
int  counterSpace(char prop[]){
    int counter = 0;
    for(int i = 0; i < strlen(prop);i++){
        if (prop[i] == ' ') counter++;
    }
    return counter;
}
//xác định vị trí khoảng cách giữa tên sản phẩm và các giá của sản phẩm
int locationSpaceEX(char prop[]){
    int locationSpace = counterSpace(prop) - 5;
    int counter = 0;
    int location;
    for(int i = 0 ; i < strlen(prop);i++){
        if(prop[i] == ' '){
            counter++;
            if(counter == locationSpace){
                location = i;
                break;
            }
        }

    }
    return location;
}
//sau khi xác định đc khoảng cách ta sẽ thay thế khoảng cách bằng ký tự '\n'
void convert(char prop[]){
    prop[locationSpaceEX(prop)] = '\n';
}
// hàm deleteNewline để xử lý những tình huống khác mà đề bài ra nhưng ở đây chúng ta 
// sẽ không sử dụng hàm này
void deleteNewline(char prop[]){
    prop[strlen(prop)-1] = '\0';
}
//sau khi đã xây dựng các hàm , xây dựng hàm convertText_ để tạo ra 1 file mới
// dễ xử lý hơn file cũ mà đề bài ra 

void convertText_(int prop,int *number){
    FILE *fr_hello = fopen("texts/hello.txt","r");
    FILE *fr_convert = fopen("texts/convert.txt","w");
    int number_mer;
    char name[1000];
    char temp[100];
    fscanf(fr_hello,"%d",&number_mer);
    fgets(temp,sizeof(temp),fr_hello);
    for(int i = 0 ; i < prop;i++){
        fgets(name,sizeof(name),fr_hello);
        convert(name);
        fprintf(fr_convert,"%s",name);
    }
    *number = number_mer;
    fclose(fr_convert);
    fclose(fr_hello);
    
}
int main(){
    int number;
    ELEMENT sp[100];
    convertText_(7,&number);
    char temp[10];
    FILE *fop = fopen("texts/convert.txt","r");
    printf("%d\n",number);
    for(int i = 0; i < 6; i++){
        fgets(sp[i].name,sizeof(sp[i].name),fop);
        for(int j = 0; j < 6;j++){
            fscanf(fop,"%f",&sp[i].prize[j]);
        }
        fgets(temp,sizeof(temp),fop);
    }
}