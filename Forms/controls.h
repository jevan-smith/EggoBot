#ifndef CONTROLS_H_
#define CONTROLS_H_

#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "EasyBMP\EasyBMP.h"
using namespace std;

void screenshot(HWND hwnd);
void PressKey(WORD key, int x, HWND hwnd);
void ClickMouse(int x, int y, HWND hwnd);
void DoubleClickMouse(int x, int y, HWND hwnd);
void RightClickMouse(int x, int y, HWND hwnd);
void ClickDown(int x, int y, HWND hwnd);
void ClickUp(int x, int y, HWND hwnd);
void MoveMouse(int x, int y, int rmouse, HWND hwnd);
void teleportMouse(int x, int y, int rmouse, HWND hwnd, BMP image, int R, int G, int B, int X, int Y);
void SendText(string text, HWND hwnd);
void CharacterSelect(int x, HWND hwnd);
void newMouseMove(int endX, int endY, int stepCount, int stepDelay, HWND hwnd, BMP image, int R, int G, int B, int X, int Y);
void PressTwoKeys(WORD key, WORD key2, int x, HWND hwnd);
void RightClickMouseAndKey(int x, int y, int z, HWND hwnd, WORD key);
void teleportMouse2(int x, int y, int rmouse, HWND hwnd);

#endif