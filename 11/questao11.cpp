/*#Abrir uma imagem colorida com o fundo branco e um quadrado preto centralizado, transformar em tom de cinza, visualizar imagem de entrada. Criem uma matriz de forma estática com as mesmas dimensões da imagem de entrada (vejam nas propriedades da imagem no Windows), peguem cada um dos pixels da imagem e coloquem na matriz que criaram. Calculem as coordenadas (xc,yc) que representam o centróide deste quadrado. Tentem pintar ou marcar ele na imagem para visualização. Xc será a média todas as coordenadas x que fazem parte do quadrado, e yc é as médias de y do quadrado. As coordenadas do quadrado são identificadas pelo tom preto(valor 0). Façam esta imagem de entrada no Paint.*/

#include "opencv\cv.h"
#include "opencv\highgui.h"

/*sempre vai ter*/
using namespace std;
using namespace cv;

/*declarando variáveis*/
Mat imcolor;
Mat imcinza;
int y, x, num;
float xc=0, yc=0;

int main(){
    /*Abrir uma imagem colorida com o fundo branco e um quadrado preto centralizado*/
    imcolor = imread("a.jpg");
    /*transformar em tom de cinza*/
    cvtColor(imcolor, imcinza, CV_RGB2GRAY);
    /*Criem uma matriz de forma estática com as mesmas dimensões da imagem de entrada (vejam nas propriedades da imagem no Windows), peguem cada um dos pixels da imagem e coloquem na matriz que criaram.*/
    for (y = 0; y < imcinza.rows; y++){
        for (y = 0; y < imcinza.cols; y++){
            gray.at<uchar>(y,x);
            if (gray.at<uchar>(y,x) < 127)
                gray.at<uchar>(y,x) = 1;
            else
                gray.at<uchar>(y,x) = 0;
            if (gray.at<uchar>(y,x) == 0){
                xc += x;
                yc += y;
                num++;
            }
            
        }
    }

    /*cálculo da centróide*/
    xc = xc/num;
    yc = yc/num;

    printf("X - %d\nY - %d\n", xc, yc);

    /*Descrever a fun��o circle:
	       Imagem onde se quer desenhar o circulo
		   O centro do circulo
		   O raio do circulo
		   A cor do circulo
		   A espessura da linha do circulo: caso positivo - tracejado, se negativo - preenchido
		   Tipo de linha
		   N�mero de bits fracion�rios nas coordenadas do centro e no valor do raio
	 */
    circle(imcolor, Point(xc, yc), 10, CV_RGB(0,0,255), -1, 8, 0);

    /*visualizar e salvar*/
    imread("original", imcolor);
    imwrite("original.jpg", imcolor);
    imread("cinza", imcinza);
    imwrite("cinza.jpg", imcinza);

    waitKey(0);

    system("pause");
    return 0;

}   
