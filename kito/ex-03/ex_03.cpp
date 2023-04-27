#include <iostream>

using namespace std;

float tinhHeSoXepLoaiHocBong(double diemMH[], int soMH, float diemRL){
    if(soMH > 0){
        //tinh tong diem
        double tongDiem = 0;
        for(int i = 0; i < soMH; ++i)
            tongDiem += diemMH[i];
        
        //tinh diem tb
        double diemTB = tongDiem / soMH;

        // xep loai hb
        double heSo = 0;

        if (diemTB > 9){
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


int main(){
    int soMH = 4;
    cin >> soMH;
    double *diemMH = new double[soMH];
    for(int i = 0; i < soMH; ++i)
        cin >> diemMH[i];
    int diemRL = 4;
    cin >> diemRL;

    cout << tinhHeSoXepLoaiHocBong(diemMH, soMH, diemRL);
}