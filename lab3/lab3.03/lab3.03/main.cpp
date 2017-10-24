#include "xmlwork.h"

//HRESULT hr; 
void main()
{
	XMLParse xml;
	CoInitialize(NULL);//initialize com library in current project, it want load without
	try {
		xml.StartXml();
		xml.FindNodeString();
		xml.AddNodeIn();
		xml.SaveNewXml();
	
		xml.loadDOMRaw();
		cout << "Processing complete..." << endl << endl;
	}
	catch (char* lpstrErr) {
		cout << lpstrErr << endl << endl;
	}
	catch (...) {
		cout << "Unknown error..." << endl << endl;
	}
	CoUninitialize();
	system("pause");
}