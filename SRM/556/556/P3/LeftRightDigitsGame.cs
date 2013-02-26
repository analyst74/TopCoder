
using System.Collections.Generic;

namespace _556.P3
{
    public class LeftRightDigitsGame
    {
        public string minNumber(string digits)
        {
            string result = digits.Substring(0, 1);
            for (int i = 1; i < digits.Length; i++)
            {
                result = PadDigit(result, digits[i].ToString());
            }

            while (result[0] == '0')
                result = result.Substring(1) + "0";

            return result;
        }

        private string PadDigit(string cur, string newChar)
        {
            int leftModeVal = int.Parse(cur.Substring(0, 1));
            int charVal = int.Parse(newChar);

            if (leftModeVal == 0 || leftModeVal > charVal)
                return newChar + cur;
            else if (leftModeVal < charVal)
                return cur + newChar;
            else
                return cur.Substring(0,1) + PadDigit(cur.Substring(1), newChar);
        }
    }
}
