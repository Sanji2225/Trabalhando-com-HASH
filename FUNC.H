#include <string.h>
#define preposicoes 25
#define tamanho_tabela 100

int check_prepo(char *str){
    char prepo[preposicoes][30] = {
        "de","ante","apos","ate","com","de",
        "em","entre","para","as","os","o",
        "a","do","da","das","dos","ao","aos","no","nos",
        "dele","dela","deles","delas"
    };

    for(int i = 0; i < preposicoes; i++){
        if(strcmp(str, prepo[i]) == 0) {
            return 1;
        }
    }
    
    return 0;
}


 int hashcode(char* key) {
     int hash = 0;
     int p = 31; 
    int len = strlen(key);
    for (int i = 0; i < len; i++) {
        hash = (hash * p) + key[i];
    }
    return hash % tamanho_tabela;
}



