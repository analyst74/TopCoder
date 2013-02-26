using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _500
{
    public class Suminator
    {
        public int findMissing(int[] program, int wantedResult)
        {
            // if -1 is 0
            Item result = Calc(program.Select(i => i == -1 ? 0 : i).ToArray());
            if (result.Value == wantedResult)
                return 0;
            else
            {
                // if -1 is not 0
                result = Calc(program);
                if (result.XCount > 0)
                {
                    long temp = (wantedResult - result.Value)/result.XCount;
                    if (temp > int.MaxValue || temp <= 0)
                        return -1;
                    else
                        return (int) temp;
                }
                else if (result.Value == wantedResult)
                    return 0;
                else
                    return -1;
            }

        }

        public Item Calc(int[] program)
        {
            var stack = new Stack<Item>();
            for (long i = 0; i < program.Length; i++)
            {
                if (program[i] == 0)
                {
                    Item temp = new Item();
                    if (stack.Any())
                        temp.Add(stack.Pop());
                    if (stack.Any())
                        temp.Add(stack.Pop());

                    stack.Push(temp);
                }
                else if (program[i] == -1)
                {
                    stack.Push(new Item(0, 1));
                }
                else
                    stack.Push(new Item(program[i], 0));
            }

            return stack.Pop();
        }

        public class Item
        {
            public Item()
            {
                this.Value = 0;
                this.XCount = 0;
            }

            public Item(long v, long x)
            {
                this.Value = v;
                this.XCount = x;
            }

            public long Value { get; set; }
            public long XCount { get; set; }

            public void Add(Item right)
            {
                this.Value += right.Value;
                this.XCount += right.XCount;
            }
        }
    }
}
