#include <stdio.h>
#include <stdlib.h>
#include "contacts.h"

#define MAX_CONTACTS 100
#define FILENAME "contacts.txt"

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int option;

    count = loadContacts(contacts, MAX_CONTACTS, FILENAME);

    do {
        printf("\n=== GERENCIADOR DE CONTATOS ===\n");
        printf("1. Adicionar contato\n");
        printf("2. Listar contatos\n");
        printf("3. Gerenciar contatos (Buscar, Editar, Remover, Ordenar)\n");
        printf("0. Sair\n");
        printf("================================\n");
        printf("Opção desejada: ");
        if (scanf("%d", &option) != 1) {
            while (getchar() != '\n');
            option = -1;
        }

        switch (option) {
            case 1:
                addContact(contacts, &count, MAX_CONTACTS);
                saveContacts(contacts, count, FILENAME);
                break;

            case 2:
                listContacts(contacts, count);
                break;

            case 3: {
                int manageOption;
                do {
                    printf("\n=== GERENCIAR CONTATOS ===\n");
                    printf("1. Pesquisar\n");
                    printf("2. Editar\n");
                    printf("3. Remover\n");
                    printf("4. Ordenar\n");
                    printf("0. Voltar\n");
                    printf("==========================\n");
                    printf("Opção desejada: ");
                    if (scanf("%d", &manageOption) != 1) {
                        while (getchar() != '\n');
                        manageOption = -1;
                    }

                    switch (manageOption) {
                        case 1:
                            searchContacts(contacts, count);
                            break;
                        case 2:
                            editContact(contacts, count);
                            saveContacts(contacts, count, FILENAME);
                            break;
                        case 3:
                            removeContact(contacts, &count);
                            saveContacts(contacts, count, FILENAME);
                            break;
                        case 4:
                            sortContacts(contacts, count);
                            saveContacts(contacts, count, FILENAME);
                            break;
                        case 0:

                            break;
                        default:
                            printf("Opção inválida!\n");
                            break;
                    }
                } while (manageOption != 0);
                break;
            }

            case 0:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida, tente novamente.\n");
                break;
        }
    } while (option != 0);

    return 0;
}
