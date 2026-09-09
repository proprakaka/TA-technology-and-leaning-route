//=========================================================
// 第04章-C#-基本语法
//=========================================================
//本章用一个“矩形 Rectangle”的例子，演示 C# 中最基础的语法要素：
//类(class)、成员变量、成员方法、访问修饰符(public/private)、以及如何实例化对象。

using System;
//using 命名空间的概念源自 C++：
//如果不写这条 using 语句，C# 程序也可以写下去，但每次使用都要写全命名空间标识，
//例如 System.Console.WriteLine(...)。
//写了 using System; 之后，就可以直接简写为 Console.WriteLine(...)。

namespace RectangleApplication
{
    //class 关键字：用于声明一个类（类型）。前面一章节说到，这相当于一个主目录下的子文件夹，这里就是用于存放矩形Rectangle的相关数据
    class Rectangle
    {
        //---- 成员变量（也叫字段 field）----
        //这两个变量“属于” Rectangle 类，我们设计它用来定义矩形的长和宽。
        double length;   //double：双精度浮点数类型（小数），用来存带小数的数值
        double width;    

        //---- 成员方法（也叫成员函数）----
        //public：访问修饰符，表示“公开的”，写上它就能被本类之外的代码调用；
        //反过来 private 表示“私有的”，只能在当前这个类内部调用。
        //void：表示这个方法不返回值，只做事情。
        //这个方法“定义”了成员变量的大小（给长和宽赋值）。
        public void Acceptdetails()
        {
            length = 4.5;
            width = 3.5;
        }

        //同理，GetArea 用来计算并“返回”矩形的面积。
        //double 是它的“返回值类型”，表示这个方法会返回一个 double 类型的数值。
        //return 关键字：把结果返回给调用者，同时结束本方法。
        public double GetArea()
        {
            return length * width;   //“*”是乘法运算符
        }

        //这个方法用于打印最终数据。
        //字符串里的 {0} 是“占位符”，会被后面逗号对应的参数依次替换，此处与C语言占位的理念具有相似性
        //"Length: {0}", length —— 这里调用了上面定义好的length变量，在此处编译后length的值会替换 {0} 占位符，输出打印lenght长，下面的width宽同理
        //GetArea()作为一个方法在此处依然可以写入打印中，计算出的面积会被打印出来。
        public void Display()
        {
            Console.WriteLine("Length: {0}", length);
            Console.WriteLine("Width: {0}", width);
            Console.WriteLine("Area: {0}", GetArea());
        }
    }


    //为了运行程序，再声明一个“包含 Main 方法”的类。
    //它的作用：实例化 Rectangle 类，并调用 Rectangle 的方法。
    class ExecuteRectangle
    {
        static void Main(string[] args)
        {
            //new 关键字：用 Rectangle 这个“类型”创建出一个“对象”。
            //r 是“引用变量”，它指向(引用)这个新建出来的对象。关于引用变量的概念，后续章节会详细讲解。
            Rectangle r = new Rectangle();

            //r.Acceptdetails() 中的 r 就是上面的那个引用变量
            //这里通过" r.方法名() "的方式调用了 Rectangle 类的 Acceptdetails 方法。
            r.Acceptdetails();

            //调用 Display()，打印出长、宽和面积。
            r.Display();

            //ReadLine：读取一行输入（这里用来让控制台停留在屏幕上，等待回车）。
            Console.ReadLine();
            //当然也可以用Console.ReadKey()，它是读取一个按键输入，同样可以是回车。
        }
    }
}