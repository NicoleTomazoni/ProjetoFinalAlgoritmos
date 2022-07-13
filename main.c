#include <stdio.h>
#include <string.h>

struct sDNA {
  int tam; // tamanho da matriz
};

int baseNitrogenada(char letra);
struct sDNA tamanhoDna();

void carregaDNA(struct sDNA dna, char[dna.tam][dna.tam]);
void escreveDNA(struct sDNA dna, char codigoG[dna.tam][dna.tam]);

int linha(struct sDNA dna, char codigoG[dna.tam][dna.tam]);
int coluna(struct sDNA dna, char codigoG[dna.tam][dna.tam]);
int diagonalP(struct sDNA dna, char codigoG[dna.tam][dna.tam]);
int diagonalS(struct sDNA dna, char codigoG[dna.tam][dna.tam]);

void isHumano();
int isSimios();

// MAIN
int main(void) {
  struct sDNA dna;
  int i, j, contIgual = 0, cont, contL = 0, contC = 0, contDp = 0, contDs = 0,
            tem = 0;

  // TAMANHO DA MATRIZ
  dna = tamanhoDna();
  char codigoG[dna.tam][dna.tam];

  // CARREGAR E ESCREVER
  carregaDNA(dna, codigoG);
  escreveDNA(dna, codigoG);

  // checas
  contL = linha(dna, codigoG);
  contC = coluna(dna, codigoG);
  contDp = diagonalP(dna, codigoG);
  contDs = diagonalS(dna, codigoG);

  // analisa
  if (contL == 1 || contC == 1 || contDs == 1 || contDp == 1) {
    tem = isSimios();
  } else {
    isHumano();
  }

  return 0;
}

// receber do usuario o tamanho do codigoG
struct sDNA tamanhoDna() {
  struct sDNA dna;
  printf("Qual o tamanho do codigo genetico?");
  printf("\nOBS: insira no minimo o número 4\n");
  scanf("%i", &dna.tam);
  return dna;
}
// pra ver se a letra é a que pode
int baseNitrogenada(char letra) {
  if (letra == 'a' || letra == 't' || letra == 'g' || letra == 'c' ||
      letra == 'A' || letra == 'C' || letra == 'G' || letra == 'T') {
    return 1;
  } else {
    printf("\n\n Insira uma base nitrogenada válida!\n\n");
    return 0;
  }
}
// CARREGA
// carrega  a matriz codigoG
void carregaDNA(struct sDNA dna, char codigoG[dna.tam][dna.tam]) {
  int i, j;
  char letra;
  //  dna para definir o tamanho
  printf("\n--Digite o código genético--\n");
  for (i = 0; i < dna.tam; i++) {
    for (j = 0; j < dna.tam; j++) {
      printf("Digite as bases nitrogenadas [%i %i] A,C,G ou T.", i, j);
      scanf("%s", &codigoG[i][j]);
      if (baseNitrogenada(codigoG[i][j]) == 0) {
        j--;
      } else {
        codigoG[i][j] = letra;
      }
      // printf("\n\n codigoG: %c", codigoG[i][j]);
    }
  }
}
// ESCREVE
// escreve  a matriz codigoG
void escreveDNA(struct sDNA dna, char codigoG[dna.tam][dna.tam]) {
  int i, j;
  char letraAtual;
  for (i = 0; i < dna.tam; i++) {
    printf("\n");
    for (j = 0; j < dna.tam; j++) {
      letraAtual = codigoG[i][j];
      printf("%s ", &letraAtual);
    }
  }
  printf("\n\n");
}

// linha
int linha(struct sDNA dna, char codigoG[dna.tam][dna.tam]) {
  int i, j, contL = 0, contIgual = 0;
  for (i = 0; i < dna.tam; i++) {
    for (j = 0; j < dna.tam; j++) {
      if (j != dna.tam) {
        if (codigoG[i][j] == codigoG[i][j + 1]) {
          contL = contL + 1;
          if (contL == 3) {
            return 1;
          }
        } else {
          contL = 0;
        }
      }
    }
  }
  return contL;
}
// coluna
int coluna(struct sDNA dna, char codigoG[dna.tam][dna.tam]) {
  int i, j, contC = 0, contIgual = 0;
  for (j = 0; j < dna.tam; j++) {
    for (i = 0; i < dna.tam; i++) {
      if (i != dna.tam) {
        if (codigoG[i][j] == codigoG[i + 1][j]) {
          contC++;
          if (contC == 3) {
            return 1;
          }
        } else {
          contC = 0;
        }
      }
    }
  }

  return contC;
}
// diagonal P
int diagonalP(struct sDNA dna, char codigoG[dna.tam][dna.tam]) {
  int i, j, contDp = 0, contIgual = 0;
  for (i = 0, j = 0; i < dna.tam; i++, j++) {
    if (codigoG[i][j] == codigoG[i + 1][j + 1]) {
      contDp++;
      if (contDp == 3) {
        return 1;
      }
    } else {
      contDp = 0;
    }
  }
  return contDp;
}
// diagonalS
int diagonalS(struct sDNA dna, char codigoG[dna.tam][dna.tam]) {
  int i, j, contDs = 0, contIgual = 0;
  for (i = 0, j = dna.tam - 1; i < dna.tam && j > -1; i++, j--) {
    if (codigoG[i][j] == codigoG[i + 1][j - 1]) {
      contDs++;
      if (contDs == 3) {
        return 1;
      }
    } else {
      printf("\n");
      contDs = 0;
    }
  }
  return contDs;
}

// humano
void isHumano() { printf("\nO DNA analisado é de um humano!\n"); }
// simios
int isSimios() {
  printf("\nO DNA analisado é de um simio!\n");
  return 1;
}