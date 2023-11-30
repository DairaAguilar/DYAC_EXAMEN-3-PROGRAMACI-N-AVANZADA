#include <Windows.h>
#include <CommDlg.h>
#include <CommCtrl.h>
#include <shellapi.h>
#include <math.h>
#include <atlstr.h>
#include <string>
#include <fstream>
#include "resource.h"
#include"MMSystem.h"
using namespace std;


LRESULT CALLBACK MENU(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK INICIO(HWND hWnd, UINT msgi, WPARAM wParaM, LPARAM LParam);
LRESULT CALLBACK VENTAS(HWND hWnd1, UINT msgi1, WPARAM wParaM1, LPARAM LParam1);
LRESULT CALLBACK COMPRASS(HWND hWnd2, UINT msgi2, WPARAM wParaM2, LPARAM LParam2);
LRESULT CALLBACK HORARIO(HWND hWnd3, UINT msgi3, WPARAM wParaM3, LPARAM LParam3);
LRESULT CALLBACK PROMOCIONES(HWND hWnd4, UINT msgi4, WPARAM wParaM4, LPARAM LParam4);

int peli, prom;
char boletos[20];
string peli1;
int x;
int aux=0;
int aux2 = 0;
int precio = 0;
HWND hwnd;
HINSTANCE hInstance;
MSG mensaje;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
    hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(101), NULL, MENU);
    ShowWindow(hwnd, SW_SHOWDEFAULT);
    /* Bucle de mensajes: */
    while (TRUE == GetMessage(&mensaje, 0, 0, 0))
    {
        TranslateMessage(&mensaje);
        DispatchMessage(&mensaje);
    }
}


LRESULT CALLBACK MENU(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

    switch (msg)
    {

    case WM_COMMAND:
    {
        char usu[20], co[20];
        GetDlgItemText(hwnd, 1002, usu, 20); //usuario
        GetDlgItemText(hwnd, 1005, co, 20); //contraseña

        if (LOWORD(wParam) == IDC_BUTTON1 && HIWORD(wParam) == BN_CLICKED)
        {
            hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(103), hwnd, INICIO, hInstance);
            ShowWindow(hwnd, SW_SHOWDEFAULT);
        }

    }break;

    case WM_CLOSE: {
        DestroyWindow(hwnd);

    }break;

    case WM_DESTROY: {
        PostQuitMessage(0);
    }break;
    }
    return 0;
}
LRESULT CALLBACK INICIO(HWND hWnd, UINT msgi, WPARAM wParaM, LPARAM LParam)
{

    switch (msgi)
    {

    case WM_COMMAND:
    {
        if (LOWORD(wParaM) == VENTA && HIWORD(wParaM) == BN_CLICKED)
        {
            if (aux == 0 && aux2==1)
            {
                hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(107), hwnd, VENTAS, hInstance);
                ShowWindow(hwnd, SW_SHOWDEFAULT);
                aux = 1;
            }
            else if (aux2 == 1)
            {
                int Aux = MessageBox(hWnd, "YA INGRESO ESTA OPCIÓN", "ADVERTENCIA", MB_OK);
            }
            else
            {
                int Aux = MessageBox(hWnd, "PRIMERO DEBEVER LOS EVENTOS", "ADVERTENCIA", MB_OK);
            }
        }
        if (LOWORD(wParaM) == COMPRAS && HIWORD(wParaM) == BN_CLICKED)
        {
            if (aux == 1)
            {
                hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(110), hwnd, COMPRASS, hInstance);
                ShowWindow(hwnd, SW_SHOWDEFAULT);
            }      
            else
            {
                int Aux = MessageBox(hWnd, "PRIMERO DEBE REALIZAR UNA COMPRA", "ADVERTENCIA", MB_OK);
            }
        }
        if (LOWORD(wParaM) == EVENTOS && HIWORD(wParaM) == BN_CLICKED)
        {
            hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(104), hwnd, HORARIO, hInstance);
            ShowWindow(hwnd, SW_SHOWDEFAULT);
            aux2 = 1;
        }

    }break;

    case WM_CLOSE: {
        DestroyWindow(hwnd);

    }break;

    case WM_DESTROY: {
        PostQuitMessage(0);
    }break;
    }
    return 0;
}
LRESULT CALLBACK VENTAS(HWND hWnd1, UINT msgi1, WPARAM wParaM1, LPARAM LParam1)
{
    
    switch (msgi1)
    {

    case WM_COMMAND:
    {
            if (LOWORD(wParaM1) == B1 && HIWORD(wParaM1) == BN_CLICKED)
            {
                peli = 1;
                hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(112), hwnd, PROMOCIONES, hInstance);
                ShowWindow(hwnd, SW_SHOWDEFAULT);
            }

            if (LOWORD(wParaM1) == B2 && HIWORD(wParaM1) == BN_CLICKED)
            {
                peli = 2;
                hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(112), hwnd, PROMOCIONES, hInstance);
                ShowWindow(hwnd, SW_SHOWDEFAULT);
            }
            if (LOWORD(wParaM1) == B3 && HIWORD(wParaM1) == BN_CLICKED)
            {
                peli = 3;
                hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(112), hwnd, PROMOCIONES, hInstance);
                ShowWindow(hwnd, SW_SHOWDEFAULT);
            }
            if (LOWORD(wParaM1) == B4 && HIWORD(wParaM1) == BN_CLICKED)
            {
                peli = 4;
                hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(112), hwnd, PROMOCIONES, hInstance);
                ShowWindow(hwnd, SW_SHOWDEFAULT);
            }
            if (LOWORD(wParaM1) == B5 && HIWORD(wParaM1) == BN_CLICKED)
            {
                peli = 5;
                hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(112), hwnd, PROMOCIONES, hInstance);
                ShowWindow(hwnd, SW_SHOWDEFAULT);
            }
            if (LOWORD(wParaM1) == B6 && HIWORD(wParaM1) == BN_CLICKED)
            {
                peli = 6;
                hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(112), hwnd, PROMOCIONES, hInstance);
                ShowWindow(hwnd, SW_SHOWDEFAULT);
            }

    }break;

    case WM_CLOSE: {
        DestroyWindow(hwnd);

    }break;

    case WM_DESTROY: {
        PostQuitMessage(0);
    }break;
    }
    return 0;
}
LRESULT CALLBACK COMPRASS(HWND hWnd2, UINT msgi2, WPARAM wParaM2, LPARAM LParam2)
{

    switch (msgi2)
    {
    case WM_INITDIALOG:
    {
        HWND hwndList = GetDlgItem(hWnd2, IDC_LIST1); // Replace IDC_LISTBOX with the ID of your ListBox

        // Convert the variables to strings
        string x_str = to_string(x);
        string peli1_str = peli1;
        string precio_str = to_string(precio);

        // Add the strings to the ListBox
        SendMessage(hwndList, LB_ADDSTRING, 0, (LPARAM)x_str.c_str());
        SendMessage(hwndList, LB_ADDSTRING, 0, (LPARAM)peli1_str.c_str());
        SendMessage(hwndList, LB_ADDSTRING, 0, (LPARAM)precio_str.c_str());
    }
    case WM_COMMAND:
    {
        if (LOWORD(wParaM2) == IDC_BUTTON2 && HIWORD(wParaM2) == BN_CLICKED)
        { 
            int owo = MessageBox(hWnd2, "GRACIAS POR SU COMPRA, HASTA PRONTO", "ADIOS", MB_OK);
            DestroyWindow(hwnd);
        }

        
    }break;

    case WM_DESTROY: {
        PostQuitMessage(0);
    }break;
    }
    return 0;
}
LRESULT CALLBACK HORARIO(HWND hWnd3, UINT msgi3, WPARAM wParaM3, LPARAM LParam3)
{

    switch (msgi3)
    {

    case WM_COMMAND:
    {
        if (LOWORD(wParaM3) == BACK && HIWORD(wParaM3) == BN_CLICKED)
        {
            hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(103), hwnd,INICIO, hInstance);
            ShowWindow(hwnd, SW_SHOWDEFAULT);
        }

    }break;

    case WM_CLOSE: {
        DestroyWindow(hwnd);

    }break;

    case WM_DESTROY: {
        PostQuitMessage(0);
    }break;
    }
    return 0;
}
LRESULT CALLBACK PROMOCIONES(HWND hWnd4, UINT msgi4, WPARAM wParaM4, LPARAM LParam4)
{

    switch (msgi4)
    {

    case WM_COMMAND:
    {
        if (peli == 1)
        {
            peli1 = "TROLS 3 21 NOVIEMBRE";
        }
        if (peli == 2)
        {
            peli1 = "LADYBUG 22 NOVIEMBRE";
        }
        if (peli == 3)
        {
            peli1 = "LADYBUG 24 NOVIEMBRE";
        }
        if (peli == 4)
        {
            peli1 = "TROLS 3 30 DE NOVIEMBRE";
        }
        if (peli == 5)
        {
            peli1 = "CHUCKY 1 DICIEMBRE";
        }
        if (peli == 6)
        {
            peli1 = "CHUCKY 5 DICIEMBRE";
        }
        int val = 0;
        GetDlgItemText(hWnd4, IDC_EDIT1, boletos, 20); //cantidad de boletos
        if (LOWORD(wParaM4) == IDC_BUTTON1 && HIWORD(wParaM4) == BN_CLICKED)
        {
            x = atoi(boletos);
           if (x < 1 || x > 4) 
           {
                int res = MessageBox(hWnd4, "Ingrese de Nuevo los Datos solo de puede de 1 a 4 boletos", "invalido", MB_OK);
           }
            val = 1;
        }
        if (LOWORD(wParaM4) == IDC_BUTTON2 && HIWORD(wParaM4) == BN_CLICKED)
        {
            if (x == 1)
            {
                int ewe = MessageBox(hWnd4, "Promoción invalida", "invalido", MB_OK);
                precio = 50;

            }
            if (x == 2)
            {
                int ewe = MessageBox(hWnd4, "Promoción valida", "valido", MB_OK);
                precio = 50;
            }
            if (x == 3)
            {
                int ewe = MessageBox(hWnd4, "Promoción valida", "valido", MB_OK);
                precio = 100;
            }
            if (x == 4)
            {
                int ewe = MessageBox(hWnd4, "Promoción valida", "valido", MB_OK);
                precio = 100;
            }
            hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(103), hwnd, INICIO, hInstance);
            ShowWindow(hwnd, SW_SHOWDEFAULT);
        }
        if (LOWORD(wParaM4) == IDC_BUTTON3 && HIWORD(wParaM4) == BN_CLICKED)
        {
            if (x == 1)
            {
                int ewe = MessageBox(hWnd4, "Promoción valida", "valido", MB_OK);
                precio = 45;

            }
            if (x == 2 )
            {
                int ewe = MessageBox(hWnd4, "Promoción valida", "valido", MB_OK);
                precio = 90;
            }
            if (x == 3)
            {
                int ewe = MessageBox(hWnd4, "Promoción valida", "valido", MB_OK);
                precio = 135;
            }
            if (x == 4)
            {
                int ewe = MessageBox(hWnd4, "Promoción valida", "valido", MB_OK);
                precio = 180;
            }
            hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(103), hwnd, INICIO, hInstance);
            ShowWindow(hwnd, SW_SHOWDEFAULT);
        }
    }break;

    case WM_CLOSE: {
        DestroyWindow(hwnd);

    }break;

    case WM_DESTROY: {
        PostQuitMessage(0);
    }break;
    }
    return 0;
}

