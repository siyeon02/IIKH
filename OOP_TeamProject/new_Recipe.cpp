#pragma once
#include "greeter.h"
#include "recipe.h"


bool goback;

void Recipe::DISPLAY_RECIPE()
{
	recipeManager.displayLibrary(); //������ ��� ǥ��
	std::cout << "Press Enter to continue...";
	std::cin.get(); //���� Ű �Է� ���
	goback = true;
}

void Recipe:: SEARCH_RECIPE()
{
	std::cout << "Enter the name of the recipe or ingredients to search: ";
	std::string searchName;
	std::getline(std::cin, searchName); //�˻��� ���ڿ� getline

	//ADD_PLAN���� ���鹮�� �޾Ƽ� �������°� ������ �̰� �߰��߾�
	while (searchName.empty()) {
		std::getline(std::cin, searchName);
	}

	recipeManager.searchRecipe(searchName); //������ �˻�
	std::cout << "Press Enter to continue...";
	std::cin.get(); //����Ű �Է� ���
	goback = true;
}

void Recipe::ADD_RECIPE()
{
	std::cout << "Enter the name of the recipe: ";
	std::string name, ingredients, instructions;
	std::getline(std::cin, name); //������ �̸� get
	std::cout << "Enter the ingredients: ";
	std::getline(std::cin, ingredients); //��� get
	std::cout << "Enter the instructions: ";
	std::getline(std::cin, instructions); // �丮 ��� get
	recipeManager.addRecipe(name, ingredients, instructions);
	std::cout << "Press Enter to continue...";
	std::cin.get(); //����Ű �Է� ���
	goback = true; // Set the flag to return to the first page
}

void Recipe:: EDIT_RECIPE()
{
	int a;
	std::cout << "Enter the number\n'1' : add something to an existiing recipe / '2' : edit all thing / '3' : delete recipe ";
	std::cin >> a;
	std::cin.ignore();

	if (a == 1) { //���� ������(�޴�)���� ingredients/instruction �߰�
		std::cout << "Enter the name of the recipe to add something: ";
		std::string editName, newIngredients, newInstructions;
		std::getline(std::cin, editName);
		
		std::cout << "Enter the new ingredients (leave empty to keep the same): ";
		std::getline(std::cin, newIngredients);
		std::cout << "Enter the new instructions: ";
		std::getline(std::cin, newInstructions);

		recipeManager.editRecipe(editName, newIngredients, newInstructions);
	}
	else if (a == 2) { //������ �ƿ� �����ϱ�
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
	else if (a == 3) { // ������(�޴�) ����

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


void RecipePart:: displayLibrary() //��ü �޴� Ȯ�ο�
{
	if (library.empty()) //���������
	{
		std::cout << "Library is empty." << std::endl; //����ִ� ���
	}
	else
	{
		std::cout << "List of Recipes:\n"; //�Ⱥ�������� ������ ���
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

	Recipe newRecipe; //���ο� ������ ��ü ����
	newRecipe.name = name; //������ ���� ����
	newRecipe.ingredients = ingredients;
	newRecipe.instructions = instructions;
	library.push_back(newRecipe); //������ ��Ͽ� �߰�
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
	for (auto& recipe : library) //��� ������ ��� ����
	{
		if (recipe.name == recipeName) //������ �����ǿ� ���� �����ǰ� ������ �˻�
		{
			if (!newIngredients.empty()) //��Ḧ ���� �߰��ߴٸ�
			{
				recipe.ingredients = newIngredients; //�߰��� ��� ����
			}
			recipe.instructions = newInstructions; //������ ������Ʈ
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
			it = library.erase(it); // �ش� ������ ����
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

