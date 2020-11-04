/*Abrir uma imagem colorida, transformar em tom de cinza, visualizar imagem de entrada. Criem uma matriz de forma estática com as mesmas dimensões da imagem de entrada (vejam nas propriedades da imagem no Windows), peguem cada um dos pixels da imagem e coloquem na matriz que criaram. Imprimam esta matriz em um arquivo de texto (*.txt) do mesmo modo que ela está alocada.*/

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace std;
using namespace cv;

FILE*arq;

int main (){
    /*abrir uma imagem colorida. Utilizo o a função imread que irá receber o nome da imagem que está salva no computador. Tudo isso será atribuído à variável imcolor que será antecedida por Mat*/
    Mat imcolor = imread("a.jpg", 1);
    /*Criando a variável  imcinza*/
    Mat imcinza;
    /* transformar em tom de cinza. Para isso eu vou utilizar a função cvtColor que irá receber como parâmetros a imagem original, a variável que irá receber a imagem transformada em cinza e a função que de fato vai fazer essa transformação*/
    cvtColor(imcolor, imcinza, CV_RGB2GRAY);

    /*Criem uma matriz de forma estática com as mesmas dimensões da imagem de entrada*/
    arq=fopen("resultado.txt", "w");
    int x, y;
    for (y = 0; y < imcinza.rows; y++){
        for (y = 0; y < imcinza.cols; y++){
            fprint(arq, "%d ", imcinza.at<uchar>(x, y));
        }
    }   fprint(arq, "\n");

    imshow("resultado", imcinza);
    imwrite("resultado.jpg", imcinza);
    fclose(arq);
    cvWaitKey(0);

}