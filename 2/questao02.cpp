//Abrir uma imagem colorida, transformar em níveis de cinza, visualizar e salvar imagem gerada.

#include "opencv\cv.h"
#include "opencv\highgui.h"

//esses dois sempre tem que estar presente 
using namespace cv;
using namespace std;

int main()
{	/* abrir uma imagem colorida. Aqui eu vou utilizar a minha função imread e ela receberá como 		parametros o nome da minha imagem salva no computador e o numeral 1 (sim, ligado etc.). VOu
	armazenar tudo isso na variável img (ela será antecedida por Mat)*/
     Mat img = imread ("teste.jpg", 1);

	 //vou criar a variável que vai armazenar a minha imagem colorida transformada e tons de cinza
	 Mat img_gray;

	 /*transformar em níveis de cinza. Aqui eu vou utilizar a função cvtColor que receberá como parametros a variável onde está armazenada a imagem original, a variável onde ficará armazenada a imagem transformada em níveis de cinza e por fim, a função cor cinza.*/
	 cvtColor (img, img_gray, CV_BGR2GRAY);

	 /* visualizar. Aqui eu vou utilizar a função imshow que receberá como parametros o nome do quadro, da janelinha que vamos abrir para visualizar a imagem e a variável que contem a imagem transformada*/
	 imshow ("IMAGE", img_gray);

	 /* e salvar a imagem gerada. Aqui eu vou utilizar a função imwrite que receberá como parametros o nome que eu quero que fique no novo arquivo e a variável onde está armazenada a imagem transformada */
	 imwrite ("teste_filtro.jpg", img_gray);
	 waitKey(0);
	 return 0;
}
  
