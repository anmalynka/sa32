//#include <iostream>
//#include <string>
//#include <cctype>
//size_t countwords(const char *);
//using namespace std;
//
//int main()
//{
//	char a[] = "Score and seven years ago";
//	float sum = 0.0;
//	char j[10];
//	string s;
//	int size = sizeof(a) / sizeof(char);
//	for (int i = 0; i < size; i++) {
//		if (!isspace(a[i])) {
//			s += a[i];
//		}
//
//		if (isspace(a[i]) && !isspace(a[i + 1])) {
//			cout << s << " " << s.length() << endl;
//			sum += s.length();
//			s = "";
//		}
//	}
//
//	cout << countwords(a);
//
//	return 0;
//}
//
//size_t countwords(const char *s)
//{
//	size_t count = 0;
//
//	while (*s)
//	{
//		while (isspace(*s)) ++s;
//		if (*s) ++count;
//		while (isalnum(*s)) ++s;
//	}
//
//	system("pause");
//	return (count);
//}