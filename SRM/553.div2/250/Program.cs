using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _250
{
    class Program
    {
        static void Main(string[] args)
        {
            //Test(4, 1, 1, 1, "Test1");
            //Test(0,0,0,0, "Test2");
            //Test(60, 10, 10, 20, "Test3");
            //Test(1000, 200, 200, 300, "Test4");
            Test(400000000, 90000000, 80000000, 100000000, "Test5");

            Console.ReadLine();
        }

        static void Test(int p1, int p2, int p3, int expect, string testName)
        {
            var cal = new PlatypusDuckAndBeaver();
            var result = cal.minimumAnimals(p1, p2, p3);
            if (result == expect)
                Console.WriteLine(testName +" passed");
            else
                Console.WriteLine(string.Format("{2} failed, expecting: {0}, actually: {1}", expect, result, testName));
        }
    }
}
