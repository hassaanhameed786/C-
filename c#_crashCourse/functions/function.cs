using System;

namespace functions
{
    class Functions
    {
        static void Main(string[] args)
        {
            Swap();

            //Console.WriteLine("Hello World!");
        }
        static void Swap()
        {
            int var =0;
            int num1 = 10, num2 = 20;
            Console.WriteLine("before swaping the values of num1 & num2 are : num1 = " + num1 + " & num2 = " + num2);
            
            var = num1;
            
            num1 = num2;
            num2 = var;
            


            Console.WriteLine("after swaping the values of num1 & num2 are :  num1 = " + num1 + " & num2 = " + num2);

        }
    }
}
