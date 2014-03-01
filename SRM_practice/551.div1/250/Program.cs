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
            var cc = new ColorfulChocolates();

            Console.WriteLine("ABCDCBC, 1 = " + cc.maximumSpread("ABCDCBC", 1));
            Console.WriteLine("ABCDCBC, 2 = " + cc.maximumSpread("ABCDCBC", 2));
            Console.WriteLine("ABBABABBA, 3 = " + cc.maximumSpread("ABBABABBA", 3));
            Console.WriteLine("ABBABABBA, 4 = " + cc.maximumSpread("ABBABABBA", 4));
            Console.WriteLine("QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO, 77 = " + cc.maximumSpread("QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO", 77));
            Console.ReadLine();
        }


    }
}
