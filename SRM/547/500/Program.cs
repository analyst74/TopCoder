using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _500
{
    class Program
    {
        static void Main(string[] args)
        {
            var p = new PillarsDivTwo();
            Program.Test1(p);
        }

        private static void Test1(PillarsDivTwo p)
        {
            var height = new int[] { 3, 3, 3 };
            var w = 2;

            Console.WriteLine(p.maximalLength(height, w));
        }
    }
}
