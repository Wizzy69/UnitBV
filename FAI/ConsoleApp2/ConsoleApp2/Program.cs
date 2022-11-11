using System.Reflection;

using ConsoleApp2;

if (args.Length != 3)
{
    Console.WriteLine($"Usage: {Assembly.GetExecutingAssembly().FullName}.exe <int> <int> <int>");
    return;
}

var a = int.Parse(args[0]);
var m = int.Parse(args[1]);
var n = int.Parse(args[2]);


if (Functions.CMMDC(a, n) != 1)
{

}



