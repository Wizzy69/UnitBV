using System.Text;


const char sub0 = '\x2080';

Dictionary<int, char> Superscript = new Dictionary<int, char>()
{
    {0, '\x2070' }, {1, '\x00B9'}, {2, '\x00B2'}, {3, '\x00B3'},
    {4, '\x2074' },{5, '\x2075' },{6, '\x2076' },{7, '\x2077' },
    {8, '\x2078' },{9, '\x2079' }
};

Console.OutputEncoding = Encoding.Unicode;

int lp, lq, k;
if (args.Length != 3)
{
    Console.WriteLine("Programul se apeleaza doar din terminal !");
    Thread.Sleep(2500);
    return;
}

if (!int.TryParse(args[0], out lp) || !int.TryParse(args[1], out lq) || !int.TryParse(args[2], out k))
{
    Console.WriteLine("Valori incorecte");
    return;
}


int lr = lq;
Console.Write("r = ");
for (int i = 1; i <= lr; ++i)
    Console.Write("a{0}", (char)(sub0 + i));
Console.WriteLine();

int lr_nou = lr * k, c = 0;
while (lr_nou < lp)
{
    lr_nou += lr * k;
    c++;
}

int intreg = lp / lr;
int rest = lp % lr;

var array = intreg.ToString().ToCharArray();
Console.Write("p = r");
foreach (var chr in array)
    Console.Write("{0}", (Superscript[chr - '0']));
for (int i = 1; i <= rest; ++i)
    Console.Write("a{0}", (char)(sub0 + i));
Console.WriteLine();


Console.Write("q = ");
for (int i = rest + 1; i <= lr; ++i)
    Console.Write("a{0}", (char)(sub0 + i));
for (int i = 1; i <= rest; ++i)
    Console.Write("a{0}", (char)(sub0 + i));
Console.WriteLine();


Console.WriteLine("c = " + c);