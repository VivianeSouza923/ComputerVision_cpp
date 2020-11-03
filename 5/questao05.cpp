//Abrir uma imagem colorida, transformar em tom de cinza, visualizar imagem de entrada. Apliquem os filtros passa baixa mediana (cv_median) e media (cv_blur), visualizem os resultados e salvem.Obs: busquem compreender os resultados de cada filtro.


#include "opencv\cv.h"
#include "opencv\highgui.h"

/* esses dois sempre vão estar aqui. */
using namespace std;
using namespace cv;

int main()
 {	/*abrir uma imagem colorida. Aqui eu vou utilizar a função imread que receberá como parametros o nome da minha imagem que está salva no computador, entre parênteses e o numeral 1 (sim, ligado etc.) Tudo isso eu vou atribuir a variável img que sera antecedida pelo Mat. */
     Mat img = imread ("image.jpg", 1);
	 /* vou criar a variável gray, media e mediana */
	 Mat gray;
	 Mat media;
	 Mat mediana;
	/* transformar em tom de cinza. Aqui eu utilizei a função cvtColor que receber como parametros a variável onde está armazenada a imagem que quero transformar, a variável que vai conter a imagem em tom de cinza e por fim, a CV_RGB2GRAY que é o que vai dar o tom cinza.*/
	 cvtColor (img, gray, CV_RGB2GRAY);
	/*Apliquem os filtros passa baixa mediana (cv_median) e media (cv_blur). Aqui eu vou utilizar medianBlur que vai receber a minha imagem já cinza, a media que é onde vai ficar armazenada as mudanças que serão feitas agora e o numeral 5)*/
	 medianBlur (gray, media, 5);
	/*visualizem os resultados. Utilizo o imshow e ele receberá como paramtros o nome da janelinha e a variável que contém a imagem que eu quero mostrar.*/
	 imshow ("Original", img);

	 imshow ("Media", media);
	/*salvar os resultados. Para salvar, eu utilizo o imwrite que receberá como paramtros o nome que eu desjo que fique no arquivo e a variável que contém as mudanças feitas na imagem.*/
	 imwrite ("media.jpg", media);
	 waitKey(0);
	 return 0;
}
  
