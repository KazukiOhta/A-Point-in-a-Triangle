#include <stdio.h>
#include <math.h>

float data[8][100];

float a;
float b;

int i;
int j;
int n;

int OK_another;
int OK_p;
int OK;



int main(int argc, const char * argv[]) {
    
    n = 0;
    while (scanf("%f %f %f %f %f %f %f %f",&data[n][0],&data[n][1],&data[n][2],&data[n][3],&data[n][4],&data[n][5],&data[n][6],&data[n][7]) != EOF) {
        n ++;
    }
    for (i = 0; i < n; i ++) {
        for (j = 0; j < 3; j ++) {
            OK_another = 0;
            OK_p = 0;
            if (data[i][(j*2)%6] == data[i][((j+1)*2)%6]) {
                if (data[i][((j+2)*2)%6] > data[i][((j+1)*2)%6]) {
                    OK_another = 1;
                } else {
                    OK_another = -1;
                }
                if (data[i][6] > data[i][((j+1)*2)%6]) {
                    OK_p = 1;
                } else {
                    OK_p = -1;
                }
                if (OK_another == OK_p) {
                    OK ++;
                }
            } else {
                a = (data[i][(j*2+1)%6]-data[i][((j+1)*2+1)%6])/(data[i][(j*2)%6]-data[i][((j+1)*2)%6]);
                b = data[i][(j*2+1)%6] - a * data[i][(j*2)%6];
                
                if (data[i][((j+2)*2+1)%6] > a*data[i][((j+2)*2)%6] + b) {
                    OK_another = 1;
                } else {
                    OK_another = -1;
                }
                if (data[i][7] > a*data[i][6] + b) {
                    OK_p = 1;
                } else {
                    OK_p = -1;
                }
                if (OK_another == OK_p) {
                    OK ++;
                }
            }
        }
        if (OK == 3) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        OK = 0;
    }
    return 0;
}
