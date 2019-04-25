#include <windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
switch (message)
{
case WM_DESTROY:
PostQuitMessage(0);
break;
default:
return DefWindowProc(hWnd, message, wParam, lParam);
}
return 0;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
MSG msg;
WNDCLASSEX wcex = {0};
HWND hWnd;

wcex.cbSize = sizeof(WNDCLASSEX);
wcex.lpfnWndProc = WndProc;
wcex.hInstance = hInstance;
wcex.lpszClassName = "TestClass";
RegisterClassEx(&wcex);
hWnd = CreateWindow("TestClass", "Hello world", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, 500, 300, NULL, NULL, hInstance, NULL);
ShowWindow(hWnd, nCmdShow);
UpdateWindow(hWnd);
while (GetMessage(&msg, NULL, 0, 0))
{
TranslateMessage(&msg);
DispatchMessage(&msg);
}
return 0;
}
