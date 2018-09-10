#include "stdafx.h"
#include <stdio.h>
#include <time.h> // For seeding random
#include <atlimage.h> 
#include <Gdiplusimaging.h> 
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include "controls.h"
#include "helper.h"
#include "EasyBMP\EasyBMP.h"
#include <fstream>
#include "Form1.h"
using namespace std;

void Login(string username, string password, int charList, HWND hwnd)
{
	//This Types in username/password login
	cout << "Logging in..." << endl;
	SendText(username, hwnd);
	PressKey(0x09, 0, hwnd);
	SendText(password, hwnd);
	PressKey(0x0D, 0, hwnd);
	system("CLS");

	cout << "Selecting Character Number (" << charList << ")..." << endl;
	Sleep(5000);

	CharacterSelect(charList, hwnd);
}

void whiteImage(HWND hwnd, BMP image, int right, int left, int top, int bottom)
{
	screenshot(hwnd);
	image.ReadFromFile("gameImage.bmp");

	for (int i = 0; i < 1023; i++)
	{
		for (int j = 0; j < 767; j++)
		{
			if (i < left/*Left*/ || j < top/*Top*/ || i > right/*Right*/ || j > bottom/*Bottom*/)
			{
				RGBApixel Temp = image.GetPixel(i, j);
				Temp.Red = 0; Temp.Green = 0; Temp.Blue = 0; Temp.Alpha = 0;
				image.SetPixel(i, j, Temp);
			}
		}
	}

	image.WriteToFile("gameImageCropped.bmp");
}


bool correctFish(HWND hwnd, BMP image, int R, int G, int B, int X, int Y)
{

	//BMP image;
	screenshot(hwnd);
	image.ReadFromFile("gameImage.bmp");

	RGBApixel Temp = image.GetPixel(X, Y);
	if (Temp.Red == R && Temp.Green == G && Temp.Blue == B)
	{
		return true;
	}

	return false;
}

void scanForFish(HWND hwnd, BMP image, int R, int G, int B, int X, int Y)
{

	teleportMouse(347, 123, 0, hwnd, image, R, G, B, X, Y);
	newMouseMove(708, 123, 13, 15, hwnd, image, R, G, B, X, Y);

	teleportMouse(347, 143, 0, hwnd, image, R, G, B, X, Y);
	newMouseMove(708, 143, 13, 15, hwnd, image, R, G, B, X, Y);

	teleportMouse(347, 163, 0, hwnd, image, R, G, B, X, Y);
	newMouseMove(708, 163, 13, 15, hwnd, image, R, G, B, X, Y);

	teleportMouse(347, 183, 0, hwnd, image, R, G, B, X, Y);
	newMouseMove(708, 182, 13, 15, hwnd, image, R, G, B, X, Y);

	teleportMouse(347, 203, 0, hwnd, image, R, G, B, X, Y);
	newMouseMove(708, 203, 13, 15, hwnd, image, R, G, B, X, Y);

	teleportMouse(347, 223, 0, hwnd, image, R, G, B, X, Y);
	newMouseMove(708, 223, 13, 15, hwnd, image, R, G, B, X, Y);

	teleportMouse(347, 243, 0, hwnd, image, R, G, B, X, Y);
	newMouseMove(708, 243, 13, 15, hwnd, image, R, G, B, X, Y);

	teleportMouse(347, 263, 0, hwnd, image, R, G, B, X, Y);
	newMouseMove(708, 263, 13, 15, hwnd, image, R, G, B, X, Y);

}

void grabFish(HWND hwnd, BMP image, bool autoloot, int R, int G, int B, int X, int Y, int fishWaitTime, int mode)
{
	if (correctFish(hwnd, image, R, G, B, X, Y) == false)
	{
		return;
	}

	remove("gameImageCropped.bmp");

	int mouseToWindowX = 0;
	int mouseToWindowY = 0;

	std::clock_t start;
	double duration;

	start = std::clock();


	while (checkForSplash(hwnd, mode) != true)
	{

		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		//cout << duration << endl;
		if (duration >= fishWaitTime)
		{
			return;
		}

		BMP image;
		RECT rc;
		GetWindowRect(hwnd, &rc);

		int w = rc.right - rc.left;
		int h = rc.bottom - rc.top;

		POINT ptMouse;
		GetCursorPos(&ptMouse);

		int mX = ptMouse.x;
		int mY = ptMouse.y;

		RECT windowPosition;
		GetWindowRect(hwnd, &windowPosition);

		mouseToWindowX = -(windowPosition.left - mX);
		mouseToWindowY = -(windowPosition.top - mY);

		int leftSide = (mouseToWindowX - 50);
		int rightSide = (mouseToWindowX + 50);
		int topSide = (mouseToWindowY - 50);
		int bottomSide = (mouseToWindowY + 50);

		whiteImage(hwnd, image, rightSide, leftSide, topSide, bottomSide);
	}

	Sleep(950);
	if (autoloot == true)
	{
		RightClickMouseAndKey(mouseToWindowX, mouseToWindowY, 0, hwnd, VK_SHIFT);
	}
	else
	{
		RightClickMouse(mouseToWindowX, mouseToWindowY, hwnd);
	}

}

bool checkForSplash(HWND hwnd, int mode)
{
	ifstream ifile("gameImageCropped.bmp");
	if (ifile)
	{
		BMP image;
		image.ReadFromFile("gameImageCropped.bmp");
		if (mode == 1) { // LIGHT MODE
			for (int i = 0; i < 1023; i++)
			{
				for (int j = 0; j < 767; j++)
				{
					RGBApixel Temp = image.GetPixel(i, j);
					if (Temp.Red >= 230 && Temp.Red <= 255 && Temp.Green >= 230 && Temp.Green <= 255 && Temp.Blue >= 235 && Temp.Blue <= 255)
					{
						return true;
					}
				}
			}
		}
		else // DARK MODE
		{
			for (int i = 0; i < 1023; i++)
			{
				for (int j = 0; j < 767; j++)
				{
					RGBApixel Temp = image.GetPixel(i, j);
					if (Temp.Red >= 180 && Temp.Red <= 255 && Temp.Green >= 180 && Temp.Green <= 255 && Temp.Blue >= 180 && Temp.Blue <= 255)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

