#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this
                          // in one cpp file
#include "catch.hpp"
#include "my_vector.h"
#include "ref_pointers.h"
/*
TEST_CASE("Verify Test Configuration", "verification")
{
    REQUIRE(true == true);
}

TEST_CASE("Verify functionreference parameter")
{
    int num{5}, num1{15};
    ref_ptr(num, &num1);
    REQUIRE(num == 100);
    REQUIRE(num1 == 200);
}

TEST_CASE("Verify vector size function")
{
    Vector v{3};
    REQUIRE(v.Size() == 3);
}

TEST_CASE("Test vector copy instance to another Vector variable")
{
    Vector v1(3);
    v1[0] = 5;
    Vector v2{v1};

    // Vector v2{v1};
    REQUIRE(v1.Size() == v2.Size());
    REQUIRE(v1[0] == 5);
    REQUIRE(v2[0] == 5);

    v1[0] = 10;
    REQUIRE(v1[0] == 10);
    REQUIRE(v2[0] == 5);
}

TEST_CASE("Test Vector overwrite existing Vector instance")
{
    Vector v1{3};
    Vector v2{3};
    v2 = v1;
    REQUIRE(v1.Size() == v2.Size());
    v1[0] = 5;
    REQUIRE(v1[0] != v2[0]);
    // v2[0] = 10;
}
*/
// TEST_CASE("Test create vec from value return func")
// {
//     Vector v1{get_vector()};
//     v1[0] = 5;
//     REQUIRE(v1[0] == 5);
// }

TEST_CASE("Test create vec from value return")
{
    Vector<int> v1{3};
    v1 = get_vector();
}

TEST_CASE("Test vector get size")
{
    Vector<int> v1{3};
    REQUIRE(v1.Capacity() == 3);
}

TEST_CASE("Test vector Reserve")
{
    Vector<int> v1{3};
    REQUIRE(v1.Capacity() == 3);
    v1.Reserve(6);
    REQUIRE(v1.Capacity() == 6);
    // REQUIRE(v1.Size())
}

TEST_CASE("Test vector push back function") {
  Vector<int> v;
  v.Push_Back(4);
  v.Push_Back(9);
  v.Push_Back(10);
  REQUIRE(v.Capacity() == 3);
  REQUIRE(v.Size() == 3);

  v.Push_Back(30);
  REQUIRE(v.Size() == 4);
  REQUIRE(v.Capacity() == 6);
}