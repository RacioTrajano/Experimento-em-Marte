#include <stdio.h>

// função para soma dos elementos da matriz
int soma_matriz (int linha, int coluna,int x_0, int y_0, int matriz[linha][coluna]){

int sum =0;
for (int i=x_0; i< x_0+3; i++){
  for (int j=y_0; j<y_0+3; j++){
     sum = sum + matriz[i][j] ;
  }
}
return sum;
}


int main () {

int leitura;
int linha_refe;
int coluna_refe;
int diferenca;
int melhor;
int linha = 0;
int coluna = 0;
int soma =0;
int referencia=100;

// leituras

scanf("%d", &linha);
scanf("%d", &coluna);
scanf("%d", &melhor);

int matriz_area[linha +2][coluna +2];

// zera matriz area

for(int i=0; i<linha+2; i++){
  for(int j= 0; j<coluna+2; j++){
    matriz_area[i][j] = 0;
  }
}
// leituras
for (int i=1; i<=linha; i++){
  for (int j=1; j<=coluna; j++){
    scanf("%d", &leitura);
    matriz_area[i][j] = leitura;
    
    }
    
}

// porção da matriz original que vai ser lida
for (int i= 1; i<linha -1; i++){
  for (int j= 1 ; j<coluna -1; j++){
      soma = soma_matriz(linha, coluna, i, j, matriz_area);
      printf("%d ", soma);
      diferenca = soma - melhor;
      if (diferenca < 0)
        diferenca = -diferenca;
      if (diferenca < referencia ){
      referencia=diferenca;
      linha_refe=i;
      coluna_refe=j;}
  }
}


//impressão da resposta
printf("A melhor area para exploracao eh %d %d com valor %d", linha_refe, coluna_refe, referencia
);



  return 0;
}