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
		/*
		Point(Rational* x, Rational* y);
		void register_line(Line* l);
		std::list<Line*>* get_lines();
		Rational* get_x() const;
		Rational* get_y() const;

		bool operator==(const Point& p) {
			return this->x == p.x && this->y == p.y;
		}

		int64_t hash() const {
			return x->hash() + y->hash();
		}
		*/
		TEST_METHOD(TestPointEqual)
		{
			auto r1 = new Point(new Rational(0), new Rational(5, 3));
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
	};
}
