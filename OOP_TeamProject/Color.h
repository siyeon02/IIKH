#define _CRT_SECURE_NO_WARNINGS
#define NOMINMAX
#pragma once
#include <Windows.h>
#include <conio.h>

class Color {
public:
    enum ConsoleColor {
        CC_BLACK,
        CC_DARKBLUE,
        CC_DARKGREEN,
        CC_DARKCYAN,
        CC_DARKRED,
        CC_DARKMAGENTA,
        CC_DARKYELLOW,
        CC_GRAY,
        CC_DARKGRAY,
        CC_BLUE,
        CC_GREEN,
        CC_CYAN,
        CC_RED,
        CC_MAGENTA,
        CC_YELLOW,
        CC_WHITE,
        CC_LIGHTGRAY = 7,
        CC_ORIGINAL = 7,
        CC_ORIGINALFONT = 7,
        CC_ORIGINALBG = 0
    };
    //�ؽ�Ʈ, ��� ���� SET
    void setColor(int color, int bgcolor)
    {
        color &= 0xf;
        bgcolor &= 0xf;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
            (bgcolor << 4) | color);
    }


    //��� ���� SET
    void setBgColor(int bgcolor) {
        CONSOLE_SCREEN_BUFFER_INFO buff;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buff);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
            ((bgcolor & 0xf) << 4) | (buff.wAttributes & 0xf));
    }

    //�ؽ�Ʈ ���� GET
    int getFontColor() {
        CONSOLE_SCREEN_BUFFER_INFO buff;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buff);
        return buff.wAttributes & 0xf;
    }

    //��� ���� GET
    int getBgColor() {
        CONSOLE_SCREEN_BUFFER_INFO buff;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buff);
        return (buff.wAttributes & 0xf0) >> 4;
    }

    //��� ���� Default
    __inline void initBgColor() {
        setBgColor(0);
    }

    //�ؽ�Ʈ, ���� Default
    __inline void initColor() {
        setColor(7, 0);
    }
};