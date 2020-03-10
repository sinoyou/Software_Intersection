#include "pch.h"
#include "CppUnitTest.h"
#include "../Intersection/AlgorithmRunner.h"
#include "../Intersection/Line.h"
#include "../Intersection/Point.h"
#include "../Intersection/Rational.h"
#include "../Intersection/utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(test)
	{
	public:
		
		TEST_METHOD(TestRationalEqual)
		{
			auto r1 = new Rational(0);
			auto r2 = new Rational(5, 3);
			auto r3 = new Rational(-10, -6);
			auto r4 = new Rational(0, 7);
			auto r5 = new Rational(5);
			auto r6 = new Rational(10, 2);
			Assert::IsTrue(*r1 == *r4);
			Assert::IsTrue(*r2 == *r3);
			Assert::IsTrue(*r5 == *r6);
			Assert::IsFalse(*r1 == *r5);
		}

		TEST_METHOD(TestRationalLess) {
			auto r1 = new Rational(0);
			auto r2 = new Rational(5, 3);
			auto r3 = new Rational(-10, 6);
			auto r4 = new Rational(0, -7);
			auto r6 = new Rational(10, -2);
			Assert::IsTrue(*r1 < *r2);
			Assert::IsTrue(*r4 < *r2);
			Assert::IsTrue(*r6 < *r4);
			Assert::IsTrue(*r3 < *r2);
			Assert::IsFalse(*r2 < *r1);
		}

		TEST_METHOD(TestRationalAdd) {
			auto zero = new Rational(0);
			auto a1 = new Rational(5, 10);
			auto a2 = new Rational(-10, 20);
			auto a3 = new Rational(1);
			Assert::IsTrue(*(Rational::add(a1, a2)) == *zero);
			Assert::IsTrue(*(Rational::add(a1, zero)) == *a1);
			Assert::IsTrue(*(Rational::add(a1, a1)) == *a3);
		}

		TEST_METHOD(TestRationalSub) {
			auto zero = new Rational(0);
			auto a1 = new Rational(5, 10);
			auto a2 = new Rational(-10, 20);
			auto a3 = new Rational(1);
			Assert::IsTrue(*(Rational::sub(a1, a2)) == *a3);
			Assert::IsTrue(*(Rational::sub(a1, zero)) == *a1);
			Assert::IsTrue(*(Rational::sub(a1, a1)) == *zero);
			Assert::IsTrue(*(Rational::sub(zero, a1)) == *a2);
		}

		TEST_METHOD(TestRationalMultiply) {
			auto zero = new Rational(0);
			auto a1 = new Rational(-1, 2);
			auto a2 = new Rational(2, 8);
			auto a3 = new Rational(-2);
			auto a4 = new Rational(1);
			Assert::IsTrue(*(Rational::multiply(zero, a1)) == *zero);
			Assert::IsTrue(*(Rational::multiply(a1, a1)) == *a2);
			Assert::IsTrue(*(Rational::multiply(a4, a4)) == *a4);
			Assert::IsTrue(*(Rational::multiply(a3, a2)) == *a1);
		}

		TEST_METHOD(TestRationalDiv) {
			auto zero = new Rational(0);
			auto a1 = new Rational(-1, 2);
			auto a2 = new Rational(2, 8);
			auto a3 = new Rational(-2);
			auto a4 = new Rational(1);
			Assert::IsTrue(*(Rational::div(zero, a1)) == *zero);
			Assert::IsTrue(*(Rational::div(a1, a2)) == *a3);
			Assert::IsTrue(*(Rational::div(a2, a4)) == *a2);
			Assert::IsTrue(*(Rational::div(a1, a1)) == *a4);

		}
	};
}
