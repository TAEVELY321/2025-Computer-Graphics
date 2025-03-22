#include <windows.h>
#include "CShape.h"
#include "CCircle.h"
#include "CRectangle.h"

LRESULT WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	WNDCLASS wc;
	HWND hwnd;
	MSG msg;
	wc.style = 0;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = L"MyWndClass";

	RegisterClass(&wc);
	
	hwnd = CreateWindow(
		L"MyWndClass", // WNDCLASS name
		L"SDK Application", // Window title
		WS_OVERLAPPEDWINDOW,// Window style
		CW_USEDEFAULT, // Horizontal position
		CW_USEDEFAULT, // Vertical position
		300, // Initial width
		200, // Initial height
		HWND_DESKTOP, // Handle of parent window
		NULL, // Menu handle
		hInstance, // Application's instance handle
		NULL // Window-creation data
	);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return (int)msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps; // a structure need to paint the client area of a window
	HDC hdc; // a device context need for drawing on a window

	switch (message)
	{

	case WM_PAINT:
	{
		hdc = BeginPaint(hwnd, &ps); // start of drawing objects
		CShape* shapes[5];
		shapes[0] = new CCircle(100, 100, 50);
		shapes[1] = new CRectangle(300, 300, 100, 100);
		shapes[2] = new CRectangle(200, 100, 50, 150);
		shapes[3] = new CCircle(100, 300, 150);
		shapes[4] = new CRectangle(200, 200, 300, 300);

		for (int i = 0; i < 5; ++i)
			shapes[i]->Draw(hdc);

		for (int i = 0; i < 5; ++i)
		{
			delete shapes[i];
			shapes[i] = NULL;
		}

		EndPaint(hwnd, &ps); // end of drawing objects
		return 0;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
	
}