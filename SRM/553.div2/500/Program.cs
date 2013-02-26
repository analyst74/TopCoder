using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _500
{
    class Program
    {
        static void Main(string[] args)
        {
            Test("T0", new int[]{7,-1,0}, 10, 3);
            Test("T1", new int[] { 100, 200, 300, 0, 100, -1 }, 600, 0);
            Test("T2", new int[] { -1, 7, 3, 0, 1, 2, 0, 0 }, 13, 0);
            Test("T3", new int[] { -1, 8, 4, 0, 1, 2, 0, 0 }, 16, -1);
            Test("T4", new int[] { 1000000000, 1000000000, 1000000000, 1000000000, -1, 0, 0, 0, 0 }, 1000000000, -1);
            Test("T5", new int[] {7, -1, 3, 0}, 3, -1);

            Console.ReadLine();
        }

        static void Test(string testName, int[] p1, int p2, int expected)
        {
            var cal = new Suminator();
            var result = cal.findMissing(p1, p2);
            if (result == expected)
                Console.WriteLine(testName + " passed");
            else
                Console.WriteLine(string.Format("{2} failed, expecting: {0}, actually: {1}", expected, result, testName));
        }
    }
}
