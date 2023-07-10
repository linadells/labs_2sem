#pragma once
#ifndef FUNC_H
#define FUNC_H
typedef struct CStudent CStud;
typedef struct CListOfStudents CList;
void insertStudentToList(CStud* insert, CList** ppHeadList);
void printList(CList* pHeadList);
void createOutputFile(CList* pHeadList);
void getInfoNewStud(CStud** ppinsert);
void deleteLosers(CList** ppHeadList);
void freeList(CList** ppHeadList);
void deleteChoosedStudent(CList** ppHeadList);
void menuStart();
void createListFromConsole(CList** ppFirst, int* iAvarageAge);
void createListFromFile(CList** ppHeadList, int* iAvarageAge);
void deleteYoungest(CList** ppHeadList, int iAvarageAge);
#endif