//C++标准库中的头文件
//C++程序至少包含一个头文件，通常是iostream头文件，但并不一定是这样
//不同情况下要求不同，自然头文件也不同，但语法结构和代码风格是相同的
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

/*
命名空间
C++中的新型概念，是C++中用于组织代码的一种机制。
它允许将标识符（如变量、函数、类等）分组到不同的命名空间中，以避免命名冲突。
通过使用命名空间，可以在不同的代码模块中使用相同的标识符而不会产生冲突，从而提高代码的可读性和可维护性。
比如，在我们没使用这条指令时，每次调用std空间下的指令时就必须要加上std::，从而与其他空间区分开来 
*/
using namespace std;

//定义常量-宏定义方式
#define pi 3.14

/*多行注释语法：
第二种写法*/

//全局变量的定义
//NULL 空值，通常用于初始化不需要赋值的变量，或者用于指针的初始化
int Global_Variables = NULL;

//一般函数的标准形式
int max(int num1 , int num2){
    int result = NULL;
    if(num1 > num2){
        result = num1;
    }else {
        result = num2;
    }
    return result;
}
//函数的声明（前置声明）：此处只声明 min 的原型，函数体定义在文件末尾；main 函数结束通常需要用return返回0值表示程序正常结束
int min(int num1 , int num2);


//函数只声明而未定义时，直接调用会弹出警告（红色波浪线）
int main(){
    
    //C++常见的预处理宏
    cout << "__DATE__:" << __DATE__ << endl;                             
    cout << "__TIME__:" << __TIME__ << endl;
    cout << "__FILE__:" << __FILE__ << endl;
    cout << "__LINE__:" << __LINE__ << "\n\n";
    
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
    long long type_LL_int_min = -9223372036854775808;
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
    char single_site[4] = {'C','A','I','\0'};
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
         
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}

int min(int num1, int num2){
    int result = NULL;
    if(num1 < num2){
        result = num1;
    }else{
        result = num2;
    }
    return result;
}
