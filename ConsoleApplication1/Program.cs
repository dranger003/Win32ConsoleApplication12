using System;

using Win32ConsoleApplication12Lib;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                Class1 c1 = new Class1();
                c1.Ping();
            }
            catch (Exception ex)
            {
                while (ex != null)
                {
                    Console.WriteLine("ERROR: {0}", ex.Message);
                    ex = ex.InnerException;
                }
            }
        }
    }
}
