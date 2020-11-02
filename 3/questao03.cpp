//Abrir uma imagem colorida em RGB, visualizar e salvar cada um dos canais separadamente. Obs: Busquem compreender o que significa cada um dos canais.

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <cmath>

//esses dois aqui sempre vão estar, logo após os includes.
using  namespace cv;
using namespace std;

int main()
 {	/* abrir uma imagem colorida em RGB. Aqui eu vou utilizar a minha função imread e ela receberá como parametros o nome da imagem salva no computador entre aspas e o numeral 1 (sim, ligado etc.). Tudo isso será armazenado na variável img que será antecedida por Mat*/
     Mat img = imread ("image.jpg", 1);
	 /*Criar um vetor para os tres canais*/
	 Mat channel [3];
	 /*Fun��o para a divis�o dos canais. split vai receber dois parametros: a variável onde está armazenada a minha imagem e o vetor criado*/
	 split (img, channel);  
	/* visualizar cada um dos canais separadamente. Aqui eu vou utilizar a função imshow que receberá como parametros o nome da janela que vai abrir e o canal (channel) que vai ser 0, 1 e 2 */
	 imshow ("GREEN", channel[0]);
	 imshow ("BLUE", channel[1]);
	 imshow ("RED", channel[2]);
	/*salvar separadamente. aqui eu vou utilizar a função imwrite que irá receber como parametros o nome que eu quero que fique salvo e os canais*/
	 imwrite ("image_green.jpg", channel[0]);
	 imwrite ("image_blue.jpg", channel[1]);
	 imwrite ("image_red.jpg", channel[2]);

     cvWaitKey(0);
 }
  
