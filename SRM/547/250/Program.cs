using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _250
{
    class Program
    {
        static void Main(string[] args)
        {
            var mt = new MinimalTriangle();
            Console.WriteLine(mt.maximalArea(5));
            Console.WriteLine(mt.maximalArea(10));
            Console.WriteLine(mt.maximalArea(10000));
        }
    }
}
