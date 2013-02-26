using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _250
{
    public class PlatypusDuckAndBeaver
    {
        public int minimumAnimals(int webbedFeet, int duckBills, int beaverTails)
        {
            int ducks = (webbedFeet - 4*beaverTails)/2;
            int beavers = webbedFeet/2 - duckBills - beaverTails;
            int platypus = duckBills + 2*beaverTails - webbedFeet/2;

            return ducks + beavers + platypus;
        }
    }
}
