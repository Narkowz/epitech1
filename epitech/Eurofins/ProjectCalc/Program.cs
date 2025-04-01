using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.Numerics;
using System.Xml;
using System.Xml.XPath;


class Calculatrice
{

    static int Main()
    {
        Console.WriteLine("Bonjour et bienvenue dans la Calculatrice 2.0 by Attilio.");
        Console.WriteLine("\t\"exit\" pour quitter la calculatrice.");
        calculatorLoop();
        return 0;
    }

    static void calculatorLoop()
    {
        int bol = 1, count = 0;
        float result = 0;
        List<float> num2 = new List<float>();
        List<char?> op = new List<char?>();
        // char? op = null;
        string? calc = null;

        while (calc != "exit")
        {
            calc = getCalcul(calc);
            if (string.IsNullOrEmpty(calc) == true)
                continue;
            if (testOperation(calc, ref count) != 0)
                continue;
            storeNumber(calc, ref result, ref num2, ref op, ref bol);
            Calculator(ref result, num2, op);
            while (num2.Count != 0)
                num2.RemoveAt(0);
            while (op.Count != 0)
                op.RemoveAt(0);
            bol = 1; calc = null; result = 0; count = 0;
        }
    }

    static string getCalcul(string? calc)
    {
        Console.Write("\nEntre ton calcul : ");
        calc = Console.ReadLine();
        if (calc == "exit")
            Environment.Exit(0);
        if (String.IsNullOrEmpty(calc) == true)
        {
            Console.Write("\n");
            return null;
        }
        return calc ?? string.Empty;
    }

    static int testOperation(string calc, ref int count)
    {
        foreach (var c in calc)
        {
            if (c >= '0' & c <= '9')
                count++;
            if ((c >= 0 & c < 32) | (c > 32 & c < 42) | c == 44 | c == 46 | c >= 58)
            {
                Console.WriteLine("N'entrez aucune lettre ou autre charactère qui n'est pas '+-*/'");
                return 1;
            }
        }
        return 0;
    }

    static void storeNumber(string calc, ref float num1, ref List<float> num2, ref List<char?> op, ref int bol)
    {
        float tempNum = 0;
        foreach (var c in calc)
        {
            if (c == ' ')
                continue;
            if (c != ' ' & c != '+' & c != '-' & c != '*' & c != '/' & bol == 1) {
                num1 = num1 * 10 + (c - '0');
                continue;
            }
            if (c == '+' | c == '-' | c == '*' | c == '/') {
                op.Add(c);
                if (bol == 2) {
                    num2.Add(tempNum);
                    tempNum = 0;
                }
                bol = 2;
                continue;
            }
            if (c != ' ' & c != '+' & c != '-' & c != '*' & c != '/' & bol == 2) {
                tempNum = tempNum * 10 + (c - '0');
                continue;
            }
        }
        num2.Add(tempNum);
    }

    static void Calculator(ref float result, List<float> num2, List<char?> op)
    {
        int index = 0;

        foreach (float number in num2)
        {
            if (index == op.Count)
                break;
            switch (Convert.ToInt32(op[index]))
            {
                case '+':
                    result = result + number;
                break;
                case '-':
                    result = result - number;
                break;
                case '*':
                    result = result * number;
                break;
                case '/':
                    result = result / number;
                break;
                default:
                    result = result;
                break;
            }
            index++;
        }
        Console.ForegroundColor = ConsoleColor.Green;
        Console.WriteLine($"{result}");
        Console.ResetColor();
        return;
    }
}