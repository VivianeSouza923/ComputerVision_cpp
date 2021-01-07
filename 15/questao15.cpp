/*Abrir uma câmera, capturar uma imagem (frame), transforme em tom de cinza, visualizar imagem de entrada, aplique o filtro de canny e visualize os resultados. Continue infinitamente capturando, transformando em tom de cinza, aplicando canny e visualizando.*/

/* by @VivianeSouza923 */

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace std;
using namespace cv;

Mat imcinza;
Mat frame;
Mat filcanny;

int main(){

    //abrir uma cÂmera
    VideoCapture cap(0);

        if(!cap.isOpened())
            return 0;

    while (1)
    {   
        /*capturar uma imagem (frame)*/
        cap >> frame;
        /*transforme em tom de cinza*/
        cvtColor(frame, imcinza, CV_RGB2GRAY);
        //visualizar imagem de entrada
        imshow("imagem de entrada", imcinza);
        // aplique o filtro de Canny
        Canny(imcinza, filcanny, 120, 100, 3);

        //visualizar resultado
        imshow("resultado (vídeo)", filcanny);

        if(waitKey(30) >= 0)
            break;

    }
    return 0;
    


}