#include <stdio.h>

#define MAX_USERS 100

struct User {
    int ID;
    int idade;
    char nome[100];
};

struct User data[MAX_USERS];

int proxID = 0;

void cadastro() {
    if (proxID < MAX_USERS) {
        struct User NewUser;
        printf("Nome do Usuário: ");
        scanf("%s", NewUser.nome);
        printf("Idade: ");
        scanf("%d", &NewUser.idade);
        printf("\n");
        NewUser.ID = proxID + 1; 
        data[proxID] = NewUser;
        proxID++;
        printf("\nUsuário %s Cadastrado!\n",NewUser.nome);
    } else {
        printf("\nLimite excedido de usuários!\n");
    }
}

void lista() {
    if (proxID == 0) {
        printf("\n\nNenhum Usuário Cadastrado no momento!\n\n");
    } else {
        printf("\n");
        printf("--------------------------------------\n");
        printf("|    Lista de Usuários Cadastrados   |\n");
        printf("--------------------------------------\n");
        for (int i = 0; i < proxID; i++) {
            printf("ID: %d\nNome: %s\nIdade: %d\n\n", data[i].ID, data[i].nome, data[i].idade);
        }
    }
}

void salvardados(){
    FILE*arquivo = fopen("banco_dados.txt","w");
    if(arquivo == NULL){
        printf("Não foi possível salvar os dados!\n");
        return;
    }
    for(int i = 0; i < proxID; i++){
    fprintf(arquivo,"%d %s %d\n", data[i].ID, data[i].nome, data[i].idade);
    }
    fclose(arquivo);
}

void carregardados(){
    FILE*arquivo = fopen("banco_dados.txt","r");
    if(arquivo == NULL){
        printf("Não foi possível salvar os dados!\n");
        return;
    }
    while(fscanf(arquivo,"%d %s %d\n",&data[proxID].ID, data[proxID].nome,&data[proxID].idade) != EOF){
        proxID++;
    }
    fclose(arquivo);
}
void update(int id){
    for(int i = 0; i < proxID; i++){
        if(data[i].ID == id){
            printf("Qual novo nome?: ");
            scanf("%s",data[i].nome);
            printf("Qual a nova idade?: ");
            scanf("%d",&data[i].idade);
            printf("\nUsuário do ID %d Atualizado!\n",data[i].ID);
            return;
        }
    }
    printf("\nUsuário não encontrado!\n");
}

void deletar(int id){
    int indice = -1;

    for(int i = 0; i < proxID; i++){
        if(data[i].ID == id){
            indice = id;
            break;
        }
    }

    if(indice != -1){
        for(int i = indice; i < proxID - 1; i++){
            data[i] = data[i+1];
        }
        proxID--;
        for(int i = 0; i < proxID; i++){
            data[i].ID = i + 1;
        }
        printf("Usuário removido com sucesso!\n");
    }
    else{
        printf("Usuário não encontrado!\n");
    }
}

int main(void){
    carregardados();
    int escolha;
    int atualizar;
    int apagar;
    do {
        printf("\n");
        printf("#########################\n");
        printf("#    MENU DE CADASTRO   #\n");
        printf("#########################\n");
        printf("\n");
        printf("1. Cadastrar Usuário:\n");
        printf("2. Listas de Usuários:\n");
        printf("3. Atualizar dados:\n");
        printf("4. Deletar dados:\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                cadastro();
                break;
            case 2:
                lista();
                break;
            case 3:
                printf("Qual ID usuário que você deseja atualizar?: \n");
                scanf("%d",&atualizar);
                update(atualizar);
                break;
            case 4:
                printf("Qual ID usuário que você deseja deletar?: \n");
                scanf("%d",&apagar);
                deletar(apagar);
                break;
            case 5:
                salvardados();
                printf("Salvando Dados...Dados Salvos!\n");
                printf("Saindo do programa. Até logo!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 5);

    return 0;
}
