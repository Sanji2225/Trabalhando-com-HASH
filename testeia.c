#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

int main(){
    char teste[30];
    char alfabetoM[26]={"ABCDEFGHIJKLMNOPQRSTUWXYZ"};
    fgets(teste,30,stdin);

    printf("com letras maiusculas: %s", teste);
    for(int i=0; i<strlen(teste);i++){
        for(int t=0;t<26;t++){
            if(teste[i]==alfabetoM[t]){
                teste[i]=teste[i]+32;
        }
    }
    }
    printf("sem letras maiusculas: %s", teste);


    system("pause");
    return 0;
}