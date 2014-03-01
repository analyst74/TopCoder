using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _250
{
    public class ColorfulChocolates
    {
        Dictionary<string, Tuple<int, int>> hash;
        public ColorfulChocolates()
        {
            hash = new Dictionary<string,Tuple<int,int>>();
        }

        public int maximumSpread(string chocolates, int maxSwap)
        {
            if (hash.ContainsKey(chocolates) && hash[chocolates].Item1 >= maxSwap)
                return hash[chocolates].Item2;


            var maxSpread = calcSpread(chocolates);

            if (maxSwap > 0)
            {
                for (int i = 0; i < chocolates.Length - 1; i++)
                {
                    var sequence = chocolates.ToCharArray();
                    var temp = sequence[i];
                    sequence[i] = sequence[i + 1];
                    sequence[i + 1] = temp;
                    var spread = maximumSpread(new string(sequence), maxSwap - 1);
                    if (spread > maxSpread)
                        maxSpread = spread;
                }
            }

            hash[chocolates] = new Tuple<int, int>(maxSwap, maxSpread);
            return maxSpread;
        }

        public int calcSpread(string chocolates)
        {
            var prev = ' ';
            var counter = 0;
            var max = 0;
            for (int i = 0; i < chocolates.Length; i++)
            {
                if (prev == chocolates[i])
                {
                    counter++;
                    if (max < counter)
                        max = counter;
                }
                else
                {
                    prev = chocolates[i];
                    counter = 0;
                }
            }

            return max+1;
        }
    }
}
