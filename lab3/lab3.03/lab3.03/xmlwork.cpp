#include "xmlwork.h"
#include "showxmlhelper.h"
CComPtr<IXMLDOMDocument> spXMLDOM;
HRESULT hr;
VARIANT_BOOL bSuccess = false;
CComPtr<IXMLDOMNode> spXMLNode;
CComBSTR bstrSS;
CComVariant varValue(0);// VT_EMPTY==0
CComPtr<IXMLDOMNode> spXMLChildNode;
CComPtr<IXMLDOMNode> spInsertedNode;
CComQIPtr<IXMLDOMElement> spXMLChildElement;
CComPtr<IXMLDOMDocument> spDoc;

void XMLParse::loadDOMRaw()
{
	HRESULT hr = S_OK;
	IXMLDOMDocument *pXMLDom = NULL;
	IXMLDOMParseError *pXMLErr = NULL;

	BSTR bstrXML = NULL;
	BSTR bstrErr = NULL;
	VARIANT_BOOL varStatus;
	VARIANT varFileName;
	VariantInit(&varFileName);

	CHK_HR(CreateAndInitDOM(&pXMLDom));

	CHK_HR(VariantFromString(L"test.xml", varFileName));
	CHK_HR(pXMLDom->load(varFileName, &varStatus));
	if (varStatus == VARIANT_TRUE)
	{
		CHK_HR(pXMLDom->get_xml(&bstrXML));
		printf("XML DOM loaded from stocks.xml:\n%S\n", bstrXML);
	}
	else
	{
		// Failed to load xml, get last parsing error
		CHK_HR(pXMLDom->get_parseError(&pXMLErr));
		CHK_HR(pXMLErr->get_reason(&bstrErr));
		cout << "Failed to load DOM"<< bstrErr;
	}

CleanUp:
	SAFE_RELEASE(pXMLDom);
	SAFE_RELEASE(pXMLErr);
	SysFreeString(bstrXML);
	SysFreeString(bstrErr);
	VariantClear(&varFileName);
}

void XMLParse::StartXml() {

		hr = spXMLDOM.CoCreateInstance(__uuidof(DOMDocument));
		if (FAILED(hr)) throw "Unable to create XML parser object";
		if (spXMLDOM.p == NULL) throw "Unable to create XML parser object";
		
		hr = spXMLDOM->load(CComVariant(L"test.xml"), &bSuccess);
		if (FAILED(hr)) throw "Unable to load XML document into the parser";
		if (!bSuccess) throw "Unable to load XML document into the parser";
	
}
void XMLParse::FindNodeString() {
	spXMLNode = NULL; 
	HRESULT hr;
	hr = NULL;
	bstrSS = L"forestry/forest";
	hr = spXMLDOM->selectSingleNode(bstrSS, &spXMLNode);
	if (FAILED(hr)) throw "Unable to locate 'xmltext' XML node";
	if (spXMLNode.p == NULL) throw "Unable to locate 'xmltext' XML node";

	hr = spXMLNode->get_nodeTypedValue(&varValue);
	if (FAILED(hr)) throw "Unable to retrieve 'xmltext' text";
	if (varValue.vt == VT_BSTR) {
		USES_CONVERSION;
		LPTSTR lpstrMsg = W2T(varValue.bstrVal);
		cout << lpstrMsg << endl;
	} 
	else {
		// Some error
		throw "Unable to retrieve 'xmltext' text";
	} 
}
void  XMLParse::AddNodeIn() {
	spXMLNode = NULL;
	bstrSS= L"forestry/forest";
	
	hr = spXMLDOM->selectSingleNode(bstrSS, &spXMLNode);
	//cout << "Found";
	if (FAILED(hr)) throw "Unable to locate XML node";
	if (spXMLNode.p == NULL) throw "Unable to locate  XML node";
	//create 
	hr = spXMLDOM->createNode(CComVariant(NODE_ELEMENT), CComBSTR("xmlchildnode"), NULL, &spXMLChildNode);
	if (FAILED(hr)) throw "Unable to create XML node";
	if (spXMLChildNode.p == NULL) throw "Unable to create XML node";
	//moveinto
	hr = spXMLNode->appendChild(spXMLChildNode, &spInsertedNode);
	if (FAILED(hr)) throw "Unable to move XML node";
	if (spInsertedNode.p == NULL) throw "Unable to move XML node";
	//insertinnode
	spXMLChildElement = spInsertedNode;
	if (spXMLChildElement.p == NULL) throw "Unable to query for 'xmlchildnode' XML element interface";
	hr = spXMLChildElement->setAttribute(CComBSTR(L"a"), CComVariant(""));
	if (FAILED(hr)) throw "Unable to insert new attribute";
}
void XMLParse::SaveNewXml()
{
	hr = spXMLDOM->save(CComVariant("updated2.xml"));
	if (FAILED(hr)) throw "Unable to save updated XML document";
}
