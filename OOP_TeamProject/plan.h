#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <cstring>
#include <vector>
#include <stdlib.h>

void SearchPlan();
void AddPlan();
void EditPlan();
void DeletePlan();

class Date {
public:
	int year;
	int month;
	int day;
	char plan_name[20]; //계획 이름
	char menu[20]; //계획에 레시피를 추가했을 때 메뉴 이름

	void SearchPlan();
	void AddPlan();
	void EditPlan();
	void DeletePlan();
};