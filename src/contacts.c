#include <stdio.h>
#include <string.h>
#include "contacts.h"

static void removeNewline(char *str) {
    size_t len = strlen(str);
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
        str[len - 1] = '\0';
        len--;
    }
}

static void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int loadContacts(Contact contacts[], int max_size, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return 0;
    }

    int count = 0;
    while (!feof(file) && count < max_size) {
        if (fgets(contacts[count].name, MAX_NAME, file) == NULL) break;
        removeNewline(contacts[count].name);

        if (fgets(contacts[count].phone, MAX_PHONE, file) == NULL) break;
        removeNewline(contacts[count].phone);

        if (fgets(contacts[count].email, MAX_EMAIL, file) == NULL) break;
        removeNewline(contacts[count].email);

        if (fgets(contacts[count].address, MAX_ADDRESS, file) == NULL) break;
        removeNewline(contacts[count].address);

        count++;
    }

    fclose(file);
    return count;
}

void saveContacts(const Contact contacts[], int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Erro ao abrir o arquivo %s para escrita.\n", filename);
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n", contacts[i].name);
        fprintf(file, "%s\n", contacts[i].phone);
        fprintf(file, "%s\n", contacts[i].email);
        fprintf(file, "%s\n", contacts[i].address);
    }

    fclose(file);
}

void addContact(Contact contacts[], int *count, int max_size) {
    if (*count >= max_size) {
        printf("Lista de contatos cheia. Não é possível adicionar mais.\n");
        return;
    }

    clearBuffer();
    Contact c;

    printf("Digite o nome: ");
    if (fgets(c.name, MAX_NAME, stdin)) {
        removeNewline(c.name);
    }

    printf("Digite o telefone: ");
    if (fgets(c.phone, MAX_PHONE, stdin)) {
        removeNewline(c.phone);
    }

    printf("Digite o e-mail: ");
    if (fgets(c.email, MAX_EMAIL, stdin)) {
        removeNewline(c.email);
    }

    printf("Digite o endereço: ");
    if (fgets(c.address, MAX_ADDRESS, stdin)) {
        removeNewline(c.address);
    }

    contacts[*count] = c;
    (*count)++;
    printf("Contato adicionado com sucesso!\n");
}

void listContacts(const Contact contacts[], int count) {
    if (count == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    printf("\n=== LISTA DE CONTATOS ===\n");
    for (int i = 0; i < count; i++) {
        printf("\nContato #%d\n", i + 1);
        printf("Nome: %s\n", contacts[i].name);
        printf("Telefone: %s\n", contacts[i].phone);
        printf("E-mail: %s\n", contacts[i].email);
        printf("Endereço: %s\n", contacts[i].address);
    }
    printf("=========================\n\n");
}

void searchContacts(const Contact contacts[], int count) {
    clearBuffer();
    char nameSearch[MAX_NAME];
    printf("Digite o nome (ou parte dele) para buscar: ");
    if (fgets(nameSearch, MAX_NAME, stdin)) {
        removeNewline(nameSearch);
    }

    int found = 0;
    printf("\n=== RESULTADO DA BUSCA ===\n");
    for (int i = 0; i < count; i++) {
        if (strstr(contacts[i].name, nameSearch) != NULL) {
            printf("\nContato #%d\n", i + 1);
            printf("Nome: %s\n", contacts[i].name);
            printf("Telefone: %s\n", contacts[i].phone);
            printf("E-mail: %s\n", contacts[i].email);
            printf("Endereço: %s\n", contacts[i].address);
            found = 1;
        }
    }
    if (!found) {
        printf("Nenhum contato encontrado.\n");
    }
    printf("==========================\n\n");
}

void editContact(Contact contacts[], int count) {
    if (count == 0) {
        printf("Nenhum contato para editar.\n");
        return;
    }

    listContacts(contacts, count);
    printf("Digite o número do contato que deseja editar: ");
    int index;
    if (scanf("%d", &index) != 1) {
        printf("Entrada inválida.\n");
        return;
    }
    clearBuffer();

    index--;
    if (index < 0 || index >= count) {
        printf("Contato inválido!\n");
        return;
    }

    printf("Editando contato #%d:\n", index + 1);

    char temp[MAX_ADDRESS];

    printf("Digite o novo nome (ou Enter para manter): ");
    if (fgets(temp, sizeof(temp), stdin)) {
        removeNewline(temp);
        if (strlen(temp) > 0) {
            strncpy(contacts[index].name, temp, MAX_NAME);
            contacts[index].name[MAX_NAME - 1] = '\0';
        }
    }

    printf("Digite o novo telefone (ou Enter para manter): ");
    if (fgets(temp, sizeof(temp), stdin)) {
        removeNewline(temp);
        if (strlen(temp) > 0) {
            strncpy(contacts[index].phone, temp, MAX_PHONE);
            contacts[index].phone[MAX_PHONE - 1] = '\0';
        }
    }

    printf("Digite o novo e-mail (ou Enter para manter): ");
    if (fgets(temp, sizeof(temp), stdin)) {
        removeNewline(temp);
        if (strlen(temp) > 0) {
            strncpy(contacts[index].email, temp, MAX_EMAIL);
            contacts[index].email[MAX_EMAIL - 1] = '\0';
        }
    }

    printf("Digite o novo endereço (ou Enter para manter): ");
    if (fgets(temp, sizeof(temp), stdin)) {
        removeNewline(temp);
        if (strlen(temp) > 0) {
            strncpy(contacts[index].address, temp, MAX_ADDRESS);
            contacts[index].address[MAX_ADDRESS - 1] = '\0';
        }
    }

    printf("Contato editado com sucesso!\n");
}

void removeContact(Contact contacts[], int *count) {
    if (*count == 0) {
        printf("Nenhum contato para remover.\n");
        return;
    }

    listContacts(contacts, *count);
    printf("Digite o número do contato que deseja remover: ");
    int index;
    if (scanf("%d", &index) != 1) {
        printf("Entrada inválida.\n");
        return;
    }
    clearBuffer();

    index--;
    if (index < 0 || index >= *count) {
        printf("Contato inválido!\n");
        return;
    }

    for (int i = index; i < (*count) - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    (*count)--;
    printf("Contato removido com sucesso!\n");
}

void sortContacts(Contact contacts[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(contacts[j].name, contacts[j + 1].name) > 0) {
                Contact temp = contacts[j];
                contacts[j] = contacts[j + 1];
                contacts[j + 1] = temp;
            }
        }
    }
    printf("Contatos ordenados por nome com sucesso!\n");
}
