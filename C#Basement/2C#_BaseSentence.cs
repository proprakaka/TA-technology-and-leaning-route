using System;
//在任何的C#程序中，第一句话都是using System;
/*
using命名空间的概念源自于C++，如果不写这条代码
C#程序也可以写下去，但是要加上命名空间标识
如System.Console.WriteLine
*/

using System;
namespace RectangleApplication
{
    //class用于声明一个类
    class Rectangle
    {
        //成员变量，这两个变量属于Rectangle类
        double length;
        double width;
        //成员函数，这个函数定义了成员变量的大小
        //public：公用函数前缀，在这里协商就可以被非Rectangle类的其他成员调用
        //反之就是private，只能是这个Rectangle类才能调用
        public void Acceptdetails()
        {
            length = 4.5;
            width = 3.5;
        }
        //同理，它作为GetArea返回length * width;
        public double GetArea()
        {
            return length * width;
        }
        //这个函数用于打印最终数据
        public void Display()
        {
            Console.WriteLine("Length: {0}", length);
            Console.WriteLine("Width: {0}", width);
            Console.WriteLine("Area: {0}", GetArea());
        }
    }

    //实例化一个类：ER这个类时一个包含了Main方法和实例化Rectangle类的类
    //有什么用：实例化Rectangle类并调用Rectangle方法
    class ExecuteRectangle
    {
        static void Main(string[] args)
        {
            //这里用Rectangle创建了它这个类型的对象new Rectangle()
            //r是引用变量，指向这个对象
            Rectangle r = new Rectangle();
            //r.Acceptdetails的r就是那个引用变量，这里调用了这个calss的Acceptdetails函数
            r.Acceptdetails(); 
            r.Display();
            Console.ReadLine();
        }
    }
}