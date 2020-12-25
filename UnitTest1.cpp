#include "pch.h"
#include "CppUnitTest.h"
#include "../semestr_project//Calculation.h"
#include "../semestr_project/Calculation.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace courseworktest
{
	TEST_CLASS(courseworktest)
	{
	public:
		calculation* c;

		TEST_METHOD_INITIALIZE(co)
		{
			c = new calculation();
		}

		TEST_METHOD_CLEANUP(cod)
		{
			delete c;
		}

		TEST_METHOD(UnitTest)
		{
			c->push_back("5", 5.0);
			c->check(c->return_data());
			c->push_back("+", 0.0);
			c->check(c->return_data());
			c->push_back("6", 6.0);
			c->check(c->return_data());
			c->infixToPrefix();
			Assert::AreEqual(c->count(), 11.0);
		}

		TEST_METHOD(UnitTest1)
		{
			c->push_back("5", 5.0);
			c->check(c->return_data());
			c->push_back("-", 0.0);
			c->check(c->return_data());
			c->push_back("4", 4.0);
			c->check(c->return_data());
			c->infixToPrefix();
			Assert::AreEqual(c->count(), 1.0);
		}

		TEST_METHOD(UnitTest2)
		{
			c->push_back("10", 10.0);
			c->check(c->return_data());
			c->push_back("*", 0.0);
			c->check(c->return_data());
			c->push_back("3.5", 3.5);
			c->check(c->return_data());
			c->infixToPrefix();
			Assert::AreEqual(c->count(), 35.0);
		}

		TEST_METHOD(UnitTest3)
		{
			c->push_back("10", 10.0);
			c->check(c->return_data());
			c->push_back("/", 0.0);
			c->check(c->return_data());
			c->push_back("2.0", 2.0);
			c->check(c->return_data());
			c->infixToPrefix();
			Assert::AreEqual(c->count(), 5.0);
		}

		TEST_METHOD(UnitTest4)
		{
			c->push_back("sin", 0.0);
			c->check(c->return_data());
			c->push_back("0", 0);
			c->check(c->return_data());
			c->infixToPrefix();
			Assert::AreEqual(c->count(), 0.0);
		}

		TEST_METHOD(UnitTest5)
		{
			c->push_back("cos", 0.0);
			c->check(c->return_data());
			c->push_back("pi", pi);
			c->check(c->return_data());
			c->infixToPrefix();
			Assert::AreEqual(c->count(), -1.0);
		}

		TEST_METHOD(UnitTest6)
		{
			c->push_back("ln", 0.0);
			c->check(c->return_data());
			c->push_back("eps", e);
			c->check(c->return_data());
			c->infixToPrefix();
			Assert::AreEqual(c->count(), 0.0);
		}

		TEST_METHOD(UnitTest7)
		{
			c->push_back("lg", 0.0);
			c->check(c->return_data());
			c->push_back("10", 10.0);
			c->check(c->return_data());
			c->infixToPrefix();
			Assert::AreEqual(c->count(), 0.0);
		}

		TEST_METHOD(UnitTest8)
		{
			c->push_back("sqrt", 0.0);
			c->check(c->return_data());
			c->push_back("4", 4.0);
			c->check(c->return_data());
			c->infixToPrefix();
			Assert::AreEqual(c->count(), 2.0);
		}

		TEST_METHOD(UnitTest9)
		{
			c->push_back("cuber", 0.0);
			c->check(c->return_data());
			c->push_back("27", 27.0);
			c->check(c->return_data());
			c->infixToPrefix();
			Assert::AreEqual(c->count(), 3.0);
		}
	};
}