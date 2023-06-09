#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define tam_max 80000
#define preposicoes 25
#define tamanho_tabela 100
typedef struct
{
    char *palavra;
    int quantidade;
} Tabela;

unsigned int hashcode(char *key)
{
    unsigned int hash = 0;
    int p = 31;
    int len = strlen(key);
    for (int i = 0; i < len; i++)
    {
        hash = (hash * p) + key[i];
    }
    return hash % tam_max;
}

int check_prepo(char *str)
{
    char prepo[preposicoes][30] = {
        "de", "ante", "apos", "ate", "com", "de",
        "em", "entre", "para", "as", "os", "o",
        "a", "do", "da", "das", "dos", "ao", "aos", "no", "nos",
        "dele", "dela", "deles", "delas"};

    for (int i = 0; i < preposicoes; i++)
    {
        if (strcmp(str, prepo[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int insere_tabela(char *pal, Tabela tabela[], int palavras_diferentes)
{
    unsigned int chave = hashcode(pal);
    if (tabela[chave].quantidade == 0)
    {
        tabela[chave].palavra=malloc(strlen(pal));
        strcpy(tabela[chave].palavra,pal);
        tabela[chave].quantidade = 1;
        //printf("%s\n", tabela[chave].palavra);
        //printf(" %d\n", chave);
        return palavras_diferentes+=1;
    }
    else
    {
        tabela[chave].quantidade++;
        //printf("Ja Havia a palavra  %s na posicao ", tabela[chave].palavra);
        //printf(" %d\n", chave);
        return palavras_diferentes;
    }
    return palavras_diferentes;
}

/*void printa_table(Tabela tab[])
{

    for (int i = 0; i < tam_max; i++)
    {
        if(tab[i].quantidade!=0){printf("Palavra %s ", tab[i].palavra);
        printf("na posicao %d ", i);
        printf("%d vezes\n", tab[i].quantidade);
        }
    }
}*/
char *maiusc_to_min(char palavra[]){
  char alfabetoM[26]={"ABCDEFGHIJKLMNOPQRSTUWXYZ"}; 
  for(int i=0; i<strlen(palavra);i++){
        for(int t=0;t<strlen(alfabetoM);t++){
            if(palavra[i]==alfabetoM[t]){
                palavra[i]=palavra[i]+32;
        }
    }
    }
  return palavra;
}

void procurar(Tabela tab[], char palavra[]){
    unsigned int chave = hashcode(palavra);
    if(tab[chave].quantidade!=0){
      printf("\npalavra %s na posicao %d, %d vezes\n", tab[chave].palavra, chave, tab[chave].quantidade);
}
    else
      printf("\nNao ha palavra\n");
    
}


int main()
{
    Tabela hash_table[tam_max];
    for (int t = 0; t < tam_max; t++)
    {
        hash_table[t].quantidade = 0;
    }
    char frase[100];
    double tempo;
    time_t t_ini, t_fim;
    int num = 0, ehprep, palavras_diferentes=0;
    char *str;
    char blacklist[] = {" !.0123456789\n\r\0.,?~^"};
    t_ini = time(NULL); // mede o tempo inicial
    // Abre o livro
    FILE *livro = fopen("brascubas.txt", "r");
    // Verifica se ele existe
    if (livro == NULL)
    {
        printf("Cade o livro fi????");
        return 0;
    }
    // apenas um teste pra ler o conteudo
    
    while (fgets(frase, tam_max, livro) != NULL)
    {
        str = strtok(frase, blacklist);
        while (str != NULL)
        {
            ehprep = check_prepo(str);
            if (ehprep == 1)
            {
                str = strtok(NULL, blacklist);
            }
            else
            {
                maiusc_to_min(str);
                palavras_diferentes=insere_tabela(str, hash_table, palavras_diferentes);
                str = strtok(NULL, blacklist);
                num++;
            }

            //str = strtok(NULL, blacklist);
        }
    }

    t_fim = time(NULL); // mede o tempo final

    tempo = difftime(t_fim, t_ini); // calcula o tempo que demorou
    //printa_table(hash_table);

    printf("%d palavras diferentes\n", palavras_diferentes);
    printf("\nO programa demorou %lfs para rodar\n", tempo);
    printf("\nNesse arquivo ha %d palavras \n", num);
    char proc[]="wayne";
    procurar(hash_table,  proc);
    return 0;
}