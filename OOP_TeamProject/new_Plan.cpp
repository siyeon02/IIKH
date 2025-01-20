#pragma once
#include "greeter.h"
#include "recipe.h"
#include "plan.h"

Date user_date[30]; // 계획 개수

RecipePart recipeManager;
Recipe p_recipe;

void Date::AddPlan()
{
	int input_date;
	std::cout << "\nEnter the date you would like to add the plan. \nex) YYYYMMDD ☞ ";
	std::cin >> input_date;

	std::cout << "------------------------------------------\n";

	int existingIndex = -1;

	for (int i = 0; i < 31; ++i) {
		if (user_date[i].year == input_date / 10000 &&
			user_date[i].month == (input_date % 10000) / 100 &&
			user_date[i].day == input_date % 100) {
			existingIndex = i;
			break;
		}
	}

	if (existingIndex == -1) {
		int emptyIndex = -1;
		for (int i = 0; i < 31; ++i) {
			if (user_date[i].year == 0) {
				emptyIndex = i;
				break;
			}
		}

		if (emptyIndex != -1) {
			user_date[emptyIndex].year = input_date / 10000;
			user_date[emptyIndex].month = (input_date % 10000) / 100;
			user_date[emptyIndex].day = input_date % 100;

			std::cout << "\nEnter the name of the menu(recipe) you want to add or search for: ";
			std::cin.ignore();
			std::string user_input;
			std::getline(std::cin, user_input);
			

			if (!recipeManager.library.empty()) { // 레시피가 비어있지 않은 경우
				// Search for the recipe in the library
				recipeManager.searchRecipe(user_input);
				std::cout << "\nPress Enter to continue...";
				std::cin.get(); // Wait for Enter key

				if (!recipeManager.library.empty()) { // 레시피가 비어있지 않다면
					// Use the first found recipe or ask the user to choose one
					std::strncpy(user_date[emptyIndex].menu, recipeManager.library[0].name.c_str(), sizeof(user_date[emptyIndex].menu));
				}
				else {
					std::cout << "Recipe not found. Please add the recipe first.1" << std::endl;
					p_recipe.ADD_RECIPE();
					std::cout << "Please enter the name of the added recipe: ";
					std::cin.getline(user_date[emptyIndex].menu, sizeof(user_date[emptyIndex].menu));
				}
			}

			else {
				std::cout << "Recipe not found. Please add the recipe first.2" << std::endl;
				p_recipe.ADD_RECIPE();
				std::cout << "Please enter the name of the added recipe: ";
				std::cin.getline(user_date[emptyIndex].menu, sizeof(user_date[emptyIndex].menu));
			}

			std::cout << "\nEnter the name of the plan you want to add: ";
			std::cin.getline(user_date[emptyIndex].plan_name, sizeof(user_date[emptyIndex].plan_name));

			std::cout << "\n날짜 " << user_date[emptyIndex].year << "/" << user_date[emptyIndex].month << "/" << user_date[emptyIndex].day
				<< "에 추가된 메뉴: " << user_date[emptyIndex].menu << ", 계획 이름: " << user_date[emptyIndex].plan_name << std::endl;
		}
	}
	else {
		std::cout << "\nAlready have plans for that date. Select edit or delete." << std::endl;
	}
	std::cout << "=============================================\n";
	std::cout << "Continue your Meal Plan !!\n";

	system("pause"); // 화면 일시 정지
	system("cls");  // 화면 지우기
}

void Date::SearchPlan()
{
	int input; //사용자 선택

	int input_year;  // 검색할 날짜
	int input_month;
	int input_day;
	char input_plan[20];  // 검색할 계획 이름
	char input_menu[20]; // 수정할 레시피 입력받는 변수


	while (1)
	{
		system("cls");

		std::cout << "\nEnter the date or name of the plan : ?\n1. Date\n2. Name\n☞ ";
		std::cin >> input;

		if (input == 1) //날짜 검색인 경우 : 겹치는 부분이 많은 순으로 정렬
		{
			std::cout << "\nEnter the date of the plan. \nex) YYYY MM DD ☞ ";
			std::cin >> input_year >> input_month >> input_day;

			std::cout << "-----------------------------\n";

			//연월달
			int l = 0;
			// 세개 다 일치하는 경우
			for (int i = 0; i < 30; i++)
			{
				if (user_date[i].year == input_year && user_date[i].month == input_month && user_date[i].day == input_day)
				{
					std::cout << user_date[i].year << "년 " << user_date[i].month << "월 " << user_date[i].day << "일\n";
					std::cout << user_date[i].plan_name << "\n";
					std::cout << user_date[i].menu << "\n";
					std::cout << "-----------------------------\n";
				}
				else l++;
			}

			int m = 0;
			// 두개만 일치하는 경우
			for (int i = 0; i < 30; i++)
			{
				if ((user_date[i].year == input_year && user_date[i].month == input_month && user_date[i].day != input_day) ||
					(user_date[i].year == input_year && user_date[i].day == input_day && user_date[i].month != input_month) ||
					(user_date[i].month == input_month && user_date[i].day == input_day && user_date[i].year != input_year))
				{
					std::cout << user_date[i].year << "년 " << user_date[i].month << "월 " << user_date[i].day << "일\n";
					std::cout << user_date[i].plan_name << "\n";
					std::cout << user_date[i].menu << "\n";
					std::cout << "-----------------------------\n";
				}
				else m++;
			}

			int k = 0;
			// 하나만 일치하는 경우
			for (int i = 0; i < 30; i++)
			{
				if ((user_date[i].year == input_year && user_date[i].month != input_month && user_date[i].day != input_day) ||
					(user_date[i].month == input_month && user_date[i].year != input_year && user_date[i].day != input_day) ||
					(user_date[i].day == input_day && user_date[i].year != input_year && user_date[i].month != input_month))
				{
					std::cout << user_date[i].year << "년 " << user_date[i].month << "월 " << user_date[i].day << "일\n";
					std::cout << user_date[i].plan_name << "\n";
					std::cout << user_date[i].menu << "\n";
					std::cout << "-----------------------------\n";
				}
				else k++;
			}


			if (l + m + k == 90) // 모두 못 찾은 경우
				std::cout << "\nNo matching results!" << '\n';

			//레시피로 넘어가서 레시피 수정하는 기능
			else // 레시피가 하나라도 있는 경우
			{
				std::cout << "자세히 보고 싶은 레시피를 입력하세요." << '\n';
				//std::cin.ignore(10, '\n'); //버퍼 비우기
				std::cin.getline(input_menu, 20, '\n');
				//std::cin >> input_menu;
				for (int i = 0; i < 30; i++)
				{
					//p_recipeManager.searchRecipe(user_date[i].menu); 
					bool s;
					std::string name = input_menu;

					s = recipeManager.searchRecipe(name); // 자세히 보고 싶은 레시피가 레시피 DB에 존재하는지 확인
					if (s) { // 레시피가 있는 경우
						char yn;
						std::cout << "수정하시겠습니까? (y/n) ☞ " << '\n';
						std::cin >> yn;
						if (yn == 'y') //edit
						{
							p_recipe.EDIT_RECIPE();
							// 레시피가 삭제 됐다면 "empyty Recipe"
							bool d = false;
							d = recipeManager.deleteAllRecipe(input_menu);
							if (d)
								strcpy(user_date[i].menu, "empty recipe");
						}
					}
					else  // 자세히 보고 싶은 레시피가 레시피 DB에 없는 경우
						std::cout << "No matching results!" << '\n';
				}
			}


			system("pause");
			system("cls");
			return;

		}

		else if (input == 2) // 계획 이름 검색인 경우
		{
			std::cout << "\nEnter the plan of the name you want to search. (ex)지혜 생일 파티) ☞ ";
			std::cin.ignore(10, '\n'); //버퍼 비우기
			std::cin.getline(input_plan, 20, '\n');

			int k = 0;
			for (int i = 0; i < 30; i++)
			{
				if (strstr(user_date[i].plan_name, input_plan) != nullptr) // 찾으려는 단어가 계획 이름에 포함된 경우
				{
					std::cout << user_date[i].year << "년 " << user_date[i].month << "월 " << user_date[i].day << "일\n";
					std::cout << user_date[i].plan_name << "\n";
					std::cout << user_date[i].menu << "\n";
					std::cout << "-----------------------------\n";
				}
				else k++;
			}

			if (k == 30) // 찾으려는 단어가 계획 이름에 포함되지 않은 경우
				std::cout << "\nNo matching results!" << '\n';

			// 레시피로 넘어가서 레시피 수정하는 기능
			else // 레시피가 하나라도 있는 경우
			{
				std::cout << "자세히 보고 싶은 레시피를 입력하세요." << '\n';
				//std::cin.ignore(10, '\n'); //버퍼 비우기
				std::cin.getline(input_menu, 20, '\n');
				for (int i = 0; i < 30; i++)
				{
					if (strstr(user_date[i].menu, input_menu) != nullptr)
					{
						//p_recipeManager.searchRecipe(user_date[i].menu); //레시피 검색
						bool s;
						std::string name = input_menu;

						s = recipeManager.searchRecipe(name); //레시피 검색

						if (s) { // 레시피가 있는 경우
							char yn;
							std::cout << "수정하시겠습니까? (y/n) ☞ " << '\n';
							std::cin >> yn;
							if (yn == 'y') //edit
								p_recipe.EDIT_RECIPE();
							break;
						}
					}
					else
						std::cout << "해당 레시피는 존재하지 않습니다." << '\n';
				}
			}

			system("pause");
			system("cls");

			return;
		}
	}
}

void Date::EditPlan()
{
	int input_date;
	std::cout << "\nEnter the date of the plan you want to edit. \nex) YYYYMMDD ☞ ";
	std::cin >> input_date;
	std::cout << "------------------------------------------\n";

	int accordIndex = -1;

	for (int i = 0; i < 31; ++i) {
		if (user_date[i].year == input_date / 10000 &&
			user_date[i].month == (input_date % 10000) / 100 &&
			user_date[i].day == input_date % 100) {
			accordIndex = i;
			break;
		}
	}

	char choice;

	if (accordIndex != -1)
	{
		std::cout << "\nWould you like to edit the menu? (y/n) ☞ ";
		std::cin >> choice;
		if (choice == 'y')
		{
			std::cout << "\nMenu name to edit: ";
			std::cin.ignore();
			std::cin.getline(user_date[accordIndex].menu, sizeof(user_date[accordIndex].menu));
		}

		std::cout << "\nWould you like to edit the name of your plan? (y/n) ☞ ";
		std::cin >> choice;
		if (choice == 'y')
		{
			std::cout << "\nPlan name to edit: ";
			std::cin.ignore();
			std::cin.getline(user_date[accordIndex].plan_name, sizeof(user_date[accordIndex].plan_name));

			std::cout << "\nThe plan for that day has been edited." << std::endl;

			std::cout << "\n Date " << user_date[accordIndex].year << user_date[accordIndex].month << user_date[accordIndex].day
				<< "\nedited menu: " << user_date[accordIndex].menu << ", name of the plan: " << user_date[accordIndex].plan_name << std::endl;
		}
	}
	else {
		std::cout << "\nNo plans to change. Add the plan." << std::endl;
		AddPlan();
	}
	std::cout << "=============================================\n";
	std::cout << "Continue your Meal Plan !!\n";

	system("pause");
	system("cls");
}

void Date :: DeletePlan() {
	int input_date;
	std::cout << "\nEnter the date to delete. \nex) YYYYMMDD ☞ ";
	std::cin >> input_date;
	std::cout << "------------------------------------------\n";

	int deleteIndex = -1;

	for (int i = 0; i < 31; ++i) {
		if (user_date[i].year == input_date / 10000 &&
			user_date[i].month == (input_date % 10000) / 100 &&
			user_date[i].day == input_date % 100) {
			deleteIndex = i;
			break;
		}
	}

	if (deleteIndex != -1) {
		user_date[deleteIndex].year = NULL;
		user_date[deleteIndex].month = NULL;
		user_date[deleteIndex].day = NULL;
		strcpy(user_date[deleteIndex].menu, "");
		strcpy(user_date[deleteIndex].plan_name, "");

		std::cout << "\nPlans for that date have been deleted." << std::endl;
	}

	else {
		std::cout << "\nThere's no plan to be deleted." << std::endl;
	}
	std::cout << "=============================================\n";
	std::cout << "Continue your Meal Plan !!\n";

	system("pause"); // 화면일시정지
	system("cls"); // 화면 지우기
}