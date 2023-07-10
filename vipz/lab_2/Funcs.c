#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// використовується для задання максимальної кількості символів у стрічках
#define MAX_SYM 31
#define MAX_TEMP 255
// використовується для задання кількості оцінок у масиві
#define QUANT_OF_MARKS 3

//--------------------------------------------------------------------------------
// Структура Cstudent використовується для збереження даних про студента 
// (прізвище, ім'я, день, місяць, рік народження, масив з 3 оцінок, вік)
//--------------------------------------------------------------------------------
typedef struct CStudent {
    char m_cSurname[MAX_SYM];
    char m_cName[MAX_SYM];
    int m_iDay;
    int m_iMonth;
    int m_iYear;
    int m_iMark[QUANT_OF_MARKS];
    int m_iAge;
}CStud;
//--------------------------------------------------------------------------------
// Структура ClistOfStudents, що представляє дані про елемент однозв'язного списку,
// який містить дані про студентів (містяться в змінній m_sData типу Cstud)
//--------------------------------------------------------------------------------
typedef struct CListOfStudents {
    CStud m_csData;
    struct CListOfStudents* m_pclNext;
} CList;
//--------------------------------------------------------------------------------
// Функція insertStudentToList вставляє елемент до однозв'язного списку у алфавітному 
// порядку, пам'ять під новий елемент виділяється динамічно
//--------------------------------------------------------------------------------
void insertStudentToList(CStud* pInsert, CList** ppHeadList) {
    CList* pNewStud, * pRun, * pPrev;
    pPrev = NULL;
    pRun = *ppHeadList;

    pNewStud = (CList*)malloc(sizeof(CStud));
    pNewStud->m_pclNext = NULL;
    pNewStud->m_csData = *pInsert;

    if (!pRun) {
        *ppHeadList = pNewStud;
    }
    else {
        if (strcmp((*ppHeadList)->m_csData.m_cSurname, pNewStud->m_csData.m_cSurname) > 0) {
            pNewStud->m_pclNext = *ppHeadList;
            *ppHeadList = pNewStud;
        }
        else {
            while ((pRun != NULL) && (strcmp(pRun->m_csData.m_cSurname, pNewStud->m_csData.m_cSurname) < 0)) {
                pPrev = pRun;
                pRun = pRun->m_pclNext;
            }
            pNewStud->m_pclNext = pPrev->m_pclNext;
            pPrev->m_pclNext = pNewStud;
        }
    }
}
//--------------------------------------------------------------------------------
// Функція printList виводить список на консоль
//--------------------------------------------------------------------------------
void printList(CList* pHeadList) {
    if (!pHeadList) {
        printf("\nList is empty");
    }
    else {
        printf("\tList of students\n");
        CList* pNew = pHeadList;
        while (pNew) {
            printf("%-10s %-8s| %02d.%02d.%04d | %d %d %d\n", pNew->m_csData.m_cSurname,
                pNew->m_csData.m_cName, pNew->m_csData.m_iDay, pNew->m_csData.m_iMonth,
                pNew->m_csData.m_iYear, pNew->m_csData.m_iMark[0], pNew->m_csData.m_iMark[1],
                pNew->m_csData.m_iMark[2]);
            pNew = pNew->m_pclNext;
        }
    }
}
//--------------------------------------------------------------------------------
// Функція createOutputFile створює вихідний текстовий файл з списком студентів, 
// повертає 0, якщо список студентів пустий 
//--------------------------------------------------------------------------------
void createOutputFile(CList* pHeadList) {
    char temp[MAX_TEMP];
    char cFileName[MAX_SYM];
    printf("\nEnter output file name:");
    gets(temp);
    if (strlen(temp) > 30) {
        printf("File name must be shorter that 30 sumbols\n");
        createOutputFile(pHeadList);
    }
    strcpy(cFileName, temp);
    strcat(cFileName, ".txt");
    FILE* fIn = fopen(cFileName, "w");
    if (!pHeadList) {
        printf("\nList is empty");
        return 0;
    }
    printf("\n\tList of students\n");
    CList* pNew = pHeadList;
    while (pNew) {
        fprintf(fIn, "%-10s %-8s| %02d.%02d.%04d | %d %d %d\n", pNew->m_csData.m_cSurname,
            pNew->m_csData.m_cName, pNew->m_csData.m_iDay, pNew->m_csData.m_iMonth,
            pNew->m_csData.m_iYear, pNew->m_csData.m_iMark[0], pNew->m_csData.m_iMark[1],
            pNew->m_csData.m_iMark[2]);
        pNew = pNew->m_pclNext;
    }
    fclose(fIn);
}
//--------------------------------------------------------------------------------
// Функція infoNewStud використовується для зчитування даних про нового студента, 
// пам'ять для змінної виділяється динамічно
//--------------------------------------------------------------------------------
void getInfoNewStud(CStud** ppInsert) {
    char temp[MAX_TEMP];
    *ppInsert = (CStud*)malloc(sizeof(CStud));
    printf("Enter info about new student:\nSurname:");
    scanf("%s", temp);
    if (strlen(temp) > 30) {
        printf("Surname must be shorter than 30 symbols\n");
        getInfoNewStud(ppInsert);
    }
    for (int i = 0; i < strlen(temp); i++) {
        if (!isalpha(temp[i])&& temp[i]!='`'&& temp[i]!='-') {
            printf("Incorrect symbols\n");
            getInfoNewStud(ppInsert);
        }
    }
    if (!isupper(temp[0])) {
        printf("First letter must be upper\n");
        getInfoNewStud(ppInsert);
    }
    strcpy((*ppInsert)->m_cSurname, temp);
    printf("Name:");
    scanf("%s", temp);
    if (strlen(temp) > 30) {
        printf("Name must be shorter than 30 symbols\n");
        getInfoNewStud(ppInsert);
    }
    for (int i = 0; i < strlen(temp); i++) {
        if (!isalpha(temp[i]) && temp[i] != '`' && temp[i] != '-') {
            printf("Incorrect symbols\n");
            getInfoNewStud(ppInsert);
        }
    }
    if (!isupper(temp[0])) {
        printf("First letter must be upper\n");
        getInfoNewStud(ppInsert);
    }
    strcpy((*ppInsert)->m_cName, temp);
    printf("Day of birth:");
    scanf("%s", temp);
    for (int i = 0; i < strlen(temp); i++) {
        if (!isdigit(temp[i])) {
            printf("It must be an integer value\n");
            getInfoNewStud(ppInsert);
        }
    }
    (*ppInsert)->m_iDay = atoi(temp);
    if ((*ppInsert)->m_iDay < 1 || (*ppInsert)->m_iDay > 31) {
        printf("Day must be from 1 to 31\n");
        getInfoNewStud(ppInsert);
    }
    printf("Month of birth:");
    scanf("%s", temp);
    for (int i = 0; i < strlen(temp); i++) {
        if (!isdigit(temp[i])) {
            printf("It must be an integer value\n");
            getInfoNewStud(ppInsert);
        }
    }
    (*ppInsert)->m_iMonth = atoi(temp);
    if (((*ppInsert)->m_iMonth < 1) || ((*ppInsert)->m_iMonth > 12)) {
        printf("Month must be from 1 to 12\n");
        getInfoNewStud(ppInsert);
    }
    printf("Year of birth:");
    scanf("%s", temp);
    for (int i = 0; i < strlen(temp); i++) {
        if (!isdigit(temp[i])) {
            printf("It must be an integer value\n");
            getInfoNewStud(ppInsert);
        }
    }
    (*ppInsert)->m_iYear = atoi(temp);
    if ((*ppInsert)->m_iYear < 1900 || (*ppInsert)->m_iYear>2023) {
        printf("Year must be from 1900 to 2023\n");
        getInfoNewStud(ppInsert);
    }
    printf("Enter mark from basics of programming:");
    scanf("%s", temp);
    for (int i = 0; i < strlen(temp); i++) {
        if (!isdigit(temp[i])) {
            printf("It must be an integer value\n");
            getInfoNewStud(ppInsert);
        }
    }
    (*ppInsert)->m_iMark[0] = atoi(temp);
    if ((*ppInsert)->m_iMark[0] < 1 || (*ppInsert)->m_iMark[0]>5) {
        printf("Marks must be from 1 to 5\n");
        getInfoNewStud(ppInsert);
    }
    printf("Enter mark from comouter discrete math:");
    scanf("%s", temp);
    for (int i = 0; i < strlen(temp); i++) {
        if (!isdigit(temp[i])) {
            printf("It must be an integer value\n");
            getInfoNewStud(ppInsert);
        }
    }
    (*ppInsert)->m_iMark[1] = atoi(temp);
    if ((*ppInsert)->m_iMark[1] < 1 || (*ppInsert)->m_iMark[1]>5) {
        printf("Marks must be from 1 to 5\n");
        getInfoNewStud(ppInsert);
    }
    printf("Enter mark from mathematical analysis:");
    scanf("%s", temp);
    for (int i = 0; i < strlen(temp); i++) {
        if (!isdigit(temp[i])) {
            printf("It must be an integer value\n");
            getInfoNewStud(ppInsert);
        }
    }
    (*ppInsert)->m_iMark[2] = atoi(temp);
    if ((*ppInsert)->m_iMark[2] < 1 || (*ppInsert)->m_iMark[2]>5) {
        printf("Marks must be from 1 to 5\n");
        getInfoNewStud(ppInsert);
    }
    (*ppInsert)->m_iAge = 365 * (2023 - (*ppInsert)->m_iYear) + 30.5 *
        (4 - (*ppInsert)->m_iMonth) + (*ppInsert)->m_iDay;
}
//--------------------------------------------------------------------------------
// Функція deleteElem видаляє студентів, які не отримали жодної 4 і 5
//--------------------------------------------------------------------------------
void deleteLosers(CList** ppHeadList) {
    if (*ppHeadList) {
        CList* pRun, * pPrev;
        pPrev = *ppHeadList;
        pRun = pPrev->m_pclNext;
        int k = 0, h = 0;

        while (h == 0) {
            for (int i = 0; i < 3; i++) {
                if ((pPrev->m_csData.m_iMark[i] == 4) ||
                    (pPrev->m_csData.m_iMark[i] == 5))
                    k++;
            }
            if (k == 0) {
                if (!(*ppHeadList)->m_pclNext) {
                    free(*ppHeadList);
                    *ppHeadList = NULL;
                    return 0;
                }
                *ppHeadList = pPrev->m_pclNext;
                free(pPrev);
                pPrev = *ppHeadList;
                pRun = pPrev->m_pclNext;
            }
            else {
                pPrev = pPrev->m_pclNext;
                pRun = pPrev->m_pclNext;;
                k = 0;
                h++;
            }
        }

        while (pRun != NULL) {
            for (int i = 0; i < 3; i++) {
                if ((pRun->m_csData.m_iMark[i] == 4) || (pRun->m_csData.m_iMark[i] == 5))
                    k++;
            }
            if (k == 0) {
                pPrev->m_pclNext = pRun->m_pclNext;
                free(pRun);
                pRun = pPrev->m_pclNext;
            }
            else {
                pPrev = pPrev->m_pclNext;
                pRun = pRun->m_pclNext;
                k = 0;
            }
        }
    }
    else {
        printf("List is empty");
        return 0;
    }
    if (!(*ppHeadList)) {
        printf("List is empty");
        return 0;
    }
}
//--------------------------------------------------------------------------------
// Функція freeList очищує список і звільняє динамічно виділену пам'ять
//--------------------------------------------------------------------------------
void freeList(CList** ppHeadList) {
    CList* pRun = *ppHeadList;
    while (pRun) {
        *ppHeadList = pRun->m_pclNext;
        free(pRun);
        pRun = *ppHeadList;
    }
    *ppHeadList = NULL;
}
//--------------------------------------------------------------------------------
// Функція deleteChoosedStudent видаляє студентів з заданими користувачем ім'ям 
// чи прізвищем
//--------------------------------------------------------------------------------
void deleteChoosedStudent(CList** ppHeadList) {
    char cDel[MAX_SYM];
    printf("Enter name or surname of student, who you want to delete:");
    gets(cDel);
    if (*ppHeadList) {
        CList* pRun, * pPrev;
        pPrev = *ppHeadList;
        pRun = pPrev->m_pclNext;
        int h = 0;

        while (h == 0) {
            if (!strcmp(pPrev->m_csData.m_cName, cDel) || 
                !strcmp(pPrev->m_csData.m_cSurname, cDel)) {
                if (!(*ppHeadList)->m_pclNext) {
                    *ppHeadList = NULL;
                    return 0;
                }
                *ppHeadList = pPrev->m_pclNext;
                pPrev = *ppHeadList;
                pRun = pPrev->m_pclNext;
            }
            else {
                pPrev = pPrev->m_pclNext;
                pRun = pPrev->m_pclNext;
                h++;
            }
        }
        pPrev = *ppHeadList;
        pRun = pPrev->m_pclNext;
        while (pRun != NULL) {
            if (!strcmp(pRun->m_csData.m_cName, cDel) || 
                !strcmp(pRun->m_csData.m_cSurname, cDel)) {
                pPrev->m_pclNext = pRun->m_pclNext;
                pRun = pPrev->m_pclNext;
            }
            else {
                pPrev = pPrev->m_pclNext;
                pRun = pRun->m_pclNext;
            }
        }
    }
    else {
        printf("List is empty");
        return 0;
    }
    if (!(*ppHeadList)) {
        printf("List is empty");
        return 0;
    }
   /* if (*ppHeadList) {
        CList* pRun, * pPrev;
        pPrev = *ppHeadList;
        pRun = pPrev->m_pclNext;
        int k = 0;

        if (!strcmp(pPrev->m_csData.m_cName, cDel) || !strcmp(pPrev->m_csData.m_cSurname, cDel)) {
            free(pPrev);
            *ppHeadList = pRun;
        }
        else {
            while (pRun != NULL) {
                if (!strcmp(pRun->m_csData.m_cName, cDel) || !strcmp(pRun->m_csData.m_cSurname, cDel)) {
                    pPrev->m_pclNext = pRun->m_pclNext;
                    free(pRun);
                    pRun = pPrev->m_pclNext;
                    k++;
                }
                else {
                    pPrev = pPrev->m_pclNext;
                    pRun = pRun->m_pclNext;
                }
            }
            if (!k) {
                printf("There isn`t such student in list");
            }
        }
    }
    else {
        printf("List is empty");
        return 0;
    }
    if (!(*ppHeadList)) {
        printf("List is empty");
        return 0;
    }*/
}
//--------------------------------------------------------------------------------
// Функція createListFromConsole створює однозв'язний список студентів, беручи 
// дані з консолі
//--------------------------------------------------------------------------------
void createListFromConsole(CList** ppFirst, int* iAvarageAge) {
    CStud* csNew;
    int iChoise;
    int iQuant = 0;
    do {
        getInfoNewStud(&csNew);
        insertStudentToList(csNew, ppFirst);
        iQuant++;
        *iAvarageAge += csNew->m_iAge;
        do {
            printf("Press '1' to continue, '2' - if you want to end\n");
            scanf_s("%i", &iChoise);
            system("CLS");
        } while (iChoise != 1 && iChoise != 2);
        printList(*ppFirst);
    } while (iChoise != 2);
    *iAvarageAge /= iQuant;
}
//--------------------------------------------------------------------------------
// Функція createListFromFile створює однозв'язний список, зчитуючи дані з файлу
//--------------------------------------------------------------------------------
void createListFromFile(CList** ppHeadList, int* iAvarageAge) {
    int k = 0;
    CStud* csNew;
    char temp[MAX_TEMP];
    char cFileName[MAX_SYM+5];
    FILE* fIn;
    int iQuant = 0;
    do {
        printf("Enter file name:");
        if (!k)
            getchar();
        gets(temp);
        if (strlen(temp) > 30) {
            printf("File name is longer than it can be\n");
            createListFromFile(ppHeadList, iAvarageAge);
        }
        strcpy(cFileName, temp);
        strcpy(temp, "");
        strcat(cFileName, ".txt");
        fIn = fopen(cFileName, "r");
        if (!fIn) {
            printf("Incorrect file name\n"); k++;
        }
    } while (!fIn);
    while (fscanf(fIn, "%s", temp) && strcmp(temp, "end")) {
        if (!strcmp(temp, "")) {
            printf("Empty file\n");
            fclose(fIn);
            createListFromFile(ppHeadList, iAvarageAge);
        }
        csNew = (CStud*)malloc(sizeof(CStud));
        if (strlen(temp) > 30) {
            printf("Surname must be shorter than 30 symbols\n");
            fclose(fIn);
            createListFromFile(ppHeadList, iAvarageAge);
        }
        for (int i = 0; i < strlen(temp); i++) {
            if (!isalpha(temp[i]) && temp[i] != '`' && temp[i] != '-') {
                printf("Incorrect symbols in data from file\n");
                fclose(fIn);
                createListFromFile(ppHeadList, iAvarageAge);
            }
        }
        if (!isupper(temp[0])) {
            printf("First letter must be upper\n");
            fclose(fIn);
            createListFromFile(ppHeadList, iAvarageAge);
        }
        strcpy((csNew)->m_cSurname, temp);
        fscanf(fIn, "%s", temp);
        if (strlen(temp) > 30) {
            printf("Name must be shorter than 30 symbols\n");
            fclose(fIn);
            createListFromFile(ppHeadList, iAvarageAge);
        }
        for (int i = 0; i < strlen(temp); i++) {
            if (!isalpha(temp[i]) && temp[i] != '`' && temp[i] != '-') {
                printf("Incorrect symbols in data from file\n");
                fclose(fIn);
                createListFromFile(ppHeadList, iAvarageAge);
            }
        }
        if (!isupper(temp[0])) {
            printf("First letter must be upper\n");
            fclose(fIn);
            createListFromFile(ppHeadList, iAvarageAge);
        }
        strcpy((csNew)->m_cName, temp);
        fscanf(fIn, "%s", temp);
        for (int i = 0; i < strlen(temp); i++) {
            if (!isdigit(temp[i])) {
                printf("Value must be an integer\n");
                fclose(fIn);
                createListFromFile(ppHeadList, iAvarageAge);
            }
        }
        (csNew)->m_iDay = atoi(temp);
        if ((csNew)->m_iDay < 1 || (csNew)->m_iDay > 31) {
            printf("Day must be from 1 to 31\n");
            fclose(fIn);
            createListFromFile(ppHeadList, iAvarageAge);
        }
        fscanf(fIn, "%s", temp);
        for (int i = 0; i < strlen(temp); i++) {
            if (!isdigit(temp[i])) {
                printf("Value must be an integer\n");
                fclose(fIn);
                createListFromFile(ppHeadList, iAvarageAge);
            }
        }
        (csNew)->m_iMonth = atoi(temp);
        if (((csNew)->m_iMonth < 1) || ((csNew)->m_iMonth > 12)) {
            printf("Month must be from 1 to 12\n");
            fclose(fIn);
            createListFromFile(ppHeadList, iAvarageAge);
        }
        fscanf(fIn, "%s", temp);
        for (int i = 0; i < strlen(temp); i++) {
            if (!isdigit(temp[i])) {
                printf("Value must be an integer\n");
                fclose(fIn);
                createListFromFile(ppHeadList, iAvarageAge);
            }
        }
        (csNew)->m_iYear = atoi(temp);
        if ((csNew)->m_iYear < 1900 || (csNew)->m_iYear>2023) {
            printf("Year must be from 1900 to 2023\n");
            fclose(fIn);
            createListFromFile(ppHeadList, iAvarageAge);
        }
        fscanf(fIn, "%s", temp);
        for (int i = 0; i < strlen(temp); i++) {
            if (!isdigit(temp[i])) {
                printf("Value must be an integer\n");
                fclose(fIn);
                createListFromFile(ppHeadList, iAvarageAge);
            }
        }
        (csNew)->m_iMark[0] = atoi(temp);
        if ((csNew)->m_iMark[0] < 1 || (csNew)->m_iMark[0]>5) {
            printf("Marks must be from 1 to 5\n");
            fclose(fIn);
            createListFromFile(ppHeadList, iAvarageAge);
        }
        fscanf(fIn, "%s", temp);
        for (int i = 0; i < strlen(temp); i++) {
            if (!isdigit(temp[i])) {
                printf("Value must be an integer\n");
                fclose(fIn);
                createListFromFile(ppHeadList, iAvarageAge);
            }
        }
        (csNew)->m_iMark[1] = atoi(temp);
        if ((csNew)->m_iMark[1] < 1 || (csNew)->m_iMark[1]>5) {
            printf("Marks must be from 1 to 5\n");
            fclose(fIn);
            createListFromFile(ppHeadList, iAvarageAge);
        }
        fscanf(fIn, "%s", temp);
        for (int i = 0; i < strlen(temp); i++) {
            if (!isdigit(temp[i])) {
                printf("Value must be an integer\n");
                fclose(fIn);
                createListFromFile(ppHeadList, iAvarageAge);
            }
        }
        (csNew)->m_iMark[2] = atoi(temp);
        if ((csNew)->m_iMark[2] < 1 || (csNew)->m_iMark[2]>5) {
            printf("Marks must be from 1 to 5\n");
            fclose(fIn);
            createListFromFile(ppHeadList, iAvarageAge);
        }
        csNew->m_iAge = 365 * (2023 - csNew->m_iYear) + 30.5 * (4 - csNew->m_iMonth) + csNew->m_iDay;
        if (iQuant == 40) {
            return 0;
        }
        insertStudentToList(csNew, ppHeadList);
        iQuant++;
        *iAvarageAge += csNew->m_iAge;
        
    }
    *iAvarageAge /= iQuant;
}
//--------------------------------------------------------------------------------
// Функція menuStart викликається на початку роботи програми для вибору варіанту
// зчитування вхідних даних 
//--------------------------------------------------------------------------------
// Функція deleteYoungest видаляє всіх студентів, молодших середнього віку в групі
//--------------------------------------------------------------------------------
void deleteYoungest(CList** ppHeadList, int iAvarageAge) {
    if (*ppHeadList) {
        CList* pRun, * pPrev;
        pPrev = *ppHeadList;
        pRun = pPrev->m_pclNext;
        int h = 0;

        while (h == 0) {
            if (pPrev->m_csData.m_iAge < iAvarageAge) {
                if (!(*ppHeadList)->m_pclNext) {
                    free(*ppHeadList);
                    *ppHeadList = NULL;
                    return 0;
                }
                *ppHeadList = pPrev->m_pclNext;
                free(pPrev);
                pPrev = *ppHeadList;
                pRun = pPrev->m_pclNext;
            }
            else {
                pPrev = pPrev->m_pclNext;
                pRun = pPrev->m_pclNext;
                h++;
            }
        }
        pPrev = *ppHeadList;
        pRun = pPrev->m_pclNext;
        while (pRun != NULL) {
            if (pRun->m_csData.m_iAge < iAvarageAge) {
                pPrev->m_pclNext = pRun->m_pclNext;
                free(pRun);
                pRun = pPrev->m_pclNext;
            }
            else {
                pPrev = pPrev->m_pclNext;
                pRun = pRun->m_pclNext;
            }
        }
    }
    else {
        printf("List is empty");
        return 0;
    }
    if (!(*ppHeadList)) {
        printf("List is empty");
        return 0;
    }
}
//--------------------------------------------------------------------------------
void menuStart() {
    int iChoise;
    int iAvarageAge = 0;
    CStud* csNew;
    CList** ppFirst = NULL;
    printf("Press '1' to input info about students from console,"
        "'2' - read info from file\n");
    scanf_s("%i", &iChoise);
    if (iChoise == 1) {
        system("CLS");
        createListFromConsole(&ppFirst, &iAvarageAge);
    }
    else if (iChoise == 2) {
        system("CLS");
        printf("\t    List of students\n");
        createListFromFile(&ppFirst, &iAvarageAge);
    }
    else {
        system("CLS");
        printf("Incorrect choise\n");
        menuStart();
    }
    system("CLS");
    printList(ppFirst);
    do {
        printf("\nMenu:\n1 - add new student\n2 - to delete student\n"
            "3 - delete students without marks 4 and 5\n"
            "4 - delete younger students\n"
            "5 - create output text file\n6 - end program\n"
            "7 - start program again\n"
            "\nEnter your choise:");
        scanf_s("%i", &iChoise);
        getchar();
        if (iChoise == 1) {
            system("CLS");
            printList(ppFirst);
            getInfoNewStud(&csNew); ;
            insertStudentToList(csNew, &ppFirst);
            system("CLS");
            printList(ppFirst);
        }
        else if (iChoise == 2) {
            system("CLS");
            printList(ppFirst);
            deleteChoosedStudent(&ppFirst);
            system("CLS");
            printList(ppFirst);
        }
        else if (iChoise == 3) {
            deleteLosers(&ppFirst);
            system("CLS");
            printList(ppFirst);
        }
        else if (iChoise == 4) {
            deleteYoungest(&ppFirst, iAvarageAge);
            system("CLS");
            printList(ppFirst);
        }
        else if (iChoise == 5) {
            system("CLS");
            printList(ppFirst);
            createOutputFile(ppFirst);
            system("CLS");
            printList(ppFirst);
        }
        else if (iChoise == 7) {
            system("CLS");
            menuStart();
        }
        else if (iChoise == 6) {
            return 0;
        }
        else {
           printf("Incorrect choise\n");
        }
    } while (iChoise != 6);
    freeList(&ppFirst);
}
//--------------------------------------------------------------------------------
