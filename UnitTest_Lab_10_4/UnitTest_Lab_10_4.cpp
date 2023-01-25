#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10_4/Lab_10_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab104
{
	TEST_CLASS(UnitTestLab104)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char fname[255] = "UnitTest.txt";
			char gname[255] = "UnitTest1.txt";
			string search = "Test";
			string result = "asdfTestgfgd\ngdTestgjkdkl\nngdTestjgjgh\nLines found : 3\n";
			ProcessTXT(fname, gname, search);
			string result1 = PrintTXT(gname);
			int compare = result.compare(result1);
			Assert::AreEqual(compare, 0);
		}
	};
}
