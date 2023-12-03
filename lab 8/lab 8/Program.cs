using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace lab_8
{
    internal class Program
    {
        public static double G(double x)
        {
            return (2*(x-2));
        }
        public static double Fi(double x)
        {
            return Math.Exp(-(x*x));
        }
        public static double Ro(double x)
        {
            return Math.Exp(x);
        }
        public static double Fx(double x)
        {
            return Fi(x)*Ro(x);
        }
        public static double Fxy(double x, double y)
        {
            return Fx(x) - G(x)*y;
        }
        public static double RungeKutt(double x, double y, double h) //Yk+1
        {
            return y + k1(x,y,h) / 4 + 3 * k3(x,y,h) / 4;
        }
        public static double k1(double x, double y, double h)
        {
            return h * Fxy(x, y);
        }
        public static double k2(double x, double y, double h)
        {
            return h * Fxy(x + h / 3, y + k1(x,y,h) / 3);
        }
        public static double k3(double x, double y, double h)
        {
            return h * Fxy(x+2*h/3, y + 2*k2(x,y,h)/3);
        }
        static void Main(string[] args)
        {
            double h0 = 0.5; //Начальный шаг
            double h;
            double x0 = 1, // Начальная точка
                b = 6, //Конечная точка
                y0 = 10, //Начальный Y
                x, y; 
            double eps = 0.001;
            x = x0;
            y = y0;
            h = h0;
            double y1, h1, h2;
            int counter = 0;

          
           
            Console.WriteLine("---------------------------------------------------------");
            Console.WriteLine("|     x    |    y'(x) с автоматическим выбором шага     |");
            Console.WriteLine("|----------|--------------------------------------------|");
            for (double k = x; k < b; k += h0)
            {
                h1 = h0;
                h2 = h1 / 2;
                for (int i = 0; i < 2;)
                {
                    if (Math.Abs(RungeKutt(x, y, h1) - RungeKutt(x, y, h2)) <= eps) break;
                    y = RungeKutt(x, y, h2);
                    h1 /= 2;
                    h2 /= 2;
                    counter++;
                    Console.WriteLine("|{0, 10}|{1, 44:F3}|", k, y);
                }
               
            }
            h1 = (b - x0) / counter;
            x = x0;
            y = y0;
            h = h0;
            Console.WriteLine("---------------------------------------------------------");
            Console.WriteLine("|     x    |          y'(x) с постоянным шагом          |");
            Console.WriteLine("|----------|--------------------------------------------|");
            for (double k = x; k < b; k += h1)
            {
                y = RungeKutt(x, y, h1);
                Console.WriteLine("|{0, 10:F3}|{1, 44:F3}|", k, y);
            }
        }
    }
}
