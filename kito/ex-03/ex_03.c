#include <stdio.h>
#include <stdlib.h>

float tinhHeSoXepLoaiHocBong(double diemMH[], int soMH, int diemRL){
    if(soMH > 0){
        //tinh tong diem
        double tongDiem = 0;
        for(int i = 0; i < soMH; ++i)
            tongDiem += diemMH[i];
        
        //tinh diem tb
        double diemTB = tongDiem / soMH;

        // xep loai hb
        double heSo = 0;

        if (diemTB >= 9){
            if (diemRL >= 90)
                heSo = 1.2;
            else if (diemRL >= 80)
                heSo = 1.1;
            else if (diemRL >= 65)
                heSo = 1.0;
        }
        else if ((diemTB >= 8 && diemTB < 9)){
            if (diemRL >= 80)
                heSo = 1.1;
            else if (diemRL >= 65)
                heSo = 1.0;
        }
        else if ((diemTB >= 7 && diemTB < 8)){
            if (diemRL >= 65)
                heSo = 1.0;
        }
        
        return heSo;
    }

    return -1;
}


int main(void){
    int soMH = 4, i;
    scanf("%d",&soMH);
    double *diemMH = (double*)malloc(soMH * sizeof(double));
    for(i = 0; i < soMH; ++i)
        scanf("%f",&diemMH[i]);
    int diemRL = 4;
    scanf("%d",&diemRL);

    printf("%.2f",tinhHeSoXepLoaiHocBong(diemMH, soMH, diemRL));
    return 0;
}