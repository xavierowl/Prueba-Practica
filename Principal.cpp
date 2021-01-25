#include <iostream>
#include <cstdlib>

#include <cmath>

#include <opencv2/core/core.hpp>

#include <opencv2/imgcodecs/imgcodecs.hpp>

#include <opencv2/highgui.hpp>

#include <opencv2/video/video.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[]){
    Mat img1 = imread("1.png");
    Mat img2 = imread("2.png");
    Mat img3 = img1.clone();
    int valor_y_1;
    int valor_y_2;
    int raiz;
    
    namedWindow("Imagen 1", WINDOW_AUTOSIZE);
    moveWindow("Imagen 1", 300, 300);
    namedWindow("Imagen 2",WINDOW_AUTOSIZE);
    moveWindow("Imagen 2", 600, 300);
    namedWindow("Imagen 3",WINDOW_AUTOSIZE);
    moveWindow("Imagen 3", 900, 300);
     
    //Se recorre todos los pixeles aplicando la ecuación del círulo
    for(int i = 0; i < img1.rows; i++){
        for(int j = 0; j < img1.cols; j++){
            raiz = 256-((j-102)*(j-102));
            if(raiz > 0){
                raiz = sqrt(raiz);
                valor_y_1 = raiz + 64;
                valor_y_2 = (raiz*-1)+64;
                
                while(valor_y_2 < valor_y_1){
                    img3.at<Vec3b>(j,valor_y_1)[0] = img2.at<Vec3b>(j,valor_y_1)[0];
                    img3.at<Vec3b>(j,valor_y_1)[1] = img2.at<Vec3b>(j,valor_y_1)[1];
                    img3.at<Vec3b>(j,valor_y_1)[2] = img2.at<Vec3b>(j,valor_y_1)[2];
                    img3.at<Vec3b>(j,valor_y_2)[0] = img2.at<Vec3b>(j,valor_y_2)[0];
                    img3.at<Vec3b>(j,valor_y_2)[1] = img2.at<Vec3b>(j,valor_y_2)[1];
                    img3.at<Vec3b>(j,valor_y_2)[2] = img2.at<Vec3b>(j,valor_y_2)[2];
                    valor_y_2 = valor_y_2+1;
                }
                //cout<<"Los valores son: "<<valor_y_1<<" y "<<valor_y_2<<endl;
            }
        }
    }
    
    //x = 64 y = 102 radio = 16
    
    imshow("Imagen 1", img1);
    imshow("Imagen 2", img2);
    imshow("Imagen 3", img3);

    waitKey(0);
    
    imwrite("Resultado.png", img3);
    
    return 0; 
}
