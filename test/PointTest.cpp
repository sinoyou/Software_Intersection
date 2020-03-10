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

		TEST_METHOD(TestPointEqual)
		{
			auto r1 = new Rational(0);
			auto r2 = new Rational(5, 3);
			auto r3 = new Rational(-10, -6);
			auto r4 = new Rational(0, 7);
			auto r5 = new Rational(5);
			auto r6 = new Rational(10, 2);

			auto p1 = new Point(r1, r2);
			auto p2 = new Point(r1, r3);
			auto p3 = new Point(r5, r6);
			auto p4 = new Point(r6, r5);

			Assert::IsTrue(*p1 == *p2);
			Assert::IsTrue(*p3 == *p4);
			Assert::IsFalse(*p3 == *p1);
		}

		TEST_METHOD(TestPointGetXY) {
			auto r1 = new Rational(0);
			auto r2 = new Rational(5, 3);
			auto r3 = new Rational(-10, -6);
			auto r4 = new Rational(0, 7);

			auto p1 = new Point(r1, r2);

			Assert::IsTrue(*(p1->get_x()) == *r4);
			Assert::IsTrue(*(p1->get_y()) == *r3);
		}

		TEST_METHOD(TestPointGetLines) {
			auto r1 = new Rational(0);
			auto r2 = new Rational(5, 3);
			auto r3 = new Rational(-10, -6);
			auto r4 = new Rational(0, 7);

			auto p1 = new Point(r1, r2);
			auto p2 = new Point(r3, r4);
			auto p3 = new Point(r1, r4);

			auto l1 = new Line(p1, p2);
			auto l2 = new Line(p3, p1);

			p1->register_line(l1);
			p1->register_line(l2);
			p2->register_line(l1);
			p3->register_line(l2);

			auto lines1 = p1->get_lines();
			Assert::IsTrue(lines1->size() == 2);
			Assert::IsTrue(p2->get_lines()->size() == 1);
			Assert::IsTrue(p3->get_lines()->size() == 1);

		}

		TEST_METHOD(TestPointLessCmp) {
			auto p1 = new Point(new Rational(5), new Rational(5));
			auto p2 = new Point(new Rational(7), new Rational(5));
			auto p3 = new Point(new Rational(-6), new Rational(6));
			auto p4 = new Point(new Rational(10000), new Rational(0));

			auto inters = new std::set<Point*, point_set_cmp>();
			inters->insert(p1);
			inters->insert(p2);
			inters->insert(p3);
			inters->insert(p4);

			int cnt = 0;
			for (auto it = inters->begin(); it != inters->end(); it++) {
				cnt++;
				if (cnt == 1) {
					Assert::IsTrue(*it == p3);
				}
				else if (cnt == 2) {
					Assert::IsTrue(*it == p1);
				}
				else if (cnt == 3) {
					Assert::IsTrue(*it == p2);
				}
				else if (cnt == 4) {
					Assert::IsTrue(*it == p4);
				}
				else {
					Assert::IsTrue(false);
				}
			}

			auto p5 = new Point(new Rational(5), new Rational(5));
			inters->insert(p5);
			Assert::IsTrue(inters->size() == 4);

		}
	};
}
