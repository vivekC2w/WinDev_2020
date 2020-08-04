//Headers
#include<windows.h>

//global varible declaraion
int iPaintFlag;
//global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR LPSZCmdLine, int iCmdShow)
{
	//variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");

	//code
	//initialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//register above class
	RegisterClassEx(&wndclass);

	//create window
	hwnd = CreateWindow(szAppName,
		TEXT("My first Application"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//code
	
	int num1 = 55;
	int num2 = 45;
	int num3;
	TCHAR STR[255];

	switch (iMsg)
	{
	
	case WM_CREATE:
		MessageBox(hwnd, TEXT("WM_CREATE IS RECIEVED"), TEXT("MESSAGE"), MB_OK);
		break;

	case WM_CHAR:
		switch (wParam) {
		case '+':
			num3 = num1 + num2;
			wsprintf(STR, TEXT("The Sum of %d & %d is %d"),num1, num2, num3);
			MessageBox(hwnd, STR, TEXT("SUM"), MB_OK );
			break;
		
		case '-':
			num3 = num1 - num2;
			wsprintf(STR, TEXT("The Substraction of %d & %d is %d"),num1, num2, num3);
			MessageBox(hwnd, STR, TEXT("SUBSTRACTION"), MB_OK );
			break;
		
		case '*':
			num3 = num1 * num2;
			wsprintf(STR, TEXT("The Multiplication of %d & %d is %d"),num1, num2, num3);
			MessageBox(hwnd, STR, TEXT("MULTIPLICATION"), MB_OK );
			break;
		
		case '/':
			num3 = num1 / num2;
			wsprintf(STR, TEXT("The Division of %d & %d is %d"),num1, num2, num3);
			MessageBox(hwnd, STR, TEXT("DIVISION"), MB_OK );
			break;
		}
		break;
		
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}