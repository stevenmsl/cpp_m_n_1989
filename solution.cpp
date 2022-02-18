#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <string>
#include <queue>
using namespace sol1989;
using namespace std;

/*takeaways
  - find all the "it's" by scanning the team from
    left to right
  - for each "it", we scan its left side first
    and then the right side to see if we can
    find any "not it". Count one if we can find
    a such case.
*/

int Solution::catchMax(vector<int> &team, int dist)
{
  const int n = team.size();
  auto it = 0, nIt = 0;

  while (it < n && team[it] != 1)
    it++;

  auto max = 0;
  while (it < n && nIt < n)
  {
    /*
       - look at the left to see if there is
         anyone "it" can capture potentially
         by skipping those beyond its reach
       - no one else can't reach those candidates
         if this "it" can't reach them as we
         are scanning from left to right
       - note that the team[nIt] might not
         be 0 from the last iteration; we
         will filter this when we look at
         the right side of this "it".
    */
    while (it - nIt > dist)
      nIt++;
    /* look at right if needed */
    auto upper = min(it + dist, n - 1);
    /*
      - if we already found nIt on the left
        this will not be executed as
        team[nIt] will be 0;
    */
    while (nIt <= upper && team[nIt] != 0)
      nIt++;

    if (nIt <= upper)
    {
      nIt++; // next position; team[nIt] might not be 0
      max++; // count one
    }

    /* we are done with this "it". Move to the next position
       and start finding the next "it".
    */
    it++;
    while (it < n && team[it] != 1)
      it++;
  }

  return max;
}