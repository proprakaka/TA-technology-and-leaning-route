//=========================================================
// 第05章 C# 数据类型 —— 引用类型 (Reference Types) 与 sizeof
//=========================================================
//上一节我们看了“值类型”（直接存数据）。
//本节讲 C# 的另外两类类型：“引用类型”和“指针类型”，以及如何用 sizeof 查看类型大小。

using System;

namespace ReferenceTypesTeaching
{
    class Program
    {
        static void Main()
        {
            //-----------------------------------------------------
            // 1. sizeof 运算符：得到某个类型在内存中占用的“字节数”(size)
            //    sizeof 后面小括号里写类型名，例如 sizeof(int)。
            //-----------------------------------------------------
            Console.WriteLine("Size of int: {0}", sizeof(int));    // 4 字节
            Console.WriteLine("Size of bool: {0}", sizeof(bool));  // 1 字节
            Console.WriteLine("Size of double: {0}", sizeof(double)); // 8 字节
            
            //和上一章节讲的一样，连续打印50个字符的-当作分割线
            Console.WriteLine(new string('-', 50));

            //-----------------------------------------------------
            // 2. 引用类型（Reference Types）
            //    引用类型不直接保存数据本身，而是保存一个“引用”(指向内存中数据的地址)。
            //    多个变量可以指向同一块内存，如果内存位置的数据是由一个变量改变的，其他变量会自动反映这种值的变化。
            //    内置的引用类型有：object、dynamic、string。
            //-----------------------------------------------------

            //--- object 类型 ---
            //object 是所有类型的“终极基类”（System.Object 的别名），
            //可以存放“任何类型”的值，但赋值前通常需要类型转换。
            object obj;
            obj = 100;   // 把一个值类型(int)塞进 object —— 这叫“装箱(boxing)”

            //把一个 object 再转回值类型，叫“拆箱(unboxing)”。
            //(int) 是“强制类型转换”，把 obj 转成 int 再用，这就是拆箱。关于类型转换后面章节会详细讲解。
            int num = (int)obj;
            Console.WriteLine("拆箱后 num = {0}", num);

            //--- dynamic 类型 ---
            //dynamic 也能存任意类型的值，但它和 object 的关键区别在于“类型检查的时机”：
            //  object 在“编译时”做类型检查；dynamic 在“运行时”才做类型检查。
            dynamic d = 20;
            d = "现在又变成了字符串";   // dynamic 可以随时换成别的类型
            Console.WriteLine("dynamic 的当前值：{0}", d);

            //--- string 类型 ---
            //string（字符串）是 System.String 的别名，用于存放文本。
            string s1 = "runoob.com";          // 用双引号包裹
            //@ 开头的字符串叫“逐字字符串(verbatim string)”：
            //   反斜杠 \ 会被当作普通字符处理，很适合写文件路径。
            string s2 = @"C:\Windows";          // 等价于 "C:\\Windows"
            string s3 = "C:\\Windows";          // 普通字符串里 \ 是转义符，\\ 才表示一个反斜杠
            Console.WriteLine("{0} | {1} | {2}", s1, s2, s3);

            //@ 字符串中还允许直接换行，换行和缩进空格都会算进字符串长度。
            string s4 = @"第一行
第二行";
            Console.WriteLine("逐字多行字符串：\n{0}", s4);

            Console.ReadKey();
        }
    }
}

/*
补充说明：关于“指针类型 (Pointer Types)”
C# 的指针类型用于存储“另一个类型的内存地址”，与 C/C++ 中的指针功能相同。
声明语法是：在类型名后面加一个 *，例如：
    char* cptr;
    int*  iptr;
不过指针类型只能用在“不安全的代码(unsafe code)”中，属于较高级的内容，
本教程暂不展开，知道有这回事即可。
*/