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
            Test0();
            Test1();
            Test2();
            Test3();
            Test4();
            Test5();
            Test6();

            Test7();

            Test8();

            Console.ReadLine();
        }

        static void Test8()
        {
            var fox = new FoxPaintingBalls();
            Console.WriteLine(fox.theMax(1000000000000000000, 1000000000000000000, 1000000000000000000, 4));
            
        }

        static void Test7()
        {
            var fox = new FoxPaintingBalls();
            Console.WriteLine(fox.theMax(12, 12, 9, 4));
        }

        static void Test0()
        {
            var fox = new FoxPaintingBalls();
            Console.WriteLine(fox.theMax(2, 2, 2, 3));
        }

        static void Test1()
        {
            var fox = new FoxPaintingBalls();
            Console.WriteLine(fox.theMax(1, 2, 3, 3));
        }

        static void Test2()
        {
            var fox = new FoxPaintingBalls();
            Console.WriteLine(fox.theMax(8, 6, 6, 4));
        }

        static void Test3()
        {
            var fox = new FoxPaintingBalls();
            Console.WriteLine(fox.theMax(7, 6, 7, 4));
        }

        static void Test4()
        {
            var fox = new FoxPaintingBalls();
            Console.WriteLine(fox.theMax(100, 100, 100, 4));
        }

        static void Test5()
        {
            var fox = new FoxPaintingBalls();
            Console.WriteLine(fox.theMax(19330428391852493, 48815737582834113, 11451481019198930, 3456));
        }


        static void Test6()
        {
            var fox = new FoxPaintingBalls();
            Console.WriteLine(fox.theMax(1, 1, 1, 1));
        }
    }
}
