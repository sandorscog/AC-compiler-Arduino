#include <cstdlib>
#include <string>
#include <vector>
#include <ostream>
#include <iostream>
#include <fstream>
#include <exception>
using std::string;
//------------------------------------------------------------------------------

char atribui(const string &line);
string tiraEspaco(const string &line);
string fraseTraduzida(const string &line);
std::vector<string> instrucoes(const std::vector<string>& texto);
void escreveArq(std::vector<string> vec);
void criaFrases();

//------------------------------------------------------------------------------
int main() {
  criaFrases();



  return 0;
}


void criaFrases(){
  std::ifstream infile;
  infile.open("testeula.ula");  //abre o arq de texto
  std::vector<string> texto;
  string linhas;


  while (std::getline(infile, linhas)){  //copia a linha do arq para linhas
    linhas = tiraEspaco(linhas);
    texto.push_back(linhas);
  }
  infile.close();  //fecha o arq de texto

  /*for (int i = 0; i < texto.size(); i++)
    std::cout << texto[i] << std::endl;*/

  std::vector<string> saidaArduino = instrucoes(texto);

  /*for (int i = 0; i < saidaArduino.size(); i++)
  std::cout << saidaArduino[i] << std::endl;*/

  escreveArq(saidaArduino);

}//end main


std::vector<string> instrucoes(const std::vector<string>& texto){

  if(texto[0] != "inicio:")         //le o arquivo e retorna um vetor com as instrucoes prontas
    throw std::exception();         //e no formato para leitura no arduino

  string tipo;
  char a = '0',
       b = '0';
  int size = texto.size();
  std::vector<string> instrucoesULA;

  for(int i = 1; i < size-1; i++){
    if(texto[i].find("=") == string::npos) {  //define se e uma atribuicao ou instrucao
      string str = "";
      str += a;
      str += b;
      str += fraseTraduzida(texto[i]);   //cria a expressao
      instrucoesULA.push_back(str);

    } else {
      if (texto[i].at(0) == 'A') {
        a = atribui(texto[i]);       //atribui os valores a A e B
      } else {
        b = atribui(texto[i]);
      }//end if qual variavel recebe o valor

    }//end if atribuicao ou nao
  }//end for

  std::ofstream escritor;          //abre arquivo para escrever as instrucoes
  escritor.open("testeula.hex");

  escritor.close();  //fecha o arquivo de instrucoes

  return instrucoesULA;
}

string fraseTraduzida(const string &line){

  string instrucao;   //retorna o codigo em hexa de qual instrucao esta presente

  if(line == "zeroL;")instrucao = "0";
  else if(line == "umL;")instrucao = "1";
  else if(line == "An;")instrucao = "2";
  else if(line == "Bn;")instrucao = "3";
  else if(line == "AouB;")instrucao = "4";
  else if(line == "AeB;")instrucao = "5";
  else if(line == "AxorB;")instrucao = "6";
  else if(line == "AnandB;")instrucao = "7";
  else if(line == "AnorB;")instrucao = "8";
  else if(line == "AxnorB;")instrucao = "9";
  else if(line == "AnouB;")instrucao = "A";
  else if(line == "AouBn;")instrucao = "B";
  else if(line == "AneB;")instrucao = "C";
  else if(line == "AeBn;")instrucao = "D";
  else if(line == "AnouBn;")instrucao = "E";
  else if(line == "AneBn;")instrucao = "F";

  return instrucao;
}

char atribui(const string &line){
  return line[2];   //retorna o valor que deve ser atribuido
}

string tiraEspaco(const string &line){
  string str = "";                       //recebe uma string e retira seus espacos
  for(int i = 0; i < line.size(); i++)
    if(line.at(i) != ' ')
      str += line.at(i);
  return str;
}

void escreveArq(std::vector<string> vec){
  std::ofstream outFile;
  outFile.open("testeula.hex");

  for(int i = 0; i < vec.size(); i++)
    outFile << vec[i] << std::endl;

  outFile.close();
}
//------------------------------------------------------------------------------
//operacoes logicas

/*

main - chama a traduzir depois a executar
ULATraduzir("testeula.ula")   //Traduz e manda para o arquivo
ULAExcecutar()  //Excecuta o aquivo traduzido

*/
