using System;
using System.Collections.Generic;

namespace _555.div2._255
{
    class XorBoardDivTwo
    {
        internal int theMax(String[] board)
        {
            // key value is in the form of x * 100 + y
            Dictionary<int,int> zeroCounts = new Dictionary<int, int>();

            for (int i = 0; i < board.Length; i++)
            {
                for (int j = 0; j < board[i].Length; j++)
                {
                    if (board[i][j] == '0')
                    {
                        for (int x = 0; x < board.Length; x++)
                            SafeAdd(zeroCounts, x*100 + j, 1);
                        for (int y = 0; y < board[i].Length; y++)
                            SafeAdd(zeroCounts, i * 100 + y, 1);
                    }
                    else
                        SafeAdd(zeroCounts, i * 100 + j, 1);
                }
            }

            int flipped = 0;
            foreach (int value in zeroCounts.Values)
            {
                if (flipped < value)
                    flipped = value;
            }


        }
        
        private void SafeAdd(Dictionary<int, int> dict, int key, int valueToAdd)
        {
            if (dict.ContainsKey(key))
                dict[key] += valueToAdd;
            else
                dict[key] = valueToAdd;
        }
    }
}
