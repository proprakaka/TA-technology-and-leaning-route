using System;

namespace ValueTypesTeaching
{
    class Program
    {
        static void Main()
        {
            // 表头
            Console.WriteLine($"{"类型",-10} {"说明",-30} {"范围",-50} {"默认值",-15}");
            Console.WriteLine(new string('=', 105));
            // 各类型数据
            Console.WriteLine($"{"bool",-10} {"布尔值",-30} {"True 或 False",-50} {"False",-15}");
            Console.WriteLine($"{"byte",-10} {"8 位无符号整数",-30} {"0 到 255",-50} {"0",-15}");
            Console.WriteLine($"{"char",-10} {"16 位 Unicode 字符",-30} {"U+0000 到 U+ffff",-50} {"'\\0'",-15}");
            Console.WriteLine($"{"decimal",-10} {"128 位精确十进制值",-30} {"(-7.9×10²⁸ 到 7.9×10²⁸)/10⁰~²⁸",-50} {"0.0M",-15}");
            Console.WriteLine($"{"double",-10} {"64 位双精度浮点型",-30} {"±5.0×10⁻³²⁴ 到 ±1.7×10³⁰⁸",-50} {"0.0D",-15}");
            Console.WriteLine($"{"float",-10} {"32 位单精度浮点型",-30} {"-3.4×10³⁸ 到 +3.4×10³⁸",-50} {"0.0F",-15}");
            Console.WriteLine($"{"int",-10} {"32 位有符号整数",-30} {"-2,147,483,648 到 2,147,483,647",-50} {"0",-15}");
            Console.WriteLine($"{"long",-10} {"64 位有符号整数",-30} {"-9,223,372,036,854,775,808 到 9,223,372,036,854,775,807",-50} {"0L",-15}");
            Console.WriteLine($"{"sbyte",-10} {"8 位有符号整数",-30} {"-128 到 127",-50} {"0",-15}");
            Console.WriteLine($"{"short",-10} {"16 位有符号整数",-30} {"-32,768 到 32,767",-50} {"0",-15}");
            Console.WriteLine($"{"uint",-10} {"32 位无符号整数",-30} {"0 到 4,294,967,295",-50} {"0",-15}");
            Console.WriteLine($"{"ulong",-10} {"64 位无符号整数",-30} {"0 到 18,446,744,073,709,551,615",-50} {"0",-15}");
            Console.WriteLine($"{"ushort",-10} {"16 位无符号整数",-30} {"0 到 65,535",-50} {"0",-15}");
            Console.ReadKey();   // 等待用户按键后关闭窗口
        }
    }
}