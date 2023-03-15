using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace Ch06Ex01
{
    class Program
    {
        //static string myString;
        static void Write()
        {
            WriteLine("Text output from function.");

            //string myString = "String defined in Write()";
            //WriteLine("Now in Write()");
            //WriteLine($"myString = {myString}");

            //WriteLine($"Local myString = {myString}");
            //WriteLine($"Global myString = {Program.myString}");
        }
        static int GetMax(int[] i)
        {
            int max;

            max = i[0];
            foreach(int v in i)
            {
                if (v > max)
                    max = v;
            }
            return max; 
        }
        static void Main(string[] args)
        {
            //string myString = "String defined in Main()";
            //Program.myString = "Global string";

            Write();

            //WriteLine("\nNow in Main()");
            //WriteLine($"myString = {myString}");

            //WriteLine($"Local myString = {myString}");
            //WriteLine($"Global myString = {Program.myString}");

            ReadKey();
        }
    }
}
