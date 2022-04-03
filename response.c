/*
No oitavo episodio da segunda temporada do seriado The Big Bang Theory, The Lizard-Spock Expansion,
Sheldon e Raj discutem qual dos dois é o melhor: o filme Saturn 3 ou a série Deep Space 9.
A sugestão de Raj para a resolução do impasse é uma disputa de Pedra-Papel-Tesoura.
Contudo, Sheldon argumenta que, se as partes envolvidas se conhecem, entre 75% e 80% das disputas de
Pedra-Papel-Tesoura terminam empatadas, e então sugere o Pedra-Papel-Tesoura-Lagarto-Spock.

As regras do jogo proposto são:
    1...a tesoura corta o papel;
    2...o papel embrulha a pedra;
    3...a pedra esmaga o lagarto;
    4...o lagarto envenena Spock;
    5...Spock destrói a tesoura;
    6...a tesoura decapita o lagarto;
    7...o lagarto come o papel;
    8...o papel contesta Spock;
    9...Spock vaporiza a pedra;
    10..a pedra quebra a tesoura.

Embora a situação não se resolva no episódio (ambos escolhem Spock, resultando em um empate),
não é difıcil deduzir o que aconteceria se a disputa continuasse.
Caso Sheldon vencesse, ele se deleitaria com a vitória, exclamando "Bazinga!";
caso Raj vencesse, ele concluiria que "Raj trapaceou!";
caso o resultado fosse empate, ele exigiria nova partida: "De novo!".
Conhecidas as personagens do jogo escolhido por ambos, faça um programa que imprima a provável reação de Sheldon.

        Entrada:
A entrada consiste em uma série de casos de teste.
A primeira linha contém um inteiro positivo T (T ≤ 100), que representa o número de casos de teste.
Cada caso de teste é representado por uma linha da entrada, contendo as escolhas de Sheldon e Raj,
respectivamente, separadas por um espaço em branco. As escolha possíveis são as personagens do 
jogo: pedra, papel, tesoura, lagarto e Spock.

Saida
Para cada caso de teste deverá ser impressa a mensagem "Caso #t: R",
onde t é o número do caso de teste (cuja contagem se inicia no número um) e R é uma das três reações possíveis de
Sheldon: "Bazinga!", "Raj trapaceou!", ou "De novo!".


Autor: João Batista Neto.
Email: netobatista090@gmail.com
Linkedin: https://www.linkedin.com/in/neto-batista-163263211/
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *LISTA_POSSIBILIDAES[]= {"pedra","papel","tesoura","lagarto","Spock"};
char *RESULTADOS[]={"Bazinga!","Raj trapaceou!","De novo!"};


//retorna o valor da escolha do vencedor ou empate (-1)
int game_rules(int choice1,int choice2){
    //{"pedra","papel","tesoura","lagarto","Spock"}
    //   0        1       2          3        4
    int result;
    if (choice1 == choice2) {
        result = -1;
        return result;
    } else {
        if (choice1 == 2 && (choice2 == 4 || (choice2 == 0))){
            result = choice2;
            return result;
        } else if (choice1 == 4 && (choice2 == 3 || (choice2 == 1))){
            result = choice2;
            return result;
        } else if (choice1 == 3 && (choice2 == 2 || (choice2 == 0))){
            result = choice2;
            return result;
        } else if (choice1 == 0 && (choice2 == 4 || choice2==1)){
            result = choice2;
            return result;
        } else if (choice1 == 1 && (choice2 == 2 || choice2 == 3)){
            result = choice2;
            return result;
        }
    }
    result=choice1;
    return result;
}
//retorna a posicao do array referente ao ganhador, 0 para Sheldon, 1 para Raj, e 2 para empate
int who_won(int sheldon_choice,int raj_choice){
    
    int sheldon=0;
    int raj=1;
    int both=2;

    int result= game_rules(sheldon_choice,raj_choice);

    if(result==-1){
        return both;
    }else if(result==sheldon_choice){
        return sheldon;
    }else if(result==raj_choice){
        return raj;
    }
}
//da a saída com a formatação necessaria.
void presentate(int num_casos,int winner){
    
    printf("Caso #%d: %s\n",num_casos+1,RESULTADOS[winner]);

}

int set_choice_to_int(char *choice){
    int response;
    
    int i;
    for (i=0;i<(sizeof(LISTA_POSSIBILIDAES)/sizeof(LISTA_POSSIBILIDAES[0]));i++){
        if(strcmp(choice,LISTA_POSSIBILIDAES[i])==0){
            response=i;
        }
    }

    return response;
}

void read_data_and_run(){
    int num_casos_teste=0;
    char sheldon_choice[50];
    char raj_choice[50];

    scanf("%d",&num_casos_teste);

    int i;
    for(i=0; i<num_casos_teste; i++){
        scanf("%s %s", &sheldon_choice, &raj_choice);

        int int_sheldon_choice = set_choice_to_int(sheldon_choice);
        int int_raj_choice = set_choice_to_int(raj_choice);

        presentate(i, who_won(int_sheldon_choice,int_raj_choice));
    }
    
}

int main(){

    read_data_and_run();

    return 0;
}