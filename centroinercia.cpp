#define M_PI 3.14159265358979323846
#include "centroinercia.h"
#include <math.h>
#include <cmath>
#include <vector>
#include <iomanip>

// ===========================================================
// ==================== MÉTODOS ÁREA =========================
// ===========================================================

// Entrada e saída
ostream &Area::Imprimir(ostream &X) const
{
    /*
    X << "Area total: ";
    */
    X << areaTotal /*<< endl*/;
    return X;
}

istream &Area::Ler(istream &X)
{
    do{
        cout << "===== ESCOLHA A FORMA DA FIGURA =====\n";
        cout << "1. Quadrado/Retangulo\n"
             << "2. Triangulo\n"
             << "3. Circulo\n"
             << "4. Semicirculo\n"
             << "5. Quarto de circulo" << endl;
        cout << "- Opcao: "; X >> opcao;

        switch(opcao){
        case 1:
            cout << "- Base/Altura: ";
            X >> base >> altura;
            AreaQuadrado();
            break;
        case 2:
            cout << "- Base/Altura: ";
            X >> base >> altura;
            AreaTriangulo();
            break;
        case 3:
            cout << "- Raio: ";
            X >> raio;
            AreaCirculo();
            break;
        case 4:
            cout << "- Raio: ";
            X >> raio;
            AreaSemiCirculo();
            break;
        case 5:
            cout << "- Raio: ";
            X >> raio;
            AreaQuartoCirculo();
            break;
        default:
            cout << "ENTRADA INVALIDA\n";
            break;
        }

    } while(opcao == 0 || opcao > 5);
    cout << "- Area existente? (1-Existe / 0-Nao existe) "; X >> hasArea;

    return X;
}

// Áreas
void Area::AreaQuadrado(){
    areaTotal = base*altura;
}

void Area::AreaTriangulo(){
    areaTotal = (base*altura)/2;
}

void Area::AreaCirculo(){
    areaTotal = M_PI * raio * raio;
}

void Area::AreaSemiCirculo(){
    areaTotal = (M_PI * raio * raio)/2;
}

void Area::AreaQuartoCirculo(){
    areaTotal = (M_PI * raio * raio)/4;
}

// ===========================================================
// ==================== MÉTODOS CENTROIDE ====================
// ===========================================================



ostream &Centroide::Imprimir(ostream &X) const
{
    /*
    X << "Dados totais da figura\n";
    X << "x: " << x << '\n'
      << "y: " << y << '\n'
      << "x*A: " << xA << '\n'
      << "y*A: " << yA << '\n';
    Area::Imprimir(X);
    X << endl;

    X << setw(20) << "x" << setw(20) << "y" << setw(20) << "x*A" << setw(20) << "y*A" << setw(20) << "A" << endl;
    */
    X << setw(15) << x << setw(15) << y << setw(15) << xA << setw(15) << yA << setw(15); Area::Imprimir(X); cout << endl;
    return X;
}

istream &Centroide::Ler(istream &X)
{
    cout << "- Posicao do centroide (x, y): ";
    X >> x >> y;
    //cout << "Digite os dados da area: \n";
    Area::Ler(X);
    SetProdutoX();
    SetProdutoY();

    return X;
}

// =========================================================
// ==================== MOMENTO INÉRCIA ====================
// =========================================================

