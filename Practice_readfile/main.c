#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int Q,W,E,R,T,Y,U,I,O,P,A,S,D,F,G,H,J,K,L,Z,X,C,V,B,N,M;
} languege;

int main(){
    FILE *fr = fopen("Practice\\lab1.txt","r");
    FILE *fw = fopen("Practice\\lab1_copy.txt","w");
    int c;
    int counter = 0;
    languege LANG;
    LANG.Q = 0;LANG.W = 0;LANG.E = 0;LANG.R = 0;LANG.T = 0;LANG.Y = 0;LANG.U = 0;LANG.I = 0;LANG.O = 0;
    LANG.P = 0;LANG.A = 0;LANG.S = 0;LANG.D = 0;LANG.F = 0;LANG.G = 0;LANG.H = 0;LANG.J = 0;LANG.K = 0;
    LANG.L = 0;LANG.Z = 0;LANG.X = 0;LANG.C = 0;LANG.V = 0;LANG.B = 0;LANG.N = 0;LANG.M = 0;
    while(1){
        if(feof(fr)) break;
        c = fgetc(fr);
        if((c != '\n') && (c !='\0') && (c != ' ')) counter++;
        switch (c)
        {
        case 'q': LANG.Q++ ;break;case 'w': LANG.W++;break;case 'e': LANG.E++;break;
        case 'r': LANG.R++ ;break;case 't': LANG.T++;break;case 'y': LANG.Y++;break;
        case 'u': LANG.U++ ;break;case 'i': LANG.I++;break;case 'o': LANG.O++;break;
        case 'a': LANG.A++ ;break;case 's': LANG.S++;break;case 'd': LANG.D++;break;
        case 'f': LANG.F++ ;break;case 'g': LANG.G++;break;case 'h': LANG.H++;break;
        case 'j': LANG.J++ ;break;case 'k': LANG.K++;break;case 'l': LANG.L++;break;
        case 'z': LANG.Z++ ;break;case 'x': LANG.X++;break;case 'c': LANG.C++;break;
        case 'v': LANG.V++ ;break;case 'b': LANG.B++;break;case 'n': LANG.N++;break;
        case 'm': LANG.M++ ;break;
        default:
            break;
        }
        
    }
   
    
}