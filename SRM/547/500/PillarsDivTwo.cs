using System;
using System.Collections.Generic;
using System.Text;

    public class PillarsDivTwo
    {
        public double maximalLength(int[] height, int w)
        {
            double result = 0;

            List<KeyValuePair<int, double>> lengths = new List<KeyValuePair<int, double>>();
            lengths.Add(new KeyValuePair<int, double>(1, 0));
            lengths.Add(new KeyValuePair<int, double>(height[0], 0));
            for (int i = 1; i < height.Length; i++)
            {
                List<KeyValuePair<int, double>> prevLengths = lengths;
                lengths = new List<KeyValuePair<int, double>>();
                foreach (KeyValuePair<int, double> prevLength in prevLengths)
                {
                    double l1 = prevLength.Value + CalcLength(prevLength.Key, 1, w);
                    if (l1 > result)
                        result = l1;

                    double l2 = prevLength.Value +  CalcLength(prevLength.Key, height[i], w);
                    if (l2 > result)
                        result = l2;

                    lengths.Add(new KeyValuePair<int, double>(1, l1));
                    lengths.Add(new KeyValuePair<int, double>(height[i], l2));
                }
            }

            return result;
        }

        private double CalcLength(int h1, int h2, int w)
        {
            int a = w;
            int b = Math.Abs(h1 - h2) * w / 2;

            return Math.Sqrt(a * a + b * b);
        }

    }