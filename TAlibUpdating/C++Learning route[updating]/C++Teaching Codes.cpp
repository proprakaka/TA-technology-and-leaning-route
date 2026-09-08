//C++标准输入输出流头文件
#include<iostream>

//C++固定位数小数点表示
#include<iomanip>

//C++随机数rand与srand种子
#include<cstdlib>
#include<ctime>

//C++的数学运算头文件
#include<cmath>

//C++的字符串操作头文件
#include<cstring>

//C++的string操作头文件
#include<string>

//命名空间
using namespace std;

//定义常量-宏定义方法
#define pi 3.14

/*这是注释语法的
第二种书写方式*/

//全局变量定义
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
//函数声明：可以用于在其他地方单独定义：见return 0 后
int min(int num1 , int num2);


//若变量没有被我们调用或初始化，编译器就会弹出警告【红色波浪线】
int main(){
    //预制宏
    cout << "__DATE__:" << __DATE__ << endl;                             
    cout << "__TIME__:" << __TIME__ << endl;
    cout << "__FILE__:" << __FILE__ << endl;
    cout << "__LINE__:" << __LINE__ << "\n\n";
    //常见内置类型
    int type_int = 1;
    float type_float = 0.1F;
    double type_double = pi;
    char type_char = 'c';
    bool type_bool = true;
    wchar_t type_wchart = L'C';
    auto type_auto = type_int;
    
    //常见修饰符
    signed type_signed_int = -1;
    unsigned type_unsigned_int = 1;
    short type_short_int_max = 32767;
    short type_short_int_min = -32768; 
    long type_long_int_max = 2147483647;
    long type_long_int_min = -2147483648;
    long long type_LL_int_max = 9223372036854775807;
    long long type_LL_int_min = -9223372036854775808;
    const int type_const_int = 123;
   
    //基本语法
    cout << "Hello World but changed by endl"<< endl;
    cout << "Hello World but chaned by \\n \n";
    cout << "This is a long \
string used \'\\\' in the sentence\n";
    cout << "First<<" << " " << "Second<<" << endl;
    cout << "type_int = " << type_int << endl;
    cout << "type_float = " << type_float << endl;
    
    //C++的小数显示模式是自动省略小数点后末尾0，这也就需要我们固定位数表示
    //fixed和setprecision都来自于iomanip，fixed用于固定显示位数，而setprecision用于传入显示多少位
    //如果我们不需要固定位数，就不需要用fixed
    cout << "type_double = " << fixed <<setprecision(10) << type_double << endl;
    cout << "type_char = " << type_char << endl;
    
    //boolalpha是iostream中的一个标准输入输出操作符，可以让bool类型的变量输出字符而非数字
    cout << "type_bool = " << boolalpha << type_bool << endl;
    
    //这一段用到static_cast强制转换，将wchar_t类型的数值转换成整数形式输出
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
   
    //sizeof第一个应用：获取基本数据类型的大小
    cout << "char : " << sizeof(char) << "字节" << endl;
    cout << "int : " << sizeof(int) << "字节" << endl;
    cout << "unsigned short :" << sizeof(unsigned short) << "字节" << endl;
    cout << "wchar_t :" << sizeof(wchar_t) << "字节" << endl;
   
    //typedef基本应用
    typedef int zheng;
    zheng type_int_zheng = 123;
   
    //简单的enmu枚举类型创建
    enum color {red , green = 100 , blue} color_red , color_green , color_blue;
    color mycolor = red;
    cout << "mycolor="<< mycolor << endl;
    cout << "color_red=" << color_red << endl;
    cout << "color_green=" << color_green << endl;
    cout << "color_blue=" << color_blue << endl;
    
    
    /*下面是类型转换，只展示上述学到的知识水平*/
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
    cout << "解释: 不同于static_cast强制转换，该转换会从头按照float方式读取int存储的10，最后读取到二进制是0x0000000A，也就是0"<< "\n\n";
    
    
    /*以下是程序流程结构的选择结构篇*/
    //1.if语句
    cout << "\nif语句结果" <<endl;
    srand(time(0));
    int if_sentence_num1 = rand();
    int if_sentence_num2 = rand();
    if(1){
        cout << "第一个数"<< if_sentence_num1 <<"和第二个数" << if_sentence_num2 <<endl;
    }
    //2.if-else语句
    cout <<"\nif-else语句结果"<<endl;
    if(if_sentence_num1 > 10000){
        cout << "第一个数" << if_sentence_num1 <<"大于10000" << endl;
    }else{
        cout << "第一个数" << if_sentence_num1 <<"小于或等于10000" << endl;
    }
    //3.else if语句
    cout <<"\nelse if语句结果"<<endl;
    if(if_sentence_num1 > if_sentence_num2){
        cout << "第一个数"<< if_sentence_num1 <<"大于第二个数" << if_sentence_num2 <<endl;
    }else if (if_sentence_num1 < 10000) {
        cout << "第一个数"<< if_sentence_num1 <<"小于10000,因此小于第二个数"<<if_sentence_num2<<endl;
    }else{
        cout << "第一个数"<< if_sentence_num1 <<"大于等于一万但却小于第二个数"<<if_sentence_num2<<endl;
    }
    //4.if的嵌套
    cout <<"\nif嵌套语句的结果"<<endl;
    if(if_sentence_num1 > if_sentence_num2){
        if(if_sentence_num1 > 10000 || if_sentence_num2 < 10000){
            cout<<"第一个数"<<if_sentence_num1<<"大于一万且第二个数"<<if_sentence_num2<<"小于一万"<<endl;
        }
        cout<<"第一个数"<<if_sentence_num1<<"大于第二个数"<<if_sentence_num2<<endl;
    }else if (if_sentence_num1 = if_sentence_num2){
        cout<<"相等，都是"<<if_sentence_num1<<endl;
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
    cout<<"\n三目运算符"<<endl;
    int switch_fixed_num3 = if_sentence_num1 > if_sentence_num2 ? if_sentence_num1 : if_sentence_num2;
    cout<<"三目运算比较第一个数和第二个数得大数:"<<switch_fixed_num3<<endl;
    
    
    /*以下是程序流程结构的循环结构篇*/
    //1.while循环 
    cout<<"\nwhile循环案例结果"<<endl;
    cout<<"打印二十次Hello World"<<endl;
    int while_count = 1;
    while(while_count <= 20){
        cout<<"第"<<while_count<<"次"<<"Hello World"<<endl;
        while_count ++;
    }
    //2.for循环
    cout<<"\nfor循环案例结果"<<endl;
    cout<<"倒数10下"<<endl;
    for(int i = 0 ; i < 10 ; i++){
        cout<<10-i<<endl;
    }
    //3.do while循环
    cout<<"\ndo while循环案例结果"<<endl;
    cout<<"正数10下"<<endl;
    int dowhile_count = 1;
    do{
        cout<<dowhile_count<<endl;
        dowhile_count ++;
    }while(dowhile_count <= 10);
    //4.嵌套循环
    cout<<"\n嵌套循环案例结果"<<endl;
    cout<<"\n试除法筛选一百以内的素数"<<endl;
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
    cout<<"\ncontinue与break在一种位置，但作用是重新开始当前循环而不是终止"<<endl;
    
    /*以下是C++的函数*/
    cout<< "\nC++一般函数形式-比较数的大小" << endl;
    //由于C/C++不允许在函数内部定义另一个函数，即嵌套函数是非标准的，故而放置在main函数外
    int Compare_num1 = rand();
    int Compare_num2 = rand();
    cout<< "两数比较结果:"<< max(Compare_num1,Compare_num2)<<endl;
    cout<< "两束比较结果:"<< min(Compare_num1,Compare_num2)<<"\n\n";
    
    cout << "\n----------------------C++常见数学元素----------------------"<<endl;  
    /*C++常见的数学运算*/
    cout << "\n以下是<cmat>常见数学运算"<<endl;
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
    cout << "\n一维数组以及基本应用" << endl;
    int numbers_height[] = {170 , 180 , 173 , 168 , 169 , 183 , 170};
    int numbers_weight[7] = {70 , 69 , 68 , 59 , 60 ,61 ,64};
    int ZhangSan_height = numbers_height[5];
    int LiSi_weight = numbers_weight[3];
    cout << "张三的身高是：" << ZhangSan_height << endl;
    cout << "李四的体重是：" << LiSi_weight << endl;
    
    cout << "\n多维数组以及基本应用" << endl;
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
    cout << "\n----------------------C风格字符串基本操作----------------------"<<endl;
    cout << "C风格的字符串起源于 C 语言，并在 C++ 中继续得到支持。\n\
字符串实际上是使用 null 字符以及\\0\
终止符的一维字符数组。\n\
因此，一个以 null 结尾的字符串，包含了组成字符串的字符。\n\n";
    char single_site[4] = {'C','A','I','\0'};
    char string_site[] = {"'STUDY"};
    cout << "C++会自动在末尾补null字符，即\\0字符"<<endl;
    cout << single_site << endl;
    cout << string_site << "\n";
    
    char str_temp[10] = {0};
    strcpy(str_temp,single_site);
    cout << "strcpy(s2->s1): " << str_temp << endl;
    cout << "strcat(s1+s2) : " << strcat(single_site,string_site) << endl;
    int str_len = strlen(single_site);
    cout << "strlen(s1) : " << str_len << endl;
    
    
    /*C++string类型字符串*/
    cout << "\n----------------------C++风格字符串基本操作----------------------"<<endl;   
    string string_str1 = "CAI'";
    string string_str2 = "STUDY";
    
    string string_temp = string_str1;
    cout << "str3 = str1 --> str3 : " << string_temp << endl;
    
    string_temp = string_str1 + string_str2;
    cout << "str3 = str1 + str3 --> str3 : " << string_temp << endl;
    
    str_len = string_temp.size(); 
    cout << "str3.size(s1+s2) ---> str3 : " << str_len << endl;
    
    
    cout << "\n----------------------C++指针----------------------"<<endl;  
    cout << "变量地址的输出打印" << endl;
    int var_act1;
    char var_act2[10];
    cout << "int act1的变量地址: " << &var_act1 << endl;
    cout << "cahr[10] act2的变量地址: " << &var_act2 << endl;
    
    //C++中使用指针
    int* int_pointer;
    int Ptest = 1;
    int_pointer = &Ptest;
    
    
    
    
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
