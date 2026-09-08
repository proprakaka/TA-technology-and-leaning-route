/*本篇将用代码文件的方式带领学习C#*/
/*您也可以参考配套的MD文档进行概念性学习*/
/*新人搭建C#环境时通常用的是VS.NET
 建议关闭代码补齐，即copilot补齐，以及CodeLens
 从而获得纯粹的代码学习环境*/


//基本语法结构与Hello World
//C#可以包含以下部分：
/*
命名空间声明
一个Class
Class属性
Class方法
Main方法
语句和表达式
注释
 */
//C#的文件后缀统一是.cs

using System;
//using用于包含System命名空间，一个程序可以有很多个using

namespace HelloWorldApplication
//namsepace声明：一个namsepace应当包含一系列的class
{
    //名称为HelloWorld的class，里面包含了他的方法Main和类的行为Console.WriteLine
    class HelloWorld
    {   
        //Main方法：C#程序的入口
        //static:静态方法，不需要创建类就能直接用
        //string[] args : 这是命令行参数数组，运行程序的时候可以通过命令行传参
        //如果你不加上string[] args，那么就无法向主函数传入参数了
        static void Main(string[] args)
        {
            //Console即控制台，WriteLine就是打印一行的意思，因此这里就不需要换行了
            Console.WriteLine("Hello World");
            //针对VS.NET用户：由于VS.NET编译运行后会立马关闭控制台，这里加一个readyKEY用于等待按键操作防止闪关
            Console.ReadKey();
        }
    }
}


/*
相信看到上面的代码，你并不会很理解C#的结构为什么如此独特，与C/C++/Python甚至Java都不同
为了理解它，首先，你需要知道C#是一门完全面向对象设计的语言，在C#中，对象化的设计理念处处存在：
所有的代码必须属于某个类(class)或结构体(struct)当中，甚至是主函数Main这个一切程序的入口点，
也必须要定义在一个类的内部。
这样，C#就没有全局这个概念了，所有的行为都被封装在一个类型中，这样既便于管理，由能够统一，
甚至可以避免全局下的命名冲突。
在这里，你可以把namspace理解为一个项目总文件夹，在这个文件夹下，不同的类/结构体都是一个小型
文件夹，在这里只装他们自己的东西，有的可以给别人看或者用，有的私密不分享出去，这样结构就非
常清晰了。
当然，你可以不写namespace，直接让所有的东西在外面跑，这个叫做顶级语句Top-Level statements，
这就可以如同一个脚本一样书写代码了。这个后续会讲到
 */