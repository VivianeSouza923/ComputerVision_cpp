/*Abrir uma imagem colorida, transformar para tom de cinza e aplicar uma Equalização de histograma utilizando a OpenCv, visualizando a imagem de entrada e seu respectivo histograma inicialmente, e, em seguida, o resultado da equalização e seu histograma. Esta técnica aumenta o contraste da imagem.*/

// by @VivianeSouza923

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace std;
using namespace cv;

Mat imcolor;
Mat imcinza;
Mat eqimcolor;
Mat hist_imcinza;
Mat hist_eqimcolor;

Mat histograma (Mat &imagem)
{

    // Definir as barras do histograma
    int bins = 256; //Quantidade de barras
    int histSize[] = {bins}; //Tamanho do histograma
 
    // O intervalo do histograma
    float lranges[] = {0, 256};
    const float* ranges[] = {lranges};
 
    Mat hist;
    int channels [] = {0}; //Numeros de canais, como a imagem de entrada й sу de um canal, vem 0
 
    int const hist_height = 256;
    Mat3b hist_image = Mat3b::zeros(hist_height, bins);
     
    calcHist(&imagem, 1, channels, Mat(), hist, 1, histSize, ranges, true, false); //Funзгo para criar o histograma
 
    double max_val=0;
    minMaxLoc(hist, 0, &max_val);
 
    // Visualizar cada barra
    for(int b = 0; b < bins; b++) 
    {
        float const binVal = hist.at<float>(b);
        int   const height = cvRound(binVal*hist_height/max_val);
        line (hist_image, Point(b, hist_height-height), Point(b, hist_height), Scalar::all(255)); 
        //    imagem      ponto inicial                 ponto final            
    }
    return hist_image;
}
 
int main()
{
 
    //Imagem de entrada
    imcolor = imread("a.jpg");
    //Converter pra cinza
    cvtColor (imcolor, imcinza, CV_RGB2GRAY);
 
    //Funзгo para equalizar
    equalizeHist (imcinza, eqimcolor); 
     
    imshow ("imagem em tons de cinza", imcinza);
    Mat hist_imcinza = histograma (imcinza);
    imshow("name1", hist_imcinza);

    imshow ("Equalized Image", eqimcolor);
    Mat hist_eqimcolor = histograma (eqimcolor);
    imshow("name2", hist_eqimcolor);
 //
	    imwrite ("imagementrada.jpg", imcinza);

	    imwrite ("Histogramaentrada.jpg", hist_imcinza);

	    imwrite ("imagemsaida.jpg", eqimcolor);

	    imwrite ("histrogramasaida.jpg", hist_eqimcolor);

    waitKey(0);
    return 0;
}
