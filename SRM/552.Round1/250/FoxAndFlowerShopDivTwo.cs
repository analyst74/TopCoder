using System;

namespace _250
{
    public class FoxAndFlowerShopDivTwo
    {
        public int theMaxFlowers(String[] flowers, int r, int c)
        {
            int leftCount = 0;
            int rightCount = 0;
            int topCount = 0;
            int bottomCount = 0;

            for (int i = 0; i < flowers.Length; i++)
            {
                for (int j = 0; j < flowers[i].Length; j++)
                {
                    if (flowers[i][j] == 'F')
                    {
                        if (i < r)
                            topCount++;
                        else if (i > r)
                            bottomCount++;

                        if (j < c)
                            leftCount++;
                        else if (j > c)
                            rightCount++;
                    }
                }
            }

            return Math.Max(Math.Max(leftCount, rightCount), Math.Max(topCount, bottomCount));
        }
    }
}
