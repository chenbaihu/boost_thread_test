/*
 *boost::scoped_ptr的实现和std::auto_ptr非常类似，都是利用了一个栈上的对象去管理一个堆上的对象，从而使得堆上的对象随着栈上的对象销毁时自动删除。
 *
 *不同的是，boost::scoped_ptr有着更严格的使用限制——不能拷贝。这就意味着：boost::scoped_ptr指针是不能转换其所有权的。
 *
 *1.不能转换所有权
 *  boost::scoped_ptr所管理的对象生命周期仅仅局限于一个区间（该指针所在的"{}"之间），无法传到区间之外，
 *  这就意味着boost::scoped_ptr对象是不能作为函数的返回值的（std::auto_ptr可以）。
 *
 *2.不能共享所有权
 *  这点和std::auto_ptr类似。这个特点一方面使得该指针简单易用。另一方面也造成了功能的薄弱——不能用于stl的容器中。
 *
 *3.不能用于管理数组对象
 *  由于boost::scoped_ptr是通过delete来删除所管理对象的，而数组对象必须通过deletep[]来删除，因此boost::scoped_ptr是不能管理数组对象的，
 *  如果要管理数组对象需要使用boost::scoped_array类。
 *
 * 接口函数如下:
 *     void reset(T* p = 0); 
 *     T& operator*() const; 
 *     T* operator->() const; 
 *     T* get() const; 
 *     void swap(scoped_ptr& b); 
 *
 * 目前c++标准库中还不支持scoped_ptr
 * */

#include <boost/scoped_ptr.hpp>

#include <string>
#include <iostream>

class implementation {
public:
    ~implementation() { std::cout <<"destroying implementation\n"; }
    void do_something() { std::cout << "did something\n"; }
};

void test()
{
    boost::scoped_ptr<implementation> impl(new implementation());
    impl->do_something();
}

int main(int argc, char* argv[])
{
    std::cout<<"Test Begin ... \n";
    test();
    std::cout<<"Test End.\n";
}

