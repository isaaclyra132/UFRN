#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Pessoa
{
private:
  string nome;
  int idade;
public:
  inline Pessoa(string no, int id):
      nome(no), idade(id) {}
  inline string getNome() const {return nome;}
  inline int getIdade() const {return idade;}
};

ostream &operator<<(ostream &O, const Pessoa &P)
{
  O << P.getNome() << '|' << P.getIdade();
  return O;
}

class maior_que
{
private:
  int N;
public:
  inline maior_que(int NN): N(NN) {}
  inline bool operator()(const Pessoa& P)
  {
    return (P.getIdade() > N);
  }
};

int main()
{
  vector<Pessoa> VP;
  vector<Pessoa>::iterator ptr;

  VP.push_back(Pessoa("Joao", 25));
  VP.push_back(Pessoa("Maria", 32));
  VP.push_back(Pessoa("Carla", 4));
  VP.push_back(Pessoa("Abel", 30));

  // Procurando alguem de idade > N
  int N;
  do
  {
    cout << "Digite a idade de busca: ";
    cin >> N;
  } while (N<=0);

  // maior_que mqN(N);
  // ptr = find_if(VP.begin(), VP.end(),
  //               mqN);
  ptr = find_if(VP.begin(), VP.end(),
                maior_que(N));
  if (ptr == VP.end())
  {
      cout << "Nao existe nenhuma pessoa de idade > "
           << N << "!\n";
  }
  else
  {
      cout << "Pessoa de idade > " << N
           << " encontrada:\n";
      cout << *ptr << endl;
  }
  cout << "================\n";
}

