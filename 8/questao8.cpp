/*Abrir uma imagem colorida, transformar em tom de cinza, visualizar imagem de entrada. Apliquem um redimensionamento da imagem, reduzindo e depois aumentando seu tamanho, visualizem os resultados e salvem. Obs: uma imagem 320×240 deve virar uma 160×120 em primeiro caso e 640×480 em segundo caso.*/

#include "opencv\cv.h"
#include "opencv\highgui.h"

/*a gente sempre começa com esses dois aqui, logo após os includes. */
using namespace std;
using namespace cv;

int main (){

    /*abrir uma imagem colorida */
    Mat imcolor = imread("a.jpg");
    Mat imcinza;
    Mat tamanho1;
    Mat tamanho2;

    /*transformar em tom de cinza*/
    cvtColor(imcolo, imcinza, CV_RGB2GRAY);

    /*VISUALIZAR IMAGEM DE ENTRADA*/
    imshow ("visualizar imagem de entrada", immcinza);

/*apliquem um redimensionamento de imagem*/

    /*a dimensão das imagens*/
    Size redimensionamento1 (160, 120);
    Size redimensionamento2 (640, 480);

    /* função para redimensionar a imagem. reduzindo e depois aumentando seu tamanho*/
    resize (imcinza, tamanho1, redimensionamento1);
    resize (imcinza, tamanho2, redimensionamento2);

    /*visualizem os resultados e salvem.*/
    imshow ("resultado dim", tamanho1);
    imshow ("resultado aum", tamanho2);
    imwrite ("resultado_dim.jpg", tamanho1);
    imwrite ("resultado_aum.jpg", tamanho2);

    waitKey(0)

    return 0;

}