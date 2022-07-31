
#ifndef GUI_CONFIG_H
#define GUI_CONFIG_H


#include "stddef.h"


#define pageStorageCreate(pageNum, labelAmount, buttonAmount);\
Object_Label ObjLabelList_##pageNum[labelAmount] = {0};\
Object_Button ObjButtonList_##pageNum[buttonAmount] = {0};\
Page_t page_##pageNum = {{0, 0,\
                          ObjLabelList_##pageNum,\
                          ObjButtonList_##pageNum}, NULL};


#define pagesStorageCreate(pagesAmount);\
Page_t *pagesStorage[pagesAmount] = {NULL};


#define guiStorageCreate();\
GUI_t GUI = {0, {0, 0}, 0, pagesStorage};


void GUI_pagesStorageInit(void);


#endif
