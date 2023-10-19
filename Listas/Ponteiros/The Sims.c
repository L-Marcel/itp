#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum operacao {
  aumentar,
  dimiuir
};

enum status {
  FOME, 
  SEDE, 
  BANHEIRO, 
  SONO, 
  TEDIO
};

const char status_messages[5][2][12] = {
  { "fome", "de fome" },
  { "sede", "de sede" },
  { "banheiro", "apertado..." },
  { "sono", "dormindo..." },
  { "tédio", "deprimido..." },
};

int aumentar_status(int* status, int qtd, int status_id) {
  *status = (*status + qtd);
  
  if(*status >= 100) {
    *status = 100;
  };

  if(*status <= 0) {
    printf("Game Over! Morreu %s\n", status_messages[status_id][1]);
    *status = 0;
    return 0;
  };

  if(*status <= 15) {
    printf("Alerta: %s está com valor baixo\n", status_messages[status_id][0]);
  };

  return 1;
};

int diminuir_status(int* status, int qtd, int status_id) {
  return aumentar_status(status, -qtd, status_id);
};

int simula_sims(int* fome, int* sede, int* banheiro, int* sono, int* tedio) {
  char acao[16];

  do {
    fgets(acao, 17, stdin);
  } while (strcmp(acao, "\n") == 0);

  acao[strlen(acao) - 1] = '\0';
  
  int* operacoes;
  int* all_status[5] = { fome, sede, banheiro, sono, tedio };

  if(strcmp(acao, "comer") == 0) {
    int operacoes_da_acao[5][3] = {
      { 30, aumentar, FOME },
      { 5, dimiuir, SEDE },
      { 5, dimiuir, SONO },
      { 5, dimiuir, TEDIO },
      { 15, dimiuir, BANHEIRO }
    };

    operacoes = (int*) operacoes_da_acao;
  } else if(strcmp(acao, "beber") == 0) {
    int operacoes_da_acao[5][3] = {
      { 30, aumentar, SEDE },
      { 5, dimiuir, FOME },
      { 20, dimiuir, BANHEIRO },
      { 5, dimiuir, SONO },
      { 5, dimiuir, TEDIO }
    };

    operacoes = (int*) operacoes_da_acao;
  } else if(strcmp(acao, "dormir") == 0) {
    int operacoes_da_acao[5][3] = {
      { 80, aumentar, SONO },
      { 30, aumentar, TEDIO },
      { 30, dimiuir, SEDE },
      { 30, dimiuir, FOME },
      { 30, dimiuir, BANHEIRO },
    };

    operacoes = (int*) operacoes_da_acao;
  } else if(strcmp(acao, "se aliviar") == 0) {
    int operacoes_da_acao[5][3] = {
      { 100, aumentar, BANHEIRO },
      { 5, dimiuir, FOME },
      { 5, dimiuir, SEDE },
      { 5, dimiuir, SONO },
      { 5, dimiuir, TEDIO }
    };

    operacoes = (int*) operacoes_da_acao;
  } else if(strcmp(acao, "jogar videogame") == 0) {
    int operacoes_da_acao[5][3] = {
      { 80, aumentar, TEDIO },
      { 20, dimiuir, SEDE },
      { 20, dimiuir, BANHEIRO },
      { 20, dimiuir, SONO },
      { 20, dimiuir, FOME },
    };

    operacoes = (int*) operacoes_da_acao;
  };

  for(int i = 0; i < 15; i += 3) {
    int ret = 1;
    int qtd = *(operacoes + i);
    int operacao = *(operacoes + i + 1);
    int status_atual = *(operacoes + i + 2);

    //printf("Acao: %s\n", acao);
    //printf("Operacao: %s (%s) (%d) (%d)\n", status_messages[status_atual], operacao == aumentar? "aumentar":"diminuir", qtd, *all_status[status_atual]);
  
    if(operacao == aumentar) {
      ret = aumentar_status(all_status[status_atual], qtd, status_atual);
    } else {
      ret = diminuir_status(all_status[status_atual], qtd, status_atual);
    };

    if(ret == 0) {
      return 0;
    };
  };

  return 1;
};

void imprime_relatorio(int fome, int sede, int banheiro, int sono, int tedio) {
  printf(
    "Status final:\nFome: %d\nSede: %d\nBanheiro: %d\nSono: %d\nTédio: %d\n",
    fome,
    sede,
    banheiro,
    sono,
    tedio
  );
};

int main(){
  int fome, sede, banheiro, sono, tedio;
  int acoes;

  scanf("%d %d %d %d %d\n", &fome, &sede, &banheiro, &sono, &tedio);
  scanf("%d\n", &acoes);

  for(int i = 0; i < acoes; i++){
    int ret = simula_sims(&fome, &sede, &banheiro, &sono, &tedio);
    if(ret == 0) break;
  }
  
  imprime_relatorio(fome, sede, banheiro, sono, tedio);
  return 0;
};