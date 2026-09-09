//=========================================================
// 第08章 C# 常量 (Constants)
//=========================================================
//“常量”与变量相反：一旦定义，它的值在程序运行期间就不能再被修改。

using System;

namespace ConstantsTeaching
{
    class Program
    {
        //-----------------------------------------------------
        // const 常量：用 const 关键字声明。
        // 语法：  const 类型 常量名 = 值;
        // const 是“编译时常量”：声明时必须立刻赋值，之后永远不能改。
        //-----------------------------------------------------
        const double PI = 3.14159;      // 数学里的圆周率，永远不会变
        const string WELCOME = "欢迎学习 C#";

        //-----------------------------------------------------
        // readonly 只读字段：也是“只能赋值一次”，但可以在构造函数里赋值，
        // 因此它的值可以一直到“运行时”才确定。
        //-----------------------------------------------------
        readonly int createdYear;       // 只读字段，稍后在构造函数里赋值

        //构造函数：与类同名、无返回类型的方法，创建对象时自动执行（详见第19章“类”）。
        Program()
        {
            createdYear = 2026;          // readonly 可以在构造函数里赋值
        }

        static void Main()
        {
            Program p = new Program();   // 触发构造函数，给 createdYear 赋值
            Console.WriteLine(WELCOME);
            Console.WriteLine("PI = {0}", PI);
            Console.WriteLine("createdYear = {0}", p.createdYear);

            //PI = 3.0;   // 错误！const 常量不能被重新赋值

            //-----------------------------------------------------
            // 各种“字面常量”的写法（字面常量就是直接写在代码里的固定值）
            //-----------------------------------------------------
            //(1) 整数常量
            int dec = 85;         // 十进制（默认）
            int hex = 0x4b;       // 十六进制，以 0x 开头（0x4b = 75）
            int bin = 0b1010;     // 二进制，以 0b 开头（10）
            int withL = 85L;      // 后缀 L 表示 long 类型
            uint withU = 85U;     // 后缀 U 表示无符号 uint
            Console.WriteLine("整数常量：dec={0}, hex={1}, bin={2}, L={3}, U={4}",
                              dec, hex, bin, withL, withU);

            //(2) 浮点常量
            double f1 = 3.14159;           // 默认双精度
            double f2 = 314159E-5;         // 指数（科学计数法）写法：314159×10⁻⁵
            float f3 = 3.14f;              // 后缀 f 表示单精度 float
            decimal f4 = 3.14m;            // 后缀 m 表示 decimal（精确十进制）
            Console.WriteLine("浮点常量：{0}, {1}, {2}, {3}", f1, f2, f3, f4);

            //(3) 字符常量：用单引号括起来，只能有一个字符
            char letter = 'x';             // 普通字符
            char newline = '\n';           // 转义字符：\n 表示换行
            char tab = '\t';               // \t 表示制表符
            char backslash = '\\';         // \\ 表示一个反斜杠
            Console.WriteLine("字符常量：letter={0}, 反斜杠={1}", letter, backslash);

            //(4) 字符串常量：双引号；@ 开头为“逐字字符串”，反斜杠不必转义
            string s1 = "hello\nworld";     // \n 会被解释成换行
            string s2 = @"hello\nworld";    // 逐字字符串：\n 原样保留
            Console.WriteLine("普通字符串含换行：\n{0}", s1);
            Console.WriteLine("逐字字符串(\\n 不变)：\n{0}", s2);

            Console.ReadKey();
        }
    }
}

/*
【小结】
  · const：编译时常量，声明即赋值、不可修改；
  · readonly：运行时常量，在声明或构造函数中赋值一次；
  · 字面常量有：整数(十/十六/二进制)、浮点(可带 f/m 后缀)、字符(单引号+转义)、字符串(双引号或 @)。
*/