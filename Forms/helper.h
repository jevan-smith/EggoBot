#ifndef HELPER_H_
#define HELPER_H_

#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "EasyBMP\EasyBMP.h"
using namespace std;

void Login(string username, string password, int charList, HWND hwnd);
void whiteImage(HWND hwnd, BMP image, int right, int left, int top, int bottom);
bool correctFish(HWND hwnd, BMP image, int R, int G, int B, int X, int Y);
void scanForFish(HWND hwnd, BMP image, int R, int G, int B, int X, int Y);
void grabFish(HWND hwnd, BMP image, bool autoloot, int R, int G, int B, int X, int Y, int fishWaitTime, int mode);
bool checkForSplash(HWND hwnd, int mode);

#endif