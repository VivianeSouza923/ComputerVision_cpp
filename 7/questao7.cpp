/*Abrir uma imagem colorida, transformar em tom de cinza, visualizar imagem de entrada. Apliquem uma limiarização (thresholding), visualizem os resultados e salvem. Obs: busquem compreender os resultados da técnica.*/

#include "opencv\cv.h"
#include "opencv\highgui.h"

/*esses dois sempre estão por aqui*/
using namespace std;
using namespace cv;

int main (){
    /* abrir uma imagem colorida*/
    Mat imcolor = imread("a.jpg");
    Mat imcinza;
    Mat thresh1;
	Mat thresh2;
	Mat thresh3;
	Mat thresh4;
	Mat thresh5;
    /*transformar em tom de cinza*/
    cvtColor(imcolor, imcinza, CV_BGR2GRAY);
    /*visualizar imagem de entrada*/
    imshow("visualizar", imcinza);
    /*Apliquem uma limiarização (thresholding)*/
    threshold (imcinza, thresh1, 127, 255, CV_THRESH_BINARY);
    threshold (imcinza, thresh2, 127, 255, CV_THRESH_BINARY_INV);
    threshold (imcinza, thresh3, 127, 255, CV_THRESH_TRUNC);
    threshold (imcinza, thresh4, 127, 255, CV_THRESH_TOZERO);
    threshold (imcinza, thresh5, 127, 255, CV_THRESH_TOZERO_INV);

    /* visualizar */
    imshow ("resultado 1", thresh1);
    imshow ("resultado 2", thresh2);
    imshow ("resultado 3", thresh3);
    imshow ("resultado 4", thresh4);
    imshow ("resultado 5", thresh5);

    waitKey(0);

    /*salvem os resultados*/
    imwrite ("resultado1.jpg", thresh1);
    imwrite ("resultado2.jpg", thresh2);
    imwrite ("resultado3.jpg", thresh3);
    imwrite ("resultado4.jpg", thresh4);
    imwrite ("resultado5.jpg", thresh5);

    return 0;





}

