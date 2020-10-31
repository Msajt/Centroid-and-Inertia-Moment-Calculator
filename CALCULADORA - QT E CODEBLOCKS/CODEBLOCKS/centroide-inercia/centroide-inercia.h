#ifndef CENTROINERCIA_H
#define CENTROINERCIA_H

#include <iostream>
#include <vector>
using namespace std;

class Area{
    double base, altura, raio, areaTotal;
    unsigned opcao;
    bool hasArea;

public:
    // Construtor default
    inline Area(): base(0.0), altura(0.0), raio(0.0), areaTotal(0.0) {}

    // Saída e entrada
    ostream &Imprimir(ostream &X) const;
    istream &Ler(istream &X);
    friend ostream &operator<<(ostream &X, const Area &A){ return A.Imprimir(X); };
    friend istream &operator>>(istream &X, Area &A){ return A.Ler(X); };

    // Formatos
    void AreaQuadrado();
    void AreaTriangulo();
    void AreaCirculo();
    void AreaSemiCirculo();
    void AreaQuartoCirculo();

    // get
    inline double GetAreaTotal() { return areaTotal; }
    inline double GetBase() { return base; }
    inline double GetAltura() { return altura; }
    inline double GetRaio() { return raio; }
    inline unsigned GetOpcao() { return opcao; }
    inline bool GetHasArea() { return hasArea; }

};

class Centroide: public Area{
    double x, y, xA, yA;
    Area A;

public:
    // Construtores
    Centroide(): Area(), x(0.0), y(0.0), xA(0.0), yA(0.0) {}

    // Saída e entrada
    ostream &Imprimir(ostream &X) const;
    istream &Ler(istream &X);
    friend istream &operator>>(istream &X, Centroide &C) { return C.Ler(X); };
    friend ostream &operator<<(ostream &X, Centroide &C) { return C.Imprimir(X); };

    // get
    void SetProdutoX(){ xA = x * Area::GetAreaTotal(); }
    void SetProdutoY(){ yA = y * Area::GetAreaTotal(); }
    double GetX() { return x; }
    double GetY() { return y; }
    double GetProdutoX(){ return xA; }
    double GetProdutoY(){ return yA; }
};
/*
class TabelaCentroide: public Centroide{
    vector<Centroide> tabela;
public:
    TabelaCentroide() {}

    void Imprimir() const;
    void Ler();
};
*/
#endif // CENTROINERCIA_H

