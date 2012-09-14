using System.Collections.Generic;

namespace _556.P1
{
    public class ChocolateBar
    {
        public int maxLength(string letters)
        {
            int result = 0;

            for (int i = 0; i < letters.Length - 1; i++)
            {
                string tempString = letters.Substring(i, 1);
                for (int j = i+1; j < letters.Length; j++)
                {
                    if (tempString.Contains(letters[j].ToString()))
                    {
                        
                        break;
                    }

                    tempString += letters[j];
                }

                if (result < tempString.Length)
                    result = tempString.Length;
            }

            return result;
        }
    }
}
