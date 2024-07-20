#include <string.h>
#include "TLSE.h"

typedef struct lsep{
  char pal[31];
  int num_vezes;
  TLSE *linhas;
  struct lsep *prox;
}TLSEP;

TLSEP* TLSEP_ins_ini(TLSEP *l, char *pal, int linha);
void TLSEP_imprime(TLSEP *l);
void TLSEP_libera(TLSEP *l);
TLSEP* TLSEP_busca(TLSEP *l, char *pal);
