/*Abrir uma imagem colorida, transformar em tom de cinza, visualizar imagem de entrada. Criem uma matriz de forma estática com as mesmas dimensões da imagem de entrada (vejam nas propriedades da imagem no Windows). Apliquem uma convolução fazendo uma varredura na matriz utilizando as máscaras do operador gradiente Sobel (procurem no google). Visualizem os resultados e salvem. Obs: Busquem compreender os resultados do operador Sobel (parece com o de canny, apenas parece).*/

/* by @VivianeSouza923 */

#include "opencv\cv.h"
#include "opencv\highgui.h"

/*esses carinhas sempre vão existir por aqui*/
using namespace std;
using namespace cv;

int main(){

    Mat imcolor, imcinza;
    Mat grad_sob;

    /*abrir uma imagem colorida*/
    imcolor = imread("a.jpg", 1);
    /*transformar em tom de cinza*/
    cvtColor(imcolor, imcinza, CV_RGB2GRAY);
    /*visualizar imagem de entrada*/
    imshow("imagem de entrada", imcolor);

    /*Criem uma matriz de forma estática com as mesmas dimensões da imagem de entrada (vejam nas propriedades da imagem no Windows). Apliquem uma convolução fazendo uma varredura na matriz utilizando as máscaras do operador gradiente Sobel (procurem no google).*/

    // Gradient X
    Sobel(imcinza, grad_sob_x, CV_16S, 1, 0, 3, 1, 0, BORDER_DEFAULT );
    convertScaleAbs(grad_sob_x, abs_grad_sob_x);

    // GRadient Y
    Sobel(imcinza, grad_sob_y, CV_16S, 0, 1, 3, 1, 0, BORDER_DEFAULT);
    convertScaleAbs(grad_sob_y, abs_grad_sob_y);

    addWeighted(abs_grad_sob_x, 0.5, abs_grad_sob_y, 0.5, 0, grad_sob);

    imshow("resultado", grad_sob);

    waitKey(0);

    return 0;



}
