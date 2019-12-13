using System;

namespace Calc
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("------------------------Calculator in C# just add and subtract feacture  ------------------------");
            
            // int num = Convert.ToInt32("221");
            // Console.WriteLine("How we convert string into numbers " + num );

            Console.Write("Enter A Digit  :");
            double num1 =Convert.ToDouble( Console.ReadLine());
            //Console.WriteLine(num1 + 44);

            Console.Write("Enter A 2nd Digit  :");
            double  num2 =Convert.ToDouble( Console.ReadLine());
            Console.WriteLine(num2 + num1);

             Console.WriteLine(num2 - num1);
             Console.WriteLine(num2 / num1);
             Console.WriteLine(num2 * num1);
            
            Console.ReadLine();
            Console.ReadKey();
        
        }

    }
}
