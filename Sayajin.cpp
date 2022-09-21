#include "Sayajin.h"

#include <iostream>
using std::cout;
using std::endl;


const string Sayajin::GUERREIRO = "Guerreiro";
int Sayajin::numSayajin = 0;

Sayajin::Sayajin(string nome, string forma, double ki, bool espada, int nivel): NORMAL(ki)
{
  this->setNome(nome);
  this->setForma(forma);
  this->setKi(ki);
  this->setNivel(nivel);
  this->setEspada(espada);
  numSayajin += 1;
}

/*Sayajin::Sayajin(): NORMAL(7924), GUERREIRO("Guerreiro")
{
  this->setNome("Vegeta");
  this->setForma("Normal");
  this->setKi(7924);
  this->setNivel(0);
}*/

/*Sayajin::Sayajin(const Sayajin& copia): NORMAL(copia.ki), GUERREIRO(copia.GUERREIRO)
{
  this->setNome(copia.nome);
  this->setForma(copia.forma);
  this->setKi(copia.ki);
  this->setNivel(copia.nivel);
}*/

Sayajin::~Sayajin() {}

string Sayajin::getNome() const
{
  return nome;
}

string Sayajin::getForma() const
{
  return forma;
}

double Sayajin::getKi() const
{
  return ki;
}

void Sayajin::setNome(string nome) {
  if (nome.length() < 30) {
    this->nome = nome;
  }
}

void Sayajin::setForma(string forma) {
  if (forma.length() < 30) {
    this->forma = forma;
  }
}

void Sayajin::setKi(double ki) {
  if (ki > 0) {
    this->ki = ki;
  }
}

void Sayajin::setNivel(int nivel) { this->nivel = nivel; }

void Sayajin::setEspada(bool espada){
  this->espada = espada;
}


void Sayajin::print() const {
  cout << '\n' << "Nome: " << nome << '\n';
  cout << "Classe: " << GUERREIRO << '\n';
  cout << "Forma: " << forma << '\n';
  if (espada == true){
    cout << "Usa espada: Sim" << '\n';
  }
  if (espada == false){
    cout << "Usa espada: Nao" << '\n';
  }
  cout.precision(10);
  cout << "Poder de luta: " << ki << '\n';
}

void Sayajin::printNumSayajin() const{
  cout << "\nNumero de Sayajins criados: " << numSayajin << '\n';
}

void Sayajin::transform() {
  if (this->nivel == 0) {
    this->setForma("Super Sayajin");
    this->setKi(ki * 10);
  }

  if (this->nivel == 1) {
    this->setForma("Super Sayajin 2");
    this->setKi(ki * 30);
  }

  if (this->nivel >= 2) {
    cout << '\n' << this->nome << " ja atingiu seu nivel maximo" << '\n';
  }

  this->setNivel(this->nivel + 1);
}
void Sayajin::untransform() {
  this->setForma("Normal");
  this->setKi(NORMAL);
  this->setNivel(0);
}

void Sayajin::kamehameha() const{
  cout << '\n' << nome << " esta utilizando o kamehameha\n";
  cout << "    ()>================())))))))\n";
}

void Sayajin::genkidama() const{
  cout << '\n' << nome << " esta utilizando a genkidama\n";
  cout << "     ((((((((((()))))))))))  \n";
}

void Sayajin::insereEsfera( const string &esfera)
{
  if (esferasDoDragao.size() < 7)
  {
    esferasDoDragao.push_back( new string(esfera));
    return;
  }

  cout << "\nNao eh possivel cadastrar "<< esfera << "Todas as eferas foram adicionadas\n";
}

void Sayajin::printEsferas() const
{
  for (int i = 0; i < esferasDoDragao.size(); i++)
  {
    cout << '\n' << *esferasDoDragao[i] << endl;
  }
}