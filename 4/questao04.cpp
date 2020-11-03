//Abrir uma imagem colorida, transformar em HSV, visualizar e salvar cada um dos canais separadamente. Obs: Busquem compreender o que significa cada um dos canais.

#include "opencv\cv.h"
#include "opencv\highgui.h"

//esses dois aqui sempre vão existir. Vão ser colocados logo após os includes
using namespace std;
using namespace cv;

int main()
 {	/*abrir uma imagem colorida. Aqui eu vou usar a minha função imread que receberá como parametros o nome do arquivo, como está salvo no computador dentro de aspas e o numeral 1(sim, ligado etc.)*/
     Mat img = imread ("teste.jpg", 1);
	 //vou criar a variável chamada HSV
	 Mat HSV;
	 //vou criar um vetor chamado channel com tamanho 3
	 Mat channel [3];
	/* transformar em HSV. Aqui eu vou utilizar a função cvtColor que receberá como parametros a variável quecontém o arquivo da imagem original, a variável que contém o arquivo da imagem transformada em HSV e a função de fato que vai fazer a transformação.*/
	 cvtColor (img, HSV, CV_RGB2HSV);
	// vou mostrar o resultado do HSV. Uso a função imshow que receberá como parametros o nome da janela que vai abrir e a variável que contém a imagem transformada
	 imshow ("IMAGE", HSV);
	//vou agora separar o HSV em canais, utilizando a função split. Recebemos a variável que contém a imagem transformada e o canal.
	 split (HSV, channel);
	//visualizar separadamente. VOu utilizar a minha função imshow que irá receber o nome que vai ficar na janela que vai abrir e o seu respectivo canal.
	 imshow ("IMAGE (CHANNEL-0)", channel[0]);
	 imshow ("IMAGE (CHANNEL-1", channel[1]);
	 imshow ("IMAGE (CHANNEL-2", channel[2]);
	//salvar separadamente. Vou utilizar a função imwrite. Ela vai receber o nome que euquero que fique salvo e a variável que contenha o que eu quero salvar.
	 imwrite ("teste1.jpg", HSV);
	 imwrite ("teste2.jpg", channel[0]);
	 imwrite ("teste3.jpg", channel[1]);
	 imwrite ("teste4.jpg", channel[2]);

     cvWaitKey(0);
 }
  
