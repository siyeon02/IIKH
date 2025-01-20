#pragma once
#include "greeter.h"
#include "recipe.h"
#include "Color.h"
#include "plan.h"

Color color;
//Greeter greeter;
Recipe recipe;
Date date;

bool returnToFirstPage;

int choice_L = 0;
int choice_1 = 0;
int choice_2 = 0;

void Greeter::greeter_start()
{
	color.setColor(Color::CC_WHITE, Color::CC_BLACK);

	system("cls");
	std::cout << "������������������������������������������������" << std::endl;
	color.setColor(Color::CC_WHITE, Color::CC_MAGENTA);
	std::cout << "��  *  *  *  ��  *  *  *  ��  *  *  *  �� *  *  *  �� \n\n";

	color.setColor(Color::CC_RED, Color::CC_BLACK);
	std::cout << "   IIIIIII  IIIIIII   KKK  KKK   HHH    HHH \n";

	color.setColor(Color::CC_RED, Color::CC_BLACK);
	std::cout << "     III      III     KKK KKK    HHH    HHH \n";

	color.setColor(Color::CC_YELLOW, Color::CC_BLACK);
	std::cout << "     III      III     KKKKK      HHH    HHH \n";

	color.setColor(Color::CC_YELLOW, Color::CC_BLACK);
	std::cout << "     III      III     KKK        HHHHHHHHHH \n";

	color.setColor(Color::CC_CYAN, Color::CC_BLACK);
	std::cout << "     III      III     KKKKK      HHH    HHH \n";

	color.setColor(Color::CC_CYAN, Color::CC_BLACK);
	std::cout << "     III      III     KKK KKK    HHH    HHH \n";

	color.setColor(Color::CC_YELLOW, Color::CC_BLACK);
	std::cout << "   IIIIIII  IIIIIII   KKK  KKK   HHH    HHH \n\n";

	color.setColor(Color::CC_WHITE, Color::CC_MAGENTA);
	std::cout << "��  *  *  *  ��  *  *  *  ��  *  *  *  ��  *  *  *  ��\n";

	color.initColor(); //���� �ʱ�ȭ

	std::cout << std::endl;
	std::cout << "������������������������������������������������" << std::endl << std::endl;

	greeter_select();
}

void Greeter::greeter_select()
{
	while (true) {

		std::cout << "������������������������������������������������" << std::endl;
		std::cout << "1.RECIPE" << std::endl;
		std::cout << "2.PLAN" << std::endl;
		std::cout << "3.QUIT" << std::endl;
		std::cout << "������������������������������������������������" << std::endl;

		std::cin >> choice_L;

		if (std::cin.fail()) { //�Է��� ���ڰ� 1, 2, 3 ��� �ƴ� ���
			std::cout << "illegal Expression" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �Է� ���� ����
			continue;
		}
		int ik = 1;
		if (ik == choice_L)std::cout << "good\n";

		switch (choice_L) {
			color.initColor(); //���� �ʱ�ȭ
		case 1:
			//recipe_move();
			//������ ��ȸ �� ����
			while (1) { //�Էµ� ���� submit�̸� �ݺ��� ����, �Լ� ����

			   //if (choice_L == '1') {

				while (choice_1 != 5) { //5������ ����ȭ�� retrun

					if (returnToFirstPage) { // ���ư��� �ϸ�
						returnToFirstPage = false;
						system("cls"); //�ܼ� cls
						choice_1 = 0; //������ �ʱ�ȭ
					}
					std::cout << "  1. Display Recipe Library\n";
					std::cout << "  2. Search Recipe\n";
					std::cout << "  3. Add Recipe\n";
					std::cout << "  4. Edit Recipe\n";
					std::cout << "  5. Exit\n";
					std::cout << "-----------------------------\n";
					std::cout << "Enter your choice: ";

					if (!(std::cin >> choice_1)) {
						std::cerr << "Invalid input. Please enter a number." << std::endl;
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						continue;
					}

					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �Է� ���� Ŭ����

					switch (choice_1) {
					case 1: {
						recipe.DISPLAY_RECIPE();
						break;
					}
					case 2: {
						recipe.SEARCH_RECIPE();
						break;
					}
					case 3: {
						recipe.ADD_RECIPE();
						break;
					}
					case 4: {
						recipe.EDIT_RECIPE();
						break;
					}
					case 5: { // Exit
						system("cls");
						std::cout << "            ~ see you again ~ \n";
						color.initColor(); //���� �ʱ�ȭ
						break;
					}
					default: { //�̻��Ѱ� ��������
						std::cout << "Invalid choice. Press Enter to try it again." << std::endl;
						std::cin.get();
						returnToFirstPage = true;
					}
					}
				}
				break;
			}
			break;
		case 2:
			//plan ��� ����
			while (1) { //�Էµ� ���� submit�̸� �ݺ��� ����, �Լ� ����
				std::cout << "=============================================\n";
				std::cout << "Your Meal Plan !!\n";
				std::cout << "1. Add Plan\n";
				std::cout << "2. Edit Plan\n";
				std::cout << "3. Delete Plan\n";
				std::cout << "4. Search Plan or Date\n";
				std::cout << "5. Exit\n";
				std::cout << "Select the menu:";

				std::cin >> choice_2;

				system("cls");

				switch (choice_2) {
				case 1:
					date.AddPlan();
					break;
				case 2:
					date.EditPlan();
					break;
				case 3:
					date.DeletePlan();
					break;
				case 4:
					date.SearchPlan();
					break;
				case 5:
					std::cout << "\nEnd the plan management.\n";
					system("cls");
					return;
				default:
					std::cout << "\nInvalid choice.Press Enter to try it again.\n";// �߸�����
					continue;
				}
				break;
			}
			//  }
			break;
		case 3:
			system("cls");//����
			return;
		default:
			std::cout << "illegal Expression" << std::endl;
			break;
		}
	}
}