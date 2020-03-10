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

		TEST_METHOD(TestLineUpper)
		{
			auto l1 = new Line(new Point(-1, -1), new Point(1, 1));
			auto l2= new Line(new Point(-1, -1), new Point(-1, 1));
			auto l3 = new Line(new Point(-1, -1), new Point(1, -1));
			auto l4 = new Line(new Point(-1, 1), new Point(1, -1));

			Assert::IsTrue(*(l1->get_upper_point()) == Point(1, 1));
			Assert::IsTrue(*(l2->get_upper_point()) == Point(-1, 1));
			Assert::IsTrue(*(l3->get_upper_point()) == Point(-1, -1));
			Assert::IsTrue(*(l4->get_upper_point()) == Point(-1, 1));
		}

		TEST_METHOD(TestLineInter) {
			auto l1 = new Line(new Point(200, 100), new Point(new Rational(0), new Rational(0)));
			auto l2 = new Line(new Point(-1, 2), new Point(1, 0));
			auto l3 = new Line(new Point(-1, 10), new Point(-1, 1));
			auto l4 = new Line(new Point(0, -2), new Point(10000, -2));
			
			auto inter1 = Line::get_intersection(l1, l2);
			auto inter2 = Line::get_intersection(l1, l3);
			auto inter3 = Line::get_intersection(l1, l4);

			Assert::IsTrue(*inter1 == Point(new Rational(2, 3), new Rational(1, 3)));
			Assert::IsTrue(*inter2 == Point(new Rational(-1), new Rational(2, -4)));
			Assert::IsTrue(*inter3 == Point(-4, -2));
		}
	};
}
