using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.Numerics;
using System.Xml;
using System.Xml.XPath;


string ?calc;
int num = 0, operation = 0, space = 0, bol = 1;
float num1 = 0, num2 = 0, result = 0;
char op = null;

Console.WriteLine("Bonjour et bienvenu dans la Calculatrice 2.0 by Attilio.");
Console.Write("\nEntre ton calcul : ");
calc = Console.ReadLine();
if (calc == "exit")
    System.Environment.Exit(1);
Console.WriteLine($"\nVoici le calcul : {calc}");

#pragma warning disable CS8602
if (String.IsNullOrEmpty(calc) == true | calc.Length < 3)
{
    Console.WriteLine("Entre un calcul valide.");
    System.Environment.Exit(1);
}
#pragma warning restore CS8602
foreach (var c in calc)
{
    if (c >= '0' & c <= '9')
        num++;
    if (c == '+' | c == '-' | c == '*' | c == '/')
        operation++;
    if (c == ' ')
        space++;
    if ((c >= 0 & c < 32) | (c > 32 & c < 42) | c == 44 | c == 46 | c >= 58) {
        Console.WriteLine("N'entrez aucune lettre ou autre charactère qui n'est pas '+-*/'");
        System.Environment.Exit(1);
    }
}
if (operation == 0 | num < 2) {
    Console.WriteLine("Merci de mettre une opération réalisable.");
    System.Environment.Exit(1);
}
Console.WriteLine($"num : {num}, operation : {operation}\n\n");

foreach (var c in calc)
{
    if (c == ' ')
        continue;
    if (c != ' ' & c != '+' & c != '-' & c != '*' & c != '/' & bol == 1) {
        num1 = num1 * 10 + (c - '0');
        continue;
    }
    if (c == '+' | c == '-' | c == '*' | c == '/') {
        op = c;
        bol++;
    }
    if (c != ' ' & c != '+' & c != '-' & c != '*' & c != '/' & bol == 2) {
        num2 = num2 * 10 + (c - '0');
        continue;
    }
}

switch (Convert.ToInt32(op))
{
    case '+':
        result = num1 + num2;
    break;
    case '-':
        result = num1 - num2;
    break;
    case '*':
        result = num1 * num2;
    break;
    case '/':
        result = num1 / num2;
    break;
}
Console.WriteLine($"calcul : {num1} {op} {num2} = {result}");
