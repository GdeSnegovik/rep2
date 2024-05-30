#include "pch.h"
#include "CppUnitTest.h"
#include "..\main-project\processing.h"
#include <vector>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	Talk* build_talk(int s_h, int s_m, int e_h, int e_m,
		const char l_name[30], const char f_name[30], const char m_name[30], const char theme_[30]) {
		Talk* talk = new Talk;
		talk->start_h = s_h;
		talk->start_m = s_m;
		talk->end_h = e_h;
		talk->end_m = e_m;
		strncpy_s(talk->last_name, l_name, 30);
		strncpy_s(talk->first_name, f_name, 30);
		strncpy_s(talk->middle_name, m_name, 30);
		strncpy_s(talk->theme, theme_, 30);
		return talk;
	}


	void delete_talk(vector<Talk*>& array)
	{
		for (auto talk : array) {
			delete talk;
		}
		array.clear();
	}


	TEST_CLASS(unittestproject)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			vector<Talk*> talks;
			Assert::AreEqual(string("Нет данных о докладах."), process(talks));
			delete_talk(talks);
		};
		TEST_METHOD(TestMethod2)
		{
			vector<Talk*> talks;
			talks.push_back(build_talk(10, 12, 10, 35, "Власов", "Кирилл", "Георгиевич", "договор"));
			talks.push_back(build_talk(9, 18, 16, 34, "Надеждина", "Мария", "Владимировна", "разговор"));
			Assert::AreEqual(string("7:16"), process(talks));
			delete_talk(talks);
		};
		TEST_METHOD(TestMethod3)
		{
			vector<Talk*> talks;
			talks.push_back(build_talk(10, 2, 15, 8, "Сидоров", "Павел", "Иванович", "сочинение"));
			talks.push_back(build_talk(17, 12, 18, 8, "Власов", "Кирилл", "Георгиевич", "договор"));
			talks.push_back(build_talk(9, 2, 12, 46, "Надеждина", "Мария", "Владимировна", "разговор"));
			Assert::AreEqual(string("5:6"), process(talks));
			delete_talk(talks);
		};
	};
}


