#pragma once
#include <atlbase.h>
#include <msxml6.h>
#include <iostream>
#include <tchar.h>
#include <stdio.h>
using namespace std;
#define CHK_HR(stmt)        do { hr=(stmt); if (FAILED(hr)) goto CleanUp; } while(0)
#define CHK_ALLOC(p)        do { if (!(p)) { hr = E_OUTOFMEMORY; goto CleanUp; } } while(0)
#define SAFE_RELEASE(p)     do { if ((p)) { (p)->Release(); (p) = NULL; } } while(0)


class XMLParse
{
private:
public:
	void loadDOMRaw();
	void StartXml();
	void FindNodeString();
	void AddNodeIn();
	void SaveNewXml();
	
};