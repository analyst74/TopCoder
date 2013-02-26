using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _500
{
    public class FoxPaintingBalls
    {
        public long theMax(long r, long g, long b, int n)
        {
            long min = Math.Min(Math.Min(r, g), b);

            if (n == 1)
                return r + g + b;
            else if ((n - 1) % 3 == 0)
            {
                long totalBalls = r + g + b;
                long totalBallsNeeded = calcBallNeed(n);
                long minBallsNeeded = totalBallsNeeded / 3;

                long result = min / minBallsNeeded;


                return Math.Min(result, totalBalls/totalBallsNeeded);
            }
            else
                return min / (calcBallNeed(n)/3);
        }

        private long calcBallNeed(int n)
        {
            long result = 0;
            for (int i = 1; i <= n; i++)
            {
                result += i;
            }

            return result;
        }
    }
}
