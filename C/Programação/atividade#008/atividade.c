#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma entrada na agenda
struct AgendaEntry {
    char *name;
    char *phone;
    struct AgendaEntry *next;
    struct AgendaEntry *prev;
};

// Estrutura para representar a agenda
struct Agenda {
    struct AgendaEntry *head;
    struct AgendaEntry *tail;
};

// Função para criar uma nova entrada na agenda
struct AgendaEntry *createAgendaEntry(char *name, char *phone) {
    struct AgendaEntry *newEntry = (struct AgendaEntry *)malloc(sizeof(struct AgendaEntry));
    newEntry->name = strdup(name);
    newEntry->phone = strdup(phone);
    newEntry->next = NULL;
    newEntry->prev = NULL;
    return newEntry;
}

// Função para inicializar a agenda
void initAgenda(struct Agenda *agenda) {
    agenda->head = NULL;
    agenda->tail = NULL;
}

// Função para inserir um novo nó no início da lista
void agd_inserir_inicio(struct Agenda *agenda, char *name, char *phone) {
    struct AgendaEntry *newEntry = createAgendaEntry(name, phone);
    
    if (agenda->head == NULL) {
        agenda->head = newEntry;
        agenda->tail = newEntry;
    } else {
        newEntry->next = agenda->head;
        agenda->head->prev = newEntry;
        agenda->head = newEntry;
    }
}

// Função para inserir um novo nó no final da lista
void agd_inserir_final(struct Agenda *agenda, char *name, char *phone) {
    struct AgendaEntry *newEntry = createAgendaEntry(name, phone);

    if (agenda->tail == NULL) {
        agenda->head = newEntry;
        agenda->tail = newEntry;
    } else {
        newEntry->prev = agenda->tail;
        agenda->tail->next = newEntry;
        agenda->tail = newEntry;
    }
}

// Função para remover todas as ocorrências de um nome na lista
void agd_remover(struct Agenda *agenda, char *name) {
    struct AgendaEntry *current = agenda->head;
    while (current != NULL) {
        struct AgendaEntry *next = current->next;
        if (strcmp(current->name, name) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                agenda->head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                agenda->tail = current->prev;
            }
            free(current->name);
            free(current->phone);
            free(current);
        }
        current = next;
    }
}

// Função para comparar nomes para fins de ordenação
int compareNames(const char *name1, const char *name2) {
    return strcmp(name1, name2);
}

// Função para ordenar a lista em ordem alfabética de nome
void agd_ordenar(struct Agenda *agenda) {
    int swapped;
    struct AgendaEntry *ptr1;
    struct AgendaEntry *lptr = NULL;

    if (agenda->head == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = agenda->head;

        while (ptr1->next != lptr) {
            if (compareNames(ptr1->name, ptr1->next->name) > 0) {
                char *tempName = ptr1->name;
                char *tempPhone = ptr1->phone;
                ptr1->name = ptr1->next->name;
                ptr1->phone = ptr1->next->phone;
                ptr1->next->name = tempName;
                ptr1->next->phone = tempPhone;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Função para liberar a memória da agenda
void freeAgenda(struct Agenda *agenda) {
    struct AgendaEntry *current = agenda->head;
    while (current != NULL) {
        struct AgendaEntry *next = current->next;
        free(current->name);
        free(current->phone);
        free(current);
        current = next;
    }
    agenda->head = NULL;
    agenda->tail = NULL;
}

int main() {
    struct Agenda agenda;
    initAgenda(&agenda);

    agd_inserir_final(&agenda, "Alice", "123-456-7890");
    agd_inserir_final(&agenda, "Bob", "987-654-3210");
    agd_inserir_final(&agenda, "Charlie", "555-123-4567");
    
    printf("Agenda desordenada:\n");
    struct AgendaEntry *current = agenda.head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->phone);
        current = current->next;
    }

    agd_ordenar(&agenda);

    printf("\nAgenda ordenada por nome:\n");
    current = agenda.head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->phone);
        current = current->next;
    }

    agd_remover(&agenda, "Bob");

    printf("\nAgenda após remover Bob:\n");
    current = agenda.head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->phone);
        current = current->next;
    }

    freeAgenda(&agenda);
    
    return 0;
}
