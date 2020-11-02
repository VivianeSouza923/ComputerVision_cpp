//abrir uma imagem colorida, visualizar e salvar

#include "opencv\cv.h"
#include "opencv\highgui.h"

//sempre vou te que colocar esses dois aqui, logo após os meus includes.
using namespace std; 
using namespace cv;

int main()
 {	/*abrir uma imagem colorida. Aqui eu tô pegando a minha função cv::imread e ela receberá como
	parametros o nome da imagem que eu salvei no computador dentro de aspas e o numeral 1 (sim, ligado etc.). Tudo isso será armazenado na variável img que está sendo antecedida por Mat*/
	 Mat img = cv::imread ("image.jpg", 1);

	 /*visualizar. Aqui eu vou utilizar a função imshow e ela receberá como parametros o nome do quadro, da janelinha que vai abrir e a variável que contém a imagem salva do computador*/
	 imshow ("IMAGE", img);

	 /*salvar. Aqui eu vou utilizar a minha função imwrite que receberá como parametro o nome que eu desejo por na minha imagem salva e a variável que contém a imagem original*/
	 imwrite ("image-save.jpg", img);

	 //boto um waitKey(0) pra determinar quanto tempo a imagem vai ficar aberta
     waitKey(0);

	 return 0;
 }
  
