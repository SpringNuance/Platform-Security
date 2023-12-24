#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define PASSWORD_LENGTH 16
#define MAX_LINE_LENGTH 1024

void generate_password(char* password) {
    srand(time(NULL));

    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = 'a' + rand() % 26;
    }
    password[PASSWORD_LENGTH] = '\0';
}

int get_password(const char* filename, const char* url, char* password) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        char* url_start = strstr(line, url);
        if (url_start != NULL) {
            char* password_start = url_start + strlen(url) + 1;
            strcpy(password, password_start);
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void set_password(const char* filename, const char* url, const char* password) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    fprintf(file, "%s:%s\n", url, password);

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    } else {
        char password[PASSWORD_LENGTH + 1];
        if (!get_password("passwords.txt", argv[1], password)) {
            generate_password(password);
            set_password("passwords.txt", argv[1], password);
        }
        printf("Password for %s: %s\n", argv[1], password);
    }
    sleep(180);
    return 0;
}