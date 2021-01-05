/*Abram um arquivo de texto (pode ser o mesmo gerado na questão 10), criem uma imagem em tom de cinza e visualizem esta imagem.*/

#include "opencv\cv.h"
#include "opencv\highgui.h"

/*sempre terá nos códigos C++, usando o OpenCV*/

using namespace std;
using namespace cv;

FILE*fp;
Mat imcinza;

int main(){

    /*Abram um arquivo de texto (pode ser o mesmo gerado na questão 10)*/
        fp = fopen("resultado.txt", "r");

    /*vamos verificar se é possível abrir o arquivo, caso não, emitimos uma mensagem de aviso*/
        if (!fp)
    {
            printf("Não foi possível abrir o arquivo\n");
            return 0;
    }

    /*quantidade de  linhas*/
    /*VAMOS COMEÇAR ARMAZENANDO 100 CARACTERES NA VARIÁVEL NAME. AQUI TEMOS UM VETOR DE CHAR COM 100 CARACTERES*/
        char name [100];
    /*TÔ INICIANDO AS NOSSAS LINHAS, OBVIAMENTE VOU INCIAR COM ZERO*/
        int qline = 0;
    /*VOU INCREMENTAR AS LINHAS, ENQUANTO MEU FGETS FOR DIFERENTE DE ZERO. MEU FGETS RECEBE NAME, 100 E O FP*/
        do
        {
            qline++;

        } while(fgets(name, 100, fp) != NULL);
        fclose(fp);
    
    /*quantidade de números*/
    fp = fopen ("resultado.txt", "r");
        /*aqui eu vou criar as variáveis number e qnumber. Number será nosso número de fato e nosso qnumber, nossa quantidade de números*/
        int number;
        int qnumber = 0;
        /*enquanto a condição for verdadeira, vamos armazenando o nosso número e incrementando*/
        while(!feof (fp)){

            fscanf(fp, "%d", &number);
            qnumber++;
        }/*após isso, fecha o arquivo*/
        fclose(fp);

        /*quantidade de colunas*/

        int qcols = (qnumber - 1)/qline;
        printf("COLUNAS: %d, LINHAS: %d, NUMEROS: %d\n", qcols, qline, qnumber);
        /*BORA PEGRA AS PROPRIEDADES DA IMAGEM*/
        Mat_<Vec3b> imcinza (qline, qcols, CV_8UC3);


}   

