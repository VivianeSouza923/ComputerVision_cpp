/*Abrir uma câmera, capturar uma imagem (frame), transforme em tom de cinza, visualizar imagem de entrada. Continue infinitamente capturando, transformando em tom de cinza e vizualizando.*/

/* by @VivianeSouza923 */

#include "opencv\cv.h"
#include "opencv\highgui.h"

/*esses carinhas sempre irão existir*/
using namespace std;
using namespace cv;

Mat imcinza;
Mat frame;

int main(){

    /*Abrir uma câmera*/

    VideoCapture cap(0);

        if (!cap.isOpened())
            return 0;


        while(1){


            /*capturar uma imagem (frame)*/
            cap >> frame;

            /*transforme em tom de cinza*/
            cvtColor(frame, imcinza, CV_RGB2GRAY);

            /*visualizar imagem de entrada*/
            imshow("resultado", imcinza);
    
            if (waitKey(30) >= 0 )
                break;



        }

        return 0;





}
