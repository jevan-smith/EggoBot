#include "stdafx.h"
#include <stdio.h>
#include <time.h> // For seeding random
#include <stdlib.h>
#include <atlimage.h> 
#include <Gdiplusimaging.h> 
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include "controls.h"
#include "EasyBMP\EasyBMP.h"
#include "helper.h"
using namespace std;

BMP image;


// Take Screen Shot of specific window
void screenshot(HWND hwnd)
{
	RECT rc;
	//HWND hwnd = h_QWidgetClassWindow;
	GetWindowRect(hwnd, &rc);
	int w = rc.right - rc.left;
	int h = rc.bottom - rc.top;

	//create
	HDC hdc = GetDC(0);
	HDC memdc = CreateCompatibleDC(hdc);
	HBITMAP hbmp = CreateCompatibleBitmap(hdc, w, h);
	HBITMAP oldbmp = (HBITMAP)SelectObject(memdc, hbmp);

	BitBlt(memdc, 0, 0, w, h, hdc, rc.left, rc.top, SRCCOPY);
	SelectObject(memdc, oldbmp);

	//copy to clipboard
	OpenClipboard(NULL);
	EmptyClipboard();
	SetClipboardData(CF_BITMAP, hbmp);
	CloseClipboard();

	CImage image;
	image.Attach(hbmp);
	image.Save(_T("gameImage.bmp"), Gdiplus::ImageFormatBMP);

	//release
	DeleteDC(memdc);
	DeleteObject(hbmp);
	ReleaseDC(0, hdc);
}


void PressKey(WORD key, int x, HWND hwnd)
{
	int y = 0;
	while (y <= x)
	{
		SetForegroundWindow(hwnd);
		Sleep(50 + rand() % 100);

		INPUT *keyClick;
		keyClick = new INPUT;
		keyClick->ki.wVk = key;
		keyClick->type = INPUT_KEYBOARD;
		keyClick->ki.dwFlags = 0;
		keyClick->ki.time = 0;
		keyClick->ki.wScan = 0;
		keyClick->ki.dwExtraInfo = 0;


		SendInput(1, keyClick, sizeof(INPUT));

		Sleep(50);

		keyClick->ki.dwFlags = KEYEVENTF_KEYUP;

		SendInput(1, keyClick, sizeof(INPUT));
		y++;
	}
}

void PressTwoKeys(WORD key, WORD key2, int x, HWND hwnd)
{
	int y = 0;
	while (y <= x)
	{
		SetForegroundWindow(hwnd);
		Sleep(50 + rand() % 100);

		INPUT *keyClick;
		keyClick = new INPUT;
		keyClick->ki.wVk = key;
		keyClick->type = INPUT_KEYBOARD;
		keyClick->ki.dwFlags = 0;
		keyClick->ki.time = 0;
		keyClick->ki.wScan = 0;
		keyClick->ki.dwExtraInfo = 0;

		INPUT *keyClick2;
		keyClick2 = new INPUT;
		keyClick2->ki.wVk = key;
		keyClick2->type = INPUT_KEYBOARD;
		keyClick2->ki.dwFlags = 0;
		keyClick2->ki.time = 0;
		keyClick2->ki.wScan = 0;
		keyClick2->ki.dwExtraInfo = 0;


		SendInput(1, keyClick, sizeof(INPUT));
		SendInput(1, keyClick2, sizeof(INPUT));

		Sleep(50);

		keyClick->ki.dwFlags = KEYEVENTF_KEYUP;
		keyClick2->ki.dwFlags = KEYEVENTF_KEYUP;

		SendInput(1, keyClick, sizeof(INPUT));
		SendInput(1, keyClick2, sizeof(INPUT));
		y++;
	}

}

void ClickMouse(int x, int y, HWND hwnd)
{
	SetForegroundWindow(hwnd);
	Sleep(200 + rand() % 250);

	mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
	Sleep(100);
	mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);


}
void DoubleClickMouse(int x, int y, HWND hwnd)
{
	SetForegroundWindow(hwnd);
	Sleep(200 + rand() % 250);

	mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
	Sleep(200);
	mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);

}

void RightClickMouseAndKey(int x, int y, int z, HWND hwnd, WORD key)
{

	int v = 0;
	while (v <= z)
	{
		SetForegroundWindow(hwnd);
		Sleep(50 + rand() % 100);

		INPUT *keyClick;
		keyClick = new INPUT;
		keyClick->ki.wVk = key;
		keyClick->type = INPUT_KEYBOARD;
		keyClick->ki.dwFlags = 0;
		keyClick->ki.time = 0;
		keyClick->ki.wScan = 0;
		keyClick->ki.dwExtraInfo = 0;


		SendInput(1, keyClick, sizeof(INPUT));

		mouse_event(MOUSEEVENTF_RIGHTDOWN, x, y, 0, 0);

		Sleep(100);

		mouse_event(MOUSEEVENTF_RIGHTUP, x, y, 0, 0);

		Sleep(200);

		keyClick->ki.dwFlags = KEYEVENTF_KEYUP; 

		SendInput(1, keyClick, sizeof(INPUT));

		v++;
	}

}

void RightClickMouse(int x, int y, HWND hwnd)
{
	SetForegroundWindow(hwnd);
	Sleep(200 + rand() % 250);

	mouse_event(MOUSEEVENTF_RIGHTDOWN, x, y, 0, 0);
	Sleep(100);
	mouse_event(MOUSEEVENTF_RIGHTUP, x, y, 0, 0);


}

void ClickDown(int x, int y, HWND hwnd)
{
	SetForegroundWindow(hwnd);
	Sleep(200 + rand() % 250);

	mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
	Sleep(100);

}

void ClickUp(int x, int y, HWND hwnd)
{
	SetForegroundWindow(hwnd);
	Sleep(200 + rand() % 250);

	mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
	Sleep(100);

}

void newMouseMove(int endX, int endY, int stepCount, int stepDelay, HWND hwnd, 
	BMP image, int R, int G, int B, int X, int Y)
{
	POINT ptMouse;
	RECT windowPosition;

	GetWindowRect(hwnd, &windowPosition);

	int finalX = (windowPosition.left + endX) + rand() % 3;
	int finalY = (windowPosition.top + endY) + rand() % 3;

	GetCursorPos(&ptMouse);

	int startX = ptMouse.x;
	int startY = ptMouse.y;



	for (int step = 1; step < stepCount; step++)
	{
		if (correctFish(hwnd, image, R, G, B, X, Y) == true)
		{
			break;
		}

		int currX = startX + (finalX - startX) * step / stepCount;
		int currY = startY + (finalY - startY) * step / stepCount;
		SetCursorPos(currX, currY);
		Sleep(stepDelay);

	}
}


void MoveMouse(int x, int y, int rmouse, HWND hwnd)
{
	SetForegroundWindow(hwnd);
	Sleep(200 + rand() % 250);

	POINT ptMouse;
	RECT windowPosition;

	GetWindowRect(hwnd, &windowPosition);

	int finalX = (windowPosition.left + x) + rand() % 3;
	int finalY = (windowPosition.top + y) + rand() % 3;

	GetCursorPos(&ptMouse);

	int mX = ptMouse.x;
	int mY = ptMouse.y;

	int counter = 0;


	while ((mX != finalX || mY != finalY))
	{

		counter++;

		GetCursorPos(&ptMouse);

		mX = ptMouse.x;
		mY = ptMouse.y;
		int dy = 0; int dx = 0;
		if (finalX > mX)
		{
			if (mX != finalX)
				dx = 3 + rand() % 2;
		}
		else
		{
			if (mX != finalX)
				dx = -3 - rand() % 2;
		}

		if (finalY > mY)
		{
			if (mY != finalY)
				dy = 3 + rand() % 2;
		}
		else
		{
			if (mY != finalY)
				dy = -3 - rand() % 2;
		}


		SetCursorPos(mX + (dx), mY + (dy));


		//SetForegroundWindow(hwnd);
		//Sleep(0);
	}

	if (rmouse == 1)
		ClickMouse(finalX, finalY, hwnd);
	else if (rmouse == 2)
		RightClickMouse(finalX, finalY, hwnd);
	else if (rmouse == 3)
		DoubleClickMouse(finalX, finalY, hwnd);
	else if (rmouse == 4)
		ClickDown(finalX, finalY, hwnd);
	else if (rmouse == 5)
		ClickUp(finalX, finalY, hwnd);

}

void teleportMouse(int x, int y, int rmouse, HWND hwnd, 
	BMP image, int R, int G, int B, int X, int Y)
{
	SetForegroundWindow(hwnd);
	Sleep(200 + rand() % 250);

	POINT ptMouse;
	RECT windowPosition;

	GetWindowRect(hwnd, &windowPosition);

	int finalX = (windowPosition.left + x) + rand() % 3;
	int finalY = (windowPosition.top + y) + rand() % 3;

	if (correctFish(hwnd, image, R, G, B, X, Y) != true)
		SetCursorPos(finalX, finalY);

	SetForegroundWindow(hwnd);


	if (rmouse == 1)
		ClickMouse(finalX, finalY, hwnd);
	else if (rmouse == 2)
		RightClickMouse(finalX, finalY, hwnd);
	else if (rmouse == 3)
		DoubleClickMouse(finalX, finalY, hwnd);
	else if (rmouse == 4)
		ClickDown(finalX, finalY, hwnd);
	else if (rmouse == 5)
		ClickUp(finalX, finalY, hwnd);

}

void teleportMouse2(int x, int y, int rmouse, HWND hwnd)
{
	SetForegroundWindow(hwnd);
	Sleep(200 + rand() % 250);

	POINT ptMouse;
	RECT windowPosition;

	GetWindowRect(hwnd, &windowPosition);

	int finalX = (windowPosition.left + x) + rand() % 3;
	int finalY = (windowPosition.top + y) + rand() % 3;

	SetForegroundWindow(hwnd);

	if (rmouse == 1)
		ClickMouse(finalX, finalY, hwnd);
	else if (rmouse == 2)
		RightClickMouse(finalX, finalY, hwnd);
	else if (rmouse == 3)
		DoubleClickMouse(finalX, finalY, hwnd);
	else if (rmouse == 4)
		ClickDown(finalX, finalY, hwnd);
	else if (rmouse == 5)
		ClickUp(finalX, finalY, hwnd);

}


void SendText(string text, HWND hwnd)
{
	for (int i = 0; i < text.length(); i++)
	{
		char c = toupper(text[i]);
		static_cast<int>(c);
		PressKey(c, 0, hwnd);
	}
}


void CharacterSelect(int x, HWND hwnd)
{
	if (x == 1)
	{
		MoveMouse(901, 110, 1, hwnd);
		PressKey(0x0D, 0, hwnd);
	}
	else if (x == 2)
	{
		MoveMouse(901, 170, 1, hwnd);
		PressKey(0x0D, 0, hwnd);
	}
	else if (x == 3)
	{
		MoveMouse(901, 220, 1, hwnd);
		PressKey(0x0D, 0, hwnd);
	}
	else if (x == 4)
	{
		MoveMouse(901, 280, 1, hwnd);
		PressKey(0x0D, 0, hwnd);
	}
	else if (x == 5)
	{
		MoveMouse(901, 335, 1, hwnd);
		PressKey(0x0D, 0, hwnd);
	}
	else if (x == 6)
	{
		MoveMouse(901, 390, 1, hwnd);
		PressKey(0x0D, 0, hwnd);
	}
	else if (x == 7)
	{
		MoveMouse(901, 440, 1, hwnd);
		PressKey(0x0D, 0, hwnd);
	}
	else if (x == 8)
	{
		MoveMouse(901, 490, 1, hwnd);
		PressKey(0x0D, 0, hwnd);
	}
	else if (x == 9)
	{
		MoveMouse(901, 540, 1, hwnd);
		PressKey(0x0D, 0, hwnd);
	}
	else if (x == 10)
	{
		MoveMouse(901, 610, 1, hwnd);
		PressKey(0x0D, 0, hwnd);
	}
	MoveMouse(0, 0, 0, hwnd);

}