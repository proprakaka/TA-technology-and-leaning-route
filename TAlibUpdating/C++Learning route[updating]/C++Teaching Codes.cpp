/*
DATE : 2026/09/05
VERSION : 1.1
DESCRIPTION : Designed C++ Teaching codes for Learning readers
注：本源代码用于学习与交流，比参考<菜鸟教程>对于C++相关的教学目录进行全文编排
同时也引入编者的个人思路与代码理解，对一些细节问题进行多方查证注释
本篇编写初心是尽可能以一份代码文件通关C++的基础代码编写和语言特色
阅读方式：本文的阅读方式很简单，就是从头读到尾，但是跳过开头有关函数的描述代码，有疑问的地方可以先保留，所有疑惑一定都会解决
如果还有什么疑惑没有在文中解决，读者可以自行查找参考文献，询问AI工具，或者邮件留言:2135504482@qq.com
*/

/*
上面是一个程序文件描述，这是多数情况下的代码编写规范
通常我们需要在代码头部对我们的代码进行注释和基本介绍
用这种方式告知其他程序员代码的基本功能和编写目的以及修改时的注意事项等等源码文件基本信息
*/



//加上这一句的使用，你已经明白了C++中的注释方式，也就是行注释双斜杠//和区域注释/* */，在很多编程语言当中，这种注释方式基本通用且延续，甚至算是行业规范


//正文从下面开始
//C++标准库中的头文件 <iostream> ，扩写全称是：input-output stream [标准]输入输出流
//C++程序至少包含一个头文件，通常是iostream头文件
//但并不一定所有的C++程序源码都是这样
//比如虚幻引擎UE5，在其中创建一个C++脚本，它的代码默认长下面这样
/*
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYPROJECT_API AMyActor : public AActor
{
    GENERATED_BODY()

public:
    // 构造函数：设默认值、建组件
    AMyActor();

protected:
    // 游戏开始/生成时调用一次
    virtual void BeginPlay() override;

public:
    // 每帧调用（默认开启）
    virtual void Tick(float DeltaSeconds) override;
};
*/

//所以不同情况下要求不同，自然头文件也不同，但语法结构和代码风格是相同的
#include<iostream>

//C++固定位小数的表示必须要包含的头文件
#include<iomanip>

//C++的rand和srand函数必须包含的头文件，用于生成随机数
#include<cstdlib>
#include<ctime>

//C++的数学函数头文件，通过它可以调用一部分常见的数学运算
#include<cmath>

//C++的字符串函数头文件，通过它可以调用一部分常见的字符串操作函数
#include<cstring>

//C++的string类头文件，调用它就能使用string类型
#include<string>

//C++的vector容器头文件
#include<vector>

//C++accumulate函数头文件
#include<numeric>

//C++内存管理头文件stack
#include<stack>

//C++队列管理头文件
#include<queue>

//C++哈希表头文件
#include <unordered_map>

//C++映射头文件
#include <map>

//C++双端映射头文件
#include <set>



/*
命名空间
C++中的新型概念，是C++中用于组织代码的一种机制。
它允许将标识符（如变量、函数、类等）分组到不同的命名空间中，以避免命名冲突。
因为C++的函数库体量庞大，不同的库或命名空间中有使用相同名称但功能不同的函数，用命名空间标记就可以将他们区分开来
通过使用命名空间，可以在不同的代码模块中使用相同的标识符而不会产生冲突，从而提高代码的可读性和可维护性。
比如，在我们没使用这条指令时，每次调用std空间下的指令时就必须要加上std::，从而与其他空间区分开来 
*/
using namespace std;

//定义常量-宏定义方式
#define pi 3.14

/*多行注释语法：
第二种写法*/

//全局变量的定义
//NULL 空值，通常用于用于不需要赋值的指针的初始化，但绝不能用于初始化普通变量
int* null_pointer = NULL;
int Global_Variables = 111;

//一般函数的标准形式
int max(int num1 , int num2){
    int result = 100;
    if(num1 > num2){
        result = num1;
    }else {
        result = num2;
    }
    return result;
}
//函数的声明（前置声明）：此处只声明 min 的原型，函数体定义在文件末尾；main 函数结束通常需要用return返回0值表示程序正常结束
int min(int num1 , int num2);

//传参函数 -> 获取当前秒数
void getSeconds(unsigned long *par){
    *par = time(NULL);
    return;
}

//平均数函数
double getAverage(int *arr , int size){
    int i , sum = 0;
    double avg;
    for(int i = 0 ; i < size ; i ++){
        sum += arr[i];
    }
    //浮除法与整除法注意点
    avg = double(sum) / size;
    return avg;
}
/*
在上面的avg后面有一个double(sum)，这个写法是类型转换写法，即将int类型的sum转换成double类型
为什么要这么做呢？
原因在于编程中的除法有两种规定
整数除法与小数除法，也叫整除和浮除
整除法会将结果截断为整数，即便保留小数位数，也依然是小数位都是0
计算机会把整数之间的除法都认为是整除法
消除的方式也很简单，进行小数化或者小数化标记
比如原本是10除以4，整除法的结果是2，我们只需要对10或者4进行小数化
比如10f/10F，或10.0
对于变量就采纳上面的显式类型转换即可
这样就可以进行浮除法得到2.5
如果我们要得到的不是整数精度，而是要精确到小数
则必须要用浮除法，小数与整数之间的除法都会被识别为浮除法，保留到小数对应的位数
*/

//随机数生成函数 用于后面的关于函数返回指针的讲解
int * getRandom(){
    static int r[10];
    srand ( (unsigned) time (NULL));
    for(int i = 0 ; i < 10 ; i++){
        r[i] = rand();
        cout << r[i] << endl;
    }
    return r;
}

//调换函数，用于后面的引用的函数传参功能的讲解
void swep(int& x , int& y){
    int temp = x;
    x = y;
    y = temp;
}

//抽样变值函数 ： 用于后续的引用函数讲解
double values_group[] = {13.3 , 14.2 , 15.2 ,16.3 ,17.9 , 15.8};
double& fiset_values(int i){
    double& ref = values_group[i];
    return ref;
}

//引用静态变量修改函数 ： 后续将引用函数用到
int& getStaticRef(){
    static int num = 5;
    return num;
}

//结构体定义
struct books
{
    char title[50];
    char author[50];
    char subject[100];
    int bookID;
} book;
//代码书写规范注释
/*
未什么我们之前的代码通常是后缀{，最后在换行}
也就是int main{
}
的书写方式
但现在却采纳
{
}
实际上两种都可以采纳，第一种通常在C语言，C++中被大多数人采纳
原因在于我们大部分情况都不会出现特别多花括号堆叠的情况
而struct采用第二种书写方式几乎是编程规范，原因在于它是面向对象编程的重要部分
struct class 等等这些关键字，他们几乎都要用到一个花括号
而且花括号里还能继续花括号
如果我们不采用第二种方式，代码会很乱
所以我们通常在面向对象编程的时候，采用第二种书写方式
例如C#，你让VS2026创建一个新的C#代码，他会默认给你设置好初始函数，而他就是第二种书写
C#也基本上采用第二种书写方式，这也是它的标准代码规范，核心还是为了可读性
*/







//结构体数据打印函数 ： 结构体作为函数参数讲解
void printBook (struct books book ){
    cout << "标题：" << book.title << endl;
    cout << "作者：" << book.author << endl;
    cout << "书目：" << book.subject << endl;
    cout << "书ID：" << book.bookID << endl;
}

//打印信息函数，用于设定指针函数用指针传参从而实现非重载打印输出
void printBookInfo(const books* book){
    cout << "书籍标题: " << book->title << endl;
    cout << "书籍作者: " << book->author << endl;
    cout << "书籍类目: " << book->subject << endl;
    cout << "书籍 ID: " << book->bookID << endl;
}


//构造函数 名与类相同才是构造函数
class Line 
{
    public:
    Line();
    void setLength(double len);
    double getLength() const;

    private:
    double length;
};

Line::Line()
{
    cout << "对象已创建" << endl;
    length = 0.0;
}

void Line::setLength(double len){
    length = len;
}

//const置后写法用于修饰整个函数，承诺函数不会改变任何值，否则会报错
double Line::getLength() const{
    return length;
}

//上述Line类可以简化，我们只需要让构造函数具备传参功能即可
class Line2
{
    public:
    Line2(double len);
    
    private:
    double length;
};

Line2 :: Line2(double len){
    cout << "对象已创建" << endl;
    length = len;
    cout << "线长 ： " << length << endl;
}

//析构函数
class Cube
{
    public:
    Cube();
    ~Cube();
    void setlen(double x , double y , double z);
    double getvolume(void);

    private:
    double wi;
    double le;
    double he;
};

Cube::Cube(){
    cout << "你创建了一个方体" << endl;
}

Cube::~Cube(){
    cout << "该方体已被删除" << endl;
}

void Cube::setlen(double x, double y, double z){
    wi = x;
    le = y;
    he = z;
}

double Cube::getvolume(void){
    double volume = wi * le * he;
    return volume;
}

//拷贝构造函数
class triangle
{
    public: 
    triangle(double hi , double de);
    triangle(const triangle &object);
    ~triangle();
    double getsquare(void){
        double square = h * d * 1/2;
        return square;
    }


    private:
    double h;
    double d;
    double* ptr;

};

triangle::triangle(double hi , double de){
    h = hi;
    d = de;
    cout << "你的三角形对象已创建" << endl;
}

//重点：拷贝结构函数
//&object是一个引用，因此这里是一个函数引用
/*
那么到底什么意思？看下面的一个长难句就会了
拷贝构造函数通常与类相生
并且通常被认为是是一个初始化函数的常用工具
首先区分堆与栈
同为内存，但其运作逻辑不同，容量亦有差别
栈以先进后出的原则进行数据存储，顺序数据压栈与出栈，速度很快，但容量很小
我们定义的变量通常放在栈内
堆则相反，容量大，速度慢，且分散，但优点是可供我们操作，可以申请堆空间进行一些想要的操作
然后再理解实参形参是值拷贝.
实参的值要传给形参，系统会自动创建副本进行复制，这就是拷贝。
你可以理解为形参就是这个副本，因为本质上我们通过引用实现传参
这雨我们的拷贝函数类似
如果我们想要创建一个和已经定义的类的变量内部数值等都相同的同类的变量，就可以用拷贝
拷贝分为显式拷贝和隐式拷贝
它们唯一的区别在于代码写法
显式拷贝
Line line2(line1);
隐式拷贝
Line line2 ＝ line1;
我们只需要选择一个喜欢的写法即可
那么它们的底层运行是什么样的呢
首先我们先看拷贝构造函数如何定义
class Line
{
    public:
    Line(double len);
    ~Line();
    Line(const double &obj){
        ptr ＝ new double;
        *ptr ＝ *obj.length;
    }
    
    private:
    double length;
    doyble* ptr;
};

Line::Line(double len){
    lengtlen＝ len;
    *ptr＝len;
}

Line::~Line(){
    delete ptr;
}

Line line1(1.1);
Line line2(line1);
Line line3 ＝ line1;

上述代码中，我们创建了一个Line类，并定义了三个Line类变量line1，line2，line3
我们给line2和line3都拷贝了line1
在这个过程中，我们的隐式拷贝和显式拷贝被系统识别，触发运作拷贝构造函数
Line(const double &obj)
这个函数与别的函数的不同之处在于
我们为了安全性规定使用const避免拷贝变值
我们为了正常运作采纳引用变量obj
我们可以看到我们的这个Line类与先前学过的都不同
它多了一个double指针ptr
多了一个obj.length的写发
在这个过程中到底发生了什么？
首先，在编译器处理到拷贝式的时候，它会确认一件事
当前类是否有已定义的拷贝构造函数？
如果有，他就会按照定义好的拷贝构造函数进行
如果没有，他就会自动生成一个拷贝构造函数
这两者有什么区别？我们最后讲述。
接着，我们开始调用拷贝构造函数
拷贝构造函数与先前学习的构造函数有相似之处，但差距在于拷贝构造函数内部采纳了引用。
接上，我们要使用拷贝构造函数前，
系统会创建一个引用副本，这个副本被赋值为实参，也就是我们的line1
相当于这个形参obj引用引用了line1，在这种情况下，obj在拷贝构造函数里就成了line1的别名
因此obj.length本质上会被编译成line1.length
那么大概我们也可以猜到了
这个line1.length被赋值给了我们新创建的变量
但，这个值是怎么被赋给它的？
没错就是靠指针。
我们在Line的private里还定义了一个ptr指针
我们以line2初始化为line1为例
在当前调用的拷贝构造函数里
，我们函数中的的ptr实际上就是line2的ptr，而非line1的
原因说专业点就是这里的line2是左值，而line1是右值，所以等号左侧代表的是line2而非line1。
那么通俗的来说，就是我们当前调用的拷贝构造函数是line2的，
其中直接调用的变量都从line2的类中取，只有line1是传入参数在等号右侧用于给左侧line2的变量赋值。
好，接下来我们就可以理解这个拷贝构造函数里的最后一个等式。
*ptr＝*obj.length;
ptr的new我们之前讲过，是为ptr开了一个新的堆空间，我们也可以认为这是一个临时空间
为什么，这里的解引用，对一个指针来讲就是取它的地址下的值，这个解释同样对obj.length一样，
因为这里的obj是引用，解引用就是取值。
他们分别取了line2的length和line1的length
这里值＝值
就成功把line1的长度值给到line2，实现拷贝
我们放到整个函数流程上看，在构造函数里我们让ptr指向当前类的length，
然后在析构函数里我们用delete把new出来的ptr内存空间给释放了
所以就这样，拷贝构造函数实现

Q1:为什么拷贝构造必须是引用传值？
我们刚才讲过，一个函数被调用的时候，系统会创建副本，并把实参赋给副本以作形参
这就是一个直接赋值的型式，这里的副本其实就是函数初始化的传参变量
比如 void func(int a , int b);
这个函数的副本就是a，b变量
回到拷贝构造函数上来，我们同样适用
如果是常规变量传参
比如Line(const Line li){
    length = l1.length;
}
如果我们要传参就涉及到line1与line2的直接赋值
我们都理解，拷贝调用函数会在同类变量初赋值的条件下运作
因此，这里也会调用一次拷贝构造函数
这就会导致如果要调用拷贝构造函数，成功调用得再调用拷贝构造函数
陷入死循环
因此不能这么做
换做引用
我们的obj引用相当于直接指向了line1，属于line1的别名
我们通过line1.length赋值给ptr开辟的新空间中，然后再间接传给line2.length
实现我们的拷贝过程
*/


triangle::triangle(const triangle &object){
    //new用于开辟堆空间，把地址赋予给ptr
    ptr = new double;
    //
    *ptr = *object.ptr;
    cout <<"已调用拷贝并为ptr分配内存" << endl;
}

triangle::~triangle(){
    cout << "内存已释放" << endl;
    delete ptr;
}













//主函数main -> 程序入口 ， 这里是你真正接触主代码的第一步
//在此之前，我们需要将一些基础的内容便于你理解
/*
#include<iostream>

int main(){
    std::cout << "Hello World !" << std::endl;
    int age;
    std::cin >> age ;
    cout << "age : " << endl;
    return 0;
}


上面一般都是你的第一个代码的主函数部分，打印helloworld，但我加了一点基础内容，如打印age
我们一个一个解释
main : 这是主函数标志，他是程序的入口，所有指令都从主函数开始一条条顺序执行，而对于主函数前面的内容，编译器会编译识别与后续替换！后面讲到。
std::  ： 这是标准输入输出流的命名空间符号，所有未使用using namespace std;的C++代码，都应当在标准输入输出函数之前加上std::
由于本文件已经使用using namespace std;命令，所以后面的代码都没有std::的标记
对此，你可以向上翻找这条代码阅读命名空间的概念，然后回来继续学习
cout ：这是标准输出函数，也是<iostream>头文件中的标准函数，C++中需要使用这条函数对数据进行打印处理
cin : 这是标准输入函数，也是<iostream>头文件中的标准函数，C++中需要使用这条函数进行数据的输入处理
为了保证全片代码编译运行结果的连贯性，cin用法基本就这一条，因此本文在此之后不再使用cin相关的会使程序挂载的指令
endl : 这是C++中的换行代码
在C语言中，你也许经常用\n换行，C++同样支持，但是\n本身是转义符号，所以需要按照字符串输出的方式书写，即用"\n"替换endl，后面会讲到转义符
<< 与 >> ：这是标准输入输出方向的指示符，对他的理解你可以认为是数据传导的方向或者数据的先后顺序
例如cout所在代码,endl换行传到到Hello World !这句话的后面，他们拼接成 Hello World ! endl 然后再传出给cout，cout负责输出打印，就会显示 Hello World ! 然后换一行
又如cin 所在代码,你输入的数据通过cin传递给age，那么我们最后打印age，就是你输入的那个数字
return 0 ;
return是返回的意思，是C++函数的一个概念，后面会细讲函数，这里的return返回的是0，这是几乎所有C/C++/C#代码的规范，用return 0 返回的0值表明代码成功运行

有基础的同学在这里可以看一下我下面的这句话：
并非所有代码的主函数都必须返回0，它可以返回任何数
因为main函数也是函数，它同样具有函数的特性，它可以被别人调用，甚至也可以调用自己
但是为什么大部分教材的基础教学中都让main函数返回0？
这是因为，在早期很多的教材和教学当中，我们都以 renturn 0 表示主函数正常运行
可实际上，我们的return可以返回任何我们想要的数值，但唯一的前提就是类型匹配对应
比如我们定义的是int main，这里的main是int类型，retrun就必须返回整数类型
我们甚至可以用int main(void) 不接受命令行参数[即不在命令行输入数据，所以cin肯定就读取不到了，就不能正常用了], void main 不返回任何数
*/
int main(){
    
    //C++常见的预处理宏
    cout << "编译运行日期__DATE__:" << __DATE__ << endl;                             
    cout << "编译运行时间__TIME__:" << __TIME__ << endl;
    cout << "编译运行文件__FILE__:" << __FILE__ << endl;
    cout << "当前所在行  __LINE__:" << __LINE__ << "\n\n";
    
    //C++的基本数据类型
    int type_int = 1;
    float type_float = 0.1F;
    double type_double = pi;
    char type_char = 'c';
    bool type_bool = true;
    wchar_t type_wchart = L'C';
    auto type_auto = type_int;
    
    //C++的类型修饰符
    signed type_signed_int = -1;
    unsigned type_unsigned_int = 1;
    short type_short_int_max = 32767;
    short type_short_int_min = -32768; 
    long type_long_int_max = 2147483647;
    long type_long_int_min = -2147483648;
    long long type_LL_int_max = 9223372036854775807;
    long long type_LL_int_min = -92233720368547758;
    const int type_const_int = 123;
   
    //输出语法相关
    cout << "Hello World but changed by endl"<< endl;
    cout << "Hello World but chaned by \\n \n";
    cout << "This is a long \
string used \'\\\' in the sentence\n";
    cout << "First<<" << " " << "Second<<" << endl;
    cout << "type_int = " << type_int << endl;
    cout << "type_float = " << type_float << endl;
    
    //C++的小数显示模式会自动省略小数末尾的0，但这里需要固定位数显示
    //fixed和setprecision来自iomanip：fixed用于固定显示位数，setprecision用于设置显示的位数
    //如果不需要固定位数，就不需要使用fixed
    cout << "type_double = " << fixed <<setprecision(10) << type_double << endl;
    cout << "type_char = " << type_char << endl;
    
    //boolalpha是iostream中的一个标准控制符，用来把bool类型的变量值转换成字符串形式输出
    cout << "type_bool = " << boolalpha << type_bool << endl;
    
    //用一个static_cast强制转换，把wchar_t类型的数值转换成整数形式输出
    cout << "type_wchart (as int) = " << static_cast<int>(type_wchart) << endl;
   
    cout << "type_signed_int = " << type_signed_int << endl;
    cout << "type_unsigned_int = " << type_unsigned_int << endl;
    cout << "type_short_int_max = " << type_short_int_max << endl;
    cout << "type_short_int_min = " << type_short_int_min << endl;
    cout << "type_long_int_max = " << type_long_int_max << endl;
    cout << "type_long_int_min = " << type_long_int_min << endl;
    cout << "type_LL_int_max = " << type_LL_int_max << endl;
    cout << "type_LL_int_min = " << type_LL_int_min << endl;
    cout << "type_const_int = " << type_const_int << endl;
   
    //sizeof的一个应用，获取不同数据类型的大小
    cout << "char : " << sizeof(char) << "字节" << endl;
    cout << "int : " << sizeof(int) << "字节" << endl;
    cout << "unsigned short :" << sizeof(unsigned short) << "字节" << endl;
    cout << "wchar_t :" << sizeof(wchar_t) << "字节" << endl;
   
    //typedef的应用
    typedef int zheng;
    zheng type_int_zheng = 123;
   
    //简单的enum枚举的使用
    enum color {red , green = 100 , blue} color_red , color_green , color_blue;
    color mycolor = red;
    cout << "mycolor="<< mycolor << endl;
    cout << "color_red=" << color_red << endl;
    cout << "color_green=" << color_green << endl;
    cout << "color_blue=" << color_blue << endl;
    
    
    /*接下来是类型转换，只展示当前数学知识水平*/
    //1.静态转换
    int turn_int =  10;
    float float_int =  static_cast<float>(turn_int);
    cout << "Aimturn number is "<< turn_int <<endl;
    cout << "Turned number is " << fixed <<setprecision(2) << float_int <<endl;
    //2.常量转换
    const int const_switch_num = 10;
    int& r_const_switch_num = const_cast<int&>(const_switch_num);
    cout << "Unswitched const number : " << const_switch_num << endl;
    cout << "Switched const number [to int and +1] : " << const_switch_num +1 << endl;
    //3.重新解释转换
    int unreinterpret_num = 10;
    float reinterpret_num_F = reinterpret_cast<float&>(unreinterpret_num);
    cout << "unredefined number : " << unreinterpret_num << endl;
    cout << "redefined number (to float) : " << fixed << setprecision(2) << reinterpret_num_F << endl; 
    cout << "说明: 不同于static_cast的常规转换，重新解释转换是用float格式读取int存储的10，实际读取的内容是0x0000000A，也就是0"<< "\n\n";
    
    
    /*接下来是常用的程序结构-选择结构篇*/
    //1.if语句
    cout << "\nif语句的结果" <<endl;
    srand(time(0));
    int if_sentence_num1 = rand();
    int if_sentence_num2 = rand();
    if(1){
        cout << "第一个数"<< if_sentence_num1 <<"和第二个数" << if_sentence_num2 <<endl;
    }
    //2.if-else语句
    cout <<"\nif-else语句的结果"<<endl;
    if(if_sentence_num1 > 10000){
        cout << "第一个数" << if_sentence_num1 <<"大于10000" << endl;
    }else{
        cout << "第一个数" << if_sentence_num1 <<"小于或等于10000" << endl;
    }
    //3.else if语句
    cout <<"\nelse if语句的结果"<<endl;
    if(if_sentence_num1 > if_sentence_num2){
        cout << "第一个数"<< if_sentence_num1 <<"大于第二个数" << if_sentence_num2 <<endl;
    }else if (if_sentence_num1 < 10000) {
        cout << "第一个数"<< if_sentence_num1 <<"小于10000，那么一定小于第二个数"<<if_sentence_num2<<endl;
    }else{
        cout << "第一个数"<< if_sentence_num1 <<"不大于第一个却小于第二个数"<<if_sentence_num2<<endl;
    }
    //4.if的嵌套
    cout <<"\nif嵌套的结果"<<endl;
    if(if_sentence_num1 > if_sentence_num2){
        if(if_sentence_num1 > 10000 || if_sentence_num2 < 10000){
            cout<<"第一个数"<<if_sentence_num1<<"大于一万，第二个数"<<if_sentence_num2<<"小于一万"<<endl;
        }
        cout<<"第一个数"<<if_sentence_num1<<"大于第二个数"<<if_sentence_num2<<endl;
    }else if (if_sentence_num1 = if_sentence_num2){
        cout<<"相等，等于"<<if_sentence_num1<<endl;
    }else{
        cout<<"第一个"<<if_sentence_num1<<"小于第二个数"<<if_sentence_num2<<endl;
    }
    //5.switch语句
    cout <<"\nswitch语句的结果"<<endl;
    int switch_day = rand()%10;
    switch(switch_day){
        case 1 :
            cout<<"Monday"<<endl;
            break;
        case 2 :
            cout<<"Tuesday"<<endl;
            break;
        case 3 :
            cout<<"Wednesday"<<endl;
            break;
        case 4 :
            cout<<"Thursday"<<endl;
            break;
        case 5 :
            cout<<"Friday"<<endl;
            break;
        case 6 :
            cout<<"Saturday"<<endl;
            break;
        case 7 :
            cout<<"Sunday"<<endl;
            break;
        default :
            cout<<switch_day<<" is invalid day"<<endl;
    }
    //6.switch嵌套
    cout<<"\nswitch嵌套结果"<<endl;
    int switch_fixed_num1 = 100;
    int switch_fixed_num2 = 200;
    switch(switch_fixed_num1){
        case 100 :
            cout<<"This is outside of 2Switch"<<endl;
            switch(switch_fixed_num2){
                case 200 :
                    cout<<"This is inner of 2Switch"<<endl;
                    break;
            }
        break;
    }
    //7.三目运算
    cout<<"\n三目运算的结果"<<endl;
    int switch_fixed_num3 = if_sentence_num1 > if_sentence_num2 ? if_sentence_num1 : if_sentence_num2;
    cout<<"三目运算比较第一个数和第二个数，较大的为:"<<switch_fixed_num3<<endl;
    
    
    /*接下来是常用的程序结构-循环结构篇*/
    //1.while循环 
    cout<<"\nwhile循环的输出结果"<<endl;
    cout<<"打印二十个Hello World"<<endl;
    int while_count = 1;
    while(while_count <= 20){
        cout<<"第"<<while_count<<"个"<<"Hello World"<<endl;
        while_count ++;
    }
    //2.for循环
    cout<<"\nfor循环的输出结果"<<endl;
    cout<<"倒数10个数"<<endl;
    for(int i = 0 ; i < 10 ; i++){
        cout<<10-i<<endl;
    }
    //3.do while循环
    cout<<"\ndo while循环的输出结果"<<endl;
    cout<<"打印10个数"<<endl;
    int dowhile_count = 1;
    do{
        cout<<dowhile_count<<endl;
        dowhile_count ++;
    }while(dowhile_count <= 10);
    //4.嵌套循环
    cout<<"\n嵌套循环的输出结果"<<endl;
    cout<<"\n用嵌套循环筛选一百以内的素数"<<endl;
    int i,j;
    for(i = 2; i < 100 ; i++){
        for(j = 2 ; j <= i/j ; j++){
            if(!(i%j)){
                break;
            }
        }
        if(j>(i/j)){
            cout << i << "是素数\n";
        }
    }
    //5.continue语句
    cout<<"\ncontinue与break的唯一区别：continue会重新开始当前循环而不会终止"<<endl;
    
    /*接下来是C++的函数*/
    cout<< "\nC++一般函数形式-比较两个数的大小" << endl;
    //在C/C++中函数内部不能再定义另一个函数（函数的嵌套定义是非标准的），所以必须定义在main函数之外
    int Compare_num1 = rand();
    int Compare_num2 = rand();
    cout<< "两个数的比较结果:"<< max(Compare_num1,Compare_num2)<<endl;
    cout<< "两个数的比较结果:"<< min(Compare_num1,Compare_num2)<<"\n\n";

    //函数的运行流程与生命周期
    /*
    一个函数在运行结束后，其内部定义的变量，作用域，结果等都会在return传导到外部后销毁
    这是函数的生命周期，对于void没有return，就会直接运行结束后销毁
    函数有return最重要的原因是因为它的编译性质
    在函数被定义后，运行代码编译器就会识别函数并对调用进行替换
    替换的就是return后面的东西
    例如max和min，他们return的值都是result
    那么这个result在函数运行结束后就会替换掉max(X,Y)
    这就是编译的预处理行为高明的地方，编译后的文件会明显直接且简洁许多，因为他是结果导向
    */
    
    cout << "\n----------------------C++常用数学元素----------------------"<<endl;  
    /*C++常用的数学函数*/
    cout << "\n使用<cmath>库的数学函数"<<endl;
    double math_num1 = 14.3;
    double math_num2 = 11.1;
    cout << "num1 = " << math_num1 <<endl;
    cout << "num2 = " << math_num2 <<endl;
    cout << "sinx = " << sin(math_num1) <<endl;
    cout << "cosx = " << cos(math_num1) <<endl;
    cout << "tanx = " << tan(math_num1) <<endl;
    cout << "lnx = " << log(math_num1) <<endl;
    cout << "powx(2) = " << pow(math_num1,2) <<endl;
    cout << "hypot(x,y) = " << hypot(math_num1,math_num2) <<endl;
    cout << "sqrt(x) = " << sqrt(math_num1) <<endl;
    cout << "fabs(|x|) = " << fabs(math_num1) <<endl;
    cout << "floor([x]) = " << floor(math_num1) <<"\n\n";

    cout << "\n----------------------C++数组----------------------"<<endl;  
    /*C++数组*/
    cout << "\n一维数组以及其应用" << endl;
    int numbers_height[] = {170 , 180 , 173 , 168 , 169 , 183 , 170};
    int numbers_weight[7] = {70 , 69 , 68 , 59 , 60 ,61 ,64};
    int ZhangSan_height = numbers_height[5];
    int LiSi_weight = numbers_weight[3];
    cout << "张三的身高是：" << ZhangSan_height << endl;
    cout << "李四的体重是：" << LiSi_weight << endl;
    
    cout << "\n二维数组以及其应用" << endl;
    int seat_index[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    for(int i = 0; i < 3 ; i++){
        for(int j = 0; j < 4 ; j++){
            cout << "座位" << seat_index[i][j] << " ";
        }
        cout<< "\n";
    }
    
    /*C风格字符串*/
    cout << "\n----------------------C风格字符串相关操作----------------------"<<endl;
    cout << "C风格的字符串源自 C 语言，但在 C++ 中依旧得到了支持。\n\
字符串实际上是使用 null 字符以及\\0\
来终止的一维字符数组。\n\
因此，一个以 null 结尾的字符串包含了组成字符串的字符\n\n";
//为什么这里不打缩进了？原因就在于，这里打的缩进会被认为是空格并被打印出来
    //对此我们通常采取下面的做法：字符串拼接
    
    cout << "C风格的字符串源自 C 语言，但在 C++ 中依旧得到了支持。\n"
        "字符串实际上是使用 null 字符以及\\0"
        "来终止的一维字符数组。\n"
        "因此，一个以 null 结尾的字符串包含了组成字符串的字符\n\n" << endl;

    //这里写16的原因在于为了预留充足的空间，防止拼接的时候数据溢出
    char single_site[16] = {'C','A','I','\0'};
    char string_site[] = {"'STUDY"};
    cout << "C++会自动在字符串末尾加上 null 字符，即\\0字符" << endl;
    cout << single_site << endl;
    cout << string_site << "\n";
    
    char str_temp[10] = {0};
    strcpy(str_temp,single_site);
    cout << "strcpy(s2->s1): " << str_temp << endl;
    cout << "strcat(s1+s2) : " << strcat(single_site,string_site) << endl;
    int str_len = strlen(single_site);
    cout << "strlen(s1) : " << str_len << endl;
    
    
    /*C++string类字符串*/
    cout << "\n----------------------C++字符串相关操作----------------------"<<endl;   
    string string_str1 = "CAI'";
    string string_str2 = "STUDY";
    
    string string_temp = string_str1;
    cout << "str3 = str1 --> str3 : " << string_temp << endl;
    
    string_temp = string_str1 + string_str2;
    cout << "str3 = str1 + str3 --> str3 : " << string_temp << endl;
    
    str_len = string_temp.size(); 
    cout << "str3.size(s1+s2) ---> str3 : " << str_len << endl;
    
    
    cout << "\n----------------------C++指针----------------------"<<endl;  
    cout << "变量地址的打印" << endl;
    int var_act1;
    char var_act2[10];
    cout << "int act1的变量地址: " << &var_act1 << endl;
    cout << "char[10] act2的变量地址: " << &var_act2 << endl;
    
    //C++中指针的基本使用
    int* int_pointer;
    int Ptest = 1;
    int_pointer = &Ptest;
    //指针的类型代表了它指向地址所存储数据的类型
    /*
    上面用到int* 写法，也就是*紧靠类型名的写法
    市面上大部分教程和教材用到的是int *写法，即*紧靠变量名的写法
    但实际上来说，其实用第一种写法是最好理解的写法：
    表明这是一个指针的变量，而非变量是指针
    其实你用哪种写都无所谓，关键是理解指针的本质
    */
    
    //直接访问地址的方式对Ptest操作
    *int_pointer = 10;
    cout << "Ptest : " << Ptest << endl;
    
    //NULL指针/空指针
    //在定义了一个指针之后，如果我们没有什么可以指向的，就初始化成NULL【规范编程】
    //在后面需要的时候就调用它就好了
    int* NUll_Pointer = NULL;
    cout << "NULL指针的值 : " << endl;
    /*
    在绝大部分操作系统上
    我们不允许访问任何指针为0的地址，因为这是一个系统保留的位置 
    内存地址0具有重要意义，它代表着我们的指针不指向任何的内存位置
    按照惯例，空指针不指向任何一个内存位置
    */
    
    //空指针检查
    if(int_pointer){
        cout << "这个指针是非空指针" << endl;
    }
    if(!NUll_Pointer){
        cout << "这个指针是空指针" << endl;
    }
    
    //指针的算术运算
    /*
    你可以对一个指针进行四种算术运算：
    ++  --  +  -
    */
    int Pointer_arr[5] = {1,2,3,4,5}; 
    int* Math_Pointer = Pointer_arr;
    //自增
    Math_Pointer ++;
    cout << "自增后指向 ： " << *Math_Pointer << endl;
    //自减
    Math_Pointer --;
    cout << "再自减后指向：" << *Math_Pointer << endl;
    //加减1与上面一至的效果
    
    //指针的比较
    /*
    在C语言和C++中，我们可以通过==和!=来判断这些指针是否指向同一个位置
    */
    int* Pointer_1 = Pointer_arr;
    int* Pointer_2 = Pointer_arr + 5;
    if(Pointer_1 != Pointer_2){
        cout << "指针未对齐" << endl;
    }else{
        cout << "两指针对齐" << endl; 
    }
    /*
    在C语言和C++中，我们可以通过>和<或>=,<=来判断两指针的相对位置前后
    */
    if(Pointer_1 > Pointer_2){
        cout << "指针1在指针2后面" << endl;
    }else if(Pointer_1 == Pointer_2){
        cout << "指针对齐" << endl;
    }else{
        cout << "指针2在指针1后面" << endl;
    }
    //注意：在进行指针操作时，请确保指针不会为空，否则会出现未定义行为
    
    
    //指针与数组
    /*
    展示程序：打印数组中的元素+它的对应地址
    */
    int* Arr_P = NULL;
    int  arr_print[10] = {1,2,3,4,5,6,7,8,9,10};
    Arr_P = arr_print;
    for(int i = 0 ; i < 10 ; i++){
        cout << *Arr_P + i << " ";
    } 
    cout << endl;
    /*
    展示程序，赋值指针数组并打印
    */
    int* Arr_P_2[10];
    for(int i = 0 ; i < 10 ; i ++ ){
        Arr_P_2[i] = &arr_print[i];
    }
    for(int i = 0 ; i < 10 ; i++){
        cout << *Arr_P_2[i] << " ";
    }
    cout << endl;
    
    const char *names[3] = {"Zhangsan" , "LiSi" , "WangWu"};
    for (int i = 0 ; i < 3 ; i++) {
        cout << "Names of Classmetes [" << i <<"]" ;
        cout << names[i] << endl;
    }

    //指向指针的指针 -> 多级间接寻址
    /*
    指向指针的指针是一种多级间接寻址的形式，或者说是一个指针链。
    指针的指针就是将指针的地址存放在另一个指针里面。
    假设现在有两个指针 1 和 2
    指针1 指向 指针2 ，而 指针2 指向实际值位置Value
    在这个模型里，指针1 包含了 指针2 的地址，指针2包含了Value的地址，形成间接首尾相连的寻址链路
    */
    //定义指针的指针
    int* *Pptr;
    //这就是指针化指针：将本来的指针定义为可以指向指针的指针
    //我们也可以用**连拼的方式定义 : int **Var_1 或者  int** Var_1
    int* Ptr;
    int var = 1000;
    Ptr = &var;
    Pptr = &Ptr;
    cout << "Var : " << var << endl;
    cout << "ptr : " << *Ptr << endl;
    cout << "pptr : " << *Pptr << endl;
    //最后的结果表明指向指针的指针本质上间接指向了最终目标，解一次引用就可以得到目标

    //传参指针 -> 传参指针能直接跨域修改函数
    /*
    我们已经在文件头部定义了一个传参函数，用来获取当前秒数
    */
    unsigned long Seconds_P;
    getSeconds( &Seconds_P ) ;
    cout << "Number of Seconds : " << Seconds_P << endl;
    /*
    上述函数能够接受函数当中的指针数值并将其修改，这就是参数传递的过程
    */
    //下面则是数组作为参数进行数值传递
    int balance[5] = {1000 , 2 , 3 , 17 , 50};
    double average;
    average = getAverage(balance , 5);
    cout << "Average is : " << average << endl;


    //从函数返回指针
    /*
    上面我们已经学习了如何通过函数对变量以及数组的结果进行传递改变
    现在，我们可以通过类似的方法，从函数返回指针
    你可能会有点乱，不太理解这两边到底什么意思
    从指针传递函数和函数返回指针，到底什么意思？
    我们将在演示代码之后进行讲述
    */
    int* fucback_P;
    fucback_P = getRandom();
    for(int i = 0 ; i < 10 ; i++){
        cout << "( P + " << i << " )" << " =  ";
        cout << *( fucback_P + i ) << endl;
    }
    /*
    现在对代码进行细致讲解
    前面的的函数代码贴在这里：
    int * getRandom(){
    static int r[10];
    srand ( (unsigned) time (NULL));
    for(int i = 0 ; i < 10 ; i++){
        r[i] = rand();
        cout << r[i] << endl;
    }
    return r;
    }
    对这个函数，我们发现他是一个指针函数，也就是说，我们的返回值类型是一个指针。
    那么你又要问了，什么是函数指针？
    函数指针是指向函数的指针变量，它可以存储函数的地址，从而允许通过指针来调用函数。
    那么在之前，我们就已经使用了函数指针。并用函数指针对我们的变量进行了函数运作结果的修改。
    回到刚才的问题，返回值。
    我们返回的是谁？是r。r是谁？是数组。数组本质是什么？其实就是指针。那么指针是什么？是内存地址。
    所以我们返回的r返回的是什么？是一个内存地址。
    我们可以看到这条指示链还是非常清晰的。
    对于这个数组，它的内存地址是一个数组的首地址，也就是数组的第一个元素的地址。
    数组的容量大小也就是元素数量，加上我们知道数组的类型
    我们就可以根据这个数量乘上类型的大小，来计算出这个数组的内存占用大小。
    因此，我们的数组的地址就是首地址，这就完全足够了。
    解释完数组以及上面函数的返回值。我们来讲解一下它们的运作流程。
    首先我们的这个函数是一个随机函数，它会生成10个随机数，并且将这些随机数存储在数组r中。
    这个阶段我们在函数当中完成，也就是定义r，赋值r，打印r。
    这个流程非常清晰地展示了这个函数的运作流程
    这个函数就像是流水线工厂，它完成了所有的流程后该做什么？就是打包发出。
    因此我们传出的就是这个r。也就是我们的产品，一个由10个随机数构成的数组。
    传递的r实际上传递的是这个数组的首地址。
    然后回到主函数对它的应用当中。
    fucback_P = getRandom();
    这条命令就是将这个数组的首地址赋值给了fucback_P。
    那么fucback_P他就指向了这个数组，所以最后的打印就是在打印这个数组的内容。
    那么读者可能会发问。
    一个函数结束后它内部产生的值什么的不都会清空吗？
    那么为什么这个数组还存在呢？
    这是因为我们在函数当中定义了一个static类型的数组。
    那么static是什么？
    它是一种存储类型修饰符，它的作用是将变量的生命周期延长到整个程序的运行期间。
    有了static的修饰，它的生命周期不会因为函数的结束而结束，它会一直存在于内存当中，直到程序结束。
    所以，我们的数组依旧存在。
    这也就是为什么，C++ 不支持在函数外返回局部变量的地址，除非定义局部变量为 static变量。
    因为只有这样，这个地址才能代表有效内容，而不会导致空指针泄露的安全风险。
    */
    

    //对此，你一定理解了static是什么，什么是指针函数，什么又是函数指针，以及整个系统的运作流程。
    

    /*
    现在，我们已经学习完了指针
    接下来我们将学习引用
    这是两个极容易混淆的概念
    在最后我们会对指针和引用进行一个总结性的对比
    */

    //C++引用
    /*
    引用是C++的一个重要概念或者说也叫特性
    它是C++中一种特殊的类型，它为一个已经存在的变量提供了一个别名。
    也就是说，它是某个已经存在变量的另一个名字。
    一旦把引用初始化为某个变量，就可以使用该引用名称或者变量名来指向变量
    引用必须在定义时初始化，但一旦绑定到某个变量后，就不可以再绑定别的变量
    */
    //引用的基本定义语法，&读作“引用”，示例可以读作 "ref_arf是一个初始化为arf的整型引用"
    int arf = 10;
    int& ref_arf = arf;
    //上面还可以写成int &ref = arf;，这两种写法是等价的
    //和指针相似，这两种写法中，&符号紧靠类型名的写法更容易理解，表示这是一个引用类型的变量
    cout << "arf = " << arf << endl;
    cout << "ref = " << ref_arf << endl;
    /*
    引用与指针存在很多不同，他们不是一个东西
    1.不存在空引用，因此它必须连接到合法内存
    2.引用被绑定后只能指向这一个对象，但指针可以修改或指向任意对象
    3.引用被创建的时候就应当初始化，指针则可以任意时候进行初始化
    4.引用的对象一定是一个变量，指针则是地址
    5.引用可以直接使用，无需解引用
    6.引用不允许多级间接访问，也就是引用变量不能再被引用
    7.引用不能进行算术运算，指针可以
    8.引用常用于函数参数传递，指针常用于动态内存分配
    9.引用不能直接创建引用数组，但可以创建数组的引用
    10.引用不能作为类的成员变量，但可以作为类的成员函数的返回值
    11.安全性上引用更加安全，但相比指针不够灵活
    12.底层来讲，引用是由指针实现的，但它们在语法上是不同的
    13.引用不占用额外内存，编译器通常会优化为直接操作所引用的对象
    */  
    //相比这么多不同，你肯定没记住几个，甚至一个都没记住
    //对此，我将会挨个示例代码讲述


    // 1. 引用NULL报错


    // 2. 引用不可以重新绑定

    // 3. 引用不占用内存，会被优化为别名

    // 4. 可以直接访问
    int ref_null = 100;
    int& null_ref = ref_null;
    cout << ref_null << endl;

    // 5. 不支持多级引用，即引用不能被引用

    // 6. 通常用于函数传参 | 这里用到头部定义的调换函数swap
    int refnumber_1 = 100;
    int refnumber_2 = 200;
    cout << "number 1 : " << refnumber_1 << endl;
    cout << "number 2 : " << refnumber_2 << endl;
    cout << "Swap rsult : " << endl;
    swep(refnumber_1 , refnumber_2);
    cout << "number 1 : " << refnumber_1 << endl;
    cout << "number 2 : " << refnumber_2 << endl;

    /*
    一定有人会问，为什么会这样？为什么我们总要借助引用、指针来通过函数修改外部变量的数据？
    这就要讲到函数的生命周期了
    函数在结束时，它内部所创建的变量，运算结果等都会在return传出后立刻销毁
    而对于void，它不需要return，自然也就直接在运行结束后销毁了
    可见，如果想要函数对外部发生改变，最简单的方式莫过于用return传出一个值给到外部
    但是，一个函数只有一次returrn，传出的值实在有限制
    对此，我们就会想到用指针，通过直接修改内存数据的方式来修改外部参数
    这就是我们的指针函数传参和函数指针传参的方法
    对于他们两个，你肯定是知道的，我们前面讲过
    那么还有没有办法改变了呢？
    当然有啊，不就是引用嘛，这就是引用传参
    我们可以看到swap函数给了两个入口，都是引用变量
    当我们传入refnumber_1和refnumber_2时，x和y就会引用他们
    这样，当我们修改函数内的x，y
    对应的，外部的refnumber_1和refnumber_2就会被修改
    因为引用最底层还是指针
    虽然我们认为它是一个变量的别名
    但这个别名就如同一个”量子纠缠“
    当引用发生改变，其代表的原始变量自然也会发生相同的改变
    这就是引用，这就是原理
    */

    //都到这里了，引用其实也可以作为返回值，也就是引用函数，对照前面的指针函数类似
    //函数依旧定义在文件头
    cout << "改变前的值列表" << endl;
    for(int i = 0 ; i < 5 ; i ++){
        cout << "values[ " << i << " ]";
        cout << values_group[i] <<endl;
    }
    cout << "改变后的值列表" << endl;
    fiset_values(1) = 31.5;
    fiset_values(3) = 21.5;
    for(int i = 0 ; i < 5 ; i++){
        cout << "Values : [ " << i <<  " ] = ";
        cout << values_group[i] << endl;
    }
    /*
    函数贴在这里：
    double& fiset_values(int i){
        double& ref = values_group[i];
        return ref;
    }

    在上面的引用函数中，[拿其中一个举例]我们对引用函数fiset_values传入了1 
    这个1会传到给函数中的i，由于这是一个引用函数
    根据函数的基本性质，函数的类型决定他的返回值类型，因此返回的ref就是一个引用类型
    对此我们在函数内部定义它时，他就是一个引用类型
    由于我们传入1，所以这里的ref被初始化成了数组的第一个元素
    也就是说，ref代表的就是那个全局数组当中的第一个元素
    对此，当我们返回ref出来的时候，实际上fiset_values(1) = 31.5被编译成 ref = 31.5
    也就是说，数组中的那第一个元素被修改成了31.5
    到此流程结束
    */

    //引用还有一个比较简洁的应用，就是修改静态变量，函数在头部
    int& static_ref = getStaticRef();
    cout << " 初始值 : " << static_ref << endl;
    static_ref = 10 ; 
    cout << " 修改后 : " << getStaticRef() << endl;

    // 7. 不能直接创建引用数组，但可以创建数组引用
    int arr_for_ref[5] = {0};
    int (&ref_arr)[5] = arr_for_ref;

    // 8. 安全但不如指针灵活
    //到此引用讲完了



    /*   结构体struct   */
    /*
    C/C++都允许定义可存储相同类型数据项的变量，但结构是C++的另一种用户自定义的可用数据类型
    它允许我们存储不同类型的数据项
    因此，你可以把结构体理解为是一种用户自定义数据类型    
    */
    /*
    ----结构体组成
    ->struct关键字 ： 定义结构体用
    ->成员变量 ： 是struct中的数据项，可以是任何类型，默认是public权限
    ->访问权限 ： public ，private ， protected 是常见的三种访问权限
    public权限可以让所有内外部成员都可以随意调用
    private权限只能让内部成员调用
    protected权限谁都无法调用
    struct与class有区别，class默认为private权限
    */
    
    //创建结构体 : 请在文件头部查找
    //结构体的优点：1.适合封装和数据存储 2.轻量化 3.面向对象属性 ; 此处不做细致讲解，后面会讲到
    
    //定义books变量
    books book1;
    books book2;
    //设定book1的数据
    strcpy(book1.title , "C++代码教程");
    strcpy(book1.author , "无名氏");
    strcpy(book1.subject , "编程教程");
    book1.bookID = 1314520;
    //设定book2的数据
    strcpy(book2.title , "C语言代码教程");
    strcpy(book2.author , "无名氏");
    strcpy(book2.subject , "编程教程");
    book2.bookID = 1145141;

    //数据输出，这里随便输出两个
    cout << book1.title << " ID代码是 ";
    cout << book1.bookID << endl;

    /*  下面是结构体的一些基本应用  */
    //1. 结构体作为函数参数 
    printBook(book1);
    printBook(book2);
    cout << endl;

    //2. 指向结构体的指针
    struct books *struct_pointer;
    //此代码定义了一个struct_pointer指针，默认指向books结构变量的地址
    struct_pointer = &book1;
    //此代码会将指针指向具体的books结构类型的变量book1
    struct_pointer->title;
    //此代码使用->将指针指向了book1.title

    //那么怎么通过指针输出对应数据呢？
    //如果想要直接用cout打印，会发现编译器会报错，因为cout不能识别结构体变量，对此需要重载<<，后续讲到
    //这里用函数指针的方式实现，printBookInfo函数在头部
    //因为我们对上面的函数定义的是onst books* book传入参数类型，因此只能接受指向books的指针
    struct books *ptrbooks2;
    ptrbooks2 = &book2;
    printBookInfo(ptrbooks2);
    /*
    函数代码：
    void printBookInfo(const books* book){
        cout << "书籍标题: " << book->title << endl;
        cout << "书籍作者: " << book->author << endl;
        cout << "书籍类目: " << book->subject << endl;
        cout << "书籍 ID: " << book->bookID << endl;
    }
    
    工作原理：
    这个函数的参数入口设定的是一个函数指针，但这个指针的类型是books结构体类型
    
    至于为什么有一个const修饰，这里插入讲解一下：
    这其实是一个C++代码书写规范，C语言，C#同样通用
    它实际上是想表明传入一个只读内容
    当我们要引用函数指针的时候，通常默认情况下是为了让形参改变实参
    但此处我们只用作打印，而非任何数据改变
    所以加上const可以有效防止篡改数据等
    本质上我们只是在这里使用到了这一个书写规范而已，此处不加const也不会有影响
    
    接上，这个指针就是我们定义的ptrbooks2
    ptrbooks2指向的是books结构体类型变量book2的地址
    因此，他会传入book2的数据
    此时就会执行打印
    工作原理本质还是一个函数指针
    */
    
    //typedef重定义结构体
    /*
    这段代码将会讲解typedef对struct的改变
    你可以对struct关键字进行取别名
    typedef struct books
    {
    char title[50];
    char autho[50];
    char subject[100];
    int book_id;
    }   
    从此，你可以用books当作结构体关键字
    books book1;
    */
    
    /*   C++的vector容器   */
    //在C++中，vector可谓是STL神器之一
    //vector是容器的一种，而非容器，容器有很多，list，map都算是容器，后面会讲这些
    //vector 本质是一个可自动扩容的动态数组，它的好处在于可以不用手动管理内存，它会自动适应
    //同时，它还支持迭代器，能方便地与STL配合
    //关于STL以及vector，后面都会细细讲解
    /*
    由于vector既具备完整的STL生态，还具有连续内存存储和随机访问速度快等优点
    导致在现代的C++开发中，vector几乎是大部分顺序数据存储场景的首要考虑
    */
    
    
    /*
    在讲 vector 语法之前，先说说 vector 对 CPU 缓存友好的原因。
    CPU 执行速度远快于内存读取速度，为了弥补这个差距，CPU 内部引入了高速缓存（Cache）。
    缓存会提前从内存加载即将使用的数据，但加载的最小单位是缓存行（通常 64 字节）。
    如果内存中的数据是连续排列的，那么一次加载就能把多个相邻数据同时放入缓存，
    后续访问这些数据时就能直接从缓存获取，避免等待内存。
    这就是“空间局部性”——缓存友好的核心。
    vector 的元素在内存中连续存储，遍历时顺序访问相邻地址，完美利用空间局部性。
    第一个元素被加载时，它所在的整个缓存行都被带入缓存
    接下来的几个元素很可能已经在那里了，所以遍历极快。
    而 list、map 等链式结构元素分散，每次访问都可能触发缓存缺失，速度自然慢很多。
    因此，vector 的连续内存让它天生对缓存友好，遍历效率远高于非连续容器。
    */
    
    //vector使用需要引入<vector>
    //vector定义语法
    vector<int>empty_vec;
    vector<int>zero_vec(5);
    vector<int>ten_vec(5 , 10);
    vector<int>initia_vec = {1,2,3,4,5};
    
    //vector功能语法
    //1. push_back()向尾部添加元素
    initia_vec.push_back(100);

    //2.直接元素访问与at元素访问 : at会检查越界，而[]不会
    int initial_vec_x = initia_vec[5];
    int initial_vec_y = initia_vec.at(5);
    cout << "x : " << initial_vec_x << endl;
    cout << "y : " << initial_vec_y << endl;

    //3. .size与.capacity获取大小 : 前者统计元素数量，后者统分配的内存容量
    int initial_vec_size = initia_vec.size();
    int initial_vec_capa = initia_vec.capacity();
    cout << "size : " << initial_vec_size << endl;
    cout << "capacity : " << initial_vec_capa << endl;

    //4. vector扩容机制
    /*   当vector想要扩容，但顺序内存再没法扩容时：
     1.申请更大内存
     2.复制旧元素
     3.释放旧内存
    代价就是占用升高，vector扩容速度会变慢
    如果多次无法找到匹配空间导致重申，就会发生卡壳的情况
    因此尽量避免大规模push_back
    */

    //5. reserve()预分配空间 : 可以有效避免频繁扩容，有效优化vector扩充导致的运行变慢
    vector<int>amplify_vec;
    amplify_vec.reserve(1000);

    //6. vector的遍历
    for(int i = 0 ; i < 1000 ; i++){
        amplify_vec.push_back(i);
    }

    for(size_t i = 0 ; i < amplify_vec.size() ; i++){
        cout << amplify_vec[i] << " " ;
        //5个元素一行
        if(i % (unsigned int)5 == 0){
            cout << endl;
        }
    }
    /*
    size_t类型：本质是无符号整数类型unsigned int
    定义在<cstddef>头文件里，但这个文件一般包含在<iostream>标准库当中
    size_t在C++中并非是关键词，而是类型别名
    一般专门用来表示对象的大小或者数组/容器的元素个数
    */    

    //7. vector迭代器遍历
    for(auto it = amplify_vec.begin() ; it != amplify_vec.end() ; ++it){
        cout << *it << " ";
        //因为迭代器不允许使用模运算符直接运算，所以我们得间接运算
        //原理 ： it-首元素 = 当前元素下标 而默认第一个下标为0，因此得+1得到1开头的索引，接着进行模运算即可
        if( (it - amplify_vec.begin() + 1) % 5 == 0){
            cout << endl;
        }
    }
    //上面的间接运算还以用计数器的方法去操作，这里你可以自己试一试，此处不再赘述

    /*
    在此之前我们没介绍auto，插入介绍一下：
    auto是一个关键字，也是一个C++变量类型
    这个类型的变量，系统会自动识别它的类型，但是auto太多会增加系统占用
    这里使用auto被认为是代码规范，因为可以增加可读性同时也减少代码编写
    迭代器
    迭代器是一个抽象的概念，实际上可以被理解为vector当中的一个专门的指针
    .begin()和.end()实际上也算是一种特殊的vector中的“指针”
    begin会读取vector首元素的位置
    end会读取vector末尾元素的位置
    因此，他们两个只具有类似于指针的指向性
    那么它们的类型是什么呢？
    是 std::vector<int>::iterator 
    这是一个vector的类型，也叫迭代器
    所以这个for代码就是在打印vector中的所有元素
    因为用到迭代器，所以也叫迭代器遍历
    */

    //8. 范围for循环 ： C++11引入的range-based for loop方法，可以快速遍历整个容器
    for (int element : amplify_vec) {
        cout << element << " ";
        if(element % 5 == 0){
            cout << endl;
        }
    }
    //element : amplify_vec 其实是在说，element要依次等于amplify_vec里的每一个元素
    /*
    PS：范围for循环完全等价于迭代器循环，他俩的本质区别在于，范围for循环更简洁
    但代价就是不能跳过某些元素或者指定某些元素，即无法进行精细控制
    */
   
    cout << endl;

    //9. 删除元素 .erase “没错就是擦除的意思，不是橡皮，橡皮是eraser”
    //我们以initia_vec为例子，我们要删除3
    initia_vec.erase(initia_vec.begin() + 3);
    for(int element : initia_vec){
        cout << element << " "; 
    }

    cout << endl;

    //10. 插入元素.insert
    //意思是从initia_vec容器的首元素开始插入，插入为100
    initia_vec.insert(initia_vec.begin() , 100);
    for(int element : initia_vec){
        cout << element << " ";
    }

    /*
    聪明的你一定会发现，我们先前讲过vector存储数据都是连续的
    我们加入一个数需要新空间，这样会引起新内存申请等繁琐操作进而增加占用和时间
    那么同样的，删除操作也会造成占用
    为什么呢？
    聪明你的聪明地察觉到了vector的连续性！
    如果你删除了vector中间的某个元素
    那么这个元素后边的所有元素
    都要发生位置的改变！
    这样，它后面有几个数字，他就得移动几次
    因为在这里元素都是一次一次往前面移动的
    那么，insert肯定也会占用了！
    在哪里插入，它后面的元素就得往后挪
    它们都一样会造成占用，增加运行时间
    所以我们应当避免频繁插入，也应当避免频繁的中间删除，更应该对大对象谨慎扩容删减

    有数据结构与算法基础的同学在这里可以发现
    每次挪动所造成的时间复杂度其实是 O(n) 呈线性增长
    这也就是为什么我们要谨慎对待大对象容器
    */

    //11. 迭代器失效
    /*
    这是个很有趣的现象
    当vector扩充以后，我们原来的vector内存地址很可能就失效了
    原因也很简单
    比如我们的vector新申请了内存
    它的地址就会改变
    */

    //12. clear()清空元素 ->它只会清空元素size，但不会清空capacity
    amplify_vec.clear();
    //clear不主动释放内存

    //13. swap()释放内存 -> 交换法释放内存，最常用且简单粗暴 -> 具体牵扯到析构，以后讲解
    vector<int>().swap(amplify_vec);

    //14. shrink_to_fit()释放内存
    //它不一定真的释放内存，具体取决于size与capacity是否相等
    /*
    若size 与 capacity相等，它就不会实现，这也就决定了它是非强制性释放内存
    这种非强制性释放内存可以有效避免触动敏感环境
    通常我们会对临时缓冲区进行shrink_to_fit()以节省内存
    若它俩不相等
    就会执行新申请size，至于capacity会尽可能对齐size
    通常配合clear使用清空容器
    时间复杂度依然是O(n)，元素数越多，线性变慢
    */
    initia_vec.clear();
    initia_vec.shrink_to_fit();

    
    //15. push_back与emplace_back
    //相比push_back()末尾加数，现代C++更推荐用emplace_back()
    cout << endl;
    ten_vec.emplace_back(100);
    for(int element : ten_vec){
        cout << element << " ";
    }


    //接下来将列举部分C++的常见数据结构
    //这部分当前都属于预览内容，有的你学过，有的你马上要学
    //还有一些是高级功能，后续都会讲到


    //Array 数组
    int Array[5] = {1,2,3,4,5};
    cout <<Array[0];

    //Struct 结构体
    struct person{
        string name;
        int age;
        int ID;
    }Zhangsan;
    Zhangsan = {"Zhangsan" , 18 , 114514};
    cout << "name : " << Zhangsan.name << endl;
    cout << "age : " << Zhangsan.age << endl;

    //Class 类
    class people
    {
    private:
        string name;
        int age;
        int ID;
    public:
        people(string n , int a , int(d)) : name(n) , age(a) , ID(d) {}
        void printInfo(){
            cout << "Name : " << name << "\n Age : " << age << "\n ID : " << ID << endl;
        }
    };
    people Lisi("Lisi",30,1314520);
    Lisi.printInfo();

    //Linked List 链表
    struct Node{
        int data;
        Node* next;
    };
    Node* head = nullptr;
    Node* newNode = new Node{10 , nullptr};
    head = newNode;

    //Stack 栈 需要引用<stack>内存管理头文件
    stack<int> s;
    s.push(1);
    s.push(2);
    cout << s.top();
    s.pop();

    //Queue 队列  需要引用<queue>头文件
    queue<int> q;
    q.push(1);
    q.push(2);
    cout << q.front();
    q.pop();
    
    //Deuqe 双端队列
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(2);
    cout << dq.front(); // 输出 2
    dq.pop_front(); 
    
    //Hash Table 哈希表 需要引用<unordered_map>头文件
    unordered_map<string, int> hashTable;
    hashTable["apple"] = 10;
    cout << hashTable["apple"]; // 输出 10
    
    //Map 映射 需要引用<map>头文件
    map<string, int> myMap;
    myMap["apple"] = 10;
    cout << myMap["apple"]; // 输出 10  
     
    //Set 集合 需要引用<set>头文件
    
    
    //Vector 动态数组 需要引用<vector>头文件
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    cout << v[0]; // 输出 1

    
    //上述内容类似于预览内容，现在有一个印象即可
    //后续我们都会讲到，而且都是比较重要的高级功能
    //在此处提到是为了迎合基础语法的排版
    /*----C++面向对象编程-----*/
    //类&对象
    //C++在C语言的基础上增加了面向对象编程
    //而类就是其核心特性，称为用户自定义类型
    //当后续学习C#这种以面向对象为核心设计的语言时，这些知识点全然互通

    class Box
    {   
        public:
        class smallBox
        {   
            public:
            double length;
            double breadth;
            double height;
            //用于设定smallbox自己的对象
            void set(double len , double bre , double hei){
                length = len;
                breadth = bre;
                height = hei;
            }
            //用于计算smallbox自己的size
            double getboxsize(){
                return (length + breadth + height) * 4;
            }
            //用于设定box对象
            void setbox (Box& outer , double len , double bre , double hei){
                outer.set(len , bre , hei);
            }
        };
        double volume;
        double length;
        double breadth;
        double height;
        
        void set(double len,double bre, double hei){
            length = len;
            breadth = bre;
            height = hei;
        }

        double getvolume(void){
            volume = length * breadth * height;
            return volume;
        }
        
        double getsquare(){
            caculatesquare();
            return square;
        }

        double getboxsize(){
            calculateboxsize();
            return Boxsize;
        }

        protected:
        double Boxsize;
        void calculateboxsize(){
            Boxsize = (length + breadth + height) * 4 ;
        }

        private:
        double square;
        double caculatesquare(void){
            square = 2 * (length * breadth + length * height + breadth * height);
            return square;
        }

    }box1,box2;
    //Box类的变量既可以在外部定义，也可以在内部定义
    Box box3;
    Box box4;

    //下述两种设定方式，一种是函数，由我们自己设定，一种是直接访问public变量输入长宽高
    box1.length = 13;
    box1.breadth = 12;
    box1.height = 11;
    box2.set(3 , 4 ,5);
    box3.set(5, 6 ,7 );

    //下述有两种函数调用逻辑
    //第一种：getvolume函数被定义在public区域，可以被直接在class外部调用
    //这种方式比较直接，相比第二种方式更好理解
    double volume = box3.getvolume();
    cout << "Volume of BOX3 : " << volume << endl;
    //第二种：caculatesuqare函数定义在private区域，不能在class外调用
    //因此，我们得在public区域定义getsquare函数获取caculate值，得到square
    double square = box2.getsquare();
    cout << "Square of BOX2 : " << square << endl;

    //类的嵌套
    Box::smallBox smallbox5;
    smallbox5.set(13.2 , 13.4 , 15.2);
    double box5size = smallbox5.getboxsize();
    smallbox5.setbox(box4 , 13.2 , 14.6 , 17.2);
    double box4size = box4.getboxsize();
    cout << "BOX4 size : " << box4size <<endl;
    cout << "BOX5 size : " << box5size << endl;

    //派生类的protected调用
    class otherBox : public Box
    {
        public:
        void showBoxsize(){
            calculateboxsize();
        }
    };
    otherBox otbox6;
    otbox6.set(3.5 , 6.1 , 3.4);
    otbox6.showBoxsize();
    double otbox6size = otbox6.getboxsize();
    cout << "BOX6 size : " << otbox6size << endl;

    



    /*
    想必你看完上面的代码绕来绕去一脸懵逼，请看下面的讲解
    */
    //上面我们定义了一个Box类，并附赠box1,和box2两个Box类变量
    /*
    在面向对象编程的过程中，我们一般会采用四个规范
    1. 花括号单占一行，就是上面的书写方式,即BSD风格或Allman风格
    2. 最好使用public private protected进行修饰圈画以增强可读性而非采用默认修饰
    3. 合理变量命名方式与注释规范
    4. 尽可能在calss内部定义好函数而非在外部定义以减少维护难度
    现在讲解一下上面的具体语法
    class 类型名
    {
        权限[访问修饰符]:
        定义变量或函数
    }(可选：初始类变量);
    
    1. 访问修饰符：
    public: 成员可以被内外部的任何成员访问修改
    private: 成员只能被内部成员访问修改，单派生类型不可以
    protected: 成员既可以被内部成员访问，也可以被派生类型访问，如果没有继承与派生，他本质与private无异
    
    2. 派生类型：
    在上面的代码里，我们创建了otherBox类，它是Box的派生类型
    但对于smallbox，它是Box的嵌套
    
    3. 默认访问修饰
    double volume定义在class内部但不在非任何访问修饰符内
    class类默认认为这些都是private类型，相比之下struct默认为public类型
    
    4. class内部函数定义
    当我们在main中定义class时，函数必须要在内部完成定义，也就是我们上面的写法
    若我们的class定义在全局当中，函数则可以通过下面的方式在外部定义
    void Box::set(double len, double bre , double hei){
        length = len;
        breadth = bre;
        height = hei;
    }

    5. class函数的调用
    我们在上面讲了两个函数调用方式
    实际上第二种是private如何与外界沟通的方式
    
    6. 各个对象的权限
    对象：如box的对象是box1,box2,box3，而smallbox的对象是samllbox4
    一个很重要的一点是，smallbox无法通过box的函数设定自己的对象
    因为box下的成员函数操作的都是自己对象的成员变量
    其核心是作用于自己的对象上
    这也就本质决定了上面的smallbox无法使用box的函数设定自己的smallbox对象
    但smallbox能否调用box的函数设定box的对象呢？
    答案是可以！
    我们只需要给smallbox一个box对象就可以了
    但smallbox与box属于一个内外层的嵌套关系，它们界限分明无法直接互相调用
    因此我们得借助指针从内存层传递参数，就是我们的setbox函数

    7.派生类型的protected调用
    派生和继承会在后续讲解到，这里只需要理解即可
    我们在上面定义了一个叫otherBox的派生类型
    它在外是可以访问Box里的protected和public权限下的东西
    同样的Box也可以访问派生类型的protected与public
    */

    /*  --- 类构造函数&析构函数 ---  */
    //一、类的构造函数
    /*
    构造函数是一种特殊的成员函数
    在每次创建类的新对象时，构造函数都会自动执行
    构造函数的名称与类的名称完全相同，且没有返回类型
    构造函数通常用于成员变量设置初始值
    */
    /*
    构造函数注意事项
    1. 构造函数没有明确的类型名称，且是相对于类而言的功能
    2. 构造函数的名称与类的名称完全一致，比如我的类叫Line，构造函数也得叫Line，否则就是别的函数
    3. 构造函数不可以在main中进行定义操作
    4. 原则上来讲可以在main里的类中进行局部定义，但不推荐，且限制极多，开发也很少用
   
    */
    //1. 一般构造函数：头部已定义好一个构造函数
    Line line;
    line.setLength(6.0);
    cout << "Length of line : " << line.getLength() << endl;

    //2.带参数的构造函数，也在头部，要求就是创建新变量必须输值进行初始化
    Line2 line2(2.5);

    //3.初始化列表 -> 代码规范
    //这里不做专门代码
    //这里给你写一下怎么写的
    /*
    Line2::Line2(double len) : lengt(len){
        cout << len << endl;
    }
    它就等价于我们在头部写的那种，直接定义方法
    */

    /*  ---类的析构函数---  */
    /*
    析构同样是一种特殊的成员函数
    在对象的生命周期结束的时候会自动执行，以用于释放对象占用的内存
    析构函数的名称与类也是完全相同的，只不过要加一个~前缀
    析构函数同样不返回任何值，而且一个类对应一个析构函数
    说人话，析构函数就是当前生命周期结束时做的最后一件事
    */
    Cube little_cube;
    little_cube.setlen(3.4 , 5.6 , 7.3);
    volume = little_cube.getvolume();
    cout << "Cube 的 体积 : " << volume << endl;
    //在这里，我们的little_cube是一个栈对象，因为它在main中直接定义
    //因此析构函数会在main结束后(运行到main的最后一个花括号)自动调用 
    //但如果我们要用到delete手动删除它，析构函数会在delete结束后自动调用
    //但因为我们这个little_cube是栈对象，不可以被手动删除，除非我们用new创建堆对象指针
    /*   后续会讲解什么是栈，什么是堆，以及什么是delete   */

    /*  ---拷贝构造函数---  */
    /*
    拷贝构造函数是一种特殊的构造函数
    顾名思义拷贝就是复制粘贴，所以在创建对象的时候
    它会使用同一类之前创建过的对象来进行新对象的初始化
    拷贝函数的要求：
    如果在类中没有定义拷贝构造函数，编译器会自行定义一个。
    如果类带有指针变量，并有动态内存分配
    则它必须有一个拷贝构造函数。
    */

    /*
    在学习拷贝函数之前，我们先简单学习栈与堆
    栈与堆都是计算机内存
    栈是顺序内存，所以很快
    但代价就是必须按顺序存取，先进后出
    堆则比较随意，甚至分散
    所以它慢
    但好处就是它可以不用按顺序来
    一般，我们在main当中定义的变量，都会放在栈里
    所以，对于上面的一些变量或函数，我们没法用delete删掉
    */
    
    triangle little_triangle(3,5);
    square = little_triangle.getsquare();
    cout << "初始默认三角形面积 ： " << square << endl;
    triangle another_triangle(little_triangle);
    triangle lilitle_triangle = little_triangle;
    /*
    关于拷贝函数的种种，你可以回到头部那里学习
    */







    







    return 0;
}

int min(int num1, int num2){
    int result = 0;
    if(num1 < num2){
        result = num1;
    }else{
        result = num2;
    }
    return result;
}
