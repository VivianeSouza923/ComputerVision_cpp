/*#Abrir uma imagem colorida, transformar em tom de cinza, visualizar imagem de entrada. Apliquem os filtros passa alta de canny (cv_canny), visualizem os resultados e salvem. Obs: busquem compreender os resultados do filtro.*/

#include "opencv\cv.h"
#include "opencv\highgui.h"

/*esses dois sempre vão estar por aqui*/
using namespace std;
using namespace cv;

int main()
 {	/*abrir uma imagem colororida. Aqui eu vou utilizar a função imread que receberá como parametro o nome que está salvo no computador dentro de aspas */
    Mat img = imread ("teste.jpg");
	/* eu vou criar a variável img_gray e a img_filter*/
	Mat img_gray;
	Mat img_filter;
	/*transformar em tom de cinza. Vou usar a função cvtColor que receberá como parametros a imagem orifinal, a variável que irá armazenar a imagem transformada e a função que de fato irá fazer a mudança*/
	cvtColor (img, img_gray, CV_BGR2GRAY);
	/*visuaizar imagem de entrada. VOu utilizar imshow que irá receber como parametros o nome da janela e a variável que contém a imagem.*/
	imshow ("IMAGE", img_gray);
	/*Apliquem os filtros passa alta de canny (cv_canny). Utilizo a função Canny que irá receber como parametros a imagem cinza, a variável que irá armazenar a mudança que iremos fazer e os limiares.*/ 
	Canny (img_gray, img_filter, 120, 100, 3);
	/*visualizem os resultados e salvem*/
	imshow ("IMAGEM COM FILTRO", img_filter);
	imwrite ("resultado.jpg", img_filter)
    cvWaitKey(0);
 }
  
