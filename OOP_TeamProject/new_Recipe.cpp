#pragma once
#include "greeter.h"
#include "recipe.h"


bool goback;

void Recipe::DISPLAY_RECIPE()
{
	recipeManager.displayLibrary(); //레시피 목록 표시
	std::cout << "Press Enter to continue...";
	std::cin.get(); //엔터 키 입력 대기
	goback = true;
}

void Recipe:: SEARCH_RECIPE()
{
	std::cout << "Enter the name of the recipe or ingredients to search: ";
	std::string searchName;
	std::getline(std::cin, searchName); //검색어 문자열 getline

	//ADD_PLAN에서 공백문자 받아서 오류나는거 때문에 이거 추가했어
	while (searchName.empty()) {
		std::getline(std::cin, searchName);
	}

	recipeManager.searchRecipe(searchName); //레시피 검색
	std::cout << "Press Enter to continue...";
	std::cin.get(); //엔터키 입력 대기
	goback = true;
}

void Recipe::ADD_RECIPE()
{
	std::cout << "Enter the name of the recipe: ";
	std::string name, ingredients, instructions;
	std::getline(std::cin, name); //레시피 이름 get
	std::cout << "Enter the ingredients: ";
	std::getline(std::cin, ingredients); //재료 get
	std::cout << "Enter the instructions: ";
	std::getline(std::cin, instructions); // 요리 방법 get
	recipeManager.addRecipe(name, ingredients, instructions);
	std::cout << "Press Enter to continue...";
	std::cin.get(); //엔터키 입력 대기
	goback = true; // Set the flag to return to the first page
}

void Recipe:: EDIT_RECIPE()
{
	int a;
	std::cout << "Enter the number\n'1' : add something to an existiing recipe / '2' : edit all thing / '3' : delete recipe ";
	std::cin >> a;
	std::cin.ignore();

	if (a == 1) { //기존 레시피(메뉴)에서 ingredients/instruction 추가
		std::cout << "Enter the name of the recipe to add something: ";
		std::string editName, newIngredients, newInstructions;
		std::getline(std::cin, editName);
		
		std::cout << "Enter the new ingredients (leave empty to keep the same): ";
		std::getline(std::cin, newIngredients);
		std::cout << "Enter the new instructions: ";
		std::getline(std::cin, newInstructions);

		recipeManager.editRecipe(editName, newIngredients, newInstructions);
	}
	else if (a == 2) { //레시피 아예 변경하기
		std::cout << "Enter the name of the recipe you want to edit: ";
		std::string editName, newIngredients, newInstructions;
		std::getline(std::cin, editName);

		std::cout << "Enter the new ingredients (leave empty to keep the same): ";
		std::getline(std::cin, newIngredients);
		std::cout << "Enter the new instructions: ";
		std::getline(std::cin, newInstructions);

		// You can add the logic to add something to the existing recipe here

		std::cout << "Changes added to the recipe." << std::endl;
	}
	else if (a == 3) { // 레시피(메뉴) 삭제

		std::cout << "Enter the name of the recipe you want to delete: ";
		std::string editName;
		std::getline(std::cin, editName);
		recipeManager.deleteAllRecipe(editName);


	}
	else {
		std::cout << "Enter only 1 or 2 or 3." << std::endl;
	}

	std::cout << "Press Enter to continue...";
	std::cin.get();
	goback = true;
}


void RecipePart:: displayLibrary() //전체 메뉴 확인용
{
	if (library.empty()) //비어있으면
	{
		std::cout << "Library is empty." << std::endl; //비어있다 출력
	}
	else
	{
		std::cout << "List of Recipes:\n"; //안비어있으면 레시피 출력
		for (const auto& recipe : library)
		{
			std::cout << "Recipe: " << recipe.name << "\n";
		}
	}
}

boolean RecipePart:: searchRecipe(const std::string& recipeName) {
	bool found = false; // Initialize a flag to indicate if any matches were found

	for (const auto& recipe : library) {
		std::cout <<1 << recipe.ingredients << " " << recipe.instructions << " " << recipe.name << "\n";
		if (recipe.name.find(recipeName) != std::string::npos ||
			recipe.ingredients.find(recipeName) != std::string::npos) {
			found = true; // Found a match
			std::cout << "-----" << "\n\n";
			std::cout << "Here's the recipe for  " << recipe.name << "\n\n";
			std::cout << "Ingredients: " << recipe.ingredients << "\n";
			std::cout << "Instructions: " << recipe.instructions << "\n\n";
			return true;
		}
	}

	if (!found) {
		std::cout << "No recipes or ingredients matching '" << recipeName << "' found." << "\n";
		return false;
	}
}

void RecipePart::addRecipe(const std::string& name, const std::string& ingredients, const std::string& instructions)
{

	for (const auto& recipe : library) {
		if (recipe.name == name) {
			std::cout << "Same name exists. Recipe not added." << std::endl;
			return;
		}
	}

	Recipe newRecipe; //새로운 레시피 객체 생성
	newRecipe.name = name; //레시피 정보 삽입
	newRecipe.ingredients = ingredients;
	newRecipe.instructions = instructions;
	library.push_back(newRecipe); //레시피 목록에 추가
	std::cout << "Recipe added to the library." << std::endl;
}

void RecipePart:: editRecipe(const std::string& recipeName, const std::string& newIngredients, const std::string& newInstructions) {
	bool recipeFound = false;

	for (auto& recipe : library) {
		std::cout << 2 << recipe.ingredients << recipe.instructions << recipe.name << "\n";
		std::cout << 3 << recipe.name << " " << recipeName << "\n";
		if (recipe.name == recipeName) {
			recipeFound = true;

			if (!newIngredients.empty()) {
				// Append new ingredients to the existing ones
				if (!recipe.ingredients.empty()) {
					recipe.ingredients += ", " + newIngredients;
				}
				else {
					recipe.ingredients = newIngredients;
				}
			}

			// Append new instructions to the existing ones
			if (!recipe.instructions.empty()) {
				recipe.instructions += " , " + newInstructions;
			}
			else {
				recipe.instructions = newInstructions;
			}

			std::cout << "Recipe edited successfully." << std::endl;
			return;
		}
	}

	if (!recipeFound) {
		std::cout << "Recipe not found." << std::endl;
	}
}

void RecipePart:: deleteRecipe(const std::string& recipeName, const std::string& newIngredients, const std::string& newInstructions)
{
	for (auto& recipe : library) //모든 레시피 목록 보기
	{
		if (recipe.name == recipeName) //수정할 레시피와 현재 레시피가 같은지 검사
		{
			if (!newIngredients.empty()) //재료를 새로 추가했다면
			{
				recipe.ingredients = newIngredients; //추가된 재료 삽입
			}
			recipe.instructions = newInstructions; //레시피 업데이트
			std::cout << "Recipe edited successfully." << std::endl;
			return;
		}
	}
	std::cout << "Recipe not found." << std::endl;
}

boolean RecipePart:: deleteAllRecipe(const std::string& recipeName) {
	auto it = library.begin();

	while (it != library.end()) {
		if (it->name == recipeName) {
			it = library.erase(it); // 해당 레시피 삭제
			std::cout << "Recipe(s) deleted successfully." << std::endl;
			return true;
		}
		else {
			++it;
			return false;
		}
	}

	/* std::cout << "Recipe(s) deleted successfully." << std::endl;*/
}

