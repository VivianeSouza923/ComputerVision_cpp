/*#Abrir uma imagem colorida, transformar em tom de cinza, visualizar imagem de entrada. Criem uma matriz de forma estática com as mesmas dimensões da imagem de entrada (vejam nas propriedades da imagem no Windows), peguem cada um dos pixels da imagem e coloquem na matriz que criaram. Apliquem uma limiarização fazendo uma varredura na matriz. Imprimam esta matriz em um arquivo de texto (*.txt) do mesmo modo que ela está alocada.*/

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace std;
using namespace cv;

Mat imcolor;
Mat imcinza;
FILE*fp;

int main()
{   /*Abrir uma imagem colorida, transformar em tom de cinza, visualizar imagem de entrada. */
    imcolor = imread("a.jpg");
    cvtColor(imcolor, imcinza, CV_RGB2GRAY);
    imshow("visualizar imagem de entrada", imcinza);

    fp = fopen("resultado.txt", "w");

    /*Apliquem uma limiarização fazendo uma varredura na matriz. Imprimam esta matriz em um arquivo de texto (*.txt) do mesmo modo que ela está alocada.*/
    for(int x = 0; y < imcinza.rows; y++){
        for(int x = 0; y< imcinza.cols; y++){
            imcinza.at<uchar>(y,x);
            if (imcinza.at<uchar>(y,x) < 127)
                fprint(fp, "1 ");
            else
                fprint(fp, "0 ");
            

        }
        fprint(fp, "\n");
    }

    fclose(fp);
    cvWaitKey(0);

    return 0;

}