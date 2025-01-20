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
	char plan_name[20]; //��ȹ �̸�
	char menu[20]; //��ȹ�� �����Ǹ� �߰����� �� �޴� �̸�

	void SearchPlan();
	void AddPlan();
	void EditPlan();
	void DeletePlan();
};