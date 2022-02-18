#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1989;

/*
Input: team = [0,1,0,1,0], dist = 3
Output: 2
*/
tuple<vector<int>, int, int> testFixture1()
{
  return make_tuple<vector<int>, int, int>(
      {0, 1, 0, 1, 0}, 3, 2);
}

/*
Input: team = [1], dist = 1
Output: 0
*/
tuple<vector<int>, int, int> testFixture2()
{
  return make_tuple<vector<int>, int, int>(
      {1}, 1, 0);
}

/*
Input: team = [0], dist = 1
Output: 0
*/
tuple<vector<int>, int, int> testFixture3()
{
  return make_tuple<vector<int>, int, int>(
      {0}, 1, 0);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<2>(f)) << endl;
  auto result = Solution::catchMax(get<0>(f), get<1>(f));
  cout << "result: " << to_string(result) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << to_string(get<2>(f)) << endl;
  auto result = Solution::catchMax(get<0>(f), get<1>(f));
  cout << "result: " << to_string(result) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Test 2 - exepct to see " << to_string(get<2>(f)) << endl;
  auto result = Solution::catchMax(get<0>(f), get<1>(f));
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}