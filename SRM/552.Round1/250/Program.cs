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
            Test0();
            Test2();
            Test3();
            Test4();

            Console.ReadLine();
        }

        static void Test0()
        {
            var flower = new string[] {
                             "F.F",
                             ".F.",
                             ".F."
                         };
            var r = 1;
            var c = 1;

            var shop = new FoxAndFlowerShopDivTwo();
            Console.WriteLine(shop.theMaxFlowers(flower, r, c));
        }

        static void Test2()
        {
            var shop = new FoxAndFlowerShopDivTwo();
            Console.WriteLine(shop.theMaxFlowers(new string[]
                                                     {
                                                         ".FF.F.F",
                                                         "FF...F.",
                                                         "..FF.FF"
                                                     }, 1, 2));
        }

        static void Test3()
        {

            var shop = new FoxAndFlowerShopDivTwo();
            Console.WriteLine(shop.theMaxFlowers(new string[]
                                                     {
                                                         "F",
                                                         ".",
                                                         "F",
                                                         "F",
                                                         "F",
                                                         ".",
                                                         "F",
                                                         "F"
                                                     }, 4, 0));
        }

        static void Test4()
        {
            var shop = new FoxAndFlowerShopDivTwo();
            Console.WriteLine(shop.theMaxFlowers(new string[]
                                                     {
                                                         ".FFF..F...",
                                                         "FFF...FF.F",
                                                         "..F.F.F.FF",
                                                         "FF..F.FFF.",
                                                         "..FFFFF...",
                                                         "F....FF...",
                                                         ".FF.FF..FF",
                                                         "..F.F.FFF.",
                                                         ".FF..F.F.F",
                                                         "F.FFF.FF.F"
                                                     }, 4, 3));
        }
    }
}
