#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#pragma once
#include <cstring>
#include <vector>
#include <stdlib.h>

class Recipe {

public:
	void DISPLAY_RECIPE();
	void SEARCH_RECIPE();
	void ADD_RECIPE();
	void EDIT_RECIPE();
};

class RecipePart
{
private:
	struct Recipe
	{
		std::string name; //메뉴이름
		std::string ingredients; //재료
		std::string instructions; // 요리방법
	};
	//std::vector<Recipe> library;

public:

	std::vector<Recipe> library;
	void displayLibrary();

	boolean searchRecipe(const std::string& recipeName);
	void addRecipe(const std::string& name, const std::string& ingredients, const std::string& instructions);
	void editRecipe(const std::string& recipeName, const std::string& newIngredients, const std::string& newInstructions);
	void deleteRecipe(const std::string& recipeName, const std::string& newIngredients, const std::string& newInstructions);
	boolean deleteAllRecipe(const std::string& recipeName);

};

extern RecipePart recipeManager;