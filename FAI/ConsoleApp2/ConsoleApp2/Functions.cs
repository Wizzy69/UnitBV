namespace ConsoleApp2
{
    public static class Functions
    {

        public static int CMMDC(int x, int y)
        {
            int r;
            while (y != 0)
            {
                r = x % y;
                x = y;
                y = r;
            }
            return x;
        }

        public static List<int> PrimeFactors(int n)
        {
            List<int> factors = new List<int>();
            int d = 2;
            if (n % d == 0)
            {
                factors.Add(d);

                while (n % d == 0)
                    n /= d;
            }

            d++;
            while (n > 1)
            {
                if (n % d == 0)
                {
                    factors.Add(d);
                    while (n % d == 0)
                        n /= d;
                }
                d += 2;
            }

            return factors;
        }
    }


}
}
