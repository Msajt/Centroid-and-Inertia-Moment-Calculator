#define M_PI 3.14159265358979323846
#include <math.h>
#include "centroide-inercia.h"
#include "cmath"
#include <iomanip>

using namespace std;

int main()
{
    char again;

    cout << "===========================================================\n";
    cout << "===== CALCULADORA DE CENTROIDES E MOMENTOS DE INERCIA =====\n";
    cout << "===========================================================\n";
    cout << endl;

    do{

    // Variaveis
    vector<Centroide> tabela;
    int tamanho=0;
    double somaArea = 0.0, somaXA = 0.0, somaYA = 0.0;

    // Entrada da quantidade de figuras
    cout << "===========================================================\n";
    do{
        cout << "Digite a quantidade de figuras:\n";
        cout << "- Total de figuras: "; cin >> tamanho;
    } while(tamanho <= 0);
    cout << "===========================================================\n";
    cout << endl;

    // Entrar com dados
    for(int i=0; i<tamanho; i++){
        cout << "     ===== DADOS DA FIGURA " << i+1 << "=====\n";
        Centroide C;
        cin >> C;
        tabela.push_back(C);
        cout << endl;
    }
    cout << endl;

    cout << "===============================================================================\n";
    cout << "================================= RESULTADOS ==================================\n";
    cout << "===============================================================================\n";

    // Imprimir os dados do centroide e somatorios
    cout << setw(15) << "x" << setw(15) << "y" << setw(15) << "x*A" << setw(15) << "y*A" << setw(15) << "A" << endl;
    cout << endl;
    for(int i=0; i<tamanho; i++){
        cout << tabela[i];
        if(tabela[i].GetHasArea()){
            somaArea += tabela[i].GetAreaTotal();
            somaXA += tabela[i].GetProdutoX();
            somaYA += tabela[i].GetProdutoY();
        } else{
            somaArea -= tabela[i].GetAreaTotal();
            somaXA -= tabela[i].GetProdutoX();
            somaYA -= tabela[i].GetProdutoY();
        }
    }
    cout << endl;

    // Imprimir somatório
    /*
    cout << "Somatorio area: " << somaArea
         << "\nSomatorio X*A: " << somaXA
         << "\nSomatorio Y*A: " << somaYA << endl;
    */
    cout << setw(15) << "SOMA AREA" << setw(15) << "SOMA X*A" << setw(15) << "SOMA Y*A" << endl;
    cout << setw(15) << somaArea << setw(15) << somaXA << setw(15) << somaYA << endl;
    cout << endl;

    double centroideX=0.0, centroideY=0.0;
    long double totalInerciaX=0.0, totalInerciaY=0.0;
    centroideX = somaXA/somaArea;
    centroideY = somaYA/somaArea;

    for(int i=0; i<tamanho; i++){
        switch(tabela[i].GetOpcao()){
        case 1:
            if(tabela[i].GetHasArea()){
            totalInerciaY += ( ( (pow(tabela[i].GetBase(), 3))*tabela[i].GetAltura() )/12 ) +
                             tabela[i].GetAreaTotal() * pow((tabela[i].GetX()-centroideX), 2);
            totalInerciaX += ( ( (pow(tabela[i].GetAltura(), 3))*tabela[i].GetBase() )/12 ) +
                             tabela[i].GetAreaTotal() * pow((tabela[i].GetY()-centroideY), 2);
            } else{
                totalInerciaY -= ( ( (pow(tabela[i].GetBase(), 3))*tabela[i].GetAltura() )/12 ) +
                                 tabela[i].GetAreaTotal() * pow((tabela[i].GetX()-centroideX), 2);
                totalInerciaX -= ( ( (pow(tabela[i].GetAltura(), 3))*tabela[i].GetBase() )/12 ) +
                                 tabela[i].GetAreaTotal() * pow((tabela[i].GetY()-centroideY), 2);
            }
            break;
        case 2:
            if(tabela[i].GetHasArea()){
            totalInerciaY += ( ( (pow(tabela[i].GetBase(), 3))*tabela[i].GetAltura() )/36 ) +
                             tabela[i].GetAreaTotal() * pow((tabela[i].GetX()-centroideX), 2);
            totalInerciaX += ( ( (pow(tabela[i].GetAltura(), 3))*tabela[i].GetBase() )/36 ) +
                             tabela[i].GetAreaTotal() * pow((tabela[i].GetY()-centroideY), 2);
            } else{
                totalInerciaY -= ( ( (pow(tabela[i].GetBase(), 3))*tabela[i].GetAltura() )/36 ) +
                                 tabela[i].GetAreaTotal() * pow((tabela[i].GetX()-centroideX), 2);
                totalInerciaX -= ( ( (pow(tabela[i].GetAltura(), 3))*tabela[i].GetBase() )/36 ) +
                                 tabela[i].GetAreaTotal() * pow((tabela[i].GetY()-centroideY), 2);
            }
            break;
        case 3:
            if(tabela[i].GetHasArea()){
            totalInerciaY += ( ( pow(tabela[i].GetRaio(), 4) * M_PI )/4 ) +
                             tabela[i].GetAreaTotal() * pow((tabela[i].GetX()-centroideX), 2);
            totalInerciaX += ( ( pow(tabela[i].GetRaio(), 4) * M_PI )/4 ) +
                             tabela[i].GetAreaTotal() * pow((tabela[i].GetY()-centroideY), 2);
            } else{
                totalInerciaY -= ( ( pow(tabela[i].GetRaio(), 4) * M_PI )/4 ) +
                                 tabela[i].GetAreaTotal() * pow((tabela[i].GetX()-centroideX), 2);
                totalInerciaX -= ( ( pow(tabela[i].GetRaio(), 4) * M_PI )/4 ) +
                                 tabela[i].GetAreaTotal() * pow((tabela[i].GetY()-centroideY), 2);
            }
            break;
        case 4:
            if(tabela[i].GetHasArea()){
            totalInerciaY += ( ( pow(tabela[i].GetRaio(), 4) * M_PI )/8 ) +
                             tabela[i].GetAreaTotal() * pow((tabela[i].GetX()-centroideX), 2);
            totalInerciaX += ( ( pow(tabela[i].GetRaio(), 4) * M_PI )/8 ) +
                             tabela[i].GetAreaTotal() * pow((tabela[i].GetY()-centroideY), 2);
            } else{
                totalInerciaY -= ( ( pow(tabela[i].GetRaio(), 4) * M_PI )/8 ) +
                                 tabela[i].GetAreaTotal() * pow((tabela[i].GetX()-centroideX), 2);
                totalInerciaX -= ( ( pow(tabela[i].GetRaio(), 4) * M_PI )/8 ) +
                                 tabela[i].GetAreaTotal() * pow((tabela[i].GetY()-centroideY), 2);
            }
            break;
        case 5:
            if(tabela[i].GetHasArea()){
            totalInerciaY += ( ( pow(tabela[i].GetRaio(), 4) * M_PI )/16 ) +
                             tabela[i].GetAreaTotal() * pow((tabela[i].GetX()-centroideX), 2);
            totalInerciaX += ( ( pow(tabela[i].GetRaio(), 4) * M_PI )/16 ) +
                             tabela[i].GetAreaTotal() * pow((tabela[i].GetY()-centroideY), 2);
            } else{
                totalInerciaY -= ( ( pow(tabela[i].GetRaio(), 4) * M_PI )/16 ) +
                                 tabela[i].GetAreaTotal() * pow((tabela[i].GetX()-centroideX), 2);
                totalInerciaX -= ( ( pow(tabela[i].GetRaio(), 4) * M_PI )/16 ) +
                                 tabela[i].GetAreaTotal() * pow((tabela[i].GetY()-centroideY), 2);
            }
            break;
        }
    }
    /*
    cout << "Centroide X: " << centroideX
         << "\nCentroide Y: " << centroideY
         << "\nMomento Inercia X: " << totalInerciaX
         << "\nMomento Inercia Y: " << totalInerciaY << endl;
    cout << "==================================================\n";
    */
    cout << setw(15) << "CENTROIDE X" << setw(15) << "CENTROIDE Y" << setw(15) << "MOM. INERCIA X" << setw(15) << "MOM. INERCIA Y" << endl;
    cout << setw(15) << centroideX << setw(15) << centroideY << setw(15) << totalInerciaX << setw(15) << totalInerciaY << endl;
    cout << "===============================================================================\n";
    cout << endl;

    cout << "- CONTINUAR? (Y)"; cin >> again;
    cout << endl;

    tabela.clear();

    } while(again == 'Y' || again == 'y');

    return 0;
}

