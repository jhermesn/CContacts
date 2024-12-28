#ifndef CONTACTS_H
#define CONTACTS_H

#define MAX_NAME    50
#define MAX_PHONE   15
#define MAX_EMAIL   50
#define MAX_ADDRESS 100

typedef struct {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char email[MAX_EMAIL];
    char address[MAX_ADDRESS];
} Contact;

int loadContacts(Contact contacts[], int max_size, const char *filename);
void saveContacts(const Contact contacts[], int count, const char *filename);
void addContact(Contact contacts[], int *count, int max_size);
void listContacts(const Contact contacts[], int count);
void searchContacts(const Contact contacts[], int count);
void editContact(Contact contacts[], int count);
void removeContact(Contact contacts[], int *count);
void sortContacts(Contact contacts[], int count);

#endif
